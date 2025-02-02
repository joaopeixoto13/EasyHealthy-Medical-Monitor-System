#include "ceventfilter.h"
#include "qcoreevent.h"
#include <iostream>
#include <QTimer>
#define INACTIVITY_TIME 120000            /**< 2 minutes */

/**
 * @brief Construct a new CEventFilter
 * @param w Pointer to the widget
 * @details This constructor creates a timer and connects it to the userInactivity() slot of the widget
 * @details If the user is inactive for 2 minutes, the userInactivity() slot is called
 * @see Widget::userInactivity()
 */
CEventFilter::CEventFilter(Widget* w): w(w)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), w, SLOT(userInactivity()));
    timer->start(INACTIVITY_TIME);
}

/**
 * @brief Event filter
 * @param obj Object that generates the event
 * @param ev Event
 * @return true if the event is filtered, false otherwise
 * @details This function filters the events generated by the GUI. If the event is a key press or a mouse move, the timer is restarted
 */
bool CEventFilter::eventFilter(QObject *obj, QEvent *ev)
{
  if(ev->type() == QEvent::KeyPress || ev->type() == QEvent::MouseMove)
       timer->start(INACTIVITY_TIME);
  return QObject::eventFilter(obj, ev);
}

