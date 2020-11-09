#include "xptools.h"

bool xptools::caselessCompare(std::string* p_str1, std::string* p_str2){
  /*
   * First, make sure the string lenths are equal.
   * If they aren't, the strings can't be equal, and we return there.
   * If they are equal, use std::tolower from <cctype> to 
   * make lowercase versions of each string and test their equality
   */

  if (p_str1->size() == p_str2->size()){
    //Declare 2 temporary strings to be compared
    std::string tmp1;
    std::string tmp2;

    //Assign lowercase versions of p_str1&2 to tmp1&2
    for (int i = 0; static_cast<size_t>(i) < p_str1->size(); ++i){
      tmp1 = std::tolower(p_str1->at(i));
      tmp2 = std::tolower(p_str2->at(i));
    }

    //Compare tmp1&2 and return the results
    return (tmp1 == tmp2);

  }else{
    //If they aren't equal in length, we know they aren't equal
    //so we skip all the other stuff and return false
    return false;
  }
}
