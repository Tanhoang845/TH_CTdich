#include<stdio.h>
#include<string.h>

FILE *fptr;

void main(){
    char vanban[256];
    
    printf("Helo World\n");
    fptr = fopen("vanba.txt","r");
    if(fptr==NULL){
        printf("Khong mo duoc file\n");
        return;
    }

    return;
}