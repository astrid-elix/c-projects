#include <stdio.h>
char encrypt(char msg[])
{

    for (int i = 0; msg[i] != '\0'; i++)
    {
        switch (msg[i])
        {
        case 'a':
            msg[i] = '1';

            break;
        case 'b':
            msg[i] = '2';
            break;
        case 'c':
            msg[i] = '3';
            break;
        case 'x':
            msg[i] = '4';
            break;
        case 'y':
            msg[i] = '5';
            break;
        case 'z':
            msg[i] = '6';
            break;
        case 'd':
            msg[i] = '7';
            break;
        case 'k':
            msg[i] = '8';
            break;
        case 'v':
            msg[i] = '9';
            break;
        case 'u':
            msg[i] = '0';
            break;
        case 'e':
            msg[i] = 'r';
            break;
        case 'f':
            msg[i] = 'S';
            break;
        case 'g':
            msg[i] = 'T';
            break;
        case 'h':
            msg[i] = 'w';
            break;
        case 'i':
            msg[i] = 'n';
            break;
        case 'j':
            msg[i] = 'o';
            break;
        case 'l':
            msg[i] = 'P';
            break;
        case 'q':
            msg[i] = 'm';
            break;
        case 'r':
            msg[i] = 'E';
            break;
        case 's':
            msg[i] = 'f';
            break;
        case 't':
            msg[i] = 'g';
            break;
        case 'w':
            msg[i] = 'H';
            break;
        case 'n':
            msg[i] = 'I';
            break;
        case 'o':
            msg[i] = 'j';
            break;
        case 'p':
            msg[i] = 'l';
            break;
        case 'm':
            msg[i] = 'q';
            break;
        }
    }
    printf("%s", msg);
}
char Decrypt(char msg[])
{
    for (int i = 0; msg[i] != '\0'; i++)
    {
        switch (msg[i])
        {
        case '1':
            msg[i] = 'a';
            break;
        case '2':
            msg[i] = 'b';
            break;
        case '3':
            msg[i] = 'c';
            break;
        case '4':
            msg[i] = 'x';
            break;
        case '5':
            msg[i] = 'y';
            break;
        case '6':
            msg[i] = 'z';
            break;
        case '7':
            msg[i] = 'd';
            break;
        case '8':
            msg[i] = 'k';
            break;
        case '9':
            msg[i] = 'v';
            break;
        case '0':
            msg[i] = 'u';
            break;
        case 'r':
            msg[i] = 'e';
            break;
        case 'S':
            msg[i] = 'f';
            break;
        case 'T':
            msg[i] = 'g';
            break;
        case 'w':
            msg[i] = 'h';
            break;
        case 'n':
            msg[i] = 'i';
            break;
        case 'o':
            msg[i] = 'j';
            break;
        case 'P':
            msg[i] = 'l';
            break;
        case 'm':
            msg[i] = 'q';
            break;
        case 'E':
            msg[i] = 'r';
            break;
        case 'f':
            msg[i] = 's';
            break;
        case 'g':
            msg[i] = 't';
            break;
        case 'H':
            msg[i] = 'w';
            break;
        case 'I':
            msg[i] = 'n';
            break;
        case 'j':
            msg[i] = 'o';
            break;
        case 'l':
            msg[i] = 'p';
            break;
        case 'q':
            msg[i] = 'm';
            break;
        }
    }
    printf("%s", msg);
}

int main()
{
start:
    char msg[100];
    int select;
    printf("This is Ace the Encrypt and Decrypt v-0.1(by Dhruv Kuhite)\n");
sel:
    printf("\nWhat you want to do :\n");
    printf("1.Encrypt\n2.Decrypt\n>>");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        printf("enter msg(no space allowed for now):\n>>> ");
        scanf("%s", msg);
        encrypt(msg);
        break;
    case 2:
        printf("enter encrypted msg to Decrypt:\n>>> ");
        scanf("%s", msg);
        Decrypt(msg);
        break;
    default:
        printf("Enter a valid number!!!");
        goto sel;
        break;
    }
    int sel2;
    printf("\n\nWant to rerun program press 1 if yes ");
    scanf("%d", &sel2);
    switch (sel2)
    {
    case 1:
        goto start;
        break;
    }
    return 0;
}