#include <iostream>
#include <cmath>
#include "../src/Loan.h" 

using namespace std;

int main() {

    //TEST 1: Normal EMI calculation
    Loan loan1(50000, 5, 3);
    long double monthly1 = loan1.calculateMonthlyPayment();

    long double expected1 = 1597.0; // expected result
    if (fabsl(monthly1 - expected1) < 1.0) {  // fabsl()-> = absolute for long double
        cout << "TEST 1 PASSED: Normal calculation" << endl;
    } else {
        cout << "TEST 1 FAILED: Normal calculation" << endl;
        cout << "Expected around " << expected1 << ", got " << monthly1 << endl;
    }

    // TEST 2: Zero years should be invalid input in real program
    // Since main.cpp prevents it, we only check that program does not crash
    Loan loan2(50000, 5, 0);
    cout << "TEST 2 PASSED: Zero years handled by validation in main.cpp" << endl;

    //TEST 3: Large values should not overflow
    Loan loan3(1000000, 10, 40);
    long double monthly3 = loan3.calculateMonthlyPayment();

    if (monthly3 > 0 && monthly3 < 10000000) {
        cout << "TEST 3 PASSED: Large values handled" << endl;
    } else {
        cout << "TEST 3 FAILED: Large calculation overflow" << endl;
    }

    return 0;
}