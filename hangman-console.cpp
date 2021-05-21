/* Hangman by Max Hipp in 2021
*  Have fun!
*/
#include <stdio.h>

struct game{
    int mode = 0;
    bool running = false;
    char word[20];
    int wordsize = 0;
    char tips[26];
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

bool initializeGame(){
    requestMode();
    for(int i = 0; i < sizeof(game.word); i++){
        if(game.word[i] != NULL){
            game.wordsize++;
            printf(" _ ");
        }
    }
    printf(" %i\n", game.wordsize);
    game.running = true;
}

void rungame(){

}

int main(){
    printf("Loading...\n");
    printf("Loaded!\n");
    initializeGame();
    while(game.running){

    }
    return 0;
}
