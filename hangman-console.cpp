/* Hangman by Max Hipp in 2021
*  Have fun!
*/
#include <stdio.h>

struct game{
    int mode = 0;
    bool running = false;
    char word[20];
    char wordtip[20];
    int wordsize = 0;
    char tips[26];
    char tip = 'a';
    int round = 0;
    char pName[10];
}game;

void requestMode(){
    printf("Please choose a mode: (0)Classic (1)Computer: ");
    scanf("%i", &game.mode);
    //printf("\nWort: %s :", game.word);
    printf("Please choose a word (max. 20 characters): ");
    scanf("%s", &game.word);
    //printf("%s", game.word);
}

void initializeGame(){
    requestMode();
    for(int i = 0; i < sizeof(game.word); i++){
        if(game.word[i] != NULL){
            game.wordsize++;
            printf(" _ ");
        }
    }
    printf(" %i\n", game.wordsize);
    game.running = true;
    //return true;
}

void updateScreen(){
    for(int i = 0; i < game.wordsize; i++){
        printf(" _ ");
    }
}

void testTip(){
    printf("%c wurde eingegeben.\n", game.tip);
}

void requestChar(){
    printf("Please enter a character: ");
    scanf("%c\n", &game.tip);
    testTip();
}

void rungame(){
    requestChar();
}

int main(){
    printf("Loading...\n");
    initializeGame();
    printf("Loaded!\n");
    while(game.running){
        rungame();
        updateScreen();
    }
    return 0;
}

