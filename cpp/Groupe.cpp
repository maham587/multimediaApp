#include "Groupe.h"
#include <sstream>  // Include sstream for stringstream
#include <typeinfo> // Include typeid

// Constructor definition
Groupe::Groupe(std::string name) : name{name} {}

// Method to retrieve the name of the group
std::string Groupe::getName() { return name; }

// Method to display details of objects in the group
std::string Groupe::displayObjectDetails() {
  std::stringstream ss;
  ss << "Groupe name : " << this->getName() << ","; // Display group name
  ss << ",,GROUPE ITEMS,,"; // Display header for group items
  for (auto item : *this) {
    item->display(ss); // Display details of each item in the group
  }
  ss << ",*************************************************,,,"; // Display
                                                                 // separator
  return ss.str(); // Return the concatenated string
}
