#include "xptools.h"

bool xptools::caselessCompare(std::string& p_str1, std::string& p_str2){
  /*
   * First, make sure the string lenths are equal.
   * If they aren't, the strings can't be equal, and we return there.
   * If they are equal, use std::tolower from <cctype> to 
   * make lowercase versions of each string and test their equality
   */

  //Immediatly end the function if they aren't equal in length
  if (p_str1.size() != p_str2.size()){
    return false;
  }

  //If they are, compare each letter, converted to lowercase. As soon as one pair doesn't match, end the function
  for (std::string::iterator l_it = p_str1.begin(), r_it = p_str2.begin();
       l_it < p_str1.end(); ++l_it, ++r_it)
  {
    if (std::tolower(*l_it) != std::tolower(*r_it)){
      return false;
    }
  }

  //If it makes it this far, they're equal
  return true;
}

