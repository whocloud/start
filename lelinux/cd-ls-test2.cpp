/*************************************************************************
	> File Name: cd-ls-test2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月21日 星期一 22时23分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int split(char *s,char *delim[])
{
    int j=0;
    int k=0;
    char temp[100];
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            temp[j++]=s[i];         
        }else
        {
            temp[j]='\0';
            delim[k] = (char *)malloc(strlen(temp));
            strcpy(delim[k],temp);
            j=0;
            k++;           
        }      
    }
    temp[j]='\0';
    delim[k] = (char *)malloc(strlen(temp));
    strcpy(delim[k],temp);
    k++;
    return k;
}
int main()
{
    char *commands[] = {"/bin/ls","/bin/cat","/bin/ps"};
    int parent_pid = getpid();
    while(1)
    {
        printf("Please input your command: ");
        char *command;
        fgets(command,100,stdin);
        command[strlen(command)-1]='\0';
        fork();
        int pid = getpid();
        if(pid==parent_pid)
        {
            wait(NULL);
            continue;        
        }else
        {
            int flag = 0;
            char *argv[5];
            int k = split(command,argv);
            argv[k]=NULL;
            for(int i=0;i<3;i++)
            {
                if(strstr(commands[i],argv[0]))
                {
                    flag=1;
                    char *envp[] = {NULL};
                    execve(commands[i],argv,envp);
                    break;                   
                }                
            }
            if(!flag)
            {
                printf("command not found: %s\n",argv[0]);                
            }
            break;           
        }        
    }
    return 0;
}

