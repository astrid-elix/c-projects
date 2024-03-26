#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#include<conio.h>
int memory()
{
    srand(time(NULL));
int sel,size,choose,end=0;
int *num;
start:
printf("Memory Game :\n");
printf("Select Dificulty:\n");
printf("1.EASY\n");
printf("2.MEDIUM\n");
printf("3.HARD\n");
scanf("%d",&sel);
switch (sel)
{
case 1:
    num=(int*)malloc(5*sizeof(int));
    size=5;
    break;
case 2:
        num=(int*)malloc(10*sizeof(int));
            size=10;
    break;
    case 3:
        num=(int*)malloc(15*sizeof(int));
            size=15;
    break;
default:
goto start;
    break;
}
printf("Remember these Values :\n");
for (int i = 0; i < size; i++)
{
   
   *num=rand()%10;
printf("value %d==> %d\n",i+1,*num);
sleep(2);
num++;
}

system("cls");
printf("Enter value you saw one by one :\n");

for (int i = size; i > 0; i--)
{
 int v=1;
   printf("value %d==>",v); 
   scanf("%d",&choose);
   if (choose!=*(num-i))
   {
    end=1;
  break;
   }
v++;
}

if (end==1)
{
    printf("You Lost Better Luck Next Time :<");
}
else{
      printf("YOU WON :)");
}


}

int rockpaper()
{
    int pscore = 0, cscore = 0;
start:

    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        
    int computer = rand() % 3 + 1, player;

    printf("Select your option :");
    printf("choose : \n1.rock\n2.paper\n3.sicssor\n==>");
    scanf("%d", &player);
    if (player < 4)
    {
        printf("computer choose : ");
        switch (computer)
        {
        case 1:
            printf("Rock\n");
            break;
        case 2:
            printf("Paper\n");
            break;
        case 3:
            printf("sicssor\n");
            break;
        }
    }
   
  if (computer==player)
  {
    printf("Draw \n");
    printf("[score of player is : %d\n]",pscore);
     printf("[score of computer is : %d]\n\n",cscore);
  }
  else if (computer==1&&player==2)
  {
    pscore++;
        printf("[score of player is : %d]\n",pscore);
     printf("[score of computer is : %d]\n\n",cscore);
  }
    else if (computer==2&&player==3)
  {
     pscore++;
        printf("[score of player is : %d]\n",pscore);
     printf("[score of computer is : %d]\n\n",cscore);
  }
    else if (computer==3&&player==1)
  {
     pscore++;
        printf("[score of player is : %d]\n",pscore);
     printf("[score of computer is : %d]\n\n",cscore);
  }
  else
  {
        cscore++;
        printf("[score of player is : %d]\n",pscore);
     printf("[score of computer is : %d]\n\n",cscore);
  }
  
        }
   
if (pscore>cscore)
{
    printf("Player won :)\n");
}
else if (pscore==cscore)
{
   printf("Draw :)");
}

else
{
     printf("Computer won :)\n");
}




}

int main()
{
    int sel;
start:

    printf("---------{Main Menu}---------\n");
    printf("1.rock paper sicssor\n");
    printf("2.memory\n=>>");
    scanf("%d", &sel);
    switch (sel)
    {
    case 1:
        rockpaper();
        break;
    case 2:
memory();
        break;
    default:
        goto start;
        break;
    }


getch();

    return 0;
}