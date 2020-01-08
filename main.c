#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char tic[9] = {'1','2','3',
                '4','5','6',
                '7','8','9'};

char p1[20],p2[20];

int combinationCount=0,playerCheck=1;

int cross[9],zero[9];
int winner;

int main()
{
    printf("\n\n TIC TAC TOE");
    printf("\n\n");
    printf("** Player 1 plays for 'X' and Player 2 plays for 'O'\n\n");

    playerName();

    board(0,0);
    return 0;
}

void playerName()
{
    printf("\n\n Enter name of player 1 : ");
    scanf("%s",p1);
    printf("\n\n Enter name of player 2 : ");
    scanf("%s",p2);

    if(strcasecmp(p1,p2)==0)
    {
        printf("\n\n **Select different names for Player-1 and Player-2** \n\n");
        playerName();
    }
}

void board(int p,int n)
{
    int i,j,a=0,x;

    // n=1 for 'X'
    // n=2 for 'O'

    if(n==1)
        tic[p]='X';
    else if(n==2)
        tic[p]='O';
    else
        printf("\n");

    printf("\t\t\t\t _________________\n");  //Upper border of the board
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            // Draw the board
            printf("\t\t\t\t|     |     |     |\n");
            printf("\t\t\t\t|  %c  |  %c  |  %c  |\n",tic[a],tic[a+1],tic[a+2]);
            printf("\t\t\t\t|_____|_____|_____|\n");
            a=a+3;
        }
    }

    win();      //Check the winner

    if(combinationCount>=9) //If all combinations are tried.
    {
        stop(100);
    }
    else
    {

        if(playerCheck%2==0)
        {
            play2();
        }
        else
        {
            //printf("\n\n\n **** Player 1 selects 'X' and Player 2 selects 'O' ****\n\n\n");
            play1();
        }

    }
}


void play1()
{
    int x;
    printf("\n '%s' enter your choice - ",p1);
    scanf("%d",&x);

    //To check if input is between 0-9
    if(x<1||x>9)
    {
        printf("\n\n Invalid input. Try again\n\n");
        play1();
    }

    //Check if 'O' already exists on the selected position
    if(tic[x-1]=='O')
    {
        printf("\n\n **Illegal turn, try again**\n\n");
        play1();
    }

    //Check if 'X' does NOT exist on the selected position
    if(tic[x-1]!='X')
    {
        printf("\n\n");
        combinationCount++;
        playerCheck++;

        board(x-1,1);
    }
    else
    {
        printf("\n\n **Illegal turn, try again**\n\n");
        play1();
    }

}


void play2()
{
    int x;

    printf("\n '%s' enter your choice - ",p2);
    scanf("%d",&x);

    //To check if input is between 0-9
    if(x<1||x>9)
    {
        printf("\n\n Invalid input. Try again\n\n");
        play1();
    }

    // Check if 'X' already exists on the selected position
    if(tic[x-1]=='X')
    {
        printf("\n\n **Illegal turn, try again**\n\n");
        play2();
    }

    //Check if 'O' does NOT on selected position
    if(tic[x-1]!='O')
    {
        printf("\n\n");
        combinationCount++;
        playerCheck++;

        board(x-1,2);    //pass updated values to the board function
    }
    else
    {
        printf("\n\n **Illegal turn, try again**\n\n");
        play2();
    }

}

//Check conditions for winning the game (8 conditions)
void win()
{
    int i;
    for(i=0;i<9;i++)
    {
        switch(i)
        {
            case 0: if(tic[i]==tic[1]&&tic[i]==tic[2])  //Fist row
                    {
                        if(tic[i]=='X') //if all are 'X'
                            winner=1;
                        else
                            winner=2;
                        stop(winner); //Call winner and pass the winner integer
                    }
                    break;

            case 1: if(tic[i]==tic[4]&&tic[i]==tic[7])  //Second Column
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 2: if(tic[i]==tic[5]&&tic[i]==tic[8])  //Third Column
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 3: if(tic[i]==tic[0]&&tic[i]==tic[6])  //First column
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 4: if(tic[i]==tic[6]&&tic[i]==tic[2])  //Right to left diagonal
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 5: if(tic[i]==tic[4]&&tic[i]==tic[3])  //Second row
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 6: if(tic[i]==tic[7]&&tic[i]==tic[8])  //Third row
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 8: if(tic[i]==tic[4]&&tic[i]==tic[0])  //Right to Left diagonal
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;
        }
    }
}

void stop(int winner)
{
    if(winner==100)
    {
        printf("\n\n\n Match Drawn\n\n\n");
        exit(0);
    }
    else
    {
        printf("\n\n\n WINNER WINNER CHICKEN DINNER \n\n");

        if(winner==1)
            printf(" %s wins !\n\n\n",p1);
        else
            printf(" %s wins !\n\n\n",p2);
        exit(0);
    }
}
