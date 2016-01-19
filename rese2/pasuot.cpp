#include "pasuot.h"


pasuot::pasuot(QWidget *parent) : QDialog(parent)
{
    almt = new QLineEdit(this);
    nama = new QLineEdit(this);
    kunci = new QLineEdit(this);
    poret = new QLineEdit(this);

    addre = new QLabel("Address");
    usre = new QLabel("Username");
    passe = new QLabel("Password");
    porte = new QLabel("Port");

    QPushButton *pass_in = new QPushButton(tr("Masuk"));
    pass_in->setDefault(true);

    QPushButton *gagal = new QPushButton(tr("rasido"));

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(pass_in, QDialogButtonBox::AcceptRole);
    QDialogButtonBox *buttonBos = new QDialogButtonBox(Qt::Horizontal);
    buttonBos->addButton(gagal, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBos, SIGNAL(rejected()), this, SLOT(close()));

    almt->setFixedWidth(128);
    nama->setFixedWidth(128);
    kunci->setFixedWidth(128);
    poret->setFixedWidth(128);
    addre->setFixedWidth(128);
    usre->setFixedWidth(128);
    passe->setFixedWidth(128);
    porte->setFixedWidth(128);

    addre->setAlignment(Qt::AlignRight);
    usre->setAlignment(Qt::AlignRight);
    passe->setAlignment(Qt::AlignRight);
    porte->setAlignment(Qt::AlignRight);

    QGridLayout *leyot = new QGridLayout;
    leyot->addWidget(addre);
    leyot->addWidget(usre);
    leyot->addWidget(passe);
    leyot->addWidget(porte);
    leyot->addWidget(buttonBox);
    leyot->addWidget(almt, 0, 1);
    leyot->addWidget(nama, 1, 1);
    leyot->addWidget(kunci, 2, 1);
    leyot->addWidget(poret, 3, 1);
    leyot->addWidget(buttonBos, 4, 1);

    leyot->setAlignment(addre, Qt::AlignRight);
    leyot->setAlignment(usre, Qt::AlignRight);
    leyot->setAlignment(passe, Qt::AlignRight);
    leyot->setAlignment(porte, Qt::AlignRight);
    leyot->setAlignment(buttonBox, Qt::AlignRight);
    leyot->setAlignment(almt, Qt::AlignLeft);
    leyot->setAlignment(nama, Qt::AlignLeft);
    leyot->setAlignment(kunci, Qt::AlignLeft);
    leyot->setAlignment(poret, Qt::AlignLeft);
    leyot->setAlignment(buttonBos, Qt::AlignLeft);
    setLayout(leyot);
    /*
    QVBoxLayout *superb = new QVBoxLayout;

    QHBoxLayout *utam = new QHBoxLayout;

    QGroupBox *utama = new QGroupBox;
    QVBoxLayout *tul = new QVBoxLayout;
    tul->addWidget(addre);
    tul->addWidget(usre);
    tul->addWidget(passe);
    tul->addWidget(porte);
    utama->setLayout(tul);

    QGroupBox *kanan = new QGroupBox;
    QVBoxLayout *posisi = new QVBoxLayout;
    posisi->addWidget(almt);
    posisi->addWidget(nama);
    posisi->addWidget(kunci);
    posisi->addWidget(poret);
    //posisi->addWidget(buttonBox);
    kanan->setLayout(posisi);

    utam->addWidget(utama);
    utam->addWidget(kanan);
    utam->addWidget(buttonBox);
    setLayout(utam);
    */

}

QString pasuot::alamat() const
{
    return almt->text();
}

QString pasuot::jeneng() const
{
    return nama->text();
}

QString pasuot::pase() const
{
    return kunci->text();
}

QString pasuot::prot() const
{
    return poret->text();
}
