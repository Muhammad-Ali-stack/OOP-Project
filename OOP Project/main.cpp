#include <iostream>
#include <cstdlib>
#include <ctime>
#include "common.h"

using namespace std;

extern void case_1();

int main() {
    srand(time(nullptr));
    int randomNumber = rand() % 2;
    
    if (randomNumber == 0) {
        cout << "Executing Case 1.cpp..." << endl;
        case_1(); // Call the function for case 1
    } else {
        cout << "Executing Case 2.cpp..." << endl;
        // Implement case_2 function call or logic here
    }

    return 0;
}
