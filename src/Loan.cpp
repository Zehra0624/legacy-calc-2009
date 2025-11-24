#include "Loan.h"

// Constructor
Loan::Loan(long double la, long double ir, long double ny) {
    loan_amount = la;
    interest_rate = ir;
    number_of_years = ny;
}

// Total amount to be paid (principal + interest)
long double Loan::calculateTotalAmount() const {
    long double interest = loan_amount * (interest_rate / 100.0L) * number_of_years;
    return loan_amount * number_of_years + interest;
}

// Total interest
long double Loan::calculateInterest() const {
    long double interest = loan_amount * (interest_rate / 100.0L) * number_of_years;
    return interest;
}

// Monthly amount
long double Loan::calculateMonthlyPayment() const {
    long double total = calculateTotalAmount();
    return total / (number_of_years * 12);
}
