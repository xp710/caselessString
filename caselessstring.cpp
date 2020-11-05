#include "caselessstring.h"

//Operators
bool caselessString::operator== (caselessString p_cls){
    //Compares the clsString of each object instead of all the data.

    if (clsString == p_cls.clsString){
        return true;
    }else{
        return false;
    }
}

void caselessString::operator= (std::string p_clsString){
    set(p_clsString);
}

//Constructor
caselessString::caselessString(){
    //Don't do anything if no arguments
}

caselessString::caselessString(std::string p_clsString){
    set(p_clsString);
}

//Functions
void caselessString::set(std::string p_clsString){
    /*
     * To convert the string:
     * Look at each letter of the string.
     * Loop through each list of letters to see if it's equal to either one.
     * If it is, that member of the clsString vector gets that member of both arrays.
     * If it's not equal to anything in either list, just add that as the member of the clsString vector.
     */

    for (int i = 0; i < (int)p_clsString.size(); ++i){
        //Because lowercase letters are more common than uppercase letters,
        //We loop through the lowercase one first.
        for (int j = 0; j < (int)lcAlphabet.size(); ++j){
            if (p_clsString.at(i) == lcAlphabet.at(j)){
                std::vector<char> temp = {lcAlphabet.at(j), ucAlphabet.at(j)};
                clsString.push_back(temp);
            }
        }
        for (int j = 0; j < (int)ucAlphabet.size(); ++j){
            if (p_clsString.at(i) == ucAlphabet.at(j)){
                std::vector<char> temp = {lcAlphabet.at(j), ucAlphabet.at(j)};
                clsString.push_back(temp);
            }
        }

        //If the size of clsString is the same as i, that means a vector was added to it this turn through the loop.
        //So, if it's the same size as i, DON'T just add the symbol to clsString, but if nothing was added, DO add it by itself.
        if ((int)clsString.size() < i){
            std::vector<char> temp = {p_clsString.at(i)};
            clsString.push_back(temp);
        }
    }
}

char caselessString::at(int p_at){
    return clsString.at(p_at).at(0);
}

int caselessString::size(){
    return clsString.size();
}

void caselessString::printLower(){
    /**
     * Prints the lowercase version of the string it holds.
     */
    for (int i = 0; i < (int)clsString.size(); ++i){
        std::cout << clsString.at(i).at(0);
    }
    std::cout << std::endl;
}

void caselessString::printUpper(){
    /**
     * Prints the uppercase version of the string it holds.
     */
    for (int i = 0; i < (int)clsString.size(); ++i){
        //To prevent going out of bounds, we have to also test to see if there are two members
        if (clsString.at(i).size() > 1){
            std::cout << clsString.at(i).at(1);
        }else{
            std::cout << clsString.at(i).at(0);
        }
    }
    std::cout << std::endl;
}
