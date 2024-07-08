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

void sort(Process process[],int n){
    int count= process[0].arrival;
    Process temp;
    for(int i=0;i<n-1;i++){
        int min =i;
        for(int j=i+1;j<n;j++){
            if(process[min].burst > process[j].burst &&  count >= process[j].arrival){
                min = j;
            }
        }
        if(min!=i){
                temp = process[i];
                process[i] = process[min];
                process[min] = temp;
        }
        count += process[i].burst;
    }
}

void print(Process process[],int n){
    int current = process[0].arrival;
    float avgtat=0.0,avgwt=0.0;
    for(int i=0;i<n;i++){
        current += process[i].burst;
        process[i].comp = current;
        
        process[i].tat = process[i].comp - process[i].arrival;
        process[i].wt = process[i].tat - process[i].burst;
        avgtat += process[i].tat;
        avgwt += process[i].wt;
    }
    printf("Process  ArrivalTime  BurstTime Completion TurnaroundTime   WaitingTime\n");
    for(int i=0;i<n;i++){
    printf("P%d%10d%10d%15d%15d%20d\n",process[i].pid,process[i].arrival,process[i].burst,process[i].comp,process[i].tat,process[i].wt);
    }
    printf("Average Waiting Time=%f\n",avgwt/n);
    printf("Average turnaround Time=%f\n",avgtat/n);
}

int main(){
    int n;
    printf("Number of processes-> ");
    scanf("%d",&n);
    Process process[n];
    printf("PID arrival Burst:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&process[i].pid,&process[i].arrival,&process[i].burst);
    }
    arrivalSort(process,n);
    sort(process,n);
    print(process,n);
    
    return 0;
}
