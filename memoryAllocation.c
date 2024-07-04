//Memmory Allocation Algorithm
#include <stdio.h>

void firstFit(int b[],int p[],int bn,int pn){
    printf("Process No.  Process Size  Block no.\n");
    for(int i=0;i<pn;i++){
        int flag=0;
        for(int j=0;j<bn;j++){
            if(p[i] < b[j]){
                b[j] -= p[i];
                printf("P%d%15d%15d\n",(i+1),p[i],j+1);
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("P%d%15d\t\tNot Allocated\n",(i+1),p[i]);
    }
}

void bestFit(int b[],int p[],int bn,int pn){
    int bno[20],temp,temp1;
    for(int i=0;i<bn;i++)
        bno[i] = i;
    printf("Process No.  Process Size  Block no.\n");
    for(int i=0;i<bn;i++){
        for(int j=0;j<bn-i-1;j++){
            if(b[j] > b[j+1]){
                temp1 = bno[j];
                bno[j] = bno[j+1];
                bno[j+1] = temp1;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }
    
    for(int i=0;i<pn;i++){
        int flag=0;
        for(int j=0;j<bn;j++){
            if(p[i] < b[j]){
                b[j] -= p[i];
                printf("P%d%15d%15d\n",(i+1),p[i],(bno[j]+1));
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("P%d%15d\t\tNot Allocated\n",(i+1),p[i]);
    }
    
}

void worstFit(int b[],int p[],int bn,int pn){
    int bno[20],temp,temp1;
    for(int i=0;i<bn;i++)
        bno[i] = i;
    printf("Process No.  Process Size  Block no.\n");
    for(int i=0;i<bn;i++){
        for(int j=0;j<bn-i-1;j++){
            if(b[j] < b[j+1]){
                temp1 = bno[j];
                bno[j] = bno[j+1];
                bno[j+1] = temp1;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }
    
    for(int i=0;i<pn;i++){
        int flag=0;
        for(int j=0;j<bn;j++){
            if(p[i] < b[j]){
                b[j] -= p[i];
                printf("P%d%15d%15d\n",(i+1),p[i],(bno[j]+1));
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("P%d%15d\t\tNot Allocated\n",(i+1),p[i]);
    }
    
}

int main(){
    
    int b[20],p[20],bn,pn,ch;
    printf("Number of Blocks-->");
    scanf("%d",&bn);
    printf("Block sizes-->");
    for(int i=0;i<bn;i++)
    scanf("%d",&b[i]);
    printf("Number of processes-->");
    scanf("%d",&pn);
    printf("Process size-->");
    for(int i=0;i<pn;i++)
    scanf("%d",&p[i]);
    
        printf("Enter Choice:\n\t1) First Fit\n\t2) Best Fit\n\t3) Worst Fit\n\t4) Exit\n\t");
    scanf("%d",&ch);
        switch(ch){
        case 1:
                firstFit(b,p,bn,pn);
                break;
        case 2:
                bestFit(b,p,bn,pn);
                break;
        case 3:
                worstFit(b,p,bn,pn);
                break;
    }
    return 0;
}
