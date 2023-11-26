/*
Exercise 2: Write a program that calculates how your investment will grow with an ABZ Term Deposit. That is, the program should tell user how much money user will end up with if the user invest an amount of money at a fixed interest rate, compounded yearly. Have the user furnish the initial amount, the number of years, and the yearly interest rate in percent.
Hint: At the end of the first year, you have 3000 + (3000 * 0.055), which is 3165. At the end of the second year, you have 3165 + (3165 * 0.055), which is 3339.08.
 Do this as many times as there are years .
 */
#include <iostream>

int main() {
    float amount;
    float years;
    float rate;
    std::cout << "Initial amount:" << std::endl;
    std::cin >> amount;
    std::cout << "Number of years:" << std::endl;
    std::cin >> years;
    std::cout << "Interest rate:" << std::endl;
    std::cin >> rate;

    rate = rate/100;

    for (int i = 0; i < years; ++i) {
        amount = amount + (amount * 0.055);
    }

    std::cout << "At the end of " << years << " years you will have $" << amount << '.' << std::endl;

    return 0;
}