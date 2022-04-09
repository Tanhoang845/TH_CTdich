#include <stdio.h>
#include "stopWord.h"

int main(){
    char listStopWord[10000][20];
    int  countStop;
    printf("Hello World\n");
    countStop = readFileStop(listStopWord);
    //if(countStop!=-1)
    //    printFileStop(listStopWord, countStop);

    countStop = readNameWord(listStopWord, countStop);
    printFileStop(listStopWord, countStop);
    
    return 0;
}