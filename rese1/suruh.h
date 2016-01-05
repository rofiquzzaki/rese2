#ifndef SURUH_H
#define SURUH_H

#include <libssh/libssh.h>

class suruh
{
public:
    suruh();
    //nginisialisasi uname secara default

    int ngakon(char *printah);
    //nginisialisasi perintah yang dimasukkan

    int konek_ssh(const char *alamat, int s_port);
    //mbuat sesi, koneksi

    int minta(const char *orang, const char *pase);
    //konek pake password

    int otentikasi();
    //otentikasi
private:
    int rc;
    ssh_session sesi_ssh;
};

#endif // SURUH_H
