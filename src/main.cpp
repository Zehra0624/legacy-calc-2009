#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>   

using namespace std;

int main() {
    long double loan_amount = 0, interest_rate = 0, number_of_years = 0;
    long double total_amount, monthly_amount; // Bug Fix 2: Safer calculations using long double

    // Bug Fix 4: Load default values from config.txt 
    // The file format is simple: 3 numbers in order: loan_amount interest_rate number_of_years
    long double defLoan = 0, defRate = 0, defYears = 0;
    ifstream config("config.txt");
    if (config) {
        config >> defLoan >> defRate >> defYears;
        config.close();
    }

    string input;

    // Big Fix 1: Loan amount input validation (with default from config)
    while (true) {
        cout << "Enter loan amount";
        if (defLoan > 0) {
            cout << " (press ENTER for " << defLoan << ")";
        }
        cout << ": ";

        getline(cin, input);

        if (input.empty()) { // User pressed ENTER
            if (defLoan > 0) {
                loan_amount = defLoan;
                cout << "Using default loan amount: " << loan_amount << endl;
            } else {
                cout << "No default loan amount in config. Please enter a value.\n";
                continue;
            }
        } else {
            loan_amount = atof(input.c_str()); // Convert string input to number
        }

        if (loan_amount > 0) {
            break; // Valid input, exit loop
        } else {
            cout << "Error: Loan amount must be positive!" << endl;
        }
    }

    // Interest rate input validation (with default from config)
    while (true) {
        cout << "Enter interest rate";
        if (defRate > 0) {
            cout << " (press ENTER for " << defRate << ")";
        }
        cout << ": ";

        getline(cin, input);

        if (input.empty()) {
            if (defRate > 0) {
                interest_rate = defRate;
                cout << "Using default interest rate: " << interest_rate << "%" << endl;
            } else {
                cout << "No default interest rate in config. Please enter a value.\n";
                continue;
            }
        } else {
            interest_rate = atof(input.c_str());
        }

        if (interest_rate > 0) {
            break; // Valid input, exit loop
        } else {
            cout << "Error: Interest rate must be positive!" << endl;
        }
    }

    // Number of years input validation (with default from config)
    while (true) {
        cout << "Enter number of years";
        if (defYears > 0) {
            cout << " (press ENTER for " << defYears << ")";
        }
        cout << ": ";

        getline(cin, input);

        if (input.empty()) {
            if (defYears > 0) {
                number_of_years = defYears;
                cout << "Using default number of years: " << number_of_years << endl;
            } else {
                cout << "No default years in config. Please enter a value.\n";
                continue;
            }
        } else {
            number_of_years = atof(input.c_str());
        }

        if (number_of_years > 0) {
            break; // Valid input, exit loop
        } else {
            cout << "Error: Tenure must be at least 1 year!" << endl;
        }
    }

    // Bug Fix 3: Step-by-step calculations to prevent overflow
    long double principal = loan_amount;
    long double interest = principal * (interest_rate / 100.0L) * number_of_years;
    total_amount = principal * number_of_years + interest;
    monthly_amount = total_amount / (number_of_years * 12);

    cout << "\n--- Loan Summary ---\n";
    cout << "Total amount to be paid: " << total_amount << endl;
    cout << "Total interest: " << interest << endl;
    cout << "Monthly amount to be paid: " << monthly_amount << endl;

    return 0;
}
