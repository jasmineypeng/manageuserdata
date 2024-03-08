/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This provides the implementation of simple utility functions getCurrentTime and openFile
* Date: <2/24/2024>
*/
#define _CRT_SECURE_NO_WARNINGS // For Visual Studio IDE only

#include <ctime>
#include "utils.h"

using namespace std;

/**
* Function Name: <getCurrentTime>
* Purpose: <Returns the system time>
* Parameter: <int& mo, int& d, int& yr, int& hr, int& min, int& sec>
* Return: <void>
*/
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec) {
    time_t t = time(0);    // get time now
    tm* now = localtime(&t);

    mo = now->tm_mon + 1;
    d = now->tm_mday;
    yr = now->tm_year + 1900;

    hr = now->tm_hour;
    min = now->tm_min;
    sec = now->tm_sec;
}

/**
 * Function Name: <openFile>
 * Purpose: <Opens the csv file>
 * Parameter: <fstream& inFile, string fileName>
 * Return: <void>
*/
void openFile(fstream& inFile, string fileName) {
    inFile.open(fileName);
}
