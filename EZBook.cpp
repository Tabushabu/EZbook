// EZBook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
# define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

struct Date{
    int month;
    int day;
    int year;
    int oneBed = 100;
    int twoBed = 50;
    int suite = 10;
}date;

void roomPicker(int month, int day, int year);

int main()
{
    // data initialization 
    char startDate[11];
    time_t now = time(0);
    tm* currDate = localtime(&now);

    //take in first user input
    cout << "Version 0.1.1\n" << endl;
    cout << "\nWelcome to EZBook!\nPlease enter a beginning date in mm/dd/yyyy format: ";
    cin >> startDate;

    //parse data
    char* monthc = strtok(startDate, " /");
    char* dayc = strtok(NULL, " /");
    char* yearc = strtok(NULL, " /");

    //convert to ints
    date.month = atoi(monthc);
    date.day = atoi(dayc);
    date.year = atoi(yearc);

    //check for valid date
    if (date.year >= 1900 + currDate->tm_year) {
      
        if ((date.year == 1900 + currDate->tm_year && date.month >= 1 + currDate->tm_mon) || (date.year > 1900 + currDate->tm_year)) {
            
            if ((date.month == 1 + currDate->tm_month && date.day >= currDate->tm_day) || (date.month > currDate->tm_month)){
                roomPicker(date.month, date.day, date.year);
            }
            else {
                cerr << "Error, this date has passed" << endl;
                return 1;
            }
        }
        else {
            cerr << "Error, this date has passed" << endl;
            return 1;
        }
    }
    else {
        cerr << "Error, this date has passed" << endl;
        return 1;
    }
    return 0;
}

//meatball
void roomPicker(int, int, int) {

    int choice;
    int count = 1;

    cout << "Currently there are " << date.oneBed << " single bed rooms available" << endl;
    cout << "Currently there are " << date.twoBed << " two bed rooms available" << endl;
    cout << "Currently there are " << date.suite << " Suites available" << endl;

    cout << "\nplease choose a room for your stay: " << endl;
    cout << "1 for a single room\n2 for a double room\n3 for a suite\n" << endl;
    cin >> choice;

    while (count != 0){
        if (choice == 1) {
            date.oneBed = date.oneBed - 1;
            cout << "\n\nYou have chosen a one bed room\nThank you and enjoy your stay!" << endl;
            count = 0;
        }

        else if (choice == 2) {
            date.twoBed = date.twoBed - 1;
            cout << "\n\nYou have chosen a two bed room\nThank you and enjoy your stay!" << endl;
            count = 0;
        }

        else if (choice == 3) {
            date.suite = date.suite - 1;
            cout << "\n\nYou have chosen a suite\nThank you and enjoy your stay!" << endl;
            count = 0;
        }

        else {
            cerr << "Error please enter either 1, 2, or 3" << endl;
        }

    }
}



