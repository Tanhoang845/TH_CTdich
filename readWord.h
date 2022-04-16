#ifndef _READ_WORD_HEADER_
#define _READ_WORD_HEADER_
#include <stdio.h>
typedef struct readWord
{
    char word[10];
    int line[10];
    int countLine;
}ListWord;

// xem tu moi co trong cac tu Stop Word khong, neu co return 1, neu khong return 0
int checkInStopWord(char listStopWord[10000][20], char newWord[10], int countStopWord);
int checkInListWord(ListWord listWord[10000], char newWord[10], int countListWord);
void insertionSort(ListWord listSord[10000], char newWord[10]);
#endif