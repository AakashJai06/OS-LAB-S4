#include <stdio.h>

int main(){
    
    int f[10],m[50],count =0,n,fn,flag =0,next=0;

printf("Number of pages-->");
scanf("%d",&n);

printf("page numbers -->");
for(int i=0;i<n;i++)
    scanf("%d",&m[i]);

printf("Number of frames -->");
scanf("%d",&fn);
int current[fn],freq[fn];
for(int i=0;i<fn;i++){
    f[i] = -1;
    current[i] = 0 ;  
    freq[i] = 0; 
}

printf("Page repacement starts--\n");

for(int i=0;i<n;i++){
    flag =0;
    for(int j=0;j<fn;j++){
        if(f[j] == m[i]){
            flag =1;
            freq[j]++;
            current[j] = next++;
            break;
        }
    }
    if(flag == 0){
        if(next < fn){
            f[next] = m[i];
            current[next] = next;
            freq[next++] = 1;
        }
        else{
            int min =0;
            for(int k=1;k<fn;k++){
                if(freq[min] > freq[k] || (freq[min] == freq[k] && current[min] > current[k]))
                min = k;
            }
            f[min] = m[i];
            current[min] = next++;
            freq[min] = 1;
        }
    }
    for(int i=0;i<fn;i++){
        if(f[i]!=-1)
            printf("%d\t",f[i]);
    }
    printf("\n");
}


  return 0;
}
