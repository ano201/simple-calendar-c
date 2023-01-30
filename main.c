#include <stdio.h>

int getFirstDay(int year)
{
    int day = (year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    return day;
}

int main()
{
    char *month[] = {"January", "February", "March", "April", "May", "June", "july", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekDay, year;

    printf("Enter Year: ");
    scanf("%d", &year);
    printf("*************Welcome to %d*************\n\n");

    // check leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        daysInMonth[1] = 29;
    }

    // get first day of the year
    weekDay = getFirstDay(year);

    for (int i = 0; i < 12; i++)
    {
        printf("\n\n\n------------------%s------------------", month[i]);
        printf("\n    Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");

        for (int spaceCounter = 0; spaceCounter < weekDay; spaceCounter++)
        {
            printf("      ");
        }

        for (int j = 1; j <= daysInMonth[i]; j++)
        {
            printf("%6d", j);
            weekDay++;
            if (weekDay > 6)
            {
                weekDay = 0;
                printf("\n");
            }
        }
    }

    return 0;
}