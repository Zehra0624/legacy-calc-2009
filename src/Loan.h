/**
 * @class Loan
 * @brief Stores loan details and calculates total, interest and monthly payment.
 */
class Loan {
public:
    long double loan_amount;
    long double interest_rate;
    long double number_of_years;

    /**
     * @brief Constructor to initialize loan values.
     * @param la Loan amount
     * @param ir Interest rate
     * @param ny Number of years
     */
    Loan(long double la = 0, long double ir = 0, long double ny = 0);

    /**
     * @brief Calculates total amount payable (principal + interest)
     * @return long double Total amount to pay
     */
    long double calculateTotalAmount() const;

    /**
     * @brief Calculates monthly payment (EMI)
     * @return long double Monthly installment
     */
    long double calculateMonthlyPayment() const;

    /**
     * @brief Calculates total interest payable
     * @return long double Total interest
     */
    long double calculateInterest() const;
};