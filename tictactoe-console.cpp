#include <stdio.h>

struct game{
    int n = 0;
    int gamemat[3][3];
    char cNameA[10];
    char cNameB[10];
    int iNum;
    bool running = false;
    int num = 0;
}game;

bool initializeGame(){
    game.running = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            game.gamemat[i][j] = 0;
        }
    }
    printf("Bitte Namen des ersten Spielers X eingeben: ");
    scanf("%s",game.cNameA);
    printf("Bitte Namen des zweiten Spielers O eingeben: ");
    scanf("%s",game.cNameB);
    printf(game.cNameA);
    printf(" vs ");
    printf(game.cNameB);
    return true;
}

void updateScreen(){
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" - ");
        }
        printf("\n");
    }
    //return 1;
}

bool checkresults(){
    if(game.num == 9){
        printf("false");
        game.running = false;
    }else{
        game.num = game.num++;
    }
    return true;
}

void rungame(){
    if(game.n == 0){
        printf("%s ist an der Reihe: ",game.cNameA);
        scanf("%u",&game.iNum);
        printf("Es wurde %i eingegeben.\n",game.iNum);
        game.n = 1;
    }else{
        printf("%s ist an der Reihe: ",game.cNameB);
        scanf("%u",&game.iNum);
        printf("Es wurde %i eingegeben.\n",game.iNum);
        game.n = 0;
    }
    printf("if finished");
    updateScreen();
    checkresults();
}

int main(){
    printf("Loading...\n");
    if (initializeGame()){
        updateScreen();
        printf("Game initialized!\n");
        while (game.running == true){
            rungame();
        }
        printf("Stopped.");
    }else{
    printf("Error");
    }
    return 0;
}
