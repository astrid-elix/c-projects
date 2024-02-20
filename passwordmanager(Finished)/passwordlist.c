#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int mainpage = 0;

int managerpass()
{
    int restart;
    FILE *managerpass2;
    char prev[10], newpass[10], textpass[10];
    getchar();

    printf("Enter previous Password :");
    scanf("%s", prev);
    for (int i = 0; prev[i] != '\0'; i++)
    {
        prev[i] -= 3;
    }

    managerpass2 = fopen("passmanagerpassword.txt", "r");
    fscanf(managerpass2, "%s", textpass);

    fclose(managerpass2);
    if (strcmp(prev, textpass) == 0)
    {
        printf("Enter a newer Pass :");
        scanf("%s", newpass);
        for (int i = 0; newpass[i] != '\0'; i++)
        {
            newpass[i] -= 3;
        }
        managerpass2 = fopen("passmanagerpassword.txt", "w");
        fprintf(managerpass2, "%s", newpass);
        fclose(managerpass2);
        printf("You want to return to main menu the press 1 or any other to exit\n=>>");
        scanf("%d", &restart);
        if (restart == 1)
        {
            mainpage = 1;
        }
    }
    else
    {
        printf("Wrong Previous Password Exiting the program");
    }
}

int usercreatedpass()
{
    int restart;
    getchar();
    FILE *yourpass;
    char youcreated[100];
    printf("Enter your password to save in current password (you will Over Write previous data):");
    gets(youcreated);
    yourpass = fopen("currentpass.txt", "w");
    for (int i = 0; youcreated[i] != '\0'; i++)
    {
        youcreated[i]-=3;
    }
    fprintf(yourpass,"%s",youcreated);
    fclose(yourpass);
    printf("You want to return to main menu the press 1 or any other to exit\n=>>");
    scanf("%d", &restart);
    if (restart == 1)
    {
        mainpage = 1;
    }
}

int historylist()
{
    int restart;
    FILE *history;
    history = fopen("history.txt", "r");
    for (int i = 0;; i++)
    {
        char see = getc(history);
        if (see == EOF)
        {
            break;
        }
        printf("%c", see);
    }

    fclose(history);
    printf("\nYou want to return to main menu the press 1 or any other to exit\n=>>");
    scanf("%d", &restart);
    if (restart == 1)
    {
        mainpage = 1;
    }
}
char previouspassword()
{
    int restart;
    FILE *previous;
    previous = fopen("previouspass.txt", "r");
    printf("Your previous password set was :\n");
    for (int i = 0;; i++)
    {
        char see;
        see = getc(previous);
        if (see == EOF)
        {
            break;
        }

        printf("%c", see + 3);
    }
    printf("\nYou want to return to main menu the press 1 or any other to exit\n=>>");
    scanf("%d", &restart);
    if (restart == 1)
    {
        mainpage = 1;
    }
}

char currentpassword()
{
    int restart;
    FILE *current;
    printf("Your current Password set is:\n");
    current = fopen("currentpass.txt", "r");
    for (int i = 0;; i++)
    {
        char see;
        see = getc(current);

        if (see == EOF)
        {
            break;
        }

        printf("%c", see + 3);
    }
    fclose(current);
    printf("\nYou want to return to main menu the press 1 or any other to exit\n=>>");
    scanf("%d", &restart);
    if (restart == 1)
    {
        mainpage = 1;
    }
}
void decrypt()
{
    int restart;
    getchar();
    char text[100];
    printf("Text Decryption:\n");
    printf("Enter a text for Decryption:");
    scanf("%[^\n]s", text);
    for (int i = 0; text[i] != '\0'; i++)
    {

        text[i] += 2;
        printf("%c", text[i]);
    }
    printf("\nYou want to return to main menu the press 1 or any other to exit\n=>>");
    scanf("%d", &restart);
    if (restart == 1)
    {
        mainpage = 1;
    }
}

int passgen(int length)
{
    int savepass, remakepass, restart;
    char *passgenerated = (char *)calloc(length, sizeof(char));

    srand(time(NULL));
start:
    printf("Your generated Password :\n");
    for (int i = 0; i < length; i++)
    {

        passgenerated[i] = (rand() % 94) + 33;
    }
    passgenerated[length] = '\0';
    printf("%s", passgenerated);
    printf("\n");

    time_t Time = time(NULL);
    char *timenow = ctime(&Time);
    FILE *currentpass;
    FILE *prevpass;
    FILE *save;
    char see;
    save = fopen("history.txt", "a");
    fprintf(save, "Your password was generated on ==>%s password generated is :%s", timenow, passgenerated);
    fprintf(save, "\n");
    fclose(save);

    printf("Want to save your Password in current password (!!!It will overwrite your previous data)? =>\n");
    printf("1.Yes\n2.No\n==>");
    scanf("%d", &savepass);
    switch (savepass)
    {
    case 1:

        currentpass = fopen("currentpass.txt", "r");
        prevpass = fopen("previouspass.txt", "w");
        for (int i = 0;; i++)
        {
            see = getc(currentpass);
            if (see == EOF)
            {
                break;
            }

            fprintf(prevpass, "%c", see);
        }
        fclose(prevpass);
        currentpass = fopen("currentpass.txt", "w");
        for (int i = 0; i < length; i++)
        {

            fprintf(currentpass, "%c", passgenerated[i] - 3);
        }
        fclose(currentpass);
        free(passgenerated);
        break;
    case 2:

        printf("Want to remake password ?\n");
        printf("1.Yes\n2.No\n==>");
        scanf("%d", &remakepass);
        switch (remakepass)
        {
        case 1:
            goto start;
            break;
        }
        break;
    }
    printf("\nYou want to return to main menu the press 1 or any other to exit\n=>>");
    scanf("%d", &restart);
    if (restart == 1)
    {
        mainpage = 1;
    }
}
int passcheck()
{

    int passfound = 0, restart;
    char yourpass[100], listpass[100];
    FILE *passlist;
    passlist = fopen("list.txt", "r");
    printf("Check if your password comes in top 1000 password list ☠️  : \n");
    printf("Enter the Password : ");
    scanf("%s", yourpass);
    for (int i = 0; i < 1000; i++)
    {
        fscanf(passlist, "%s", listpass);
        if (strcmp(yourpass, listpass) == 0)
        {
            passfound = 1;
            goto end;
        }
    }
end:
    if (passfound == 1)
    {
        printf("Your Password was Found in this List 🗿");
    }
    else
    {
        printf("Your Password was not found in this List 👑");
    }
    printf("\nYou want to return to main menu the press 1 or any other to exit\n=>>");
    scanf("%d", &restart);
    if (restart == 1)
    {
        mainpage = 1;
    }
}

void encrypt()
{
    int restart;
    getchar();
    char text[100];
    printf("Text Encryption:\n");
    printf("Enter a text of Encryption :");
    scanf("%[^\n]s", text);

    for (int i = 0; text[i] != '\0'; i++)
    {

        text[i] -= 2;
        printf("%c", text[i]);
    }
    printf("\nYou want to return to main menu the press 1 or any other to exit\n=>>");
    scanf("%d", &restart);
    if (restart == 1)
    {
        mainpage = 1;
    }
}
int nextpage()
{
    int sel;
start:
    printf("[Second page] :\n");
    printf("7.previous password\n");
    printf("8.Password History\n");
    printf("9.Set Your own current password\n");
    printf("10.Set you Password manager password\n");
    printf("11.Back\n");
      printf("12.Exit\n==>");
    scanf("%d", &sel);
    switch (sel)
    {
    case 7:
        previouspassword();
        break;
    case 8:
        historylist();
        break;
    case 9:
        usercreatedpass();
        break;
    case 10:
        managerpass();
        break;

    case 11:
        mainpage = 1;
        break;
case 12:

break;
    default:
        goto start;
        break;
    }
}

int main()
{

    int sel;
    int lengthpass;
    char passmanagerpass[10], textpass[10];
password:
    printf("Enter Your Password Manager Login Password :");
    scanf("%s", passmanagerpass);
    for (int i = 0; passmanagerpass[i] != '\0'; i++)
    {
        passmanagerpass[i] -= 3;
    }

    FILE *managerpass;
    managerpass = fopen("passmanagerpassword.txt", "r");
    fscanf(managerpass, "%s", textpass);

    fclose(managerpass);
    if (strcmp(passmanagerpass, textpass) == 0)
    {
        goto start;
    }
    else
    {
        goto password;
    }

start:
    mainpage = 0;
    printf("------Password Manager------\n");
    printf("[First page] :\n");
    printf("Select an option :\n");
    printf("1.Generate a Password\n");
    printf("2.Encrypt a text\n");
    printf("3.Decrypt a text\n");
    printf("4.Check password in 1000 Password list\n");
    printf("5.Your Current password\n");
    printf("6.nextpage\n=>>");
    scanf("%d", &sel);
    switch (sel)
    {
    case 1:

    gen:

        printf("select Password length for Generation : \n");
        printf("1. 8 Length Password\n");
        printf("2. 12 Length Password\n");
        printf("3. 16 Length Password\n");
        printf("4. Go Back\n");
        scanf("%d", &lengthpass);
        switch (lengthpass)
        {
        case 1:

            passgen(8);
            break;

        case 2:
            passgen(12);
            break;

        case 3:
            passgen(16);
            break;
        case 4:
            goto start;
            break;

        default:

            goto gen;
            break;
        }
        break;
    case 2:
    {
        encrypt();
    }
    break;
    case 3:
    {
        decrypt();
    }
    break;
    case 4:
        passcheck();
        break;
    case 5:
        currentpassword();
        break;
    case 6:
        nextpage();
        break;
    default:
        goto start;
        break;
    }
    if (mainpage == 1)
    {
        goto start;
    }

    return 0;
}