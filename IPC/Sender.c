#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(){
    
    void *shared_memory;
    char buffer[100];
    int shmid;
    
    shmid = shmget((key_t)1222,1024,0666|IPC_CREAT);
    printf("Key of the shared memory is %d\n",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Enter data to be written in the shared memory-> ");
    read(0,buffer,100);
    strcpy(shared_memory,buffer);
    printf("\nYou wrote : %s",(char *)shared_memory);
    
    return 0;
}
