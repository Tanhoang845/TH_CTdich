#include <stdio.h>
#include "stopWord.h"

char fileStop[12] = "stopw.txt";
char fileWord[12] = "vanban.txt";


FILE *fst, *fmain;
int readFileStop(char listStopWord[10000][20]){
    fst = fopen(fileStop,"r");
    if(fst==NULL){
        printf("Khong tim thay file: %s\n", fileStop);
        return -1;
    }

    
    int countStop = -1;
    while(!feof(fst))
        {
            countStop++;
            fscanf(fst,"%s",listStopWord[countStop]);    
            //printf("OK: %d %s\n", countStop,listStopWord[countStop]);
        }
    fclose(fst);
    return countStop-1;
}

void printFileStop(char listStopWord[10000][20], int countStop){
    for(int i=0; i<=countStop; i++)
        printf("%d %s\n", i,listStopWord[i]);
    return;
}

int readNameWord(char listStopWord[10000][20], int stopWord){
    fmain = fopen(fileWord,"r");
    if(fmain == NULL){
        printf("Khong tim thay file: %s", fileWord);
        return -1;
    }
    char c1 = 0, c2 = 0, c3; //c1,c2 la cac ki tu da duoc doc, c3 la ki tu hien tai: c1c2c3
    char fw;//Bo qua ki tu Viet hoa Dau doan
    fw = getc(fmain);
    while(!feof(fmain)){        
        c3 = getc(fmain);
        if(c3>='A'&& c3<='Z'&&c1!='.')
            {
                stopWord++;
                listStopWord[stopWord][0]=c3;
                int i=0;
                while(!feof(fmain)&& (c3=getc(fmain)) && c3!=' ' && c3!='\n' && c3!=',' && c3!='.')
                    {
                        i++;
                        listStopWord[stopWord][i] = c3;
                    }
            }
        c1=c2;
        c2=c3;
        
    }

    fclose(fmain);
    return stopWord;
}