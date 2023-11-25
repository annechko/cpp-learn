#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>

int protofunction(int, int);

int main() {
    /******************
     **** Types *******
     *****************/
    // Character types
    char c1;
    char16_t c2;
    char32_t c3;
    wchar_t c4;
    // Integer types (signed)
    signed char its1;
    signed short its2;
    signed int its3;
    signed long int its4;
    signed long long its5;
    // Integer types (unsigned)	unsigned char
    unsigned short int ui1;
    unsigned int ui2;
    unsigned long int ui3;
    unsigned long long int ui4;
    // Floating - point types
    float fp1;
    double fp2;
    long double fp3;
    // Boolean type
    bool b;

    /*************************
     **** initialization *****
     ************************/

    int x = 0;
    int x2(0);
    int x3{0};

    /*************************
    **** Type deduction: auto and decltype *****
    ************************/

    int foo = 0;
    auto bar = foo;
    decltype(foo) bar2;

    /*************************
    **** strings *************
    ************************/

    // include <string>
    // to express a string  - enclose the characters between double quotes
    // string literal - is enclosed in double quotes (")
    std::string multi = "sdfsdf";
    // a single character, we enclose it between single quotes
    char singlechar = 's';
    char specialchar = '\n';

    // concatenated to form a single string literal by separating them by blank spaces, including tabs, newlines, and other valid blank characters.
    std::string conc = "hello " " world"
                       " Hi!";

    std::string online = "hello \
                         world";

    auto uni16 = u'ы';
    auto uni32 = U'ы';
    auto uni2 = L'у';
//    std::cout << (char32_t) uni32;
    auto uniu8 = u8"ырауврвр";

    std::string ex = R"(string with \backslash)";


    /*********************************
    **** Typed constant expressions **
    *********************************/

    const double pi = 3.1415926;
    const char tab = '\t';

    // preprocessor directives
#define PIWITHEND 3.14159;
#define PI 3.14159

    auto withpi = 2 * PI;
    auto withpi2 = 2 * PIWITHEND

    /**********************
    **** Operators ********
    ***********************/

    bool res1 = (7 == 5);
    bool res2 = (7 != 5);
    bool bfalse = true && false;
    bool btrue = true || false;

    // type casting
    int i_for_float;
    float f_to_cast = 3.14;
    i_for_float = (int) f_to_cast;
    int i_2 = int(f_to_cast);

    // the size in bytes of that type or object
    auto sizeof_int = sizeof(int);

    // insertion operator, two "less than" signs
//    std::cout << 1 << std::endl;
    // extraction operator, (i.e., two "greater than" signs)
    int age;
//    std::cin >> age;


    // cin extraction always considers spaces (whitespaces, tabs, new-line...) as terminating
    // the value being extracted
    // extracting a string means to always extract a single word, not a phrase or an entire sentence.
    std::string mystring_one_word;
    std::string mystring_multi_word;
//    std::cin >> mystring_one_word;

//    std::getline(std::cin, mystring_multi_word);
    std::cout << mystring_multi_word;

    // stringstream

// include <sstream>

    std::string mystr;
    float price = 0;
    int quantity = 0;
    if (0) {
        std::cout << "Enter price: ";
        getline(std::cin, mystr);
        std::stringstream(mystr) >> price;
        std::cout << "Enter quantity: ";
        getline(std::cin, mystr);
        std::stringstream(mystr) >> quantity;
        std::cout << "Total price: " << price * quantity << std::endl;
    }

    /**********************
    **** Statements ********
    ***********************/
    int xf = 33;
    if (0) {
        if (xf > 0) {
            std::cout << "x is positive";
        } else if (xf < 0) {
            std::cout << "x is negative";
        } else {
            std::cout << "x is 0";
        }
    }

    if (0) {
        // include <thread>
        int n = 10;
        while (n > 0) {
            std::cout << n << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            --n;
        }
    }

    if (0) {
        std::string str;
        do {
            std::cout << "Enter text: ";
            getline(std::cin, str);
            std::cout << "You entered: " << str << '\n';
        } while (str != "goodbye");
    }

    if (0) {
        for (int n = 10; n > 0; n--) {
            std::cout << n << ", ";
        }
    }
    if (0) {
        std::string str{"Hello!"};
        for (char c: str) {
            std::cout << "[" << c << "]";
        }

        std::cout << '\n';
    }


    if (0) {
        switch (x) {
            case 1:
            case 2:
            case 3:
                std::cout << "x is 1, 2 or 3";
                break;
            default:
                std::cout << "x is not 1, 2 nor 3";
        }
    }

    return EXIT_SUCCESS;
}


int addition(int a, int b = 1) {
    return a + b;
}

int protofunction(int r, int e) {
    return 0;
}

void print_message() {
    std::cout << "I'm a function!";
}

void param_by_ref(std::string &to_print) {
    std::cout << to_print;
}

// the function is forbidden to modify the values of neither a nor b
// but can actually access their values as references (aliases of the arguments)
// without having to make actual copies of the strings
std::string concatenate_without_memory_copy(const std::string &a, const std::string &b) {
    return a + b;
}

// to suggest the compiler that the code generated by the function body shall be inserted
// at each point the function is called, instead of being invoked with a regular function call.
// although the compiler is free to not inline it, and optimize otherwise
inline int some_large_formula_for_readability(const int &a, const int &b) {
    return a + b / 3 * 26 * 17236;
}

// at least one of the declarations is required, because odd and even are mutually called.
void odd(int x);

void even(int x);

void odd(int x) {
    if ((x % 2) != 0) std::cout << "It is odd.\n";
    else even(x);
}

void even(int x) {
    if ((x % 2) == 0) std::cout << "It is even.\n";
    else odd(x);
}

// overloaded functions (i.e., two functions with the same name)
// a function cannot be overloaded only by its return type.
// At least one of its parameters must have a different type.
int operate(int a, int b) {
    return (a * b);
}

double operate(double a, double b) {
    return (a / b);
}

// The function sum could be overloaded for a lot of types,
// and it could make sense for all of them to have the same body
//  For cases such as this, C++ has the ability to define functions with generic types,
//  known as function templates.
template<class SomeType>
SomeType sum(SomeType a, SomeType b) {
    return a + b;
}

int sum_res = sum<int>(10, 20);
int sum_res2 = sum(10, 20);


template<typename T, int N>
T fixed_multiply(T val) {
    return val * N;
}

auto eee = fixed_multiply<int, 2>(10);
