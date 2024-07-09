#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pid;
    int arrival;
    int burst;
    int comp;
    int tat;
    int wt;
}Process;

void arrivalSort(Process process[],int n){
    Process temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(process[j].arrival > process[j+1].arrival){
                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }
}

void roundRobin(Process process[],int n,int t){
    int complete=0,rbt[n],current=process[0].arrival;
    float avgtat=0.0,avgwt=0.0;
    for(int i=0;i<n;i++){
        rbt[i] = process[i].burst;
        process[i].comp = 0;
    }
    while(complete!=n){
        for(int i=0;i<n;i++){
                if(rbt[i] > 0 && current >= process[i].arrival){
                    if(rbt[i] > t){
                        rbt[i] -= t;
                        current +=t;
                    }
                    else{
                        current += rbt[i];
                        rbt[i] = 0;
                        complete++;
                        process[i].comp = current;
                        process[i].tat = process[i].comp - process[i].arrival;
                        process[i].wt = process[i].tat - process[i].burst;
                        avgtat += process[i].tat;
                        avgwt += process[i].wt;
                    }
                }
            }
        }
    printf("Process  ArrivalTime  BurstTime Completion TurnaroundTime   WaitingTime\n");
    for(int i=0;i<n;i++){
    printf("P%d%10d%10d%15d%15d%20d\n",process[i].pid,process[i].arrival,process[i].burst,process[i].comp,process[i].tat,process[i].wt);
    }
    printf("Average Waiting Time=%f\n",avgwt/n);
    printf("Average turnaround Time=%f\n",avgtat/n);
}


int main(){
    int n,t;
    printf("Number of processes-> ");
    scanf("%d",&n);
    Process process[n];
    printf("PID arrival Burst:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&process[i].pid,&process[i].arrival,&process[i].burst);
    }
    printf("Time Quantum : ");
    scanf("%d",&t);
    arrivalSort(process,n);
    roundRobin(process,n,t);
    
    return 0;
}
