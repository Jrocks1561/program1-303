#include "Header.H"
#include <iostream>

using namespace std;
//This prints the array (wasn't required but I figured it made more sense for the user to be able to see)
void printArray(const int array[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << array[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
}
//If the target (user input) is found in the array it lets us know where and if not also lets us know!
int findInt(const int array[], int target, int length) {
    for (int i = 0; i < length; ++i) {
        if (array[i] == target) {
            cout << "The integer " << target << " is at index " << i << endl;
            return i;
        }
    }

    cout << "The integer " << target << " is not in the array." << endl;
    return -1;
}
// uses index to find a value to update
void modifyInt(int array[], int index, int length) {
    //validating that the index is even valid!
    if (index < 0 || index >= length) {
        cout << "Invalid index :(" << endl;
        return;
    }
    int oldValue = array[index];
    int newValue;

    cout << "Enter the new value: ";
    cin >> newValue;

    if (cin.fail()) {
        cout << "Invalid input for new value :((((" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    array[index] = newValue;

    cout << "Old value: " << oldValue << endl;
    printArray(array, length);
}
//Problem i had with this function was adding to the end because I had a max length of 100 set so here is how it works now tno fix that!
void addIntToEnd(int*& array, int& length, int value) {
    int newLength = length + 1;

    // Check if dynamic memory allocation is needed
    if (newLength > length) {
        int* newArray = new int[newLength];

        // Copy elements from the original array to the new array
        for (int i = 0; i < length; ++i) {
            newArray[i] = array[i];
        }

        // Add the new value to the end of the new array
        newArray[length] = value;
        delete[] array; // Free the memory of the original array
        array = newArray;
        length = newLength;

        cout << "Integer added to the end of the array." << endl;
        printArray(array, length);
    }
    else {
        cout << " Not letting add to the end ?? :(" << endl;
    }
}
void remove(int array[], int& length, int index) {
    if (index >= 0 && index < length) {
        for (int i = index; i < length - 1; ++i) {
            array[i] = array[i + 1];
        }
        --length;

        cout << "Element removed from the array!!! YAYY" << endl;
        printArray(array, length);
    }
    else {
        cout << "Invalid index for removal :(" << endl;
    }
}