#include <pwd.h>

int loggin(struct pwd * user, char username[500], char password[500]){
    user->id = 0;
    user->name = username;
    user->pass = password;
    user->pid = pid;
    user->Date = "";
}