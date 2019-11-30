#ifndef SYSTEM_H
#define SYSTEM_H
int sys_kall;
char sys_all_coamnd[500];
char args[500];
char user[100];
int userid;
int taskid;
char nametask[100];
volatile void panic(const char * str);
#endif // !SYSTEM_h
