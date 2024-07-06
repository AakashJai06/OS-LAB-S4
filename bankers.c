#include <stdio.h>

int main(){
    
    int n,m,i,j;
    
    printf("Number of Processes-->");
    scanf("%d",&n);
    printf("Number of Resources-->");
    scanf("%d",&m);
    
    int alloc[n][m],max[n][m],avail[m],y=0,seq[n];
    
    printf("Enter max-->\n");
    for(i =0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);
    }
    printf("Enter alloc-->\n");
    for(i =0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);
    }
    
    printf("Enter avail-->");
    for(i =0;i<m;i++){
            scanf("%d",&avail[i]);
    }
    
    int f[n],need[n][m];
    for(i =0;i<n;i++){
       f[i] = 0;
    }
    
    for(i =0;i<n;i++){
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    
    for(i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(f[j] == 0){
                int flag = 0;
                for(int k=0;k<m;k++){
                    if(need[j][k] > avail[k]){
                        flag =1;
                        break;
                    }
                }
                if (flag == 0){
                    for(int k =0;k<m;k++){
                        avail[k] += alloc[j][k];
                    }
                    f[j] = 1;
                    seq[y++] = j;
                }
            }
        }
    }
    
    int flag = 0;
    for(i =0;i<n;i++){
            if(f[i] == 0){
                printf("No safe seq");
                flag=1;
                break;
            }
    }
    if(flag == 0){
        printf("Safe sequence :\t");
        for(i =0;i<n-1;i++){
            printf("P%d->",seq[i]);
    }
    printf("P%d",seq[n-1]);
    }
    
    return 0;
}
