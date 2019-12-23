#include <stdio.h>
#include <stdlib.h>

int win();
int board(int p,int n);
char tic[9] = {'1','2','3','4','5','6','7','8','9'};

void stop(int winner);
int cross[9],zero[9];
int winner;
int main()
{
    printf("\n\n TIC TAC TOE");
    printf("\n\n");
    printf("** Player 1 plays for 'X' and Player 2 plays for 'O'\n\n");
    printf("** If you select wrong or illegal option your turn will be skipped **\n\n");
    board(0,0);
    return 0;
}
int board(int p,int n)
{
    int i,j,a=0,x;
    static int k=0,l=1;

    if(n==1)
        tic[p]='X';
    else if(n==2)
        tic[p]='O';
    else
        printf("\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("\t     |     |    |\n");
            printf("\t  %c  |  %c  |  %c |\n",tic[a],tic[a+1],tic[a+2]);
            printf("\t_____|_____|____|\n");
            a=a+3;
        }
    }

    win();

    if(k>=9)
    {
        stop(100);
    }
    else
    {

        if(l%2==0)
        {
            goto next;
        }
        else
        {
            //printf("\n\n\n **** Player 1 selects 'X' and Player 2 selects 'O' ****\n\n\n");
            printf("\n Player 1 enter your choice - ");
            scanf("%d",&x);

                    if(tic[x-1]=='O')
                    {
                        printf("\n\n Wrong choice, you have missed your turn\n\n");
                        l++;
                    }
                else
                {
                    if(tic[x-1]!='X')
                    {
                        printf("\n\n");
                        k++;l++;
                        board(x-1,1);
                    }
                     else
                    {
                        printf("\n\n You have selected the same option ,your turn is dismissed\n\n");

                    }
                }
            next :
                printf("\n Player 2 enter your choice - ");
                scanf("%d",&x);

                    if(tic[x-1]=='X')
                    {
                        printf("c\n\n Wrong choice, you have missed your turn\n\n");
                        l++;
                        board(x-1,1);
                    }

                else
                {
                    if(tic[x-1]!='O')
                    {
                        printf("\n\n");
                        k++;l++;
                        board(x-1,2);
                    }
                    else
                    {
                        printf("\n\n You have selected the same option ,your turn is dismissed\n\n");
                        board(x-1,2);
                    }
                }
        }

    }
    return 0;
}
int win()
{
    int i;
    for(i=0;i<9;i++)
    {
        switch(i)
        {
            case 0: if(tic[i]==tic[1]&&tic[i]==tic[2])
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 1: if(tic[i]==tic[4]&&tic[i]==tic[7])
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 2: if(tic[i]==tic[5]&&tic[i]==tic[8])
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 3: if(tic[i]==tic[0]&&tic[i]==tic[6])
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 4: if(tic[i]==tic[6]&&tic[i]==tic[2])
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 5: if(tic[i]==tic[4]&&tic[i]==tic[3])
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 6: if(tic[i]==tic[7]&&tic[i]==tic[8])
                    {
                        if(tic[i]=='X')
                            winner=1;
                        else
                            winner=2;
                        stop(winner);
                    }
                    break;

            case 8: if(tic[i]==tic[4]&&tic[i]==tic[0])
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
    return 0;
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
        printf(" Player %d wins !\n\n\n",winner);
        exit(0);
    }
}
