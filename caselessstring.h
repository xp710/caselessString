/*
 * caselessString: A way to make and compare strings unrestricted by case.
 *
 * Original author: XP710
 * Copyright 2020 GPLv3.0
 */
//TODO: Commas don't work. There are probably other characters that don't work.

#ifndef CASELESSSTRING_H
#define CASELESSSTRING_H

#include <string>
#include <vector>
#include <iostream>

//lists for making things caseless. Outside of the class so that they aren't declared in every object. OPTIMIZATION, BABY!!
const std::vector<char> lcAlphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                                'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const std::vector<char> ucAlphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

class caselessString
{
private:
    //The caseless string itself
    //It's a vector of vectors because each letter is a vector of two letters, one uppercase, one lowercase
    std::vector<std::vector<char>> clsString;

public:
    //Constructor
    caselessString();
    caselessString(std::string p_clsString);

    //Functions
    void set(std::string p_clsString); //The function for converting a string into a classless string
    char at(int p_at); //Return the lowercase version of the char at p_at
    int size(); //Return the number of CASELESS caracters in clsString.
    friend std::istream &operator>>(std::istream &input, caselessString &p_cls){ //Overloaded cin for inputting to caselessStrings
    std::string temp;
    input >> temp;
    p_cls.set(temp);
    return input;
}
    void printLower(); //Print the lowercase version of the string.
    void printUpper(); //Print the uppercase version of the string.

    //Operators
    bool operator== (caselessString p_cls);
    void operator= (std::string p_clsString);
};

#endif // CASELESSSTRING_H
