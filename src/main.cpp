#include<iostream>

using namespace std;

int main() {
    double loan_amount,interest_rate,number_of_years,total_amount,monthly_amount;
    
	//Big Fix 1: Valdating Inputs to prevent negative or invalid loan amounts
    do {
      cout << "Enter the loan amount: ";
      cin >> loan_amount;
      if(loan_amount <= 0) {
        cout << "Error: Loan amount must be positive!" << endl;
	  }
    } while(loan_amount <= 0);

    do {
      cout << "Enter the interest rate: ";
      cin >> interest_rate;
      if(interest_rate < 0) {
        cout << "Error: Interest rate cannot be negative!" << endl;
	  }
    } while(interest_rate < 0);

    do {
      cout << "The number of years: ";
      cin >> number_of_years;
      if(number_of_years <= 0) {
        cout << "Error: Tenure must be at least 1 year!" << endl;
	  }
    } while(number_of_years <= 0);

	total_amount=(number_of_years*loan_amount)+(number_of_years*loan_amount*(interest_rate/100.00));
	monthly_amount=total_amount/(number_of_years*12);

	cout<<"Total amount to be paid: "<<total_amount<<endl;
	cout<<"Total interest: "<<total_amount-(number_of_years*loan_amount)<<endl;
	cout<<"Monthly amount to be paid: "<<monthly_amount<<endl;

	return 0;
}