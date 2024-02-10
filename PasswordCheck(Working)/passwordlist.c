#include <stdio.h>
#include <string.h>
int main()
{
    int passfound = 0;
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

    return 0;
}