#include <stdio.h>
#include <dirent.h>

struct dirent *dptr;

int main(){
    
    char dirName[50];
    
    DIR *dirp;
    
    printf("Enter Directory Name--------->");
    scanf("%s",dirName);
    
    if(!(dirp = opendir(dirName))){
        printf("<------Error------>");
        return 1;
    }
    
    while(dptr = readdir(dirp)){
        printf("%s\n", dptr->d_name);
    }
    closedir(dirp);
    return 0;
}
