/*************************************************************************
	> File Name: cd.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月21日 星期一 21时44分02秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
 
#define MAXSIZE 100
  
void info_print();

int main(int argc, char const *argv[]) {
    while(1) {
        char command[MAXSIZE];
        pid_t pid;
        int status;
        info_print();
        bzero(command, MAXSIZE);
        gets(command);
        if(-1 == (pid = fork())) {
            perror("fork");
            exit(-1);
        }
        if(pid > 0) {
            wait(&status);
        } else {
            int i, flag = 0, j = 0;
            char *file, *argv[10];
            file = command;
            argv[flag++] = command;
            for (i = 0; command[i] != '\0'; i++) {
                while(command[i] == ' ') {
                    command[i++] = '\0';
                    j = 1;
                }
                if(j == 1) {
                    argv[flag++] = command + i;
                    j = 0;
                }
            }
            argv[flag] = NULL;
            if(strncmp(file, "cd", 2) == 0) {
                if(chdir(argv[1]) == -1) {
                    perror("chdir");
                    exit(-1);
                }
            } else {
                if(execvp(file, argv)) {
                    fprintf(stderr,"%s: command not found\n");
                }
            }
        }
    }
    return 0;
}

void info_print() {
    char buf[MAXSIZE], *username, hostname[MAXSIZE], pwd[MAXSIZE], ch;
    bzero(buf, MAXSIZE);
    bzero(pwd, MAXSIZE);
    bzero(hostname, MAXSIZE);
    if((username = getenv("USER")) == NULL) {
        printf("Error: get username failure!\n");
        exit(-1);
    }
    if(getcwd(pwd, MAXSIZE) == NULL) {
        perror("getcwd");
        exit(-1);
    }
    if(gethostname(hostname, MAXSIZE) == -1) {
        perror("gethostname");
        exit(-1);
    }
    if(strcmp(username,"root") == 0) {
        ch = '#';
    } else {
        ch = '$';
    }
    sprintf(buf, "%s@%s:%s%c", username, hostname, pwd, ch);
    fprintf(stdout, "%s", buf);
}
