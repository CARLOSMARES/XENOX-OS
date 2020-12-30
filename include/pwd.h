#ifndef _PWD_H
#define _PWD_H

struct pwd{
    int id;
    char name[500];
    char pass[100];
    int pid;
    char Date[10];
    int access;
    int state;
};

int loggin(struct pwd * user, char username[500], char password[500]);

#endif