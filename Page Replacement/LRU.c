//Page Replacement algorithm LRU
#include <stdio.h>

int main(){
    
int m[50],f[10],n,fn,next=0,current[10],flag=1;
    
printf("Number of pages-->");
scanf("%d",&n);

printf("page numbers -->");
for(int i=0;i<n;i++)
    scanf("%d",&m[i]);

printf("Number of frames -->");
scanf("%d",&fn);

printf("Page repacement starts--\n----\n");

for(int i=0;i<fn;i++)
    f[i] = -1;

for(int i=0;i<n;i++){
    for(int j=0;j<fn;j++){
        flag =0;
        if(m[i] == f[j]){
            current[j] = next++;
            flag =1;
            break;
        }
    }
        if(flag ==0){
            if(next < fn){
                f[next] = m[i];
                current[next] = next++; 
            }
            else{
                int min =0;
                for(int k=1;k<fn;k++){
                    if(current[min] > current[k])  min =k;
                }
                f[min] = m[i];
                current[min] = next++;
            }
        }
    for(int k=0;k<fn;k++){
        if(f[k] != -1){
            printf("%d\t",f[k]);
        }
    }
    if(flag == 0)
        printf(" M\n");
    else
        printf(" H\n");
    printf("\n-----\n");
    flag =0;
}
    
    return 0;
}
