#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stopWord.h"
#include "readWord.h"

int lineCount =0;
char* readWord(FILE *fptr);

int main(){
    FILE *fptr;
    fptr = fopen("vanban.txt","r");

    char listStopWord[10000][20];
    int  countStop;
    printf("Hello World\n");
    countStop = readFileStop(listStopWord);

    countStop = readNameWord(listStopWord, countStop);
    //printFileStop(listStopWord, countStop);

    ListWord listWord[10000];
    int countListWord=-1;
    int wordInList;
    while( !feof(fptr) )
        {
            char phu[10];
            strcpy(phu,readWord(fptr));
            if(strlen(phu)==0)
                continue;
            if(checkInStopWord(listStopWord, phu,countStop)==0){
                int check =checkInListWord(listWord, phu, countListWord);
                printf("|%s %d|",phu, lineCount);
                if(check==0){                                        
                    countListWord++;
                    strcpy(listWord[countListWord].word,phu);
                    listWord[countListWord].countLine=1;
                    listWord[countListWord].line[0]=lineCount;
                }
                else
                    {
                        listWord[check].countLine++;
                        int t = listWord[check].countLine;                        
                        listWord[check].line[t]=lineCount;
                    }
            }                      
        }

        for(int i=0; i<countListWord; i++){
            printf("%s ",listWord[i].word);
            for(int j=0; j<listWord[i].countLine; j++)
                printf("%d, ",listWord[i].line[j]);
            printf("\n");
        }
    
    return 0;
}

char* readWord(FILE *fptr){
    char *s =  (char*) malloc(sizeof(char)*10);
    s[0]='\0';
    char c;
    int i=-1;
    while( !feof(fptr) )
        {
            c = getc(fptr);
            if(c=='\n')
                lineCount++;

            if( (c>='a'&& c<='z') || (c>='A'&& c<='Z')){
                i++;
                s[i]=c;
            }
            else
                { 
                    i++;
                    s[i]='\0';
                    return s;
                }
        }        
    return s;
}