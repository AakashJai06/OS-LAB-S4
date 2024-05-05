#include <stdio.h>

typedef struct{
    
    int name;
    int arrival;
    int burst;
    int completion;
    int turnAround;
    int waiting;
    
}Process;

void swapTime(Process processess[],int n){
    
    int currentTime = 0,min;
    
    for(int i =0 ; i < n - 1; i++){
        min = i;
        for(int j=i+1;j<n;j++)
            if(processess[j].burst < processess[min].burst && processess[j].arrival <= currentTime)
                min = j;
                
        if(min != i){
                currentTime += processess[min].burst;
                processess[min].completion = currentTime;
                Process temp = processess[min];
                processess[min] = processess[i];
                processess[i] = temp;
        }
        else{
            currentTime += processess[min].burst;
            processess[min].completion = currentTime;
        }
    }
    
        currentTime += processess[n-1].burst;
        processess[n-1].completion = currentTime;
    
}

void calculateTime(Process processess[],int n,float *avgTAT,float *avgWt){
    
    for(int i=0;i<n;i++){
        
        processess[i].turnAround = processess[i].completion - processess[i].arrival;
        *avgTAT += processess[i].turnAround;
        processess[i].waiting = processess[i].turnAround - processess[i].burst;
        *avgWt += processess[i].waiting;
        
    }
}


int main(){
    
    Process processess[] = {
        {1, 0, 8},
        {2, 1, 1},
        {3, 2, 3},
        {4, 3, 2},
        {5, 4, 6}
    };
    
    int n = sizeof(processess) / sizeof(Process);
    float avgWt = 0.0,avgTAT = 0.0;
    
    swapTime(processess,n);
    calculateTime(processess,n,&avgTAT,&avgWt);
    
    printf("Process  ArrivalTime BurstTime TurnaroundTime    WaitingTime  completion\n");
    
    for(int i=0;i<n;i++)
   {
       printf("P%d%10d%10d%15d%20d%15d\n",processess[i].name,processess[i].arrival,processess[i].burst,processess[i].turnAround,processess[i].waiting,processess[i].completion);
       
   }
    printf("Average Waiting Time=%f\n",avgWt/n);
    printf("Average turnaround Time=%f\n",avgTAT/n);
    
}
