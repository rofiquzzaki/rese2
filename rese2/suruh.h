#ifndef SURUH_H
#define SURUH_H

#include <libssh/libssh.h>
extern ssh_session sesi_ssh;
extern char *alb;
extern int porb;
extern char *jenb;
extern char *pasb;

class suruh
{
public:
    suruh();
    //nginisialisasi uname secara default

    int ngakon(char *printah);
    //nginisialisasi perintah yang dimasukkan

    int konek_ssh(char *alamat, int s_port);
    //mbuat sesi, koneksi

    int minta(char *orang, char *pase);
    //konek pake password

    int otentikasi();
    //otentikasi
private:
    int rc;
    /*
    ssh_session sesi_ssh;
    char *alb;
    int porb;
    char *jenb;
    char *pasb;
    */

};

#endif // SURUH_H
