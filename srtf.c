#include <stdio.h>

typedef struct{
    
    int name;
    int arrival;
    int burst;
    int completion;
    int turnAround;
    int waiting;
    
}Process;

int shortest(Process processes[],int n,int ct){
    int min = -1;
    for(int i=0;i<n;i++){
        if(processes[i].arrival <= ct && processes[i].burst > 0 && processes[i].burst <= processes[min].burst)
                min = i;
    }
    return min;
}

void execute(Process processes[],int n){
    int current = processes[0].arrival;int totalBT=0,min;
    
    for(int i=0;i<n;i++){
        totalBT += processes[i].burst;
    }
    while(totalBT >0){
        
        min = shortest(processes,n,current);
        printf("Executing p%d\n",processes[min].name);
        current++;
        processes[min].burst--;
        totalBT--;
    }
}

int main(){
    
    Process processes[] = {
        {1, 0, 8},
        {2, 1, 1},
        {3, 2, 3},
        {4, 3, 2},
        {5, 4, 6}
    };
    
    int n = sizeof(processes) / sizeof(Process);
    
    execute(processes,n);
    
}
