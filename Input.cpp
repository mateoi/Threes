#include "Input.hpp"

using namespace std;

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
