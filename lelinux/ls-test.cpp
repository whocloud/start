/*************************************************************************
	> File Name: ls-test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月19日 星期六 19时20分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
int main(int argc,char* argv[])
{
    DIR* dir = opendir(".");
    struct dirent* ent=NULL;
    while((ent = readdir(dir)))
    {
        if((ent->d_type == 4||ent->d_type == 8)&&ent->d_name[0]!='.')
        printf("%s  ",ent->d_name);
             
    }
    closedir(dir);
    puts("");
    return 0;

}
