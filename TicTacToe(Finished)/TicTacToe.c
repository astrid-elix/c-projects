#include <stdio.h>

void tictactoe(char tag[])
{

    printf("[%c|%c|%c]\n", tag[0], tag[1], tag[2]);
    printf("[%c|%c|%c]\n", tag[3], tag[4], tag[5]);
    printf("[%c|%c|%c]\n", tag[6], tag[7], tag[8]);
}

char change(char tag[], int sel, int player)
{
    for (int i = 0; i < 9; i++)
    {
        if (sel == tag[i])
        {
            if (player == 1)
            {
                tag[i] = 'x';
            }
            else
            {
                tag[i] = 'y';
            }
        }
    }
}

int number(int num, char *sel)
{
    *sel = 48 + num;
}

int check(int num, char t[])
{

    if (t[num - 1] == 'x' || t[num - 1] == 'y')
    {
        return 1;
    }
}

int gameend(char tag[], int player)
{
    if (tag[0] == tag[1] && tag[0] == tag[2] || tag[3] == tag[4] && tag[3] == tag[5] || tag[6] == tag[7] && tag[6] == tag[8])
    {
        printf("player %d has won :)", player);
        return 1;
    }
    else if (tag[0] == tag[3] && tag[0] == tag[6] || tag[1] == tag[4] && tag[1] == tag[7] || tag[2] == tag[5] && tag[2] == tag[8])
    {
        printf("player %d has won :)", player);
        return 1;
    }
    else if (tag[0] == tag[4] && tag[0] == tag[8] || tag[2] == tag[4] && tag[2] == tag[6])
    {
        printf("player %d has won :)", player);
        return 1;
    }
}

int main()
{
    int  num, num2, player = 1, samenumber,kick=0;
    char tag[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}, sel, sel2, end = 0;

    printf("TIC TAC TOE GAME\n");
    printf("select the number to place your symbol\n");
    printf("there are two player x(player 1),y(player 2)\n");
start:
    printf("[%c|%c|%c]\n", tag[0], tag[1], tag[2]);
    printf("[%c|%c|%c]\n", tag[3], tag[4], tag[5]);
    printf("[%c|%c|%c]\n", tag[6], tag[7], tag[8]);

    for (int i = 1; i < 10; i = i + 2)
    {
        kick=0;

    first:
        samenumber = 0;
      if (kick==5)
      {
        printf("player 2 won and player 1 kicked for too many False attempts");
       goto end;
       
      }
      
        printf("chance of player %d : \n", player);
        scanf("%d", &num);
        if (num > 9)
        {
            printf("select number between 1 to 9\n");
            goto first;
        }

        number(num, &sel);
        samenumber = check(num, tag);
        if (samenumber == 1)
        {
            printf("Already chosen select diffrent option\n");
             kick++;
            goto first;
           
        }
        change(tag, sel, player);
        tictactoe(tag);

        end = gameend(tag, player);
        if (end == 1)
        {
            goto end;
        }

kick=0;

        if (i < 9)
        {
        second:
           if (kick==5)
      {
        printf("player 1 won and player 2 kicked for too many False attempts");
       goto end;
       
      }
            samenumber = 0;
            printf("chance of player %d : \n", player + 1);
            scanf("%d", &num2);
            if (num > 9)
            {
                printf("select number between 1 to 9\n");
                goto second;
            }
            number(num2, &sel2);
            samenumber = check(num2, tag);
            if (samenumber == 1)
            {
                printf("Already chosen select diffrent option\n");
                 kick++;
                goto second;
               
            }

            change(tag, sel2, player + 1);

            tictactoe(tag);

            end = gameend(tag, player + 1);
            if (end == 1)
            {
                goto end;
            }
        }
    }

end:
    if (end == 0)
    {
        printf("Draw");
    }

    return 0;
}