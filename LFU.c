//Page Replacement LFU
#include <stdio.h>

int main(){
    
    int n,fn,m[50],f[10],freq[10],count=0,flag =0,flag2=0,min;
printf("Number of pages-->");
scanf("%d",&n);


printf("page numbers -->");
for(int i=0;i<n;i++)
    scanf("%d",&m[i]);

printf("Number of frames -->");
scanf("%d",&fn);

for(int i=0;i<fn;i++){
    f[i] = -1; freq[i] = 0;
}

printf("Page repacement starts--\n----\n");

for(int i=0;i<n;i++){
    flag =0,flag2=0;
    for(int j=0;j<fn;j++){
        if(m[i] == f[j]){
            freq[j] += 1;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        if(i < fn){
            f[count] = m[i];
            freq[count++] = 1;
        }
        else{
            min = 0;
            for(int k = 1 ; k<fn;k++){
                if(freq[min] > freq[k]){
                    min =k;
                    if(freq[min] == freq[k]){
                        flag2=1;
                        break;
                    }
                }
            }
            if(flag2 == 0){
                f[min] = m[i];
                freq[min] = 1;
            }
            else{
                f[count++] = m[i];
            }
        }
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
}
    
    return 0;
}
