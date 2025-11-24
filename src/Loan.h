#ifndef LOAN_H
#define LOAN_H

class Loan {
public:
    long double loan_amount;
    long double interest_rate;
    long double number_of_years;

    Loan(long double la = 0, long double ir = 0, long double ny = 0);

    long double calculateTotalAmount() const;
    long double calculateMonthlyPayment() const;
    long double calculateInterest() const;
};

#endif
