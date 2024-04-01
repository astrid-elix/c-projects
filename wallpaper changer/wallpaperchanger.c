#include <stdio.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
char displaywallpaper();
char setwallpaper();
void restart1()
{

system("shutdown /r /t 0");

}
void pageone()
{
    int select;
int restart=0 ;
system("cls");
    printf("This is Wallpaper Changer :\n");
    printf("1.Display wallpaper\n");
    printf("2.Set Wallpaper\n");
    printf("3.Restart\n==>>");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        displaywallpaper();
        break;
    case 2:
setwallpaper();
        break;

    case 3:
printf("Want to restart then press 1");
scanf("%d",&restart);
if (restart==1)
{
  restart1();
}

        break;

    default:
        pageone();
        break;
    }
}

int main()
{
    pageone();
    return 0;
}

char displaywallpaper()
{

    system("cls");
        int select;
        char dir[1024];
        char wallpaper[100];
        _getcwd(dir, 1024);
        strcat(dir, "\\wallpapers");
        _chdir(dir);

        printf("wallaper you want to see :\n");
        printf("1.cinnamoroll\n");
        printf("2.demonslayer\n");
        printf("3.drstone\n");
        printf("4.inuyasha\n");
        printf("5.Japan\n");
        printf("6.Jujutsu Kaisen\n");
        printf("7.landscape\n");
        printf("8.naruto\n");
        printf("9.rengoku\n");
        printf("10.Wallpaper1\n");
        printf("11.back\n==>");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            strcpy(wallpaper, "cinnamoroll.jpg");
            break;
        case 2:
            strcpy(wallpaper, "\"demonslayer.jpeg\"");
            break;
        case 3:
            strcpy(wallpaper, "\"drstone.jpg\"");
            break;
        case 4:
            strcpy(wallpaper, "\"inuyasha.jpg\"");
            break;

        case 5:
            strcpy(wallpaper, "\"japan.jpg\"");
            break;
        case 6:
            strcpy(wallpaper, "\"Jujutsu Kaisen.jpeg\"");
            break;
        case 7:
            strcpy(wallpaper, "\"landscape.jpg\"");
            break;
        case 8:
            strcpy(wallpaper, "\"naruto.jpg\"");
            break;
        case 9:
            strcpy(wallpaper, "\"rengoku.jpg\"");
            break;
        case 10:
            strcpy(wallpaper, "\"wallpaper1.jpeg\"");
            break;
        case 11:
            pageone();
            break;
        default:
            displaywallpaper();
            break;
        }
        system(wallpaper);
        displaywallpaper();
    
}


char setwallpaper()
{
       system("cls");
int select;
int restart=0;
char wallpaper[100];
  char dir[1024];
   _getcwd(dir, 1024);
        strcat(dir, "\\wallpapers");
        _chdir(dir);
     
FILE *change;
 
change=fopen("change.bat","w");


  printf("wallaper you want to set :\n");
        printf("1.cinnamoroll\n");
        printf("2.demonslayer\n");
        printf("3.drstone\n");
        printf("4.inuyasha\n");
        printf("5.Japan\n");
        printf("6.Jujutsu Kaisen\n");
        printf("7.landscape\n");
        printf("8.naruto\n");
        printf("9.rengoku\n");
        printf("10.Wallpaper1\n");
        printf("11.back\n==>");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            strcpy(wallpaper, "\\cinnamoroll.jpg");
            break;
        case 2:
            strcpy(wallpaper, "\\demonslayer.png");
            break;
        case 3:
            strcpy(wallpaper, "\\drstone.jpg");
            break;
        case 4:
            strcpy(wallpaper, "\\inuyasha.jpg");
            break;

        case 5:
            strcpy(wallpaper, "\\japan.jpg");
            break;
        case 6:
            strcpy(wallpaper, "\\Jujutsu Kaisen.jpeg");
            break;
        case 7:
            strcpy(wallpaper, "\\landscape.jpg");
            break;
        case 8:
            strcpy(wallpaper, "\\naruto.jpg");
            break;
        case 9:
            strcpy(wallpaper, "\\rengoku.jpg");
            break;
        case 10:
            strcpy(wallpaper, "\\wallpaper1.jpeg");
            break;
        case 11:
            pageone();
            break;
        default:
            displaywallpaper();
            break;
        }

fprintf(change,"reg add \"HKEY_CURRENT_USER\\Control Panel\\Desktop\" /v Wallpaper /t REG_SZ /d \"%s%s\" ",dir,wallpaper);


fclose(change);
system("change.bat");
printf("Want to restart then press 1\n=>>");
scanf("%d",&restart);
if (restart==1)
{
  restart1();
}

}
