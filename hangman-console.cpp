#include <stdio.h>

struct game{
    char word[20];
    char tips[26];
    int round;
    char pName[10];
}game;

int main(){
    printf("Loading...");
    printf("Loaded!");
    return 0;
}
