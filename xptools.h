#ifndef XPTOOLS_H
#define XPTOOLS_H

#include <cctype>
#include <string>

//define the xptools namespace 
namespace xptools
{
  //The function for comparing string without case
  extern bool caselessCompare(std::string& p_str1, std::string& p_str2); //Take two string arguments and return their case-agnostic equality
}

#endif //XPTOOLS_H
