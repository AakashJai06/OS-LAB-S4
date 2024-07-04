//SCAN Disk Scheduling
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int rq[100],n,initial,thm=0,size,move,temp,i;
    printf("Number of Requests--> ");
    scanf("%d",&n);
    printf("Request Sequence--> ");
    for(i=0;i<n;i++)
    scanf("%d",&rq[i]);
    printf("Initial head position--> ");
    scanf("%d",&initial);
    printf("Size of Disk--> ");
    scanf("%d",&size);
    printf("Head Movement direction:\n\t1) 0 For left \n\t2) 1 For right\t");
    scanf("%d",&move);
    
    for(i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(rq[j] > rq[j+1]){
                temp = rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = temp;
            }
        }
    }
    int index;
    for(i=0;i<n;i++){
        if(initial < rq[i]){
            index = i;
            break;
        }
    }
    
    if(move == 1){
        for(i=index;i<n;i++){
            thm += abs(initial-rq[i]);
            initial = rq[i];
        }
        thm += abs(rq[i-1]-size-1);
        initial = size-1;
        for( i= index-1;i>=0;i--){
            thm += abs(rq[i]-initial);
            initial = rq[i];
        }
    }
    else{
     for(i=index-1;i>=0;i--){
            thm += abs(initial-rq[i]);
            initial = rq[i];
        }
        thm += abs(rq[i+1]-0);
        initial = 0;
        for(i= index;i<n;i++){
            thm += abs(rq[i]-initial);
            initial = rq[i];
        }   
    }
    
    printf("Total Head Movement is %d",thm);
    
    return 0;
}
