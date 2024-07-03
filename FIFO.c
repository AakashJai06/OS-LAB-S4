//Page replacement FIFO

#include <stdio.h>

int main(){
    
    int f[10],m[50],count =0,n,fn,flag =0;

printf("Number of pages-->");
scanf("%d",&n);


printf("page numbers -->");
for(int i=0;i<n;i++)
    scanf("%d",&m[i]);

printf("Number of frames -->");
scanf("%d",&fn);

for(int i=0;i<fn;i++)
    f[i] = -1;

printf("Page repacement starts--\n----\n");

for(int i=0;i < n ; i++){
    for(int j=0; j < fn;j++){
        if(f[j] == m[i]){
            flag =1;
            break;
        }
    }
    if(flag == 0){
        f[count++] = m[i];
    }
    for(int k=0;k<fn;k++){
        if(f[k] != -1){
            printf("%d\t",f[k]);
        }
    }
    
    if(flag == 1)
        printf(" H\n");
    else
        printf(" M\n");    
    printf("-----\n");
    
    if(count == fn)
        count = 0;
        flag =0;
}
    
    return 0;
}

