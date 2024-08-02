#include "widget.h"
#include <QApplication>
#include "ceventfilter.h"

int main(int argc, char *argv[])
{
    putenv((char*)"QT_IM_MODULE=qtvirtualkeyboard");    /**< Set the environment variable to use the virtual keyboard */
    QApplication a(argc, argv);
    Widget w;
    w.show();
    CEventFilter filter(&w);
    a.installEventFilter(&filter);
    return a.exec();
}
