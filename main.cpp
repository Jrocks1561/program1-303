#include "Header.H"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
//joshaLynn Worth 



int main() {
    const int MAX_ARRAY_SIZE = 100;
    int* array = new int[MAX_ARRAY_SIZE];
    int arrayLength = 0;

    ifstream inputFile("text.txt");
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    int value;
    while (inputFile >> value && arrayLength < MAX_ARRAY_SIZE) {
        array[arrayLength++] = value;
    }

    cout << "Array from file: ";
    printArray(array, arrayLength);

    int userInput;

    cout << "Welcome to project 1!" << endl;

    while (true) {
        cout << endl;
        ///making my main menu
        cout << "Main Menu" << endl;
        cout << "1.) Check if an integer is in the array & if it exists, at what index!" << endl;
        cout << "2.) Modify an integer in an array with an index" << endl;
        cout << "3.) Add an integer to the end of the array" << endl;
        cout << "4.) Remove an element from the array using an index" << endl;
        cout << "5.) Quit (because you are done)" << endl;

        ///validiating user inputs
        try {
            cout << "Enter your choice! :)";
            cin >> userInput;

            if (cin.fail()) {
                throw runtime_error("Invalid input. Please enter a number? obviously not anything else?");
            }

            if (userInput < 1 || userInput > 5) {
                throw runtime_error("Invalid input. Please enter a number between 1 and 5!!!!");
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            continue;
        }
        //goobye user!
        if (userInput == 5) {
            cout << "Exiting the program!! AHHHHH BYYEEE" << endl;
            break;
        }
        //Calls on the functions depending on user choice!
        switch (userInput) {
        case 1: {
            int target;
            cout << "Enter the integer to check :) ";
            cin >> target;
            //make sure that the integer works
            if (cin.fail()) {
                cout << "Invalid input for target integer :(" << endl;
                break;
            }

            findInt(array, target, arrayLength);
            break;
        }
        case 2: {
            int index;
            cout << "Enter the index to modify :)";
            cin >> index;
            
            if (cin.fail()) {
                cout << "Invalid input for index :(" << endl;
                break;
            }

            modifyInt(array, index, arrayLength);
            break;
        }
        case 3: {
            int newValue;
            cout << "Enter the integer to add to the end :)";
            cin >> newValue;

            if (cin.fail()) {
                cout << "Invalid input for new value :(" << endl;
                break;
            }

            addIntToEnd(array, arrayLength, newValue);
            break;
        }
        case 4: {
            int index;
            cout << "Enter the index to remove :) ";
            cin >> index;

            if (cin.fail()) {
                cout << "Invalid input for index :(" << endl;
                break;
            }

            remove(array, arrayLength, index);
            break;
        }
        default:
            cout << "Please enter a number between 1 and 5!!!!" << endl;
            break;
        }
    }

    delete[] array;

    return 0;
}
