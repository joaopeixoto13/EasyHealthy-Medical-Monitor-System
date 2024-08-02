#include "widget.h"
#include "qtconcurrentrun.h"
#include "ui_widget.h"
#include "QQmlContext"
#include "QQuickItem"
#include <QScroller>
#include "MessageQueue.h"
#include <sstream>
#include <unistd.h>

#define ACK "1"
#define NACK "0"


std::string dateToString(QString sdate)
{
    int date = sdate.toInt();
    int month = int(date / 10000);
    int day = int(date / 100) % 100;
    int hour = int(date % 100);
    return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(hour);
}

/**
 * @brief Construct a new Widget object
 * @param parent widget
 */
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /**< Start on the Resume page*/
    ui->stackedWidget->setCurrentIndex(9);
    /**< Configure the handler of the virtual keyboard*/
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/VtKeyboard.qml")));
    ui->quickWidget->setFocusPolicy(Qt::NoFocus);
    ui->quickWidget->show();
    /**< Set the callback of the signal send by the InputPanel*/
    auto QObj1 = ui->quickWidget->rootObject();
    QObject::connect(QObj1,SIGNAL(keyboardchanged(bool)),this,SLOT(keyboardChanged(bool)));
    /**< Configure the scroll area to use the virtual keyboard*/
    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);
    /**< Configure the scroll area to use the virtual keyboard*/
    QScroller::grabGesture(ui->scrollArea_2, QScroller::LeftMouseButtonGesture);
    m_previousWidget = 0;
    m_settingsFlowControl = false;
    /**< Start the threads*/
    QtConcurrent::run(this,&Widget::tInterface);
    QtConcurrent::run(this,&Widget::tUpdateGUI);;
}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Thread responsable to send the information to the backend
 */
void Widget::tInterface(void)
{
    /**< Create the message queue*/
    CMessageQueue mq(MSGQ_FROM_GUI, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
    mq.open();
    std::string content;
    while(1)
    {
        /**< If exist information to send*/
        if(!m_tInterfaceBuffer.isEmpty())
        {
            content = m_tInterfaceBuffer.front();
            const char* msgcontent = content.c_str();
            mq.send((char*)msgcontent);
            m_tInterfaceBuffer.pop();
        }
        usleep(50);
    }
    mq.close();
}


/**
 * @brief Thread responsable for receive the information from the backend and update the GUI
 */
void Widget::tUpdateGUI(void)
{
    /**< Create the message queue*/
    CMessageQueue mq(MSGQ_TO_GUI, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
    char msgcontent[MAX_MSG_LEN];
    int row = 0;
    mq.open();
    while(1)
    {
        std::string content, st1;
        std::stringstream ss;
        QStringList listA;
        QString qline;
        /**< Wait for information from the backend*/
        mq.receive(msgcontent);
        /**< Parse the message*/
        content = msgcontent;
        switch (msgcontent[0])
        {
            case 'N':
                /**< If the user dont exist, open the settings page*/
                content = content.substr(2);
                if(content == NACK)
                {
                    /**< Clean all contents*/
                    ui->SettingsFeedbackLabel->clear();
                    ui->NameLineEdit->clear();
                    ui->UserEmaiLineEdit->clear();
                    ui->DoctorEmailLineEdit->clear();
                    ui->FeminineRadioButton->setChecked(false);
                    ui->MasculineRadioButton->setChecked(true);
                    ui->HeightSpinBox->setValue(1);
                    ui->WeightSpinBox->setValue(1);
                    ui->ActivityLevelSpinBox->setValue(1);
                    ui->AgeSpinBox->setValue(1);
                    m_previousWidget = ui->stackedWidget->currentIndex();
                    m_settingsFlowControl = false;
                    ui->stackedWidget->setCurrentIndex(8);
                }
                /**< else open main menu page*/
                else
                    ui->stackedWidget->setCurrentIndex(1);
                break;
            case 'S':
                /**< Print the content of the message in the table*/
                if(content.length() > 3)
                {
                    content = content.substr(2);
                    ss.str(content);
                    row = 0;
                    while (std::getline(ss,st1))
                    {
                        qline = QString::fromStdString(st1);
                        listA = qline.split(' ');
                        listA.replaceInStrings("_"," ");
                        listA.removeAt(1);
                        ui->tableWidget->insertRow(row);
                        for (int x = 0; x < listA.size(); x++)
                        {
                            QTableWidgetItem *item = new QTableWidgetItem(listA.at(x));
                            ui->tableWidget->setItem(row, x, item);
                        }
                        row++;
                    }
                }
                ui->stackedWidget->setCurrentIndex(6);
                break;
            case 'R':
                content = content.substr(2);
                /**< Print the result of the measurement*/
                ui->RunTestButton->setDisabled(false);
                /**< Measurement result*/
                if(content == NACK)
                    ui->RunResulLabel->setText("Error during the measurement!");
                else
                {
                    qline = QString::fromStdString(content);
                    listA = qline.split(' ');
                    ui->RunResulLabel->setText(QString::fromStdString("Result = " + listA.at(2).toStdString()));
                }

                break;
            case 'E':
                content = content.substr(2);
                /**< Print the result of the export operation*/
                ui->PersonalButton->setDisabled(false);
                ui->DoctorButton->setDisabled(false);
                ui->USBButton->setDisabled(false);
                ui->RunTestPageBackButton->setDisabled(false);
                /**< Export operation result*/
                ui->ExportResultLabel->clear();
                ui->ExportResultLabel->setText(QString::fromStdString(content));
                break;
            case 'M':
                content = content.substr(2);
                qline = QString::fromStdString(content);
                listA = qline.split(' ');
                listA.replaceInStrings("_"," ");
                ui->label_2->setText(listA.at(0));
                ui->label_3->setText(listA.at(1));
                ui->label_4->setText(listA.at(2));
                ui->label_5->setText(listA.at(3));
                ui->stackedWidget->setCurrentIndex(0);
                break;
            case 'I':
                content = content.substr(2);
                qline = QString::fromStdString(content);
                listA = qline.split(' ');
                ui->SettingsFeedbackLabel->clear();
                ui->NameLineEdit->setText(listA.at(0));
                ui->UserEmaiLineEdit->setText(listA.at(5));
                ui->DoctorEmailLineEdit->setText(listA.at(6));
                if(listA.at(1) == "1")
                {
                    ui->FeminineRadioButton->setChecked(true);
                    ui->MasculineRadioButton->setChecked(false);
                }
                else
                {
                    ui->FeminineRadioButton->setChecked(false);
                    ui->MasculineRadioButton->setChecked(true);
                }
                ui->HeightSpinBox->setValue(listA.at(3).toInt());
                ui->WeightSpinBox->setValue(listA.at(4).toInt());
                ui->ActivityLevelSpinBox->setValue(listA.at(7).toInt());
                ui->AgeSpinBox->setValue(listA.at(2).toInt());
                m_previousWidget = ui->stackedWidget->currentIndex();
                m_settingsFlowControl = false;
                ui->stackedWidget->setCurrentIndex(8);
                break;
            case 'T':
                if(content.length() > 3)
                {
                    content = content.substr(2);
                    ss.str(content);
                    row = 0;
                    while (std::getline(ss,st1))
                    {
                        qline = QString::fromStdString(st1);
                        listA = qline.split(' ');
                        listA.replace(1,QString::fromStdString(dateToString(listA.at(1))));
                        if(listA.at(0) == "T")
                            listA.replace(0, "Temperature");
                        else if(listA.at(0) == "H")
                            listA.replace(0, "HeartBeat Rate");
                        else if(listA.at(0) == "O")
                            listA.replace(0, "Oxygen Saturation");
                        ui->tableWidget_2->insertRow(row);
                        for (int x = 0; x < listA.size(); x++)
                        {
                            QTableWidgetItem *item = new QTableWidgetItem(listA.at(x));
                            ui->tableWidget_2->setItem(row, x, item);
                        }
                        row++;
                    }
                }
                ui->stackedWidget->setCurrentIndex(5);
                break;
            default:
                break;
        }
        usleep(50);
    }
    mq.close();
}

/**
 * @brief Widget::keyboardChanged - Resize the scroll area when the keyboard is opened
 * @param active - true if the keyboard is opened
 */
void Widget::keyboardChanged(bool active)
{
    if(active)
    {
        ui->scrollArea->resize(ui->scrollArea->width(),260);
        ui->scrollArea_2->resize(ui->scrollArea_2->width(),260);
    }
    else
    {
        ui->scrollArea->resize(ui->scrollArea->width(),480);
        ui->scrollArea_2->resize(ui->scrollArea_2->width(),480);
    }
}

/**
 * @brief Widget::UserInactivity - Set the idle page after user inactivity for certain amount of time
 */
void Widget::userInactivity()
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->quickWidget->setParent(ui->SettingsPage);
    ui->quickWidget->stackUnder(ui->WifiClockPage);
}

/**
 * @brief Login Page Callbacks
 */

void Widget::on_User1Button_clicked()
{
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("N 0");
}


void Widget::on_User2Button_clicked()
{
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("N 1");
}


void Widget::on_User3Button_clicked()
{
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("N 2");
}


void Widget::on_User4Button_clicked()
{
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("N 3");
}

/**
 * @brief Main Menu Page Callbacks
 */

void Widget::on_SettingsButton_clicked()
{
    m_tInterfaceBuffer.push("I");
}


void Widget::on_TestButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Widget::on_ScheduleButton_clicked()
{
    ui->ScheduleFeedbackLabel->clear();
    ui->OxygenRadioButton->setChecked(false);
    ui->HeartRadioButton->setChecked(false);
    ui->TempRadioButton->setChecked(true);
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);
    m_tInterfaceBuffer.push("T");
}


void Widget::on_ConsultButton_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->ConsultFeedbackLabel->clear();
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("S");
}


void Widget::on_ExportButton_clicked()
{
    ui->ExportResultLabel->clear();
    ui->stackedWidget->setCurrentIndex(7);
}


void Widget::on_ResumeButton_clicked()
{
    m_tInterfaceBuffer.push("M");
}


void Widget::on_WifiButton_clicked()
{
    ui->WifiNameLineEdit->clear();
    ui->WifiPasswordLineEdit->clear();
    ui->WifiClockFeedbackLabel->clear();
    ui->quickWidget->setParent(ui->WifiClockPage);
    ui->quickWidget->lower();
    ui->stackedWidget->setCurrentIndex(10);
}

/** 
 * @brief Back Buttons Callbacks
 */

void Widget::on_SchedulePageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Widget::on_ConsultMeasurementsBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Widget::on_ExportMenuPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Widget::on_TestMenuPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Widget::on_RunTestPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Widget::on_MainMenuPageBackButton_clicked()
{
    m_tInterfaceBuffer.push("M");
}


void Widget::on_WifiClockPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->quickWidget->setParent(ui->SettingsPage);
    ui->quickWidget->lower();
}

/**
 * @brief Select test Page Callbacks
 */

void Widget::on_TempButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    m_selectedTest = "T";
    ui->RunResulLabel->clear();
    ui->RunTestImageLabel->setStyleSheet("background: rgb(255, 255, 255);image: url(:/Images/temp-info.png);");
    ui->RunTestInformationLabel->clear();
    ui->RunTestInformationLabel->setText("After positioning the sensor as shown in the figure,\n click on the ""Run"" button, keep the sensor steady\n until you ear the sound that signals the end of\n the measurement.");
}


void Widget::on_HeartBButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    m_selectedTest = "H";
    ui->RunResulLabel->clear();
    ui->RunTestImageLabel->setStyleSheet("background: rgb(255, 255, 255);image: url(:/Images/finger-info.png);");
    ui->RunTestInformationLabel->clear();
    ui->RunTestInformationLabel->setText("After put the finger as shown in the figure, click on the ""Run"" button, stay steady and wait until you ear the sound that signals the end of the measurement.");
}


void Widget::on_OxygenStButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    m_selectedTest = "O";
    ui->RunResulLabel->clear();
    ui->RunTestInformationLabel->clear();
    ui->RunTestImageLabel->setStyleSheet("background: rgb(255, 255, 255);image: url(:/Images/finger-info.png);");
    ui->RunTestInformationLabel->clear();
    ui->RunTestInformationLabel->setText("After put the finger as shown in the figure, click on the ""Run"" button, stay steady and wait until you ear the sound that signals the end of the measurement.");
}

/**
 * @brief Settings Page Callbacks
 */

/**
 * @brief Clear the profile 
 * @details This function will send a message to the backend to clear the profile
 */
void Widget::on_ClearProfileButton_clicked()
{
    if(m_previousWidget == 1)
    {
        /**< Clean all contents*/
        ui->SettingsFeedbackLabel->clear();
        ui->NameLineEdit->clear();
        ui->UserEmaiLineEdit->clear();
        ui->DoctorEmailLineEdit->clear();
        ui->FeminineRadioButton->setChecked(false);
        ui->MasculineRadioButton->setChecked(true);
        ui->HeightSpinBox->setValue(1);
        ui->WeightSpinBox->setValue(1);
        ui->ActivityLevelSpinBox->setValue(1);
        ui->AgeSpinBox->setValue(1);
        m_settingsFlowControl = true;
        ui->SettingsFeedbackLabel->setText("Profile cleaned!");
        /**< Send the message to the backend*/
        m_tInterfaceBuffer.push("D");
    }
    else
        ui->SettingsFeedbackLabel->setText("Can't clean the profile! -> Make login first");
}

/**
 * @brief Update the profile Callback
 * @details This function will send a message to the backend to update the profile
 */
void Widget::on_UpdateProfileButton_clicked()
{
    /**< Check if all fields are filled*/
    if ((ui->UserEmaiLineEdit->text().size() == 0) || (ui->DoctorEmailLineEdit->text().size() == 0) || (ui->NameLineEdit->text().size() == 0))
    {
        ui->SettingsFeedbackLabel->setText("Error: Fill all the fields!");
        return;
    }
    /** Parse all contents*/
    ui->SettingsFeedbackLabel->setText("Profile updated!");
    std::string content;
    std::string name(ui->NameLineEdit->text().toStdString());
    std::string userEmail(ui->UserEmaiLineEdit->text().toStdString());
    std::string doctorEmail(ui->DoctorEmailLineEdit->text().toStdString());
    std::replace(name.begin(), name.end(), ' ', '_');
    std::string sex;
    if(ui->MasculineRadioButton->isChecked())
        sex = "0";
    else
        sex = "1";
    std::string height(std::to_string(ui->HeightSpinBox->value()));
    std::string wheight(std::to_string(ui->WeightSpinBox->value()));
    std::string age(std::to_string(ui->AgeSpinBox->value()));
    std::string activity_l(std::to_string(ui->ActivityLevelSpinBox->value()));
    /**< Create the message to be sent to the backend*/
    content =name + " " + sex + " " + age + " " + height + " " + wheight + " " + userEmail + " " + doctorEmail + " " + activity_l;
    /**< Send the message to the backend*/
    if(m_previousWidget == 0)
        m_tInterfaceBuffer.push("C " + content);
    else
        m_tInterfaceBuffer.push("U " + content);
    m_settingsFlowControl = false;
}

/**
 * @brief Settings Page Back Button Callback
 * @details If the user is logged in, the back button will return to the main menu, otherwise it will return to the login page  
 */
void Widget::on_SettingsPageBackButton_clicked()
{
    if((m_settingsFlowControl == true) || m_previousWidget == 0)
        m_tInterfaceBuffer.push("M");
    else
        ui->stackedWidget->setCurrentIndex(1);
}

/**
 * @brief Export Page Callbacks
 * @details Send to the backend the export method choosed
 */

void Widget::on_PersonalButton_clicked()
{
    ui->PersonalButton->setDisabled(true);
    ui->DoctorButton->setDisabled(true);
    ui->USBButton->setDisabled(true);
    ui->RunTestPageBackButton->setDisabled(true);
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("E U");
}


void Widget::on_DoctorButton_clicked()
{
    ui->PersonalButton->setDisabled(true);
    ui->DoctorButton->setDisabled(true);
    ui->USBButton->setDisabled(true);
    ui->RunTestPageBackButton->setDisabled(true);
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("E D");
}


void Widget::on_USBButton_clicked()
{
    ui->PersonalButton->setDisabled(true);
    ui->DoctorButton->setDisabled(true);
    ui->USBButton->setDisabled(true);
    ui->RunTestPageBackButton->setDisabled(true);
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("E X");
}

/**
 * @brief Run Test Page 
 * @details Send to the backend the test to be run
 */
void Widget::on_RunTestButton_clicked()
{
    ui->RunResulLabel->clear();
    ui->RunTestButton->setDisabled(true);
    /**< Send the message to the backend*/
    m_tInterfaceBuffer.push("R " + m_selectedTest);
}

/**
 * @brief Schedule Page 
 * @details Send to the backend the schedule to be added
 */
void Widget::on_AddScheduleButton_clicked()
{
    char aux0[3];
    char aux1[3];
    char aux2[3];
    /**< Parse all the contents*/
    sprintf(aux0,"%02d",ui->dateTimeEdit->date().month());
    sprintf(aux1,"%02d",ui->dateTimeEdit->date().day());
    sprintf(aux2,"%02d",ui->dateTimeEdit->time().hour());
    std::string content;
    std::string smonth(aux0);
    std::string sday(aux1);
    std::string shour(aux2);
    std::string testtype;
    if(ui->TempRadioButton->isChecked())
        testtype = "T ";
    else if(ui->HeartRadioButton->isChecked())
        testtype = "H ";
    else
        testtype = "O ";
    /**< Create the message to be sent to the backend*/
    content = "A " + testtype + smonth + sday + shour;
    /**< Send the message to the backend*/
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);
    m_tInterfaceBuffer.push(content);
    ui->ScheduleFeedbackLabel->setText("Alarm added!");
}

void Widget::on_WifiClockButton_clicked()
{
    char aux0[5];
    char aux1[3];
    char aux2[3];
    char aux3[3];
    char aux4[3];
    /**< Parse all the contents*/
    sprintf(aux0,"%04d",ui->dateTimeEdit_2->date().year());
    sprintf(aux1,"%02d",ui->dateTimeEdit_2->date().month());
    sprintf(aux2,"%02d",ui->dateTimeEdit_2->date().day());
    sprintf(aux3,"%02d",ui->dateTimeEdit_2->time().hour());
    sprintf(aux4,"%02d",ui->dateTimeEdit_2->time().minute());
    std::string content;
    std::string syear(aux0);
    std::string smonth(aux1);
    std::string sday(aux2);
    std::string shour(aux3);
    std::string sminute(aux4);
    std::string testtype;
    content = "W " + ui->WifiNameLineEdit->text().toStdString() + " " + ui->WifiPasswordLineEdit->text().toStdString() + " " + syear + smonth + sday + shour + sminute;
    m_tInterfaceBuffer.push(content);
    ui->WifiClockFeedbackLabel->setText("Updated!");
}


void Widget::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1 == 8)
    {
        usleep(500);
        ui->stackedWidget->setCurrentIndex(2);
    }
}

