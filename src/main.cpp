#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>   
#include "Loan.h"

using namespace std;

int main() {
    long double loan_amount = 0, interest_rate = 0, number_of_years = 0;
    long double total_amount, monthly_amount;

    // ---- Load defaults from config.txt ----
    long double defLoan = 0, defRate = 0, defYears = 0;
    ifstream config("config.txt");
    if (config) {
        config >> defLoan >> defRate >> defYears;
        config.close();
    }

    string input;

    // --------- Loan amount input ---------
    while (true) {
        cout << "Enter loan amount";
        if (defLoan > 0) cout << " (press ENTER for " << defLoan << ")";
        cout << ": ";

        getline(cin, input);

        if (input.empty() && defLoan > 0) {
            loan_amount = defLoan;
            cout << "Using default loan amount: " << loan_amount << endl;
        } else {
            loan_amount = atof(input.c_str());
        }

        if (loan_amount > 0) break;
        cout << "Error: Loan amount must be positive!" << endl;
    }

    // --------- Interest rate input ---------
    while (true) {
        cout << "Enter interest rate";
        if (defRate > 0) cout << " (press ENTER for " << defRate << ")";
        cout << ": ";

        getline(cin, input);

        if (input.empty() && defRate > 0) {
            interest_rate = defRate;
            cout << "Using default interest rate: " << interest_rate << "%" << endl;
        } else {
            interest_rate = atof(input.c_str());
        }

        if (interest_rate > 0) break;
        cout << "Error: Interest rate must be positive!" << endl;
    }

    // --------- Number of years input ---------
    while (true) {
        cout << "Enter number of years";
        if (defYears > 0) cout << " (press ENTER for " << defYears << ")";
        cout << ": ";

        getline(cin, input);

        if (input.empty() && defYears > 0) {
            number_of_years = defYears;
            cout << "Using default number of years: " << number_of_years << endl;
        } else {
            number_of_years = atof(input.c_str());
        }

        if (number_of_years > 0) break;
        cout << "Error: Tenure must be at least 1 year!" << endl;
    }

    // --------- Create Loan object and calculate ---------
    Loan loan(loan_amount, interest_rate, number_of_years);

    cout << "\n--- Loan Summary ---\n";
    cout << "Total amount to be paid: " << loan.calculateTotalAmount() << endl;
    cout << "Total interest: " << loan.calculateInterest() << endl;
    cout << "Monthly amount to be paid: " << loan.calculateMonthlyPayment() << endl;

    return 0;
}

