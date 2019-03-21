#include<stdio.h>
#include <unistd.h>

int main(int argc, char**argv)
{
    pid_t pid = NULL;
    pid = fork();
    if(pid == 0 ){
        while(1){
            sleep(1);
            printf("this is child process!!\n");
        }
    }else{
        while(1){
            sleep(2);
            printf("this is parent process!!\n");
        }
    }
    return 0;
}