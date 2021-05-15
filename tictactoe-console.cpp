/* TicTacToe by Max Hipp in 2021
*  Have fun!
*/

#include <stdio.h>
//#include <iostream> //geht aus bisher unerfindlichen Gründen bei mir nicht
//using namespace std;

struct game
{
    int n = 1;
    int gamemat[3][3];
    char cNameA[10];
    char cNameB[10];
    int iNum;
    bool running = false;
    int num = 0;
    int round = 1;
} game;

bool initializeGame()
{
    game.running = true;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            game.gamemat[i][j] = 0;
        }
    }
    printf("Please enter a name for player X (max. 10 characters): ");
    scanf("%s",game.cNameA);
    printf("Please enter a name for player O (max. 10 characters): ");
    scanf("%s",game.cNameB);
    printf(game.cNameA);
    printf(" vs ");
    printf(game.cNameB);
    return true;
}

void updateScreen()
{
    printf("\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(game.gamemat[i][j] == 1)
            {
                printf(" X ");
            }
            else if(game.gamemat[i][j] == 4)
            {
                printf(" O ");
            }
            else
            {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

void calcmat(int z)
{
    int x = z/10;
    int y = z%10;
    printf("%i %i", x, y);
    game.gamemat[x-1][y-1] = game.n;
}

//quick and dirty, maybe change to a better looking function...
void checkresults()
{
    int x;
    for(int i = 0; i < 3; i++)
    {
        x = 0;
        for(int j = 0; j < 3; j++)
        {
            x = x + game.gamemat[i][j];
        }
        if(x == 3)
        {
            printf("%s won!\n", game.cNameA);
            game.running = false;
            return;
        }
        else if(x == 12)
        {
            printf("%s won!\n", game.cNameB);
            game.running = false;
            return;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        x = 0;
        for(int j = 0; j < 3; j++)
        {
            x = x + game.gamemat[j][i];
        }
        if(x == 3)
        {
            printf("%s won!\n", game.cNameA);
            game.running = false;
            return;
        }
        else if(x == 12)
        {
            printf("%s won!\n", game.cNameB);
            game.running = false;
            return;
        }
    }
    x = 0;
    for(int i = 0; i < 3; i++)
    {
        x = x + game.gamemat[i][i];
    }
    if(x == 3)
    {
        printf("%s won!", game.cNameA);
        game.running = false;
        return;
    }
    else if(x == 12)
    {
        printf("%s won!\n", game.cNameB);
        game.running = false;
        return;
    }
    x = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 2; j >= 0; j--)
        {
            x = x + game.gamemat[i][j];
        }
    }
    if(x == 3)
    {
        printf("%s won!\n", game.cNameA);
        game.running = false;
        return;
    }
    else if(x == 12)
    {
        printf("%s won!\n", game.cNameB);
        game.running = false;
        return;
    }
    if(game.round == 9){
        printf("Tie! Nobody has won...\n");
        game.running = false;
        return;
    }else{
        game.round = game.round + 1;
        return;
    }
}

void rungame()
{
    if(game.n == 1)
    {
        printf("%s ist an der Reihe: ",game.cNameA);
        scanf("%u",&game.iNum);
        printf("Es wurde %i eingegeben.\n",game.iNum);
        calcmat(game.iNum);
        game.n = 4;
    }
    else
    {
        printf("%s ist an der Reihe: ",game.cNameB);
        scanf("%u",&game.iNum);
        printf("Es wurde %i eingegeben.\n",game.iNum);
        calcmat(game.iNum);
        game.n = 1;
    }
    updateScreen();
    checkresults();
}

int main()
{
    printf("Loading...\n");
    if (initializeGame())
    {
        updateScreen();
        printf("Game initialized!\n");
        while (game.running)
        {
            rungame();
        }
        printf("Stopped.");
    }
    else
    {
        printf("Error");
    }
    while (true){

    }
    //cin.ignore();
    //cin.get();
    return 0;
}
