#include <stdio.h>
#include <sys/stat.h>

int main(){
    char filename[50];
    struct stat sfile;
    
    printf("<-----ENTER FILE NAME------>");
    scanf("%s",filename);
    
    if(stat(filename,&sfile) == -1){
        printf("<--ERRROR-->");
        return 1;
    }
    
    printf("<-----File infos------>\n");
    printf("ST Mode :  %o\n",sfile.st_mode);
    printf("File size :  %ld Bytes\n",sfile.st_size);
    printf("File uid :  %d\n",sfile.st_uid);
    return 0;
}
