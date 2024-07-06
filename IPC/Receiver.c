#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(){
    
    void *shared_memory;
    int shmid;
    char buffer[100];
    shmid = shmget((key_t)1222,1024,0666);
    printf("Key of the shared memory is %d",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf("\nProcess attached at %p\n",shared_memory);
    printf("Data read from shared memory is : %s",(char *)shared_memory);
    
    return 0;
}
