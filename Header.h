#pragma once
#include <iostream>

void printArray(const int array[], int length);
int findInt(const int array[], int target, int length);
void modifyInt(int array[], int index, int length);
void addIntToEnd(int*& array, int& length, int value);
void remove(int array[], int& length, int index);