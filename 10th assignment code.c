#include <stdio.h>
#include <time.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int getFirstDayOfMonth(int year, int month) {
    struct tm time_in;

    time_in.tm_year = year - 1900;
    time_in.tm_mon = month;
    time_in.tm_mday = 1;
    time_in.tm_hour = 0;
    time_in.tm_min = 0;
    time_in.tm_sec = 0;
    time_in.tm_isdst = -1;

    mktime(&time_in);
    return time_in.tm_wday;
}

int main() {
    int year, month, day, startDay, space;

    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter the year: ");
    scanf("%d", &year);

    if (isLeapYear(year) == 1) {
        daysInMonth[1] = 29;
    }

    printf("\nCalendar for %d\n", year);

    for (month = 0; month < 12; month++) {
        printf("\n--- %s ---\n", months[month]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        startDay = getFirstDayOfMonth(year, month);

        for (space = 0; space < startDay; space++) {
            printf("     ");
        }

        for (day = 1; day <= daysInMonth[month]; day++) {
            printf("%5d", day);

            if ((day + startDay) % 7 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}