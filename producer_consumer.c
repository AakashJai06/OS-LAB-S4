#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];

sem_t full,empty,mutex;
int in=0,out=0;

void* Producer(void *args){
    for(int i=0;i<BUFFER_SIZE;i++){
        sleep(1);
        int item = rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Produced : %d\n",item);
        in = (in+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
    } 
    return NULL;
}

void* Consumer(void *args){
    for(int i=0;i<BUFFER_SIZE;i++){
        sleep(2);
        int item;
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out];
        out = (out+1)%BUFFER_SIZE;
        printf("Consumed : %d\n",item);
        sem_post(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main(){
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFFER_SIZE);
    pthread_t producer , consumer;
    pthread_create(&producer,NULL,Producer,NULL);
    pthread_create(&consumer,NULL,Consumer,NULL);
    
    pthread_join(producer,NULL);
    pthread_join(consumer,NULL);
}
