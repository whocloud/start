/*************************************************************************
	> File Name: cd-ls-test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月19日 星期六 19时27分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void my_ls(char *cur_dir);
void my_cd(const char *cd_to);
char * my_pwd();

char buffer[512];

int main(int argc, char **argv, char **environ)
{
    my_cd("/home/administrator/BruceZhang");
    my_ls(my_pwd());
    return 0;
}

void my_ls(char *cur_dir)
{
    DIR *dir;
    struct dirent *link;
    struct stat buf;
    struct tm *p;
    char file_type[11] = {0};
    char t_buffer[128] = {0};
    char sbuf[512] = {0};
    printf("%s\n", cur_dir);
    dir = opendir(cur_dir);
    while ((link = readdir(dir)) != NULL)
    {
        if (lstat(link -> d_name, &buf) == -1)
        {
            perror("lstat");
            continue;
                
        }
        if (strcmp(link -> d_name, ".") == 0 || strcmp(link -> d_name, "..") == 0)
        {
            continue;
                
        }
        strcpy(file_type, "----------");
        switch (buf.st_mode & S_IFMT)
        {
            case S_IFSOCK :
                file_type[0] = 's';
                break;
            case S_IFLNK :
                file_type[0] = 'l';
                break;
            case S_IFBLK :
                file_type[0] = 'b';
                break;
            case S_IFDIR :
                file_type[0] = 'd';
                break;
            case S_IFCHR :
                file_type[0] = 'c';
                break;
            case S_IFIFO :
                file_type[0] = 'f';
                break;
            default :
                break;
        }
        if (buf.st_mode & S_IRUSR)
        {
            file_type[1] = 'r';
        }
        if (buf.st_mode & S_IWUSR)
        {
            file_type[2] = 'w';    
        }
        if (buf.st_mode & S_IXUSR)
        {
            file_type[3] = 'x';
        }
    if (buf.st_mode & S_IRGRP)
    {
        file_type[4] = 'r';    
    }
        if (buf.st_mode & S_IWGRP)
        {
            file_type[5] = 'w';
        }
        if (buf.st_mode & S_IXGRP)
        {
            file_type[6] = 'x';        
        }
        if (buf.st_mode & S_IROTH)
        {
            file_type[7] = 'r';              
        }
        if (buf.st_mode & S_IWOTH)
        {
            file_type[8] = 'w';             
        }
        if (buf.st_mode & S_IXOTH)
        {
            file_type[9] = 'x';                  
        }
        p = gmtime((time_t *)&(buf.st_mtim));
        strftime(t_buffer, 128, "%b %e %H:%M", p);
        sprintf(sbuf, "%s  %3d %-8d %-8d %8lu %s %s", file_type, (int)buf.st_nlink, buf.st_uid, buf.st_gid, (long)buf.st_size, t_buffer, link -> d_name);
        printf("%s\n", sbuf);
    }
}

void my_cd(const char *cd_to)
{
    chdir(cd_to);
}

char * my_pwd()
{
    memset(buffer, 0, sizeof(buffer));
    getcwd(buffer, sizeof(buffer));
    printf("%s\n", buffer);
    return buffer;
}
