#ifndef _STOP_WORD_HEADER_
#define _STOP_WORD_HEADER_

int readFileStop(char listStopWord[10000][20]);
void printFileStop(char listStopWord[10000][20], int stopWord);
int readNameWord(char listStopWord[10000][20], int stopWord);

#endif