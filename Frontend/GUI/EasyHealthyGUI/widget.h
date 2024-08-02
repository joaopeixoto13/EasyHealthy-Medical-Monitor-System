#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <pthread.h>
#include "fifo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


/**
 * @brief The Widget class
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    int m_previousWidget;                           /**< Indicate the previous widget */
    bool m_settingsFlowControl;                     /**< Indicate if the settings flow control is active */
    std::string m_selectedTest;                     /**< Indicate the test select by the user */
    void tInterface(void);                          /**< Thread responsable to send the information to the backend */
    void tUpdateGUI(void);                          /**< Thread responsable for receive the information from the backend and update the GUI */
    CFifo<std::string> m_tInterfaceBuffer;          /**< Buffer to send the information to the backend */
public slots:
    void keyboardChanged(bool active);              /**< Slot to receive the keyboard status */
    void userInactivity();                          /**< Slot to receive the timer overflow */

private slots:

    void on_ConsultMeasurementsBackButton_clicked();    /**< Callback to the ConsultMeasurementsBackButton */

    void on_SettingsButton_clicked();                   /**< Callback to the SettingsButton */   

    void on_TestButton_clicked();                       /**< Callback to the TestButton */

    void on_ScheduleButton_clicked();                   /**< Callback to the ScheduleButton */

    void on_ConsultButton_clicked();                    /**< Callback to the ConsultButton */

    void on_ExportButton_clicked();                     /**< Callback to the ExportButton */

    void on_SchedulePageBackButton_clicked();           /**< Callback to the SchedulePageBackButton */

    void on_ExportMenuPageBackButton_clicked();         /**< Callback to the ExportMenuPageBackButton */

    void on_SettingsPageBackButton_clicked();           /**< Callback to the SettingsPageBackButton */

    void on_TestMenuPageBackButton_clicked();           /**< Callback to the TestMenuPageBackButton */

    void on_RunTestPageBackButton_clicked();            /**< Callback to the RunTestPageBackButton */

    void on_TempButton_clicked();                       /**< Callback to the TempButton */

    void on_HeartBButton_clicked();                     /**< Callback to the HeartBButton */

    void on_OxygenStButton_clicked();                   /**< Callback to the OxygenStButton */

    void on_User1Button_clicked();                      /**< Callback to the User1Button */

    void on_MainMenuPageBackButton_clicked();           /**< Callback to the MainMenuPageBackButton */

    void on_ClearProfileButton_clicked();               /**< Callback to the ClearProfileButton */

    void on_UpdateProfileButton_clicked();              /**< Callback to the UpdateProfileButton */

    void on_User2Button_clicked();                      /**< Callback to the User2Button */

    void on_User3Button_clicked();                      /**< Callback to the User3Button */

    void on_User4Button_clicked();                      /**< Callback to the User4Button */

    void on_PersonalButton_clicked();                   /**< Callback to the PersonalButton */

    void on_DoctorButton_clicked();                     /**< Callback to the DoctorButton */

    void on_USBButton_clicked();                        /**< Callback to the USBButton */

    void on_RunTestButton_clicked();                    /**< Callback to the RunTestButton */

    void on_AddScheduleButton_clicked();                /**< Callback to the AddScheduleButton */

    void on_stackedWidget_currentChanged(int arg1);     /**< Callback to when a Page changed */

    void on_ResumeButton_clicked();                     /**< Callback to the ResumeButton */

    void on_WifiButton_clicked();                       /**< Callback to the WifiButton */

    void on_WifiClockPageBackButton_clicked();          /**< Callback to the WifiClockPageBackButton */

    void on_WifiClockButton_clicked();                  /**< Callback to the WifiClockButton */

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
