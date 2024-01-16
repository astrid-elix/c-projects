// Quiz project

#include <stdio.h>

int main()
{
    int a = 0, b = 0;
start:
a=0;
    printf("\tWELCOME TO THE QUIZ :)\n");
    printf("\tHOPE YOU ENJOY :)\n\n");
    printf("Which of the following is an output device?\n1)monitor\t2)mouse\n3)keyboard\t4)mic");
    printf("\nYour answer: ");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        a++;
        break;
    }
    b = 0;
    printf("\nWhich of the following is an input device?\n1)monitor\t2)mouse\n3)printer\t4)speaker");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 2)
        a++;
    b = 0;
    printf("\nWhich of the following is the extension of Notepad?\n1).txt\t2).ppt\n3).py\t4).mp4");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 1)
        a++;
    b = 0;
    printf("\nBIOS is used?\n1)interpreter\t2)application software\n3)compiler\t4)operating system");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 4)
        a++;
    b = 0;
    printf("\nWhat is the mean of the REBooting in the system?\n1)Restarting computer\t2)Install the program\n3)To scan\t4)operating system");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 1)
        a++;
    b = 0;
    printf("\nWhich one of the following groups contains graphical file extensions?\n1)GIF, TCE, WMF\t2)JPG, CPX, GCM\n3)JPG, GIF, BMP\t4)TCP, JPG, BMP");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 3)
        a++;
    b = 0;
    printf("\nWhich of the following is equal to a gigabyte?\n1)1024 bytes\t       2)512 GB\n3)1024 megabytes\t4)1024 bits");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 3)
        a++;
    b = 0;
    printf("\nWhat kind of language can computer understand?\n1)Normal language\t2)Computer language\n3)Assembly language\t4)High-level language");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 3)
        a++;
    b = 0;
    printf("\nWhat is the full form of DRAM?\n1)Dynamic Remote Access Memory\t2)Dependent Remote Access Memory\n3)Dependent Random-Access Memory\t4)Dynamic Random-Access Memory");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 4)
        a++;
    b = 0;
    printf("\nWhat is smallest unit of the information? \n1)A bit \t 2)A byte \n3)A block \t4)A nibble");
    printf("\nYour answer: ");
    scanf("%d", &b);
    if (b == 1)
        a++;
    b = 0;
    printf("\n\n");
    switch (a)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        printf("BETER LUCK NEST TIME :/");

        break;
    case 5:
        printf("OK NOT BAD :|");
        break;
    case 6:
    case 7:
        printf("GOOD :>");
        break;
    case 8:
        printf("VERY GOOD :)");
        break;
    case 9:
    case 10:
        printf(":) EXCELLENT :)");
        break;
    }
    printf("\nYOUR MARKS =%d/10", a);
    printf("\n\n Want a retest press 1 if yes any other key if no ....");
    b = 0;
    scanf("%d", &b);
    if (b == 1)
    {
        goto start;
    }

    return 0;
}