#include <stdio.h>

typedef struct{
    int id;
    int burst;
    int remaining; 
    int completion;
    int tat;
    int wt;
}Process;

void roundRobin(Process processes[],int n,int tq){
    int complete = 0;
    int current=0;
    for(int i=0;i<n;i++){
        processes[i].remaining = processes[i].burst;
        processes[i].completion = 0;
    }
    while(complete < n){
        int flag = 0;
            for(int i=0;i<n;i++){
            if(processes[i].remaining > 0){
            flag =1;
            if(processes[i].remaining <= tq){
                current += processes[i].remaining;
                processes[i].completion = current;
                processes[i].remaining = 0;
                printf("Process P%d completed at time %d\n", processes[i].id, processes[i].completion);
                complete++;
                processes[i].tat = processes[i].completion; 
                processes[i].wt = processes[i].tat - processes[i].burst;
            }
            else{
                current += tq;
                processes[i].remaining -= tq;
            }
        }
    }
    if(!flag)
        break;
    }
}

int main(){
    
    Process processes[] = {
      {1, 4}, {2, 3}, {3, 5} 
    };
    
    int n = sizeof(processes)/sizeof(Process);
    
    roundRobin(processes,n,2);
    
    return 0;
}
