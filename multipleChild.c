#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int num =3;
    pid_t p;
    
    printf("Parent process (PID %d) is creating child processes...\n", getpid());
    
    for(int i=0;i<num;i++){
        p = fork();
        
        if(p == 0){
            printf("Child process (PID %d) created by parent (PID %d)\n", getpid(), getppid());
            exit(0);
        }
    }
    
    for(int i=0;i<num;i++){
        wait(NULL);
    }
    
    printf("Parent process (PID %d) has finished creating child processes.\n", getpid());
    return 0;
    
}
