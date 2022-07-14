/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <time.h>

/*
 * January 1st 1900 was a monday
 */

//int weekDay;

struct tm originDate;
struct tm targetDate;

int *day = &targetDate.tm_mday;
int *month = &targetDate.tm_mon;
int *year = &targetDate.tm_year;

int *startDay = &originDate.tm_mday;
int *startMonth = &originDate.tm_mon;
int *startYear = &originDate.tm_year;

/*enum weekDay {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};*/

int getDayOfYear() {
    int dayOfYear = 0;
    
    switch (*month) {
        case 12:
            dayOfYear += 334;
            break;
        case 11:
            dayOfYear += 304;
            break;
        case 10:
            dayOfYear += 273;
            break;
        case 9:
            dayOfYear += 243;
            break;
        case 8:
            dayOfYear += 212;
            break;
        case 7:
            dayOfYear += 181;
            break;
        case 6:
            dayOfYear += 151;
            break;
        case 5:
            dayOfYear += 120;
            break;
        case 4:
            dayOfYear += 90;
            break;
        case 3:
            dayOfYear += 59;
            break;
        case 2:
            dayOfYear += 31;
            break;
        case 1:
            dayOfYear = 0;
            break;
    dayOfYear += *day;
    return dayOfYear;
    }
}

int getDaysSinceOrigin() {
    int daysSince = getDayOfYear();
    int yearsSince = *year - *startYear;
    
    if ((*month == 2 && *day > 28) || *month > 2) {
        if (yearsSince % 4 == 0) {
            daysSince++;
        }
    }
    
    daysSince += 365 * yearsSince;
    return daysSince;
    
}

int getLeapYears() {
    
}


void main () {
    originDate.tm_mday = 1;
    originDate.tm_mon = 1;
    originDate.tm_year = 1900;
    
    printf("--------------------------\n");
    printf("Day of the Week Calculator\n");
    printf("--------------------------\n\n");
    printf("Please enter a date (DD-MM-YYYY):");
    
    scanf("%2d/%2d/%4d", day, month, year);
    
    //DEBUG
    printf("Target Date: %d/%d/%d\n", *day, *month, *year);
    printf("Origin Date: %d/%d/%d\n", *startDay, *startMonth, *startYear);

    printf("Day of Year: %d\n", getDayOfYear());
    printf("Days Since Origin: %d\n", getDaysSinceOrigin());
    
}










