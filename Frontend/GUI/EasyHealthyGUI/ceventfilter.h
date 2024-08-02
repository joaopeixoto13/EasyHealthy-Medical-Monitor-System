#ifndef CEVENTFILTER_H
#define CEVENTFILTER_H
#include "qobject.h"
#include "qobjectdefs.h"
#include "widget.h"

/**
 * @brief The CEventFilter class
 * @details This class is used to filter events from the GUI
 */
class CEventFilter: public QObject
{
    Q_OBJECT                    
    Widget *w;                                      /**< Pointer to the widget */
public:
    QTimer *timer;                                  /**< Timer used to count the innactivity time */
    CEventFilter(Widget* w);                        /**< Constructor */
protected:
    bool eventFilter(QObject *obj, QEvent *ev);     /**< Event filter */
};
#endif // CEVENTFILTER_H
