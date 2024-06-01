#include <stdio.h>

struct Process{
    int pid;
    int arrival;
    int burst;
    int completion;
    int tat;
    int wt;
};

void sort(struct Process processes[],int n){
    int current = processes[0].arrival;
    
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(processes[j].burst < processes[min].burst && processes[j].arrival <= current){
                min = j;
            }
        }
        if(min != i){
            struct Process temp = processes[min];
            processes[min] = processes[i];
            processes[i] = temp;
        }
        current += processes[i].burst;
        processes[i].completion = current;
    }
}

void calculateTimes(struct Process processes[], int n) {
    int current = processes[0].arrival;
    for (int i = 0; i < n; i++) {
        current =+ processes[i].burst;
        processes[i].tat = processes[i].completion - processes[i].arrival;
        processes[i].wt = processes[i].tat - processes[i].burst;
    }
    
    float avgwt=0.0;
    float avgtat=0.0;
    printf("Process  ArrivalTime  BurstTime Completion TurnaroundTime   WaitingTime\n");
       for(int i=0;i<n;i++)
       {
           printf("P%d%10d%10d%15d%15d%20d\n",processes[i].pid,processes[i].arrival,processes[i].burst,processes[i].completion,processes[i].tat,processes[i].wt);
           avgwt=avgwt+processes[i].wt;
           avgtat=avgtat+processes[i].tat;
       }
    printf("Average Waiting Time=%f\n",avgwt/n);
    printf("Average turnaround Time=%f\n",avgtat/n);
}

int main(){
    struct Process processes[] = {
        {1, 0, 8},
        {2, 1, 1},
        {3, 2, 3},
        {4, 3, 2},
        {5, 4, 6}
    };
    
    int n = sizeof(processes)/sizeof(struct Process);
    
    sort(processes,n);
    calculateTimes(processes,n);
}
