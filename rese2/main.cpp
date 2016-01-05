#include "widget.h"
//#include "suruh.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;

    //suruh pr;
    //if(pr.otentikasi() == 0)
    //{

        w.show();

    //}

    return a.exec();
}
