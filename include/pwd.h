#ifndef _PWD_H
#define _PWD_H

struct passwd
{
    char *pw_name;
    char *pw_passwd;
    int pw_uid;
    int pw_guid;
    char *pw_gecos;
    char *pw_dir;
    char *pw_shell;
};

#endif