#include <stdio.h>

void firstFit(int b[],int p[],int m,int n){
    printf("Process No  Process Size  Block no\n");
    for(int i=0;i<n;i++){
        int flag =0;
        for(int j=0;j<m;j++){
            if(b[j] > p[i]){
                b[j] -= p[i];
                flag = 1;
                printf("%d%15d%15d\n",i+1,p[i],j+1);
                break;
            }
        }
        if(!flag){
            printf("%d%15d            Not Allocated\n",i+1,p[i]);
        }
    }
}

void worstFit(int b[],int p[],int m,int n){
    printf("Process No  Process Size  Block no\n");
    for(int i=0;i<n;i++){
        int flag =0,max = i;
        for(int j=i+1;j<m;j++){
            if(b[max] < b[j]){
                max  = j;
            }
        }
        if(b[max]>p[i]){
            b[max] -=p[i];
            printf("%d%15d%15d\n",i+1,p[i],max+1);
            flag = 1;
        }
        if(!flag){
            printf("%d%15d            Not Allocated\n",i+1,p[i]);
        }
    }
}

void bestFit(int b[],int p[],int m,int n){
    printf("Process No  Process Size  Block no\n");
    for(int i=0;i<n;i++){
        int min=-1;
        for(int j=0;j<m;j++){
            if(b[j] > p[i]){
                if(min == -1 || b[j] < b[min]){
                    min  = j;
                }
            }
        }
        if(min != -1){
            b[min] -=p[i];
            printf("%d%15d%15d\n",i+1,p[i],min+1);
        }
        else{
            printf("%d%15d            Not Allocated\n",i+1,p[i]);
        }
    }
}

int main(){
    
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]),ch;
    
    printf("1) First Fit\n2) Worst Fit\n3) Best Fit\nChoice:  ");
    scanf("%d",&ch);    
    
    switch(ch){
        case 1: 
                firstFit(blockSize,processSize,m,n);
                break;
        case 2:
                worstFit(blockSize,processSize,m,n);
                break;
        case 3:
                bestFit(blockSize,processSize,m,n);
                break;
    }
}
