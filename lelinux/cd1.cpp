/*************************************************************************
	> File Name: cd1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月21日 星期一 22时44分57秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
using namespace std;
int parseline(char *, char *);
int buildin_command(char *);
void eval(char *);

int main(int argc,char *argv[]){
    char cmdstring[MAX_CMD];
    int n;
    while(1){
    printf("*myshell*>");
    fflush(stdout);
    /*read*/
    if((n=read(0,cmdstring,MAX_CMD))<0){
        printf("read error");           
    }
        eval(cmdstring);        
    }
    return 0;
}

int buildin_command(char **argv){   
    if(strcmp(argv[0],"exit")==0){
        exit(0);           
    }
    if(strcmp(argv[0],"cd")==0){
        if(chdir(argv[1])){
            printf("myselous:cd:%s:no such directory\n",argv[1]);
        }
        return 1;
    }
    if(strcmp(argv[0],"pwd")==0){
        char buf[MAX_DIR_NAME];
        printf("%s\n",getcwd(buf,sizeof(buf)));
        return 1;
    }
    return 0;//not a buildin_command
}

int parseline(char *buf,char**argv){ 
    while(*buf==' '){
        buf++;
    }
    int delim = 0;
    int argc = 0;
    while(*buf!='\n'){
        while(buf[delim]!='\n'&&buf[delim]!=' '){
            delim++;           
        }
        if(buf[delim] == '\n'){
            buf[delim] = '\0';
            argv[argc++] = buf;
            break;            
        }
        buf[delim] = '\0';
        argv[argc++] = buf; 
        buf+=delim+1;
        /*指示器indicator=0*/
        delim = 0;
        while(*buf==' '){
            buf++;           
        }            
    }
    /*the last element is NULL*/
    argv[argc] = NULL;
    return 0;
}

void eval(char *cmdstring){
    /*parse the cmdstring to argv*/
    char *argv[MAX_CMD];
    /*Holds modified command line*/
    char buf[MAX_CMD];
    strcpy(buf,cmdstring);
    /*parse the cmdstring*/
    parseline(buf,argv);
    if(argv[0]==NULL){
        return;/*ignore empty lines*/        
    }
    /*is a buildin command*/
    /*direct return*/
    if(buildin_command(argv)) return;
    int pid = fork();
    if(pid == 0){
        if(execvp(argv[0],argv)<0){
            printf("%s:command not found.\n",argv[0]);
            exit(0);                
        }
    }
    wait(pid);
}


