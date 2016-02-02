#include "widget.h"
//#include "suruh.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    suruh pr;

    if(pr.otentikasi() == 0)
    {
        pr.ngakon("uname -o");
        w.l_os->setText(pr.otput);
        pr.ngakon("uname -n");
        w.l_hostname->setText(pr.otput);
        w.show();
    }
    else
    {
        return 0;
    }

    return a.exec();
}
