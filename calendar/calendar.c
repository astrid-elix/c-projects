#include <stdio.h>
struct week
{
    char weekd[5];
} weekkd[7] = {{"Su"}, {"Mo"}, {"Tu"}, {"We"}, {"Th"}, {"Fr"}, {"Sa"}};

struct calendar
{

    char month[20];
    int monthcode;
};

int main()
{
    struct calendar totalmonths[12] = {{"Jan", 1}, {"Feb", 4}, {"March", 4}, {"April", 0}, {"May", 2}, {"June", 5}, {"July", 0}, {"Aug", 3}, {"Sep", 6}, {"Oct", 1}, {"Nov", 4}, {"Dec", 6}};

    int year, y = 0, c = 1, len = 0, firstday, weekday, k = 1;

    printf("Enter Year :");
    scanf("%d", &year);
    if (year % 4 == 0)
    {

        totalmonths[0].monthcode = 0;
        totalmonths[1].monthcode = 3;
    }

    for (int i = year; i > 0; i = i / 10)
    {

        y = i % 10;
        len++;
    }
    for (int i = 0; i < len - 1; i++)
    {
        y *= 10;
    }

    int yearcode = y % 400;
    switch (yearcode)
    {
    case 100:
        yearcode = 4;
        break;
    case 200:
        yearcode = 2;
        break;
    case 300:
        yearcode = 0;
        break;
    case 0:
        yearcode = 6;
        break;
    }

    for (int i = 0; i < 12; i++)
    {
        printf("%s ", totalmonths[i].month);
        printf("\n");

        for (int j = 0; j < 7; j++)
        {
            printf("%s  ", weekkd[j].weekd);
        }
        int monthcode;
        int c = i;
        switch (c)
        {
        case 0:
            monthcode = totalmonths[i].monthcode;
            break;
        case 1:
            monthcode = totalmonths[i].monthcode;
            break;
        case 2:
            monthcode = totalmonths[i].monthcode;
            break;
        case 3:
            monthcode = totalmonths[i].monthcode;
            break;
        case 4:
            monthcode = totalmonths[i].monthcode;
            break;
        case 5:
            monthcode = totalmonths[i].monthcode;
            break;
        case 6:
            monthcode = totalmonths[i].monthcode;
            break;
        case 7:
            monthcode = totalmonths[i].monthcode;
            break;
        case 8:
            monthcode = totalmonths[i].monthcode;
            break;
        case 9:
            monthcode = totalmonths[i].monthcode;
            break;
        case 10:
            monthcode = totalmonths[i].monthcode;
            break;
        case 11:
            monthcode = totalmonths[i].monthcode;
            break;
        }

        weekday = (1 + monthcode + yearcode + (year - y) + ((year - y) / 4)) % 7;

        int days;
        if ((i == 0) || (i == 2) || (i == 4) || (i == 6) || (i == 7) || (i == 9) || (i == 11))
        {
            days = 31;
        }
        else if (i == 1)
        {
            if (year % 4 == 0)
            {
                days = 29;
            }
            else
            {
                days = 28;
            }
        }
        else
        {
            days = 30;
        }

        printf("\n");

        switch (weekday)
        {
        case 1:
            firstday = 1;

            break;
        case 2:
            firstday = 2;
            printf("    ");
            break;

        case 3:
            firstday = 3;
            printf("        ");
            break;
        case 4:
            firstday = 4;
            printf("            ");
            break;
        case 5:
            firstday = 5;
            printf("                ");
            break;
        case 6:
            firstday = 6;
            printf("                    ");
            break;
        case 0:
            firstday = 0;
            printf("                        ");
            break;
        }
        int count = 0;
        for (k = 1; k <= days; k++)
        {

            printf("%d  ", k);

            if (k <= 9)
            {
                printf(" ");
            }

            switch (firstday)
            {
            case 2:
                if (k == 6)
                {
                    printf("\n");
                    count -= 6;
                }

                break;
            case 3:
                if (k == 5)
                {
                    printf("\n");
                    count -= 5;
                }

                break;
            case 4:
                if (k == 4)
                {
                    printf("\n");
                    count -= 4;
                }

                break;
            case 5:
                if (k == 3)
                {
                    printf("\n");
                    count -= 3;
                }

                break;
            case 6:
                if (k == 2)
                {
                    printf("\n");
                    count -= 2;
                }

                break;
            case 0:

                if (k == 1)
                {
                    printf("\n");
                    count -= 1;
                }

                break;
            }

            count++;
            if (count == 7)
            {
                printf("\n");

                count = 0;
            }
        }

        printf("\n\n\n");
    }

    return 0;
}