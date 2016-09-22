#include "Input.hpp"

using namespace std;

/**
 * Asks the user to input a number between min and max.
 */
int userInput(int min, int max) {
    int result = min - 1;
    string input;
    while (getline(cin, input)) {
        if (stringstream(input) >> result) {
            if (result >= min && result <= max)
                break;
        } 
        cout << "Please enter a number between " << min << " and " << max << "." << endl;
    }
    return result;
}

vector<int>* userMultiInput(int min, int max) {
    vector<int>* result = new vector<int>();
    string input;
    while (getline(cin, input)) {
        result->clear();
        stringstream stream(input);
        string section;
        int item = min - 1;
        bool done = false;
        while (getline(stream, section, ' ')) {
            if (stringstream(section) >> item) {
                if (item >= min && item <= max) {
                    result->push_back(item);
                    done = true;
                    continue;
                }
            }
            done = false;
            break;
        }
        if (done) {
            break;
        } else {
            cout << "Please enter numbers between " << min << " and " << max << "." << endl;
        }
    }
    return result;
}

/* Pause the program and wait for input */
void pauseProgram() {
    cin.get();
}

