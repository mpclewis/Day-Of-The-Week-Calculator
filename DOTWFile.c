/******************************************************************************

A program that takes any date as input (DD-MM-YYY) and finds what day of the
week it is.

*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "main.h"

/*********************************
 * January 1st 1900 was a monday *
 *********************************/

/*******************
   Global Variables
*******************/

struct tm originDate;
struct tm targetDate;

int *day = &targetDate.tm_mday;
int *month = &targetDate.tm_mon;
int *year = &targetDate.tm_year;

int *startDay = &originDate.tm_mday;
int *startMonth = &originDate.tm_mon;
int *startYear = &originDate.tm_year;

FILE *inputFile;
FILE *outputFile;

/******************
  Global Functions
******************/

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
    }
    dayOfYear += *day;
    
    return dayOfYear;
}

int getDaysSinceOrigin() {
    int daysSince = getDayOfYear();
    int yearsSince = *year - *startYear;
    int leapYears = getLeapYears(yearsSince);
    
    if ((*month == 2 && *day > 28) || *month > 2) {
        if (yearsSince % 4 == 0) {
            daysSince++;
        }
    }
    
    daysSince += 365 * yearsSince;
    daysSince += leapYears;
    return daysSince;
    
}

int getLeapYears(int noYears) {
    int leapYears = noYears / 4;
    return leapYears;
}



/***************
  Main Function
****************/

int main () {
    //Declares weekday variable and array containing days of the week
    int weekDay;
    char fileLine[11];
    char monToSun[][10] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
        
    };
    //Sets origin date
    originDate.tm_mday = 1;
    originDate.tm_mon = 1;
    originDate.tm_year = 1900;
    
    //Opens input/output files
    inputFile = fopen("dates.txt", "r");
    if (inputFile == NULL){
        printf("Input file not found!");
        return (1);
    }
    else {
        printf("Input file succesfully opened!\n");
    }
    outputFile = fopen("days.txt", "a");
    if (outputFile == NULL){
        printf("Failed to open output file!\n");
        return (1);
    }
    else {
        printf("Output file succesfully opened!");
    }
    
    //Reads input file and writes output to file
    do {
        fscanf(inputFile, "%d/%2d/%4d", day, month, year);
        weekDay = getDaysSinceOrigin() % 7;
        fprintf(outputFile, "%d/%d/%d is a %s\n", *day, *month, *year, monToSun[weekDay - 1]);
    }
    while(fgets(fileLine, 11, inputFile) != NULL);
    
    //CLoses files
    fclose(inputFile);
    fclose(outputFile);
    
    
    // DEBUG
    // printf("Target Date: %d/%d/%d\n", *day, *month, *year);
    // printf("Origin Date: %d/%d/%d\n\n", *startDay, *startMonth, *startYear);
    
    // printf("Day of Year: %d\n", getDayOfYear());
    // printf("Days Since Origin: %d\n", getDaysSinceOrigin());
    
    return(0);
    
}










