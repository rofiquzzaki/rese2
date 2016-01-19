#ifndef PASUOT_H
#define PASUOT_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>

class pasuot : public QDialog
{
    Q_OBJECT
public:
    explicit pasuot(QWidget *parent = 0);
    QString alamat() const;
    QString jeneng() const;
    QString pase() const;
    QString prot() const;

private:
    QLabel *addre;
    QLabel *usre;
    QLabel *passe;
    QLabel *porte;
    QLineEdit *almt;
    QLineEdit *nama;
    QLineEdit *kunci;
    QLineEdit *poret;
    //QGroupBox *utama;
    //QGroupBox *kanan;

signals:

public slots:
};
#endif // PASUOT_H
