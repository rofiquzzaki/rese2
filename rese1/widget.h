#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QPushButton;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void dipencet(bool cek);

signals:
    void hitunganKe();

private:
    Ui::Widget *ui;
    QPushButton *t_uname;
    int m_penghitung;
};

#endif // WIDGET_H
