#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readWord.h"



int checkInStopWord(char listStopWord[10000][20], char newWord[10], int countStopWord)
{
    for(int i=0; i<countStopWord; i++){
        if(strcmp(listStopWord[i],newWord)==0)
            return 1;
    }
    return 0;
}
int checkInListWord(ListWord listWord[10000], char newWord[10], int countListWord){
    for(int i=0; i<countListWord; i++){
        if(strcmp(listWord[i].word,newWord)==0)
            return i;
    }
    return 0;
}