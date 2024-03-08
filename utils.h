/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: Header class for utils.cpp, which contains the implementation of the utility functions getCurrentTime and openFile
* Date: <2/24/2024>
*/

#pragma once
#include <string>
#include <fstream>

using namespace std;

void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec);

void openFile(fstream& inFile, string fileName);
