//
// Created by Christian Reiswich on 9/16/24.
//

#include <iostream>
#include <sstream>
#include <string>
#define RESET "\033[0m"
#define GREEN "\033[32m"  //String in Green
#define BLUE "\033[34m"   //Integer in Blue

// maps symbols/characters '0' ... '9' ... 'a' ... 'f' to numbers 0 ... 15
void hexDigitToInt(char hexDigit){
    // TODO '0' ... '9'
    if(hexDigit >= '0' && hexDigit <= '9') {
        int intDigit1 = hexDigit - '0';
        std::cout << BLUE << intDigit1 << RESET << ", ";
    }
    // TODO 'a' ... 'f'
    if(hexDigit >= 'a' && hexDigit <= 'f') {
        int intDigit2 = hexDigit - 'a' + 10;
        std::cout << BLUE << intDigit2 << RESET << ", ";
    }
}

// maps numbers 0 ... 15 to symbols/characters '0' ... '9' ... 'a' ... 'f'
char intToHexDigit(int number){
    std::ostringstream oss;
    oss << std::hex << number;
    std::string result = oss.str();
    std::cout << GREEN << "'" << result << "'" << RESET << ", ";
}

// symbols/characters '0' ... '9' ... 'a' ... 'f' -> 'f' ... 'a' ... '9' ... '0'
std::string reserved(std::string str) {
    for(int i=str.length() -1; i >=0; i--) {
        std::cout << GREEN << str[i] << RESET;
    }
    return "";
}

// print String "100" in each digits -> '1' '0' '0'
std::string printEachDigit(std::string s1) {
    for(int i=0; i <= s1.length(); i++) {
        std::cout << GREEN <<s1[i] << RESET << " ";
    }
    std::cout << std::endl;
    return "";
}

// see https://www.arndt-bruenner.de/mathe/scripts/Zahlensysteme.htm
int hexStringToInt(std::string hexStr){
    int returnValue = 0;
    int base = 1;

    for(int i=hexStr.length() - 1; i >= 0; i--) {
        char c = hexStr[i];
        int value = digittoint(c);

        returnValue += value * base;
        base *= 16;
    }
    return returnValue;
}

// HexString "100" converting to long Integer -> +256
void hexStringtolongInt(const char *hexString) {
    int numInt = (int)strtol(hexString, NULL, 16);
    std::cout << "HexString " << GREEN << hexString << RESET << " converted to long Int is: " << BLUE << numInt << RESET <<
    std::endl;
}

std::string intToHexString(int n){
    char hex_String[20];
    std::cout << "Integer n: " << BLUE << n << RESET << " converted to hexString is: ";
    sprintf(hex_String, "%X", n);
    std::cout << GREEN << hex_String << RESET << std::endl;
    return "";
}

int intToDualString(int decimal) {
    int numberOfBits = sizeof(int) * 8;
    char binary[numberOfBits + 1];

    for(int i=0; i < numberOfBits; i++) {
        if((decimal & (0x80000000 >> i)) == 0) binary[i] = '0';
        else binary[i] = '1';
    }
    binary[numberOfBits] ='\0';
    std::string binarySting(binary);
    std::cout << "Int decimal: " << BLUE << decimal << RESET << " convert to binaryString is: " << GREEN << binarySting
    << RESET << std::endl;
    return 0;
}


int main(/*int argc, char** argv, char** envp*/){
    // TODO hexDigitToInt
    std::cout << "- hexDigitToInt -----------------------------------------------------------------------" << std::endl;
    for(char c='0'; c <= '9'; c++) hexDigitToInt(c);
    for(char x='a'; x <= 'f'; x++) hexDigitToInt(x);
    //println(hexDigitToInt('a' + 10)); = 10
    std::cout << std::endl;

    // TODO intToHexDigit
    std::cout << "- intToHexDigit -----------------------------------------------------------------------" << std::endl;
    for(int i=0; i <= 15; i++) intToHexDigit(i);
    std::cout << std::endl;

    // TODO PascalStrings Reserved
    std::cout << "- Reserved ----------------------------------------------------------------------------" << std::endl;
    std::string myStr = "0123456789abcdef";
    std::cout << "Original: " << GREEN << myStr << RESET << " Resvered: " << reserved(myStr) << std::endl;
    //reserved(pStr);

    // TODO hexStringToInt
    std::cout << "- hexStringToInt ----------------------------------------------------------------------" << std::endl;
    std::string s1 = "100";     // s1 = {3, {'1', '0', '0',}};
    std::string s2 = "fffe";    // s2 = {4, {'f', 'f', 'f', 'e',}};
    std::cout << "s1 = 0x" << GREEN << s1 << RESET << " = " << BLUE << hexStringToInt(s1) << RESET << std::endl;
    std::cout << "s2 = 0x" << GREEN << s2 << RESET << " = " << BLUE << hexStringToInt(s2) << RESET << std::endl;

    // TODO printPascalString
    std::cout << "- printEachDigit ----------------------------------------------------------------------" << std::endl;
    printEachDigit(s1);

    // TODO hexStringtolongInt
    std::cout << "- hexStringToLongInt ------------------------------------------------------------------" << std::endl;
    hexStringtolongInt("123");

    // TODO intToHexString
    std::cout << "- IntToHexString ----------------------------------------------------------------------" << std::endl;
    intToHexString(123);

    // TODO intToDualString
    std::cout << "- IntToDualString ---------------------------------------------------------------------" << std::endl;
    intToDualString(5);

    return 0;
}