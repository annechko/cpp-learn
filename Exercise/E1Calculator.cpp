/*
 Exercise 1: You are asked to create a Four-function calculator program. The program will ask the user to enter a number, an operator, and another number. You are asked to use floating point. It should then carry out the arithmetical operation such as: addition, subtraction, multiplication, and division. Use a switch statement to select the operation. Finally, display the result.
Once it finishes the calculation, the program should ask whether the user wants to do another calculation. The response can be ‘y’ or ‘n’.
 */
#include <iostream>
#include <exception>
#include <sstream>

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int divide(int a, int b) {
    if (b == 0) {
        throw new std::exception();
    }
    return a / b;
}

int multiply(int a, int b) {
    return a * b;
}

int calculate() {
    std::string chars;
    std::getline(std::cin, chars);
    int firstNumber;
    int secondNumber;

    std::string firstNumberChars = "";
    std::string secondNumberChars = "";
    char operatorChar = '0';
    for (char c: chars) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (operatorChar == '0') {
                operatorChar = c;
                continue;
            } else {
                throw new std::exception();
            }
        } else {
            if (operatorChar == '0') {
                firstNumberChars += c;
                continue;
            } else {
                secondNumberChars += c;
            }
        }
    }

    if (operatorChar == '0' || firstNumberChars.size() == 0 || secondNumberChars.size() == 0) {
        throw new std::exception();
    }
    int result;
    std::stringstream(firstNumberChars) >> firstNumber;
    std::stringstream(secondNumberChars) >> secondNumber;

    switch (operatorChar) {
        case '+':
            result = sum(firstNumber, secondNumber);
            break;
        case '-':
            result = sub(firstNumber, secondNumber);
            break;
        case '*':
            result = multiply(firstNumber, secondNumber);
            break;
        case '/':
            result = divide(firstNumber, secondNumber);
            break;
    }
    return result;
}

int main() {
    std::string runAgain = "y";
    do {
        std::cout << "Please enter number, operator, number:" << std::endl;

        try {
            int result = calculate();
            std::cout << "Result: " << result << "\n";
        } catch (...) {
            std::cout << "Exception occurred" << std::endl;
        }

        std::cout << "Once more? y or n" << std::endl;
        std::getline(std::cin, runAgain);
    } while (runAgain.size() == 1 && runAgain[0] == 'y');

    return 0;
}