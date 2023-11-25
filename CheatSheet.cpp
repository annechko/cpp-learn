#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
    float price=0;
    int quantity=0;

    std::cout << "Enter price: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> price;
    std::cout << "Enter quantity: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> quantity;
    std::cout << "Total price: " << price*quantity << std::endl;







    return 0;
}
