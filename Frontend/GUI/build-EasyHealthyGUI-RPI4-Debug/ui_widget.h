/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *LoginPage;
    QPushButton *User1Button;
    QPushButton *User2Button;
    QPushButton *User3Button;
    QPushButton *User4Button;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *WifiButton;
    QWidget *MainMenuPage;
    QPushButton *ConsultButton;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *ScheduleButton;
    QPushButton *TestButton;
    QPushButton *ExportButton;
    QPushButton *SettingsButton;
    QPushButton *MainMenuPageBackButton;
    QWidget *SettingsPage;
    QQuickWidget *quickWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *ClearProfileButton;
    QPushButton *UpdateProfileButton;
    QPushButton *SettingsPageBackButton;
    QLineEdit *NameLineEdit;
    QLineEdit *UserEmaiLineEdit;
    QLineEdit *DoctorEmailLineEdit;
    QLabel *SettingsFeedbackLabel;
    QSpinBox *AgeSpinBox;
    QSpinBox *ActivityLevelSpinBox;
    QSpinBox *HeightSpinBox;
    QSpinBox *WeightSpinBox;
    QGroupBox *SexGroupBox;
    QRadioButton *MasculineRadioButton;
    QRadioButton *FeminineRadioButton;
    QLabel *label_16;
    QLabel *label_18;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QWidget *TestMenuPage;
    QPushButton *HeartBButton;
    QPushButton *TempButton;
    QPushButton *OxygenStButton;
    QPushButton *TestMenuPageBackButton;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *RunTestPage;
    QPushButton *RunTestPageBackButton;
    QPushButton *RunTestButton;
    QLabel *RunResulLabel;
    QLabel *RunTestInformationLabel;
    QLabel *RunTestImageLabel;
    QWidget *SchedulePage;
    QPushButton *SchedulePageBackButton;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *AddScheduleButton;
    QLabel *ScheduleFeedbackLabel;
    QLabel *label_29;
    QGroupBox *ScheduleTextgroupBox;
    QRadioButton *TempRadioButton;
    QRadioButton *HeartRadioButton;
    QRadioButton *OxygenRadioButton;
    QTableWidget *tableWidget_2;
    QWidget *ConsultMeasurementsPage;
    QPushButton *ConsultMeasurementsBackButton;
    QLabel *ConsultFeedbackLabel;
    QTableWidget *tableWidget;
    QWidget *ExportMenuPage;
    QPushButton *PersonalButton;
    QPushButton *ExportMenuPageBackButton;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *ExportResultLabel;
    QPushButton *USBButton;
    QPushButton *DoctorButton;
    QWidget *Dummy;
    QWidget *Logo;
    QPushButton *ResumeButton;
    QWidget *WifiClockPage;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLineEdit *WifiPasswordLineEdit;
    QLabel *WifiClockFeedbackLabel;
    QLabel *label_30;
    QLineEdit *WifiNameLineEdit;
    QLabel *label_32;
    QPushButton *WifiClockPageBackButton;
    QPushButton *WifiClockButton;
    QDateTimeEdit *dateTimeEdit_2;
    QLabel *label_33;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 480);
        Widget->setStyleSheet(QString::fromUtf8(""));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 480));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/back.png);"));
        LoginPage = new QWidget();
        LoginPage->setObjectName(QString::fromUtf8("LoginPage"));
        LoginPage->setContextMenuPolicy(Qt::DefaultContextMenu);
        User1Button = new QPushButton(LoginPage);
        User1Button->setObjectName(QString::fromUtf8("User1Button"));
        User1Button->setGeometry(QRect(70, 140, 160, 160));
        User1Button->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/pessoa.png);\n"
"border:2px solid #000000;\n"
"outline: none;"));
        User1Button->setFlat(false);
        User2Button = new QPushButton(LoginPage);
        User2Button->setObjectName(QString::fromUtf8("User2Button"));
        User2Button->setGeometry(QRect(240, 140, 160, 160));
        User2Button->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/pessoa.png);\n"
"border:2px solid #000000;\n"
"outline: none;"));
        User2Button->setFlat(false);
        User3Button = new QPushButton(LoginPage);
        User3Button->setObjectName(QString::fromUtf8("User3Button"));
        User3Button->setGeometry(QRect(410, 140, 160, 160));
        User3Button->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/pessoa.png);\n"
"border:2px solid #000000;\n"
"outline: none;"));
        User3Button->setFlat(false);
        User4Button = new QPushButton(LoginPage);
        User4Button->setObjectName(QString::fromUtf8("User4Button"));
        User4Button->setGeometry(QRect(580, 140, 160, 160));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        User4Button->setPalette(palette);
        User4Button->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/pessoa.png);\n"
"border:2px solid #000000;\n"
"outline: none;"));
        User4Button->setFlat(false);
        label_2 = new QLabel(LoginPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 300, 160, 60));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0, 0, 1, 1);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush1(gradient);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(0, 0, 1, 1);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush2(gradient1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        QLinearGradient gradient2(0, 0, 1, 1);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush3(gradient2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0, 0, 1, 1);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush4(gradient3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0, 0, 1, 1);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush5(gradient4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QLinearGradient gradient5(0, 0, 1, 1);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush6(gradient5);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient6(0, 0, 1, 1);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush7(gradient6);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient7(0, 0, 1, 1);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush8(gradient7);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QLinearGradient gradient8(0, 0, 1, 1);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush9(gradient8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_2->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSans"));
        font.setPointSize(14);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_2->setTextFormat(Qt::RichText);
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);
        label_2->setMargin(1);
        label_3 = new QLabel(LoginPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 300, 160, 60));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient9(0, 0, 1, 1);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush10(gradient9);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient10(0, 0, 1, 1);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush11(gradient10);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush11);
        QLinearGradient gradient11(0, 0, 1, 1);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush12(gradient11);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush12);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient12(0, 0, 1, 1);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush13(gradient12);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient13(0, 0, 1, 1);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush14(gradient13);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        QLinearGradient gradient14(0, 0, 1, 1);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush15(gradient14);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient15(0, 0, 1, 1);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush16(gradient15);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient16(0, 0, 1, 1);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush17(gradient16);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        QLinearGradient gradient17(0, 0, 1, 1);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush18(gradient17);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush18);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_3->setPalette(palette2);
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_3->setTextFormat(Qt::RichText);
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);
        label_3->setMargin(1);
        label_4 = new QLabel(LoginPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 300, 160, 60));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient18(0, 0, 1, 1);
        gradient18.setSpread(QGradient::PadSpread);
        gradient18.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient18.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush19(gradient18);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush19);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient19(0, 0, 1, 1);
        gradient19.setSpread(QGradient::PadSpread);
        gradient19.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient19.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush20(gradient19);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush20);
        QLinearGradient gradient20(0, 0, 1, 1);
        gradient20.setSpread(QGradient::PadSpread);
        gradient20.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient20.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush21(gradient20);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush21);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient21(0, 0, 1, 1);
        gradient21.setSpread(QGradient::PadSpread);
        gradient21.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient21.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush22(gradient21);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush22);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient22(0, 0, 1, 1);
        gradient22.setSpread(QGradient::PadSpread);
        gradient22.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient22.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush23(gradient22);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush23);
        QLinearGradient gradient23(0, 0, 1, 1);
        gradient23.setSpread(QGradient::PadSpread);
        gradient23.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient23.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush24(gradient23);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush24);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient24(0, 0, 1, 1);
        gradient24.setSpread(QGradient::PadSpread);
        gradient24.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient24.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush25(gradient24);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush25);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient25(0, 0, 1, 1);
        gradient25.setSpread(QGradient::PadSpread);
        gradient25.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient25.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush26(gradient25);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush26);
        QLinearGradient gradient26(0, 0, 1, 1);
        gradient26.setSpread(QGradient::PadSpread);
        gradient26.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient26.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush27(gradient26);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush27);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_4->setPalette(palette3);
        label_4->setFont(font);
        label_4->setAutoFillBackground(false);
        label_4->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_4->setTextFormat(Qt::RichText);
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(false);
        label_4->setMargin(1);
        label_5 = new QLabel(LoginPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(580, 300, 160, 60));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient27(0, 0, 1, 1);
        gradient27.setSpread(QGradient::PadSpread);
        gradient27.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient27.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush28(gradient27);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush28);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient28(0, 0, 1, 1);
        gradient28.setSpread(QGradient::PadSpread);
        gradient28.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient28.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush29(gradient28);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush29);
        QLinearGradient gradient29(0, 0, 1, 1);
        gradient29.setSpread(QGradient::PadSpread);
        gradient29.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient29.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush30(gradient29);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush30);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient30(0, 0, 1, 1);
        gradient30.setSpread(QGradient::PadSpread);
        gradient30.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient30.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush31(gradient30);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush31);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient31(0, 0, 1, 1);
        gradient31.setSpread(QGradient::PadSpread);
        gradient31.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient31.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush32(gradient31);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush32);
        QLinearGradient gradient32(0, 0, 1, 1);
        gradient32.setSpread(QGradient::PadSpread);
        gradient32.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient32.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush33(gradient32);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush33);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient33(0, 0, 1, 1);
        gradient33.setSpread(QGradient::PadSpread);
        gradient33.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient33.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush34(gradient33);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush34);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient34(0, 0, 1, 1);
        gradient34.setSpread(QGradient::PadSpread);
        gradient34.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient34.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush35(gradient34);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush35);
        QLinearGradient gradient35(0, 0, 1, 1);
        gradient35.setSpread(QGradient::PadSpread);
        gradient35.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient35.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush36(gradient35);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush36);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_5->setPalette(palette4);
        label_5->setFont(font);
        label_5->setAutoFillBackground(false);
        label_5->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_5->setTextFormat(Qt::RichText);
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(false);
        label_5->setMargin(1);
        WifiButton = new QPushButton(LoginPage);
        WifiButton->setObjectName(QString::fromUtf8("WifiButton"));
        WifiButton->setGeometry(QRect(12, 12, 58, 58));
        WifiButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/mechanical-gears-.png);\n"
"border: none;\n"
"outline: none;\n"
""));
        WifiButton->setFlat(true);
        stackedWidget->addWidget(LoginPage);
        MainMenuPage = new QWidget();
        MainMenuPage->setObjectName(QString::fromUtf8("MainMenuPage"));
        ConsultButton = new QPushButton(MainMenuPage);
        ConsultButton->setObjectName(QString::fromUtf8("ConsultButton"));
        ConsultButton->setGeometry(QRect(200, 250, 175, 175));
        ConsultButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/analise-de-dados.png);\n"
"border:2px solid #000000;\n"
"outline: none;\n"
""));
        ConsultButton->setFlat(false);
        label_8 = new QLabel(MainMenuPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 210, 175, 40));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient36(0, 0, 1, 1);
        gradient36.setSpread(QGradient::PadSpread);
        gradient36.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient36.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush37(gradient36);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush37);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient37(0, 0, 1, 1);
        gradient37.setSpread(QGradient::PadSpread);
        gradient37.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient37.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush38(gradient37);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush38);
        QLinearGradient gradient38(0, 0, 1, 1);
        gradient38.setSpread(QGradient::PadSpread);
        gradient38.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient38.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush39(gradient38);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush39);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient39(0, 0, 1, 1);
        gradient39.setSpread(QGradient::PadSpread);
        gradient39.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient39.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush40(gradient39);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush40);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient40(0, 0, 1, 1);
        gradient40.setSpread(QGradient::PadSpread);
        gradient40.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient40.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush41(gradient40);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush41);
        QLinearGradient gradient41(0, 0, 1, 1);
        gradient41.setSpread(QGradient::PadSpread);
        gradient41.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient41.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush42(gradient41);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush42);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient42(0, 0, 1, 1);
        gradient42.setSpread(QGradient::PadSpread);
        gradient42.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient42.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush43(gradient42);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient43(0, 0, 1, 1);
        gradient43.setSpread(QGradient::PadSpread);
        gradient43.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient43.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush44(gradient43);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush44);
        QLinearGradient gradient44(0, 0, 1, 1);
        gradient44.setSpread(QGradient::PadSpread);
        gradient44.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient44.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush45(gradient44);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush45);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_8->setPalette(palette5);
        label_8->setFont(font);
        label_8->setAutoFillBackground(false);
        label_8->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_8->setTextFormat(Qt::RichText);
        label_8->setScaledContents(true);
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(false);
        label_8->setMargin(1);
        label_9 = new QLabel(MainMenuPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 410, 175, 60));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient45(0, 0, 1, 1);
        gradient45.setSpread(QGradient::PadSpread);
        gradient45.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient45.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush46(gradient45);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush46);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient46(0, 0, 1, 1);
        gradient46.setSpread(QGradient::PadSpread);
        gradient46.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient46.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush47(gradient46);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush47);
        QLinearGradient gradient47(0, 0, 1, 1);
        gradient47.setSpread(QGradient::PadSpread);
        gradient47.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient47.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush48(gradient47);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush48);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient48(0, 0, 1, 1);
        gradient48.setSpread(QGradient::PadSpread);
        gradient48.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient48.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush49(gradient48);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush49);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient49(0, 0, 1, 1);
        gradient49.setSpread(QGradient::PadSpread);
        gradient49.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient49.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush50(gradient49);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush50);
        QLinearGradient gradient50(0, 0, 1, 1);
        gradient50.setSpread(QGradient::PadSpread);
        gradient50.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient50.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush51(gradient50);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush51);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient51(0, 0, 1, 1);
        gradient51.setSpread(QGradient::PadSpread);
        gradient51.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient51.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush52(gradient51);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush52);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient52(0, 0, 1, 1);
        gradient52.setSpread(QGradient::PadSpread);
        gradient52.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient52.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush53(gradient52);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush53);
        QLinearGradient gradient53(0, 0, 1, 1);
        gradient53.setSpread(QGradient::PadSpread);
        gradient53.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient53.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush54(gradient53);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush54);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_9->setPalette(palette6);
        label_9->setFont(font);
        label_9->setAutoFillBackground(false);
        label_9->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_9->setTextFormat(Qt::RichText);
        label_9->setScaledContents(true);
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setWordWrap(false);
        label_9->setMargin(1);
        label_7 = new QLabel(MainMenuPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(425, 410, 175, 60));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient54(0, 0, 1, 1);
        gradient54.setSpread(QGradient::PadSpread);
        gradient54.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient54.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush55(gradient54);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush55);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient55(0, 0, 1, 1);
        gradient55.setSpread(QGradient::PadSpread);
        gradient55.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient55.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush56(gradient55);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush56);
        QLinearGradient gradient56(0, 0, 1, 1);
        gradient56.setSpread(QGradient::PadSpread);
        gradient56.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient56.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush57(gradient56);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush57);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient57(0, 0, 1, 1);
        gradient57.setSpread(QGradient::PadSpread);
        gradient57.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient57.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush58(gradient57);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush58);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient58(0, 0, 1, 1);
        gradient58.setSpread(QGradient::PadSpread);
        gradient58.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient58.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush59(gradient58);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush59);
        QLinearGradient gradient59(0, 0, 1, 1);
        gradient59.setSpread(QGradient::PadSpread);
        gradient59.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient59.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush60(gradient59);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush60);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient60(0, 0, 1, 1);
        gradient60.setSpread(QGradient::PadSpread);
        gradient60.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient60.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush61(gradient60);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush61);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient61(0, 0, 1, 1);
        gradient61.setSpread(QGradient::PadSpread);
        gradient61.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient61.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush62(gradient61);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush62);
        QLinearGradient gradient62(0, 0, 1, 1);
        gradient62.setSpread(QGradient::PadSpread);
        gradient62.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient62.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush63(gradient62);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush63);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_7->setPalette(palette7);
        label_7->setFont(font);
        label_7->setAutoFillBackground(false);
        label_7->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_7->setTextFormat(Qt::RichText);
        label_7->setScaledContents(true);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(false);
        label_7->setMargin(1);
        label_6 = new QLabel(MainMenuPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(425, 210, 175, 40));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient63(0, 0, 1, 1);
        gradient63.setSpread(QGradient::PadSpread);
        gradient63.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient63.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush64(gradient63);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush64);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient64(0, 0, 1, 1);
        gradient64.setSpread(QGradient::PadSpread);
        gradient64.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient64.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush65(gradient64);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush65);
        QLinearGradient gradient65(0, 0, 1, 1);
        gradient65.setSpread(QGradient::PadSpread);
        gradient65.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient65.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush66(gradient65);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush66);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient66(0, 0, 1, 1);
        gradient66.setSpread(QGradient::PadSpread);
        gradient66.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient66.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush67(gradient66);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush67);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient67(0, 0, 1, 1);
        gradient67.setSpread(QGradient::PadSpread);
        gradient67.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient67.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush68(gradient67);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush68);
        QLinearGradient gradient68(0, 0, 1, 1);
        gradient68.setSpread(QGradient::PadSpread);
        gradient68.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient68.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush69(gradient68);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush69);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient69(0, 0, 1, 1);
        gradient69.setSpread(QGradient::PadSpread);
        gradient69.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient69.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush70(gradient69);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush70);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient70(0, 0, 1, 1);
        gradient70.setSpread(QGradient::PadSpread);
        gradient70.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient70.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush71(gradient70);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush71);
        QLinearGradient gradient71(0, 0, 1, 1);
        gradient71.setSpread(QGradient::PadSpread);
        gradient71.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient71.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush72(gradient71);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush72);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_6->setPalette(palette8);
        label_6->setFont(font);
        label_6->setAutoFillBackground(false);
        label_6->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_6->setTextFormat(Qt::RichText);
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(false);
        label_6->setMargin(1);
        label_10 = new QLabel(MainMenuPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(200, 440, 175, 60));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient72(0, 0, 1, 1);
        gradient72.setSpread(QGradient::PadSpread);
        gradient72.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient72.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush73(gradient72);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush73);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient73(0, 0, 1, 1);
        gradient73.setSpread(QGradient::PadSpread);
        gradient73.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient73.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush74(gradient73);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush74);
        QLinearGradient gradient74(0, 0, 1, 1);
        gradient74.setSpread(QGradient::PadSpread);
        gradient74.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient74.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush75(gradient74);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush75);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient75(0, 0, 1, 1);
        gradient75.setSpread(QGradient::PadSpread);
        gradient75.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient75.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush76(gradient75);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush76);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient76(0, 0, 1, 1);
        gradient76.setSpread(QGradient::PadSpread);
        gradient76.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient76.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush77(gradient76);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush77);
        QLinearGradient gradient77(0, 0, 1, 1);
        gradient77.setSpread(QGradient::PadSpread);
        gradient77.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient77.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush78(gradient77);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush78);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient78(0, 0, 1, 1);
        gradient78.setSpread(QGradient::PadSpread);
        gradient78.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient78.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush79(gradient78);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush79);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient79(0, 0, 1, 1);
        gradient79.setSpread(QGradient::PadSpread);
        gradient79.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient79.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush80(gradient79);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush80);
        QLinearGradient gradient80(0, 0, 1, 1);
        gradient80.setSpread(QGradient::PadSpread);
        gradient80.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient80.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush81(gradient80);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush81);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_10->setPalette(palette9);
        label_10->setFont(font);
        label_10->setAutoFillBackground(false);
        label_10->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_10->setTextFormat(Qt::RichText);
        label_10->setScaledContents(true);
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setWordWrap(false);
        label_10->setMargin(1);
        label_11 = new QLabel(MainMenuPage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(425, 440, 175, 60));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient81(0, 0, 1, 1);
        gradient81.setSpread(QGradient::PadSpread);
        gradient81.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient81.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush82(gradient81);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush82);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient82(0, 0, 1, 1);
        gradient82.setSpread(QGradient::PadSpread);
        gradient82.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient82.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush83(gradient82);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush83);
        QLinearGradient gradient83(0, 0, 1, 1);
        gradient83.setSpread(QGradient::PadSpread);
        gradient83.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient83.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush84(gradient83);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush84);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient84(0, 0, 1, 1);
        gradient84.setSpread(QGradient::PadSpread);
        gradient84.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient84.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush85(gradient84);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush85);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient85(0, 0, 1, 1);
        gradient85.setSpread(QGradient::PadSpread);
        gradient85.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient85.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush86(gradient85);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush86);
        QLinearGradient gradient86(0, 0, 1, 1);
        gradient86.setSpread(QGradient::PadSpread);
        gradient86.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient86.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush87(gradient86);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush87);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient87(0, 0, 1, 1);
        gradient87.setSpread(QGradient::PadSpread);
        gradient87.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient87.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush88(gradient87);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush88);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient88(0, 0, 1, 1);
        gradient88.setSpread(QGradient::PadSpread);
        gradient88.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient88.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush89(gradient88);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush89);
        QLinearGradient gradient89(0, 0, 1, 1);
        gradient89.setSpread(QGradient::PadSpread);
        gradient89.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient89.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush90(gradient89);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush90);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_11->setPalette(palette10);
        label_11->setFont(font);
        label_11->setAutoFillBackground(false);
        label_11->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_11->setTextFormat(Qt::RichText);
        label_11->setScaledContents(true);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setWordWrap(false);
        label_11->setMargin(1);
        ScheduleButton = new QPushButton(MainMenuPage);
        ScheduleButton->setObjectName(QString::fromUtf8("ScheduleButton"));
        ScheduleButton->setGeometry(QRect(425, 30, 175, 175));
        ScheduleButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/agenda.png);\n"
"border:2px solid #000000;\n"
"outline: none;"));
        ScheduleButton->setFlat(false);
        TestButton = new QPushButton(MainMenuPage);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));
        TestButton->setGeometry(QRect(200, 30, 175, 175));
        TestButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/vacina.png);\n"
"border:2px solid #000000;\n"
"outline: none;"));
        TestButton->setIconSize(QSize(16, 16));
        TestButton->setFlat(false);
        ExportButton = new QPushButton(MainMenuPage);
        ExportButton->setObjectName(QString::fromUtf8("ExportButton"));
        ExportButton->setGeometry(QRect(425, 250, 175, 175));
        ExportButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/exportar.png);\n"
"border:2px solid #000000;\n"
"outline: none;\n"
""));
        ExportButton->setFlat(false);
        SettingsButton = new QPushButton(MainMenuPage);
        SettingsButton->setObjectName(QString::fromUtf8("SettingsButton"));
        SettingsButton->setGeometry(QRect(12, 12, 58, 58));
        SettingsButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/mechanical-gears-.png);\n"
"border: none;\n"
"outline: none;\n"
""));
        SettingsButton->setFlat(true);
        MainMenuPageBackButton = new QPushButton(MainMenuPage);
        MainMenuPageBackButton->setObjectName(QString::fromUtf8("MainMenuPageBackButton"));
        MainMenuPageBackButton->setGeometry(QRect(732, 12, 58, 58));
        MainMenuPageBackButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/return.png);\n"
"border: none;\n"
"outline: none;"));
        MainMenuPageBackButton->setFlat(true);
        stackedWidget->addWidget(MainMenuPage);
        SettingsPage = new QWidget();
        SettingsPage->setObjectName(QString::fromUtf8("SettingsPage"));
        SettingsPage->setFocusPolicy(Qt::NoFocus);
        SettingsPage->setContextMenuPolicy(Qt::DefaultContextMenu);
        SettingsPage->setAcceptDrops(false);
        quickWidget = new QQuickWidget(SettingsPage);
        quickWidget->setObjectName(QString::fromUtf8("quickWidget"));
        quickWidget->setGeometry(QRect(0, 250, 800, 260));
        quickWidget->setMouseTracking(true);
        quickWidget->setTabletTracking(true);
        quickWidget->setFocusPolicy(Qt::NoFocus);
        quickWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        quickWidget->setAutoFillBackground(false);
        quickWidget->setStyleSheet(QString::fromUtf8(""));
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
        scrollArea = new QScrollArea(SettingsPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 800, 480));
        scrollArea->setTabletTracking(true);
        scrollArea->setFocusPolicy(Qt::ClickFocus);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignBottom|Qt::AlignJustify);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 800, 480));
        ClearProfileButton = new QPushButton(scrollAreaWidgetContents);
        ClearProfileButton->setObjectName(QString::fromUtf8("ClearProfileButton"));
        ClearProfileButton->setGeometry(QRect(20, 20, 141, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("FreeSans"));
        font1.setBold(true);
        ClearProfileButton->setFont(font1);
        ClearProfileButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(134, 132, 130);\n"
"border:2px solid #1e1b18;\n"
"color: #FFFFFF;\n"
"outline: none;"));
        ClearProfileButton->setIconSize(QSize(16, 16));
        ClearProfileButton->setFlat(false);
        UpdateProfileButton = new QPushButton(scrollAreaWidgetContents);
        UpdateProfileButton->setObjectName(QString::fromUtf8("UpdateProfileButton"));
        UpdateProfileButton->setGeometry(QRect(180, 20, 141, 41));
        UpdateProfileButton->setFont(font1);
        UpdateProfileButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(134, 132, 130);\n"
"border:2px solid #1e1b18;\n"
"color: #FFFFFF;\n"
"outline: none;"));
        UpdateProfileButton->setIconSize(QSize(16, 16));
        UpdateProfileButton->setFlat(false);
        SettingsPageBackButton = new QPushButton(scrollAreaWidgetContents);
        SettingsPageBackButton->setObjectName(QString::fromUtf8("SettingsPageBackButton"));
        SettingsPageBackButton->setGeometry(QRect(732, 12, 58, 58));
        SettingsPageBackButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/return.png);\n"
"border: none;\n"
"outline: none;"));
        SettingsPageBackButton->setFlat(true);
        NameLineEdit = new QLineEdit(scrollAreaWidgetContents);
        NameLineEdit->setObjectName(QString::fromUtf8("NameLineEdit"));
        NameLineEdit->setGeometry(QRect(30, 110, 371, 31));
        NameLineEdit->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(255, 255, 255);\n"
"outline: none;"));
        NameLineEdit->setInputMethodHints(Qt::ImhEmailCharactersOnly);
        UserEmaiLineEdit = new QLineEdit(scrollAreaWidgetContents);
        UserEmaiLineEdit->setObjectName(QString::fromUtf8("UserEmaiLineEdit"));
        UserEmaiLineEdit->setGeometry(QRect(30, 170, 371, 31));
        UserEmaiLineEdit->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(255, 255, 255);\n"
"outline: none;"));
        UserEmaiLineEdit->setInputMethodHints(Qt::ImhEmailCharactersOnly);
        DoctorEmailLineEdit = new QLineEdit(scrollAreaWidgetContents);
        DoctorEmailLineEdit->setObjectName(QString::fromUtf8("DoctorEmailLineEdit"));
        DoctorEmailLineEdit->setGeometry(QRect(30, 230, 371, 31));
        DoctorEmailLineEdit->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(255, 255, 255);\n"
"outline: none;"));
        DoctorEmailLineEdit->setInputMethodHints(Qt::ImhEmailCharactersOnly);
        SettingsFeedbackLabel = new QLabel(scrollAreaWidgetContents);
        SettingsFeedbackLabel->setObjectName(QString::fromUtf8("SettingsFeedbackLabel"));
        SettingsFeedbackLabel->setGeometry(QRect(0, 430, 800, 51));
        SettingsFeedbackLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 50, 47);\n"
"color: #FFFFFF;"));
        SettingsFeedbackLabel->setAlignment(Qt::AlignCenter);
        AgeSpinBox = new QSpinBox(scrollAreaWidgetContents);
        AgeSpinBox->setObjectName(QString::fromUtf8("AgeSpinBox"));
        AgeSpinBox->setGeometry(QRect(490, 230, 70, 31));
        AgeSpinBox->setStyleSheet(QString::fromUtf8("outline: none;"));
        AgeSpinBox->setAlignment(Qt::AlignCenter);
        AgeSpinBox->setMinimum(1);
        AgeSpinBox->setMaximum(200);
        ActivityLevelSpinBox = new QSpinBox(scrollAreaWidgetContents);
        ActivityLevelSpinBox->setObjectName(QString::fromUtf8("ActivityLevelSpinBox"));
        ActivityLevelSpinBox->setGeometry(QRect(640, 230, 70, 31));
        ActivityLevelSpinBox->setStyleSheet(QString::fromUtf8("outline: none;"));
        ActivityLevelSpinBox->setAlignment(Qt::AlignCenter);
        ActivityLevelSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        ActivityLevelSpinBox->setMinimum(1);
        ActivityLevelSpinBox->setMaximum(5);
        ActivityLevelSpinBox->setValue(1);
        HeightSpinBox = new QSpinBox(scrollAreaWidgetContents);
        HeightSpinBox->setObjectName(QString::fromUtf8("HeightSpinBox"));
        HeightSpinBox->setGeometry(QRect(490, 170, 70, 31));
        HeightSpinBox->setStyleSheet(QString::fromUtf8("outline: none;"));
        HeightSpinBox->setAlignment(Qt::AlignCenter);
        HeightSpinBox->setMinimum(1);
        HeightSpinBox->setMaximum(250);
        WeightSpinBox = new QSpinBox(scrollAreaWidgetContents);
        WeightSpinBox->setObjectName(QString::fromUtf8("WeightSpinBox"));
        WeightSpinBox->setGeometry(QRect(640, 170, 70, 31));
        WeightSpinBox->setStyleSheet(QString::fromUtf8("outline: none;"));
        WeightSpinBox->setAlignment(Qt::AlignCenter);
        WeightSpinBox->setMinimum(1);
        WeightSpinBox->setMaximum(230);
        SexGroupBox = new QGroupBox(scrollAreaWidgetContents);
        SexGroupBox->setObjectName(QString::fromUtf8("SexGroupBox"));
        SexGroupBox->setGeometry(QRect(490, 110, 221, 31));
        SexGroupBox->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);\n"
"outline: none;"));
        SexGroupBox->setFlat(true);
        SexGroupBox->setCheckable(false);
        MasculineRadioButton = new QRadioButton(SexGroupBox);
        MasculineRadioButton->setObjectName(QString::fromUtf8("MasculineRadioButton"));
        MasculineRadioButton->setGeometry(QRect(20, 7, 51, 23));
        MasculineRadioButton->setStyleSheet(QString::fromUtf8("outline: none;"));
        MasculineRadioButton->setChecked(true);
        FeminineRadioButton = new QRadioButton(SexGroupBox);
        FeminineRadioButton->setObjectName(QString::fromUtf8("FeminineRadioButton"));
        FeminineRadioButton->setGeometry(QRect(170, 7, 41, 23));
        FeminineRadioButton->setStyleSheet(QString::fromUtf8("outline: none;"));
        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(30, 90, 201, 21));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient90(0, 0, 1, 1);
        gradient90.setSpread(QGradient::PadSpread);
        gradient90.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient90.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush91(gradient90);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush91);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient91(0, 0, 1, 1);
        gradient91.setSpread(QGradient::PadSpread);
        gradient91.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient91.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush92(gradient91);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush92);
        QLinearGradient gradient92(0, 0, 1, 1);
        gradient92.setSpread(QGradient::PadSpread);
        gradient92.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient92.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush93(gradient92);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush93);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient93(0, 0, 1, 1);
        gradient93.setSpread(QGradient::PadSpread);
        gradient93.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient93.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush94(gradient93);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush94);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient94(0, 0, 1, 1);
        gradient94.setSpread(QGradient::PadSpread);
        gradient94.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient94.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush95(gradient94);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush95);
        QLinearGradient gradient95(0, 0, 1, 1);
        gradient95.setSpread(QGradient::PadSpread);
        gradient95.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient95.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush96(gradient95);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush96);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient96(0, 0, 1, 1);
        gradient96.setSpread(QGradient::PadSpread);
        gradient96.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient96.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush97(gradient96);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush97);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient97(0, 0, 1, 1);
        gradient97.setSpread(QGradient::PadSpread);
        gradient97.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient97.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush98(gradient97);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush98);
        QLinearGradient gradient98(0, 0, 1, 1);
        gradient98.setSpread(QGradient::PadSpread);
        gradient98.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient98.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush99(gradient98);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush99);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_16->setPalette(palette11);
        QFont font2;
        font2.setFamily(QString::fromUtf8("FreeSans"));
        font2.setPointSize(12);
        font2.setBold(true);
        label_16->setFont(font2);
        label_16->setAutoFillBackground(false);
        label_16->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_16->setTextFormat(Qt::RichText);
        label_16->setScaledContents(true);
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_16->setWordWrap(false);
        label_16->setMargin(1);
        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 150, 281, 21));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient99(0, 0, 1, 1);
        gradient99.setSpread(QGradient::PadSpread);
        gradient99.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient99.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush100(gradient99);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush100);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient100(0, 0, 1, 1);
        gradient100.setSpread(QGradient::PadSpread);
        gradient100.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient100.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush101(gradient100);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush101);
        QLinearGradient gradient101(0, 0, 1, 1);
        gradient101.setSpread(QGradient::PadSpread);
        gradient101.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient101.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush102(gradient101);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush102);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient102(0, 0, 1, 1);
        gradient102.setSpread(QGradient::PadSpread);
        gradient102.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient102.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush103(gradient102);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush103);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient103(0, 0, 1, 1);
        gradient103.setSpread(QGradient::PadSpread);
        gradient103.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient103.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush104(gradient103);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush104);
        QLinearGradient gradient104(0, 0, 1, 1);
        gradient104.setSpread(QGradient::PadSpread);
        gradient104.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient104.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush105(gradient104);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush105);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient105(0, 0, 1, 1);
        gradient105.setSpread(QGradient::PadSpread);
        gradient105.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient105.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush106(gradient105);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush106);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient106(0, 0, 1, 1);
        gradient106.setSpread(QGradient::PadSpread);
        gradient106.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient106.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush107(gradient106);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush107);
        QLinearGradient gradient107(0, 0, 1, 1);
        gradient107.setSpread(QGradient::PadSpread);
        gradient107.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient107.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush108(gradient107);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush108);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_18->setPalette(palette12);
        label_18->setFont(font2);
        label_18->setAutoFillBackground(false);
        label_18->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_18->setTextFormat(Qt::RichText);
        label_18->setScaledContents(true);
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_18->setWordWrap(false);
        label_18->setMargin(1);
        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(30, 210, 291, 21));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient108(0, 0, 1, 1);
        gradient108.setSpread(QGradient::PadSpread);
        gradient108.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient108.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush109(gradient108);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush109);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient109(0, 0, 1, 1);
        gradient109.setSpread(QGradient::PadSpread);
        gradient109.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient109.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush110(gradient109);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush110);
        QLinearGradient gradient110(0, 0, 1, 1);
        gradient110.setSpread(QGradient::PadSpread);
        gradient110.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient110.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush111(gradient110);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush111);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient111(0, 0, 1, 1);
        gradient111.setSpread(QGradient::PadSpread);
        gradient111.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient111.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush112(gradient111);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush112);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient112(0, 0, 1, 1);
        gradient112.setSpread(QGradient::PadSpread);
        gradient112.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient112.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush113(gradient112);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush113);
        QLinearGradient gradient113(0, 0, 1, 1);
        gradient113.setSpread(QGradient::PadSpread);
        gradient113.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient113.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush114(gradient113);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush114);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient114(0, 0, 1, 1);
        gradient114.setSpread(QGradient::PadSpread);
        gradient114.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient114.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush115(gradient114);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush115);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient115(0, 0, 1, 1);
        gradient115.setSpread(QGradient::PadSpread);
        gradient115.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient115.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush116(gradient115);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush116);
        QLinearGradient gradient116(0, 0, 1, 1);
        gradient116.setSpread(QGradient::PadSpread);
        gradient116.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient116.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush117(gradient116);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush117);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_23->setPalette(palette13);
        label_23->setFont(font2);
        label_23->setAutoFillBackground(false);
        label_23->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_23->setTextFormat(Qt::RichText);
        label_23->setScaledContents(true);
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_23->setWordWrap(false);
        label_23->setMargin(1);
        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(490, 90, 151, 21));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient117(0, 0, 1, 1);
        gradient117.setSpread(QGradient::PadSpread);
        gradient117.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient117.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush118(gradient117);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush118);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient118(0, 0, 1, 1);
        gradient118.setSpread(QGradient::PadSpread);
        gradient118.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient118.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush119(gradient118);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush119);
        QLinearGradient gradient119(0, 0, 1, 1);
        gradient119.setSpread(QGradient::PadSpread);
        gradient119.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient119.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush120(gradient119);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush120);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient120(0, 0, 1, 1);
        gradient120.setSpread(QGradient::PadSpread);
        gradient120.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient120.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush121(gradient120);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush121);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient121(0, 0, 1, 1);
        gradient121.setSpread(QGradient::PadSpread);
        gradient121.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient121.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush122(gradient121);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush122);
        QLinearGradient gradient122(0, 0, 1, 1);
        gradient122.setSpread(QGradient::PadSpread);
        gradient122.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient122.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush123(gradient122);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush123);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient123(0, 0, 1, 1);
        gradient123.setSpread(QGradient::PadSpread);
        gradient123.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient123.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush124(gradient123);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush124);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient124(0, 0, 1, 1);
        gradient124.setSpread(QGradient::PadSpread);
        gradient124.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient124.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush125(gradient124);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush125);
        QLinearGradient gradient125(0, 0, 1, 1);
        gradient125.setSpread(QGradient::PadSpread);
        gradient125.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient125.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush126(gradient125);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush126);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_24->setPalette(palette14);
        label_24->setFont(font2);
        label_24->setAutoFillBackground(false);
        label_24->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_24->setTextFormat(Qt::RichText);
        label_24->setScaledContents(true);
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_24->setWordWrap(false);
        label_24->setMargin(1);
        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(490, 150, 101, 21));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient126(0, 0, 1, 1);
        gradient126.setSpread(QGradient::PadSpread);
        gradient126.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient126.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush127(gradient126);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush127);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient127(0, 0, 1, 1);
        gradient127.setSpread(QGradient::PadSpread);
        gradient127.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient127.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush128(gradient127);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush128);
        QLinearGradient gradient128(0, 0, 1, 1);
        gradient128.setSpread(QGradient::PadSpread);
        gradient128.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient128.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush129(gradient128);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush129);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient129(0, 0, 1, 1);
        gradient129.setSpread(QGradient::PadSpread);
        gradient129.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient129.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush130(gradient129);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush130);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient130(0, 0, 1, 1);
        gradient130.setSpread(QGradient::PadSpread);
        gradient130.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient130.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush131(gradient130);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush131);
        QLinearGradient gradient131(0, 0, 1, 1);
        gradient131.setSpread(QGradient::PadSpread);
        gradient131.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient131.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush132(gradient131);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush132);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient132(0, 0, 1, 1);
        gradient132.setSpread(QGradient::PadSpread);
        gradient132.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient132.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush133(gradient132);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush133);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient133(0, 0, 1, 1);
        gradient133.setSpread(QGradient::PadSpread);
        gradient133.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient133.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush134(gradient133);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush134);
        QLinearGradient gradient134(0, 0, 1, 1);
        gradient134.setSpread(QGradient::PadSpread);
        gradient134.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient134.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush135(gradient134);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush135);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_25->setPalette(palette15);
        label_25->setFont(font2);
        label_25->setAutoFillBackground(false);
        label_25->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_25->setTextFormat(Qt::RichText);
        label_25->setScaledContents(true);
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_25->setWordWrap(false);
        label_25->setMargin(1);
        label_26 = new QLabel(scrollAreaWidgetContents);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(640, 150, 121, 21));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient135(0, 0, 1, 1);
        gradient135.setSpread(QGradient::PadSpread);
        gradient135.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient135.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush136(gradient135);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush136);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient136(0, 0, 1, 1);
        gradient136.setSpread(QGradient::PadSpread);
        gradient136.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient136.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush137(gradient136);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush137);
        QLinearGradient gradient137(0, 0, 1, 1);
        gradient137.setSpread(QGradient::PadSpread);
        gradient137.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient137.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush138(gradient137);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush138);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient138(0, 0, 1, 1);
        gradient138.setSpread(QGradient::PadSpread);
        gradient138.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient138.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush139(gradient138);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush139);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient139(0, 0, 1, 1);
        gradient139.setSpread(QGradient::PadSpread);
        gradient139.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient139.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush140(gradient139);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush140);
        QLinearGradient gradient140(0, 0, 1, 1);
        gradient140.setSpread(QGradient::PadSpread);
        gradient140.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient140.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush141(gradient140);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush141);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient141(0, 0, 1, 1);
        gradient141.setSpread(QGradient::PadSpread);
        gradient141.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient141.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush142(gradient141);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush142);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient142(0, 0, 1, 1);
        gradient142.setSpread(QGradient::PadSpread);
        gradient142.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient142.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush143(gradient142);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush143);
        QLinearGradient gradient143(0, 0, 1, 1);
        gradient143.setSpread(QGradient::PadSpread);
        gradient143.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient143.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush144(gradient143);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush144);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_26->setPalette(palette16);
        label_26->setFont(font2);
        label_26->setAutoFillBackground(false);
        label_26->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_26->setTextFormat(Qt::RichText);
        label_26->setScaledContents(true);
        label_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_26->setWordWrap(false);
        label_26->setMargin(1);
        label_27 = new QLabel(scrollAreaWidgetContents);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(490, 210, 111, 21));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient144(0, 0, 1, 1);
        gradient144.setSpread(QGradient::PadSpread);
        gradient144.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient144.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush145(gradient144);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush145);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient145(0, 0, 1, 1);
        gradient145.setSpread(QGradient::PadSpread);
        gradient145.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient145.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush146(gradient145);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush146);
        QLinearGradient gradient146(0, 0, 1, 1);
        gradient146.setSpread(QGradient::PadSpread);
        gradient146.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient146.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush147(gradient146);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush147);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient147(0, 0, 1, 1);
        gradient147.setSpread(QGradient::PadSpread);
        gradient147.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient147.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush148(gradient147);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush148);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient148(0, 0, 1, 1);
        gradient148.setSpread(QGradient::PadSpread);
        gradient148.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient148.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush149(gradient148);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush149);
        QLinearGradient gradient149(0, 0, 1, 1);
        gradient149.setSpread(QGradient::PadSpread);
        gradient149.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient149.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush150(gradient149);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush150);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient150(0, 0, 1, 1);
        gradient150.setSpread(QGradient::PadSpread);
        gradient150.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient150.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush151(gradient150);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush151);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient151(0, 0, 1, 1);
        gradient151.setSpread(QGradient::PadSpread);
        gradient151.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient151.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush152(gradient151);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush152);
        QLinearGradient gradient152(0, 0, 1, 1);
        gradient152.setSpread(QGradient::PadSpread);
        gradient152.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient152.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush153(gradient152);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush153);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_27->setPalette(palette17);
        label_27->setFont(font2);
        label_27->setAutoFillBackground(false);
        label_27->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_27->setTextFormat(Qt::RichText);
        label_27->setScaledContents(true);
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_27->setWordWrap(false);
        label_27->setMargin(1);
        label_28 = new QLabel(scrollAreaWidgetContents);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(640, 210, 151, 21));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient153(0, 0, 1, 1);
        gradient153.setSpread(QGradient::PadSpread);
        gradient153.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient153.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush154(gradient153);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush154);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient154(0, 0, 1, 1);
        gradient154.setSpread(QGradient::PadSpread);
        gradient154.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient154.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush155(gradient154);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush155);
        QLinearGradient gradient155(0, 0, 1, 1);
        gradient155.setSpread(QGradient::PadSpread);
        gradient155.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient155.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush156(gradient155);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush156);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient156(0, 0, 1, 1);
        gradient156.setSpread(QGradient::PadSpread);
        gradient156.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient156.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush157(gradient156);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush157);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient157(0, 0, 1, 1);
        gradient157.setSpread(QGradient::PadSpread);
        gradient157.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient157.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush158(gradient157);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush158);
        QLinearGradient gradient158(0, 0, 1, 1);
        gradient158.setSpread(QGradient::PadSpread);
        gradient158.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient158.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush159(gradient158);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush159);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient159(0, 0, 1, 1);
        gradient159.setSpread(QGradient::PadSpread);
        gradient159.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient159.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush160(gradient159);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush160);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient160(0, 0, 1, 1);
        gradient160.setSpread(QGradient::PadSpread);
        gradient160.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient160.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush161(gradient160);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush161);
        QLinearGradient gradient161(0, 0, 1, 1);
        gradient161.setSpread(QGradient::PadSpread);
        gradient161.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient161.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush162(gradient161);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush162);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_28->setPalette(palette18);
        label_28->setFont(font2);
        label_28->setAutoFillBackground(false);
        label_28->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_28->setTextFormat(Qt::RichText);
        label_28->setScaledContents(true);
        label_28->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_28->setWordWrap(false);
        label_28->setMargin(1);
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(SettingsPage);
        TestMenuPage = new QWidget();
        TestMenuPage->setObjectName(QString::fromUtf8("TestMenuPage"));
        HeartBButton = new QPushButton(TestMenuPage);
        HeartBButton->setObjectName(QString::fromUtf8("HeartBButton"));
        HeartBButton->setGeometry(QRect(312, 150, 175, 175));
        HeartBButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/batimento-cardiaco.png);\n"
"border:2px solid #000000;\n"
"outline: none;"));
        HeartBButton->setFlat(false);
        TempButton = new QPushButton(TestMenuPage);
        TempButton->setObjectName(QString::fromUtf8("TempButton"));
        TempButton->setGeometry(QRect(80, 150, 175, 175));
        TempButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/temperatura.png);\n"
"border:2px solid #000000;\n"
"outline: none;"));
        TempButton->setIconSize(QSize(16, 16));
        TempButton->setFlat(false);
        OxygenStButton = new QPushButton(TestMenuPage);
        OxygenStButton->setObjectName(QString::fromUtf8("OxygenStButton"));
        OxygenStButton->setGeometry(QRect(545, 150, 175, 175));
        OxygenStButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/oxygen.png);\n"
"border:2px solid #000000;\n"
"outline: none;\n"
"\n"
""));
        OxygenStButton->setFlat(false);
        TestMenuPageBackButton = new QPushButton(TestMenuPage);
        TestMenuPageBackButton->setObjectName(QString::fromUtf8("TestMenuPageBackButton"));
        TestMenuPageBackButton->setGeometry(QRect(732, 12, 58, 58));
        TestMenuPageBackButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/return.png);\n"
"border: none;\n"
"outline: none;"));
        TestMenuPageBackButton->setFlat(true);
        label_12 = new QLabel(TestMenuPage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(80, 330, 175, 40));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient162(0, 0, 1, 1);
        gradient162.setSpread(QGradient::PadSpread);
        gradient162.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient162.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush163(gradient162);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush163);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient163(0, 0, 1, 1);
        gradient163.setSpread(QGradient::PadSpread);
        gradient163.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient163.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush164(gradient163);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush164);
        QLinearGradient gradient164(0, 0, 1, 1);
        gradient164.setSpread(QGradient::PadSpread);
        gradient164.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient164.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush165(gradient164);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush165);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient165(0, 0, 1, 1);
        gradient165.setSpread(QGradient::PadSpread);
        gradient165.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient165.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush166(gradient165);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush166);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient166(0, 0, 1, 1);
        gradient166.setSpread(QGradient::PadSpread);
        gradient166.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient166.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush167(gradient166);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush167);
        QLinearGradient gradient167(0, 0, 1, 1);
        gradient167.setSpread(QGradient::PadSpread);
        gradient167.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient167.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush168(gradient167);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush168);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient168(0, 0, 1, 1);
        gradient168.setSpread(QGradient::PadSpread);
        gradient168.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient168.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush169(gradient168);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush169);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient169(0, 0, 1, 1);
        gradient169.setSpread(QGradient::PadSpread);
        gradient169.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient169.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush170(gradient169);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush170);
        QLinearGradient gradient170(0, 0, 1, 1);
        gradient170.setSpread(QGradient::PadSpread);
        gradient170.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient170.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush171(gradient170);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush171);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_12->setPalette(palette19);
        QFont font3;
        font3.setFamily(QString::fromUtf8("FreeSans"));
        font3.setPointSize(16);
        font3.setBold(true);
        label_12->setFont(font3);
        label_12->setAutoFillBackground(false);
        label_12->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_12->setTextFormat(Qt::RichText);
        label_12->setScaledContents(true);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setWordWrap(false);
        label_12->setMargin(1);
        label_13 = new QLabel(TestMenuPage);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(312, 330, 175, 40));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient171(0, 0, 1, 1);
        gradient171.setSpread(QGradient::PadSpread);
        gradient171.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient171.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush172(gradient171);
        palette20.setBrush(QPalette::Active, QPalette::Button, brush172);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient172(0, 0, 1, 1);
        gradient172.setSpread(QGradient::PadSpread);
        gradient172.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient172.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush173(gradient172);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush173);
        QLinearGradient gradient173(0, 0, 1, 1);
        gradient173.setSpread(QGradient::PadSpread);
        gradient173.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient173.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush174(gradient173);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush174);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient174(0, 0, 1, 1);
        gradient174.setSpread(QGradient::PadSpread);
        gradient174.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient174.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush175(gradient174);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush175);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient175(0, 0, 1, 1);
        gradient175.setSpread(QGradient::PadSpread);
        gradient175.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient175.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush176(gradient175);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush176);
        QLinearGradient gradient176(0, 0, 1, 1);
        gradient176.setSpread(QGradient::PadSpread);
        gradient176.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient176.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush177(gradient176);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush177);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient177(0, 0, 1, 1);
        gradient177.setSpread(QGradient::PadSpread);
        gradient177.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient177.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush178(gradient177);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush178);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient178(0, 0, 1, 1);
        gradient178.setSpread(QGradient::PadSpread);
        gradient178.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient178.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush179(gradient178);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush179);
        QLinearGradient gradient179(0, 0, 1, 1);
        gradient179.setSpread(QGradient::PadSpread);
        gradient179.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient179.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush180(gradient179);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush180);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_13->setPalette(palette20);
        label_13->setFont(font3);
        label_13->setAutoFillBackground(false);
        label_13->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_13->setTextFormat(Qt::RichText);
        label_13->setScaledContents(true);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(false);
        label_13->setMargin(1);
        label_14 = new QLabel(TestMenuPage);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(545, 330, 175, 40));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient180(0, 0, 1, 1);
        gradient180.setSpread(QGradient::PadSpread);
        gradient180.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient180.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush181(gradient180);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush181);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient181(0, 0, 1, 1);
        gradient181.setSpread(QGradient::PadSpread);
        gradient181.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient181.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush182(gradient181);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush182);
        QLinearGradient gradient182(0, 0, 1, 1);
        gradient182.setSpread(QGradient::PadSpread);
        gradient182.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient182.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush183(gradient182);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush183);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient183(0, 0, 1, 1);
        gradient183.setSpread(QGradient::PadSpread);
        gradient183.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient183.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush184(gradient183);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush184);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient184(0, 0, 1, 1);
        gradient184.setSpread(QGradient::PadSpread);
        gradient184.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient184.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush185(gradient184);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush185);
        QLinearGradient gradient185(0, 0, 1, 1);
        gradient185.setSpread(QGradient::PadSpread);
        gradient185.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient185.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush186(gradient185);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush186);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient186(0, 0, 1, 1);
        gradient186.setSpread(QGradient::PadSpread);
        gradient186.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient186.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush187(gradient186);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush187);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient187(0, 0, 1, 1);
        gradient187.setSpread(QGradient::PadSpread);
        gradient187.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient187.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush188(gradient187);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush188);
        QLinearGradient gradient188(0, 0, 1, 1);
        gradient188.setSpread(QGradient::PadSpread);
        gradient188.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient188.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush189(gradient188);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush189);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_14->setPalette(palette21);
        label_14->setFont(font3);
        label_14->setAutoFillBackground(false);
        label_14->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_14->setTextFormat(Qt::RichText);
        label_14->setScaledContents(true);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(false);
        label_14->setMargin(1);
        label_15 = new QLabel(TestMenuPage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(545, 360, 175, 40));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient189(0, 0, 1, 1);
        gradient189.setSpread(QGradient::PadSpread);
        gradient189.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient189.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush190(gradient189);
        palette22.setBrush(QPalette::Active, QPalette::Button, brush190);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient190(0, 0, 1, 1);
        gradient190.setSpread(QGradient::PadSpread);
        gradient190.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient190.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush191(gradient190);
        palette22.setBrush(QPalette::Active, QPalette::Base, brush191);
        QLinearGradient gradient191(0, 0, 1, 1);
        gradient191.setSpread(QGradient::PadSpread);
        gradient191.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient191.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush192(gradient191);
        palette22.setBrush(QPalette::Active, QPalette::Window, brush192);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient192(0, 0, 1, 1);
        gradient192.setSpread(QGradient::PadSpread);
        gradient192.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient192.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush193(gradient192);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush193);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient193(0, 0, 1, 1);
        gradient193.setSpread(QGradient::PadSpread);
        gradient193.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient193.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush194(gradient193);
        palette22.setBrush(QPalette::Inactive, QPalette::Base, brush194);
        QLinearGradient gradient194(0, 0, 1, 1);
        gradient194.setSpread(QGradient::PadSpread);
        gradient194.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient194.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush195(gradient194);
        palette22.setBrush(QPalette::Inactive, QPalette::Window, brush195);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient195(0, 0, 1, 1);
        gradient195.setSpread(QGradient::PadSpread);
        gradient195.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient195.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush196(gradient195);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush196);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient196(0, 0, 1, 1);
        gradient196.setSpread(QGradient::PadSpread);
        gradient196.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient196.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush197(gradient196);
        palette22.setBrush(QPalette::Disabled, QPalette::Base, brush197);
        QLinearGradient gradient197(0, 0, 1, 1);
        gradient197.setSpread(QGradient::PadSpread);
        gradient197.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient197.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush198(gradient197);
        palette22.setBrush(QPalette::Disabled, QPalette::Window, brush198);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_15->setPalette(palette22);
        label_15->setFont(font3);
        label_15->setAutoFillBackground(false);
        label_15->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_15->setTextFormat(Qt::RichText);
        label_15->setScaledContents(true);
        label_15->setAlignment(Qt::AlignCenter);
        label_15->setWordWrap(false);
        label_15->setMargin(1);
        stackedWidget->addWidget(TestMenuPage);
        RunTestPage = new QWidget();
        RunTestPage->setObjectName(QString::fromUtf8("RunTestPage"));
        RunTestPageBackButton = new QPushButton(RunTestPage);
        RunTestPageBackButton->setObjectName(QString::fromUtf8("RunTestPageBackButton"));
        RunTestPageBackButton->setGeometry(QRect(732, 12, 58, 58));
        RunTestPageBackButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/return.png);\n"
"border: none;\n"
"outline: none;"));
        RunTestPageBackButton->setFlat(true);
        RunTestButton = new QPushButton(RunTestPage);
        RunTestButton->setObjectName(QString::fromUtf8("RunTestButton"));
        RunTestButton->setGeometry(QRect(20, 20, 141, 41));
        RunTestButton->setFont(font1);
        RunTestButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(134, 132, 130);\n"
"border:2px solid #1e1b18;\n"
"color: #FFFFFF;\n"
"outline: none;"));
        RunTestButton->setIconSize(QSize(16, 16));
        RunTestButton->setFlat(false);
        RunResulLabel = new QLabel(RunTestPage);
        RunResulLabel->setObjectName(QString::fromUtf8("RunResulLabel"));
        RunResulLabel->setGeometry(QRect(0, 430, 800, 50));
        RunResulLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 50, 47);\n"
"color: #FFFFFF;"));
        RunResulLabel->setAlignment(Qt::AlignCenter);
        RunTestInformationLabel = new QLabel(RunTestPage);
        RunTestInformationLabel->setObjectName(QString::fromUtf8("RunTestInformationLabel"));
        RunTestInformationLabel->setGeometry(QRect(110, 280, 581, 101));
        RunTestInformationLabel->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(255, 255, 255);"));
        RunTestInformationLabel->setScaledContents(true);
        RunTestInformationLabel->setAlignment(Qt::AlignCenter);
        RunTestInformationLabel->setWordWrap(true);
        RunTestImageLabel = new QLabel(RunTestPage);
        RunTestImageLabel->setObjectName(QString::fromUtf8("RunTestImageLabel"));
        RunTestImageLabel->setGeometry(QRect(110, 90, 581, 191));
        RunTestImageLabel->setStyleSheet(QString::fromUtf8("background: rgb(255, 255, 255)"));
        RunTestImageLabel->setScaledContents(true);
        RunTestImageLabel->setWordWrap(true);
        stackedWidget->addWidget(RunTestPage);
        SchedulePage = new QWidget();
        SchedulePage->setObjectName(QString::fromUtf8("SchedulePage"));
        SchedulePageBackButton = new QPushButton(SchedulePage);
        SchedulePageBackButton->setObjectName(QString::fromUtf8("SchedulePageBackButton"));
        SchedulePageBackButton->setGeometry(QRect(732, 12, 58, 58));
        SchedulePageBackButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/return.png);\n"
"border: none;\n"
"outline: none;"));
        SchedulePageBackButton->setFlat(true);
        dateTimeEdit = new QDateTimeEdit(SchedulePage);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(125, 97, 550, 50));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        dateTimeEdit->setFont(font4);
        dateTimeEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"outline: none;"));
        dateTimeEdit->setAlignment(Qt::AlignCenter);
        dateTimeEdit->setCalendarPopup(false);
        AddScheduleButton = new QPushButton(SchedulePage);
        AddScheduleButton->setObjectName(QString::fromUtf8("AddScheduleButton"));
        AddScheduleButton->setGeometry(QRect(20, 20, 141, 41));
        AddScheduleButton->setFont(font1);
        AddScheduleButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(134, 132, 130);\n"
"border:2px solid #1e1b18;\n"
"color: #FFFFFF;\n"
"outline: none;"));
        AddScheduleButton->setIconSize(QSize(16, 16));
        AddScheduleButton->setFlat(false);
        ScheduleFeedbackLabel = new QLabel(SchedulePage);
        ScheduleFeedbackLabel->setObjectName(QString::fromUtf8("ScheduleFeedbackLabel"));
        ScheduleFeedbackLabel->setGeometry(QRect(0, 430, 800, 50));
        ScheduleFeedbackLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 50, 47);\n"
"color: #FFFFFF;"));
        ScheduleFeedbackLabel->setAlignment(Qt::AlignCenter);
        label_29 = new QLabel(SchedulePage);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(170, 70, 460, 21));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient198(0, 0, 1, 1);
        gradient198.setSpread(QGradient::PadSpread);
        gradient198.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient198.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush199(gradient198);
        palette23.setBrush(QPalette::Active, QPalette::Button, brush199);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient199(0, 0, 1, 1);
        gradient199.setSpread(QGradient::PadSpread);
        gradient199.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient199.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush200(gradient199);
        palette23.setBrush(QPalette::Active, QPalette::Base, brush200);
        QLinearGradient gradient200(0, 0, 1, 1);
        gradient200.setSpread(QGradient::PadSpread);
        gradient200.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient200.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush201(gradient200);
        palette23.setBrush(QPalette::Active, QPalette::Window, brush201);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient201(0, 0, 1, 1);
        gradient201.setSpread(QGradient::PadSpread);
        gradient201.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient201.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush202(gradient201);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush202);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient202(0, 0, 1, 1);
        gradient202.setSpread(QGradient::PadSpread);
        gradient202.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient202.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush203(gradient202);
        palette23.setBrush(QPalette::Inactive, QPalette::Base, brush203);
        QLinearGradient gradient203(0, 0, 1, 1);
        gradient203.setSpread(QGradient::PadSpread);
        gradient203.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient203.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush204(gradient203);
        palette23.setBrush(QPalette::Inactive, QPalette::Window, brush204);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient204(0, 0, 1, 1);
        gradient204.setSpread(QGradient::PadSpread);
        gradient204.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient204.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush205(gradient204);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush205);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient205(0, 0, 1, 1);
        gradient205.setSpread(QGradient::PadSpread);
        gradient205.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient205.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush206(gradient205);
        palette23.setBrush(QPalette::Disabled, QPalette::Base, brush206);
        QLinearGradient gradient206(0, 0, 1, 1);
        gradient206.setSpread(QGradient::PadSpread);
        gradient206.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient206.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush207(gradient206);
        palette23.setBrush(QPalette::Disabled, QPalette::Window, brush207);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_29->setPalette(palette23);
        QFont font5;
        font5.setFamily(QString::fromUtf8("FreeSans"));
        font5.setPointSize(11);
        font5.setBold(true);
        label_29->setFont(font5);
        label_29->setAutoFillBackground(false);
        label_29->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_29->setTextFormat(Qt::RichText);
        label_29->setScaledContents(true);
        label_29->setAlignment(Qt::AlignCenter);
        label_29->setWordWrap(false);
        label_29->setMargin(1);
        ScheduleTextgroupBox = new QGroupBox(SchedulePage);
        ScheduleTextgroupBox->setObjectName(QString::fromUtf8("ScheduleTextgroupBox"));
        ScheduleTextgroupBox->setGeometry(QRect(90, 155, 620, 61));
        ScheduleTextgroupBox->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);\n"
"outline: none;"));
        ScheduleTextgroupBox->setFlat(true);
        TempRadioButton = new QRadioButton(ScheduleTextgroupBox);
        TempRadioButton->setObjectName(QString::fromUtf8("TempRadioButton"));
        TempRadioButton->setGeometry(QRect(10, 20, 141, 23));
        TempRadioButton->setStyleSheet(QString::fromUtf8("outline: none;"));
        TempRadioButton->setChecked(true);
        HeartRadioButton = new QRadioButton(ScheduleTextgroupBox);
        HeartRadioButton->setObjectName(QString::fromUtf8("HeartRadioButton"));
        HeartRadioButton->setGeometry(QRect(220, 20, 161, 23));
        HeartRadioButton->setStyleSheet(QString::fromUtf8("outline: none;"));
        OxygenRadioButton = new QRadioButton(ScheduleTextgroupBox);
        OxygenRadioButton->setObjectName(QString::fromUtf8("OxygenRadioButton"));
        OxygenRadioButton->setGeometry(QRect(420, 20, 211, 23));
        OxygenRadioButton->setStyleSheet(QString::fromUtf8("outline: none;"));
        tableWidget_2 = new QTableWidget(SchedulePage);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(115, 215, 570, 211));
        tableWidget_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"outline: none;"));
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget_2->setAutoScroll(false);
        tableWidget_2->setAutoScrollMargin(16);
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setProperty("showDropIndicator", QVariant(true));
        tableWidget_2->setAlternatingRowColors(true);
        tableWidget_2->setShowGrid(false);
        tableWidget_2->setGridStyle(Qt::SolidLine);
        tableWidget_2->setSortingEnabled(false);
        tableWidget_2->setWordWrap(true);
        tableWidget_2->setCornerButtonEnabled(false);
        tableWidget_2->setRowCount(0);
        tableWidget_2->setColumnCount(2);
        tableWidget_2->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(230);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(285);
        tableWidget_2->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_2->horizontalHeader()->setStretchLastSection(false);
        tableWidget_2->verticalHeader()->setVisible(false);
        stackedWidget->addWidget(SchedulePage);
        ConsultMeasurementsPage = new QWidget();
        ConsultMeasurementsPage->setObjectName(QString::fromUtf8("ConsultMeasurementsPage"));
        ConsultMeasurementsBackButton = new QPushButton(ConsultMeasurementsPage);
        ConsultMeasurementsBackButton->setObjectName(QString::fromUtf8("ConsultMeasurementsBackButton"));
        ConsultMeasurementsBackButton->setGeometry(QRect(732, 12, 58, 58));
        ConsultMeasurementsBackButton->setFocusPolicy(Qt::StrongFocus);
        ConsultMeasurementsBackButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/return.png);\n"
"border: none;\n"
"outline: none;"));
        ConsultMeasurementsBackButton->setAutoDefault(false);
        ConsultMeasurementsBackButton->setFlat(true);
        ConsultFeedbackLabel = new QLabel(ConsultMeasurementsPage);
        ConsultFeedbackLabel->setObjectName(QString::fromUtf8("ConsultFeedbackLabel"));
        ConsultFeedbackLabel->setGeometry(QRect(0, 430, 800, 50));
        ConsultFeedbackLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 50, 47);\n"
"color: #FFFFFF;"));
        ConsultFeedbackLabel->setAlignment(Qt::AlignCenter);
        tableWidget = new QTableWidget(ConsultMeasurementsPage);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 70, 740, 351));
        tableWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"outline: none;"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setAutoScroll(false);
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(230);
        tableWidget->horizontalHeader()->setDefaultSectionSize(246);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        stackedWidget->addWidget(ConsultMeasurementsPage);
        ExportMenuPage = new QWidget();
        ExportMenuPage->setObjectName(QString::fromUtf8("ExportMenuPage"));
        PersonalButton = new QPushButton(ExportMenuPage);
        PersonalButton->setObjectName(QString::fromUtf8("PersonalButton"));
        PersonalButton->setGeometry(QRect(80, 150, 175, 175));
        PersonalButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/pessoa.png);\n"
"border:2px solid #000000;\n"
"outline: none;\n"
""));
        PersonalButton->setIconSize(QSize(16, 16));
        PersonalButton->setFlat(false);
        ExportMenuPageBackButton = new QPushButton(ExportMenuPage);
        ExportMenuPageBackButton->setObjectName(QString::fromUtf8("ExportMenuPageBackButton"));
        ExportMenuPageBackButton->setGeometry(QRect(732, 12, 58, 58));
        ExportMenuPageBackButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/return.png);\n"
"border: none;\n"
"outline: none;"));
        ExportMenuPageBackButton->setFlat(true);
        label_17 = new QLabel(ExportMenuPage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(545, 330, 175, 40));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient207(0, 0, 1, 1);
        gradient207.setSpread(QGradient::PadSpread);
        gradient207.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient207.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush208(gradient207);
        palette24.setBrush(QPalette::Active, QPalette::Button, brush208);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient208(0, 0, 1, 1);
        gradient208.setSpread(QGradient::PadSpread);
        gradient208.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient208.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush209(gradient208);
        palette24.setBrush(QPalette::Active, QPalette::Base, brush209);
        QLinearGradient gradient209(0, 0, 1, 1);
        gradient209.setSpread(QGradient::PadSpread);
        gradient209.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient209.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush210(gradient209);
        palette24.setBrush(QPalette::Active, QPalette::Window, brush210);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient210(0, 0, 1, 1);
        gradient210.setSpread(QGradient::PadSpread);
        gradient210.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient210.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush211(gradient210);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush211);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient211(0, 0, 1, 1);
        gradient211.setSpread(QGradient::PadSpread);
        gradient211.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient211.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush212(gradient211);
        palette24.setBrush(QPalette::Inactive, QPalette::Base, brush212);
        QLinearGradient gradient212(0, 0, 1, 1);
        gradient212.setSpread(QGradient::PadSpread);
        gradient212.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient212.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush213(gradient212);
        palette24.setBrush(QPalette::Inactive, QPalette::Window, brush213);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient213(0, 0, 1, 1);
        gradient213.setSpread(QGradient::PadSpread);
        gradient213.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient213.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush214(gradient213);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush214);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient214(0, 0, 1, 1);
        gradient214.setSpread(QGradient::PadSpread);
        gradient214.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient214.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush215(gradient214);
        palette24.setBrush(QPalette::Disabled, QPalette::Base, brush215);
        QLinearGradient gradient215(0, 0, 1, 1);
        gradient215.setSpread(QGradient::PadSpread);
        gradient215.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient215.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush216(gradient215);
        palette24.setBrush(QPalette::Disabled, QPalette::Window, brush216);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_17->setPalette(palette24);
        label_17->setFont(font);
        label_17->setAutoFillBackground(false);
        label_17->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_17->setTextFormat(Qt::RichText);
        label_17->setScaledContents(true);
        label_17->setAlignment(Qt::AlignCenter);
        label_17->setWordWrap(false);
        label_17->setMargin(1);
        label_19 = new QLabel(ExportMenuPage);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(80, 360, 175, 40));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient216(0, 0, 1, 1);
        gradient216.setSpread(QGradient::PadSpread);
        gradient216.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient216.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush217(gradient216);
        palette25.setBrush(QPalette::Active, QPalette::Button, brush217);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush);
        palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient217(0, 0, 1, 1);
        gradient217.setSpread(QGradient::PadSpread);
        gradient217.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient217.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush218(gradient217);
        palette25.setBrush(QPalette::Active, QPalette::Base, brush218);
        QLinearGradient gradient218(0, 0, 1, 1);
        gradient218.setSpread(QGradient::PadSpread);
        gradient218.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient218.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush219(gradient218);
        palette25.setBrush(QPalette::Active, QPalette::Window, brush219);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient219(0, 0, 1, 1);
        gradient219.setSpread(QGradient::PadSpread);
        gradient219.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient219.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush220(gradient219);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush220);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient220(0, 0, 1, 1);
        gradient220.setSpread(QGradient::PadSpread);
        gradient220.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient220.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush221(gradient220);
        palette25.setBrush(QPalette::Inactive, QPalette::Base, brush221);
        QLinearGradient gradient221(0, 0, 1, 1);
        gradient221.setSpread(QGradient::PadSpread);
        gradient221.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient221.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush222(gradient221);
        palette25.setBrush(QPalette::Inactive, QPalette::Window, brush222);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient222(0, 0, 1, 1);
        gradient222.setSpread(QGradient::PadSpread);
        gradient222.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient222.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush223(gradient222);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush223);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient223(0, 0, 1, 1);
        gradient223.setSpread(QGradient::PadSpread);
        gradient223.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient223.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush224(gradient223);
        palette25.setBrush(QPalette::Disabled, QPalette::Base, brush224);
        QLinearGradient gradient224(0, 0, 1, 1);
        gradient224.setSpread(QGradient::PadSpread);
        gradient224.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient224.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush225(gradient224);
        palette25.setBrush(QPalette::Disabled, QPalette::Window, brush225);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_19->setPalette(palette25);
        QFont font6;
        font6.setFamily(QString::fromUtf8("FreeSans"));
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setUnderline(false);
        font6.setStrikeOut(false);
        font6.setKerning(true);
        label_19->setFont(font6);
        label_19->setAutoFillBackground(false);
        label_19->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_19->setTextFormat(Qt::RichText);
        label_19->setScaledContents(true);
        label_19->setAlignment(Qt::AlignCenter);
        label_19->setWordWrap(false);
        label_19->setMargin(1);
        label_20 = new QLabel(ExportMenuPage);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(80, 330, 175, 40));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient225(0, 0, 1, 1);
        gradient225.setSpread(QGradient::PadSpread);
        gradient225.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient225.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush226(gradient225);
        palette26.setBrush(QPalette::Active, QPalette::Button, brush226);
        palette26.setBrush(QPalette::Active, QPalette::Text, brush);
        palette26.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient226(0, 0, 1, 1);
        gradient226.setSpread(QGradient::PadSpread);
        gradient226.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient226.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush227(gradient226);
        palette26.setBrush(QPalette::Active, QPalette::Base, brush227);
        QLinearGradient gradient227(0, 0, 1, 1);
        gradient227.setSpread(QGradient::PadSpread);
        gradient227.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient227.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush228(gradient227);
        palette26.setBrush(QPalette::Active, QPalette::Window, brush228);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient228(0, 0, 1, 1);
        gradient228.setSpread(QGradient::PadSpread);
        gradient228.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient228.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush229(gradient228);
        palette26.setBrush(QPalette::Inactive, QPalette::Button, brush229);
        palette26.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient229(0, 0, 1, 1);
        gradient229.setSpread(QGradient::PadSpread);
        gradient229.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient229.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush230(gradient229);
        palette26.setBrush(QPalette::Inactive, QPalette::Base, brush230);
        QLinearGradient gradient230(0, 0, 1, 1);
        gradient230.setSpread(QGradient::PadSpread);
        gradient230.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient230.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush231(gradient230);
        palette26.setBrush(QPalette::Inactive, QPalette::Window, brush231);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient231(0, 0, 1, 1);
        gradient231.setSpread(QGradient::PadSpread);
        gradient231.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient231.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush232(gradient231);
        palette26.setBrush(QPalette::Disabled, QPalette::Button, brush232);
        palette26.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient232(0, 0, 1, 1);
        gradient232.setSpread(QGradient::PadSpread);
        gradient232.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient232.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush233(gradient232);
        palette26.setBrush(QPalette::Disabled, QPalette::Base, brush233);
        QLinearGradient gradient233(0, 0, 1, 1);
        gradient233.setSpread(QGradient::PadSpread);
        gradient233.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient233.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush234(gradient233);
        palette26.setBrush(QPalette::Disabled, QPalette::Window, brush234);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_20->setPalette(palette26);
        label_20->setFont(font);
        label_20->setAutoFillBackground(false);
        label_20->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_20->setTextFormat(Qt::RichText);
        label_20->setScaledContents(true);
        label_20->setAlignment(Qt::AlignCenter);
        label_20->setWordWrap(false);
        label_20->setMargin(1);
        label_21 = new QLabel(ExportMenuPage);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(312, 330, 175, 40));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient234(0, 0, 1, 1);
        gradient234.setSpread(QGradient::PadSpread);
        gradient234.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient234.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush235(gradient234);
        palette27.setBrush(QPalette::Active, QPalette::Button, brush235);
        palette27.setBrush(QPalette::Active, QPalette::Text, brush);
        palette27.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient235(0, 0, 1, 1);
        gradient235.setSpread(QGradient::PadSpread);
        gradient235.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient235.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush236(gradient235);
        palette27.setBrush(QPalette::Active, QPalette::Base, brush236);
        QLinearGradient gradient236(0, 0, 1, 1);
        gradient236.setSpread(QGradient::PadSpread);
        gradient236.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient236.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush237(gradient236);
        palette27.setBrush(QPalette::Active, QPalette::Window, brush237);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient237(0, 0, 1, 1);
        gradient237.setSpread(QGradient::PadSpread);
        gradient237.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient237.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush238(gradient237);
        palette27.setBrush(QPalette::Inactive, QPalette::Button, brush238);
        palette27.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient238(0, 0, 1, 1);
        gradient238.setSpread(QGradient::PadSpread);
        gradient238.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient238.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush239(gradient238);
        palette27.setBrush(QPalette::Inactive, QPalette::Base, brush239);
        QLinearGradient gradient239(0, 0, 1, 1);
        gradient239.setSpread(QGradient::PadSpread);
        gradient239.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient239.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush240(gradient239);
        palette27.setBrush(QPalette::Inactive, QPalette::Window, brush240);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient240(0, 0, 1, 1);
        gradient240.setSpread(QGradient::PadSpread);
        gradient240.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient240.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush241(gradient240);
        palette27.setBrush(QPalette::Disabled, QPalette::Button, brush241);
        palette27.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient241(0, 0, 1, 1);
        gradient241.setSpread(QGradient::PadSpread);
        gradient241.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient241.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush242(gradient241);
        palette27.setBrush(QPalette::Disabled, QPalette::Base, brush242);
        QLinearGradient gradient242(0, 0, 1, 1);
        gradient242.setSpread(QGradient::PadSpread);
        gradient242.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient242.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush243(gradient242);
        palette27.setBrush(QPalette::Disabled, QPalette::Window, brush243);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_21->setPalette(palette27);
        label_21->setFont(font);
        label_21->setAutoFillBackground(false);
        label_21->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_21->setTextFormat(Qt::RichText);
        label_21->setScaledContents(true);
        label_21->setAlignment(Qt::AlignCenter);
        label_21->setWordWrap(false);
        label_21->setMargin(1);
        label_22 = new QLabel(ExportMenuPage);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(312, 360, 175, 40));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient243(0, 0, 1, 1);
        gradient243.setSpread(QGradient::PadSpread);
        gradient243.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient243.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush244(gradient243);
        palette28.setBrush(QPalette::Active, QPalette::Button, brush244);
        palette28.setBrush(QPalette::Active, QPalette::Text, brush);
        palette28.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient244(0, 0, 1, 1);
        gradient244.setSpread(QGradient::PadSpread);
        gradient244.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient244.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush245(gradient244);
        palette28.setBrush(QPalette::Active, QPalette::Base, brush245);
        QLinearGradient gradient245(0, 0, 1, 1);
        gradient245.setSpread(QGradient::PadSpread);
        gradient245.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient245.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush246(gradient245);
        palette28.setBrush(QPalette::Active, QPalette::Window, brush246);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette28.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient246(0, 0, 1, 1);
        gradient246.setSpread(QGradient::PadSpread);
        gradient246.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient246.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush247(gradient246);
        palette28.setBrush(QPalette::Inactive, QPalette::Button, brush247);
        palette28.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient247(0, 0, 1, 1);
        gradient247.setSpread(QGradient::PadSpread);
        gradient247.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient247.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush248(gradient247);
        palette28.setBrush(QPalette::Inactive, QPalette::Base, brush248);
        QLinearGradient gradient248(0, 0, 1, 1);
        gradient248.setSpread(QGradient::PadSpread);
        gradient248.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient248.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush249(gradient248);
        palette28.setBrush(QPalette::Inactive, QPalette::Window, brush249);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette28.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient249(0, 0, 1, 1);
        gradient249.setSpread(QGradient::PadSpread);
        gradient249.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient249.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush250(gradient249);
        palette28.setBrush(QPalette::Disabled, QPalette::Button, brush250);
        palette28.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient250(0, 0, 1, 1);
        gradient250.setSpread(QGradient::PadSpread);
        gradient250.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient250.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush251(gradient250);
        palette28.setBrush(QPalette::Disabled, QPalette::Base, brush251);
        QLinearGradient gradient251(0, 0, 1, 1);
        gradient251.setSpread(QGradient::PadSpread);
        gradient251.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient251.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush252(gradient251);
        palette28.setBrush(QPalette::Disabled, QPalette::Window, brush252);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_22->setPalette(palette28);
        label_22->setFont(font);
        label_22->setAutoFillBackground(false);
        label_22->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_22->setTextFormat(Qt::RichText);
        label_22->setScaledContents(true);
        label_22->setAlignment(Qt::AlignCenter);
        label_22->setWordWrap(false);
        label_22->setMargin(1);
        ExportResultLabel = new QLabel(ExportMenuPage);
        ExportResultLabel->setObjectName(QString::fromUtf8("ExportResultLabel"));
        ExportResultLabel->setGeometry(QRect(0, 430, 800, 50));
        ExportResultLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 50, 47);\n"
"color: #FFFFFF;"));
        ExportResultLabel->setAlignment(Qt::AlignCenter);
        USBButton = new QPushButton(ExportMenuPage);
        USBButton->setObjectName(QString::fromUtf8("USBButton"));
        USBButton->setGeometry(QRect(545, 150, 175, 175));
        USBButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/flash-drive.png);\n"
"border:2px solid #000000;\n"
"outline: none;\n"
"\n"
""));
        USBButton->setFlat(false);
        DoctorButton = new QPushButton(ExportMenuPage);
        DoctorButton->setObjectName(QString::fromUtf8("DoctorButton"));
        DoctorButton->setGeometry(QRect(312, 150, 175, 175));
        DoctorButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/white.png);\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/Images/assistencia-medica.png);\n"
"border:2px solid #000000;\n"
"outline: none;\n"
""));
        DoctorButton->setFlat(false);
        stackedWidget->addWidget(ExportMenuPage);
        PersonalButton->raise();
        ExportMenuPageBackButton->raise();
        label_17->raise();
        label_19->raise();
        label_20->raise();
        label_21->raise();
        label_22->raise();
        USBButton->raise();
        DoctorButton->raise();
        ExportResultLabel->raise();
        Dummy = new QWidget();
        Dummy->setObjectName(QString::fromUtf8("Dummy"));
        stackedWidget->addWidget(Dummy);
        Logo = new QWidget();
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setStyleSheet(QString::fromUtf8("background-image: url(:/Images/logo.png);"));
        ResumeButton = new QPushButton(Logo);
        ResumeButton->setObjectName(QString::fromUtf8("ResumeButton"));
        ResumeButton->setGeometry(QRect(-20, -20, 840, 520));
        ResumeButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));"));
        stackedWidget->addWidget(Logo);
        WifiClockPage = new QWidget();
        WifiClockPage->setObjectName(QString::fromUtf8("WifiClockPage"));
        scrollArea_2 = new QScrollArea(WifiClockPage);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 800, 480));
        scrollArea_2->setTabletTracking(true);
        scrollArea_2->setFocusPolicy(Qt::ClickFocus);
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setFrameShadow(QFrame::Plain);
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea_2->setWidgetResizable(false);
        scrollArea_2->setAlignment(Qt::AlignBottom|Qt::AlignJustify);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 800, 480));
        WifiPasswordLineEdit = new QLineEdit(scrollAreaWidgetContents_2);
        WifiPasswordLineEdit->setObjectName(QString::fromUtf8("WifiPasswordLineEdit"));
        WifiPasswordLineEdit->setGeometry(QRect(30, 190, 371, 31));
        WifiPasswordLineEdit->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(255, 255, 255);\n"
"outline: none;"));
        WifiPasswordLineEdit->setInputMethodHints(Qt::ImhEmailCharactersOnly|Qt::ImhHiddenText);
        WifiClockFeedbackLabel = new QLabel(scrollAreaWidgetContents_2);
        WifiClockFeedbackLabel->setObjectName(QString::fromUtf8("WifiClockFeedbackLabel"));
        WifiClockFeedbackLabel->setGeometry(QRect(0, 430, 800, 51));
        WifiClockFeedbackLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 50, 47);\n"
"color: #FFFFFF;"));
        WifiClockFeedbackLabel->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(scrollAreaWidgetContents_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(30, 160, 291, 21));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient252(0, 0, 1, 1);
        gradient252.setSpread(QGradient::PadSpread);
        gradient252.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient252.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush253(gradient252);
        palette29.setBrush(QPalette::Active, QPalette::Button, brush253);
        palette29.setBrush(QPalette::Active, QPalette::Text, brush);
        palette29.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient253(0, 0, 1, 1);
        gradient253.setSpread(QGradient::PadSpread);
        gradient253.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient253.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush254(gradient253);
        palette29.setBrush(QPalette::Active, QPalette::Base, brush254);
        QLinearGradient gradient254(0, 0, 1, 1);
        gradient254.setSpread(QGradient::PadSpread);
        gradient254.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient254.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush255(gradient254);
        palette29.setBrush(QPalette::Active, QPalette::Window, brush255);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette29.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette29.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient255(0, 0, 1, 1);
        gradient255.setSpread(QGradient::PadSpread);
        gradient255.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient255.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush256(gradient255);
        palette29.setBrush(QPalette::Inactive, QPalette::Button, brush256);
        palette29.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient256(0, 0, 1, 1);
        gradient256.setSpread(QGradient::PadSpread);
        gradient256.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient256.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush257(gradient256);
        palette29.setBrush(QPalette::Inactive, QPalette::Base, brush257);
        QLinearGradient gradient257(0, 0, 1, 1);
        gradient257.setSpread(QGradient::PadSpread);
        gradient257.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient257.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush258(gradient257);
        palette29.setBrush(QPalette::Inactive, QPalette::Window, brush258);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette29.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette29.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient258(0, 0, 1, 1);
        gradient258.setSpread(QGradient::PadSpread);
        gradient258.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient258.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush259(gradient258);
        palette29.setBrush(QPalette::Disabled, QPalette::Button, brush259);
        palette29.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette29.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient259(0, 0, 1, 1);
        gradient259.setSpread(QGradient::PadSpread);
        gradient259.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient259.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush260(gradient259);
        palette29.setBrush(QPalette::Disabled, QPalette::Base, brush260);
        QLinearGradient gradient260(0, 0, 1, 1);
        gradient260.setSpread(QGradient::PadSpread);
        gradient260.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient260.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush261(gradient260);
        palette29.setBrush(QPalette::Disabled, QPalette::Window, brush261);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette29.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_30->setPalette(palette29);
        label_30->setFont(font2);
        label_30->setAutoFillBackground(false);
        label_30->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_30->setTextFormat(Qt::RichText);
        label_30->setScaledContents(true);
        label_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_30->setWordWrap(false);
        label_30->setMargin(1);
        WifiNameLineEdit = new QLineEdit(scrollAreaWidgetContents_2);
        WifiNameLineEdit->setObjectName(QString::fromUtf8("WifiNameLineEdit"));
        WifiNameLineEdit->setGeometry(QRect(30, 110, 371, 31));
        WifiNameLineEdit->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(255, 255, 255);\n"
"outline: none;"));
        WifiNameLineEdit->setInputMethodHints(Qt::ImhEmailCharactersOnly);
        label_32 = new QLabel(scrollAreaWidgetContents_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(30, 90, 201, 21));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient261(0, 0, 1, 1);
        gradient261.setSpread(QGradient::PadSpread);
        gradient261.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient261.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush262(gradient261);
        palette30.setBrush(QPalette::Active, QPalette::Button, brush262);
        palette30.setBrush(QPalette::Active, QPalette::Text, brush);
        palette30.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient262(0, 0, 1, 1);
        gradient262.setSpread(QGradient::PadSpread);
        gradient262.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient262.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush263(gradient262);
        palette30.setBrush(QPalette::Active, QPalette::Base, brush263);
        QLinearGradient gradient263(0, 0, 1, 1);
        gradient263.setSpread(QGradient::PadSpread);
        gradient263.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient263.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush264(gradient263);
        palette30.setBrush(QPalette::Active, QPalette::Window, brush264);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette30.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient264(0, 0, 1, 1);
        gradient264.setSpread(QGradient::PadSpread);
        gradient264.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient264.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush265(gradient264);
        palette30.setBrush(QPalette::Inactive, QPalette::Button, brush265);
        palette30.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient265(0, 0, 1, 1);
        gradient265.setSpread(QGradient::PadSpread);
        gradient265.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient265.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush266(gradient265);
        palette30.setBrush(QPalette::Inactive, QPalette::Base, brush266);
        QLinearGradient gradient266(0, 0, 1, 1);
        gradient266.setSpread(QGradient::PadSpread);
        gradient266.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient266.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush267(gradient266);
        palette30.setBrush(QPalette::Inactive, QPalette::Window, brush267);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette30.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient267(0, 0, 1, 1);
        gradient267.setSpread(QGradient::PadSpread);
        gradient267.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient267.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush268(gradient267);
        palette30.setBrush(QPalette::Disabled, QPalette::Button, brush268);
        palette30.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette30.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient268(0, 0, 1, 1);
        gradient268.setSpread(QGradient::PadSpread);
        gradient268.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient268.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush269(gradient268);
        palette30.setBrush(QPalette::Disabled, QPalette::Base, brush269);
        QLinearGradient gradient269(0, 0, 1, 1);
        gradient269.setSpread(QGradient::PadSpread);
        gradient269.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient269.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush270(gradient269);
        palette30.setBrush(QPalette::Disabled, QPalette::Window, brush270);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette30.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_32->setPalette(palette30);
        label_32->setFont(font2);
        label_32->setAutoFillBackground(false);
        label_32->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_32->setTextFormat(Qt::RichText);
        label_32->setScaledContents(true);
        label_32->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_32->setWordWrap(false);
        label_32->setMargin(1);
        WifiClockPageBackButton = new QPushButton(scrollAreaWidgetContents_2);
        WifiClockPageBackButton->setObjectName(QString::fromUtf8("WifiClockPageBackButton"));
        WifiClockPageBackButton->setGeometry(QRect(732, 12, 58, 58));
        WifiClockPageBackButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"image: url(:/Images/return.png);\n"
"border: none;\n"
"outline: none;"));
        WifiClockPageBackButton->setFlat(true);
        WifiClockButton = new QPushButton(scrollAreaWidgetContents_2);
        WifiClockButton->setObjectName(QString::fromUtf8("WifiClockButton"));
        WifiClockButton->setGeometry(QRect(20, 20, 221, 41));
        WifiClockButton->setFont(font1);
        WifiClockButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"background-color: rgb(134, 132, 130);\n"
"border:2px solid #1e1b18;\n"
"color: #FFFFFF;\n"
"outline: none;"));
        WifiClockButton->setIconSize(QSize(16, 16));
        WifiClockButton->setFlat(false);
        dateTimeEdit_2 = new QDateTimeEdit(scrollAreaWidgetContents_2);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(450, 110, 311, 111));
        dateTimeEdit_2->setInputMethodHints(Qt::ImhDigitsOnly);
        dateTimeEdit_2->setTime(QTime(0, 0, 0));
        dateTimeEdit_2->setMinimumDateTime(QDateTime(QDate(1752, 9, 14), QTime(0, 0, 0)));
        label_33 = new QLabel(scrollAreaWidgetContents_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(450, 90, 301, 21));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient270(0, 0, 1, 1);
        gradient270.setSpread(QGradient::PadSpread);
        gradient270.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient270.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush271(gradient270);
        palette31.setBrush(QPalette::Active, QPalette::Button, brush271);
        palette31.setBrush(QPalette::Active, QPalette::Text, brush);
        palette31.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient271(0, 0, 1, 1);
        gradient271.setSpread(QGradient::PadSpread);
        gradient271.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient271.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush272(gradient271);
        palette31.setBrush(QPalette::Active, QPalette::Base, brush272);
        QLinearGradient gradient272(0, 0, 1, 1);
        gradient272.setSpread(QGradient::PadSpread);
        gradient272.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient272.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush273(gradient272);
        palette31.setBrush(QPalette::Active, QPalette::Window, brush273);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette31.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette31.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient273(0, 0, 1, 1);
        gradient273.setSpread(QGradient::PadSpread);
        gradient273.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient273.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush274(gradient273);
        palette31.setBrush(QPalette::Inactive, QPalette::Button, brush274);
        palette31.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient274(0, 0, 1, 1);
        gradient274.setSpread(QGradient::PadSpread);
        gradient274.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient274.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush275(gradient274);
        palette31.setBrush(QPalette::Inactive, QPalette::Base, brush275);
        QLinearGradient gradient275(0, 0, 1, 1);
        gradient275.setSpread(QGradient::PadSpread);
        gradient275.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient275.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush276(gradient275);
        palette31.setBrush(QPalette::Inactive, QPalette::Window, brush276);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette31.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette31.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient276(0, 0, 1, 1);
        gradient276.setSpread(QGradient::PadSpread);
        gradient276.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient276.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush277(gradient276);
        palette31.setBrush(QPalette::Disabled, QPalette::Button, brush277);
        palette31.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient277(0, 0, 1, 1);
        gradient277.setSpread(QGradient::PadSpread);
        gradient277.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient277.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush278(gradient277);
        palette31.setBrush(QPalette::Disabled, QPalette::Base, brush278);
        QLinearGradient gradient278(0, 0, 1, 1);
        gradient278.setSpread(QGradient::PadSpread);
        gradient278.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient278.setColorAt(0, QColor(0, 0, 0, 0));
        QBrush brush279(gradient278);
        palette31.setBrush(QPalette::Disabled, QPalette::Window, brush279);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette31.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_33->setPalette(palette31);
        label_33->setFont(font2);
        label_33->setAutoFillBackground(false);
        label_33->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0));\n"
"color:rgb(255, 255, 255);"));
        label_33->setTextFormat(Qt::RichText);
        label_33->setScaledContents(true);
        label_33->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_33->setWordWrap(false);
        label_33->setMargin(1);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        stackedWidget->addWidget(WifiClockPage);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);
        ConsultMeasurementsBackButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        User1Button->setText(QString());
        User2Button->setText(QString());
        User3Button->setText(QString());
        User4Button->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "User 1", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "User 2", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "User 3", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "User 4", nullptr));
        WifiButton->setText(QString());
        ConsultButton->setText(QString());
        label_8->setText(QCoreApplication::translate("Widget", "Do a test", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "Consult the", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Export the", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Schedule", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "measurements", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "measurements", nullptr));
        ScheduleButton->setText(QString());
        TestButton->setText(QString());
        ExportButton->setText(QString());
        SettingsButton->setText(QString());
        MainMenuPageBackButton->setText(QString());
        ClearProfileButton->setText(QCoreApplication::translate("Widget", "Clear", nullptr));
        UpdateProfileButton->setText(QCoreApplication::translate("Widget", "Update", nullptr));
        SettingsPageBackButton->setText(QString());
        SettingsFeedbackLabel->setText(QString());
        SexGroupBox->setTitle(QString());
        MasculineRadioButton->setText(QCoreApplication::translate("Widget", "M", nullptr));
        FeminineRadioButton->setText(QCoreApplication::translate("Widget", "F", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "Name", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "User Email", nullptr));
        label_23->setText(QCoreApplication::translate("Widget", "Doctor Email", nullptr));
        label_24->setText(QCoreApplication::translate("Widget", "Sex", nullptr));
        label_25->setText(QCoreApplication::translate("Widget", "Height", nullptr));
        label_26->setText(QCoreApplication::translate("Widget", "Weight", nullptr));
        label_27->setText(QCoreApplication::translate("Widget", "Age", nullptr));
        label_28->setText(QCoreApplication::translate("Widget", "Activity Level", nullptr));
        HeartBButton->setText(QString());
        TempButton->setText(QString());
        OxygenStButton->setText(QString());
        TestMenuPageBackButton->setText(QString());
        label_12->setText(QCoreApplication::translate("Widget", "Temperature", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "Heartbeat", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "Oxygen", nullptr));
        label_15->setText(QCoreApplication::translate("Widget", "saturation", nullptr));
        RunTestPageBackButton->setText(QString());
        RunTestButton->setText(QCoreApplication::translate("Widget", "Run", nullptr));
        RunResulLabel->setText(QString());
        RunTestInformationLabel->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        RunTestImageLabel->setText(QString());
        SchedulePageBackButton->setText(QString());
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("Widget", "M / d / h", nullptr));
        AddScheduleButton->setText(QCoreApplication::translate("Widget", "Add", nullptr));
        ScheduleFeedbackLabel->setText(QString());
        label_29->setText(QCoreApplication::translate("Widget", "Select Month / Day / Hour of the alarm and the test type", nullptr));
        ScheduleTextgroupBox->setTitle(QString());
        TempRadioButton->setText(QCoreApplication::translate("Widget", "Temperature", nullptr));
        HeartRadioButton->setText(QCoreApplication::translate("Widget", "HeartBeat Rate", nullptr));
        OxygenRadioButton->setText(QCoreApplication::translate("Widget", "Oxygen Saturation", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "Test type", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "Time", nullptr));
        ConsultMeasurementsBackButton->setText(QString());
        ConsultFeedbackLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "Test type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "Result", nullptr));
        PersonalButton->setText(QString());
        ExportMenuPageBackButton->setText(QString());
        label_17->setText(QCoreApplication::translate("Widget", "USB", nullptr));
        label_19->setText(QCoreApplication::translate("Widget", "email", nullptr));
        label_20->setText(QCoreApplication::translate("Widget", "Personal", nullptr));
        label_21->setText(QCoreApplication::translate("Widget", "Doctor", nullptr));
        label_22->setText(QCoreApplication::translate("Widget", "email", nullptr));
        ExportResultLabel->setText(QString());
        USBButton->setText(QString());
        DoctorButton->setText(QString());
        ResumeButton->setText(QString());
        WifiClockFeedbackLabel->setText(QString());
        label_30->setText(QCoreApplication::translate("Widget", "Wifi Password", nullptr));
        label_32->setText(QCoreApplication::translate("Widget", "Wifi Name", nullptr));
        WifiClockPageBackButton->setText(QString());
        WifiClockButton->setText(QCoreApplication::translate("Widget", "Connect/Update Clock", nullptr));
        dateTimeEdit_2->setDisplayFormat(QCoreApplication::translate("Widget", "yy/M/d/ h:mm", nullptr));
        label_33->setText(QCoreApplication::translate("Widget", "Year/Month/Day Hour/Minute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
