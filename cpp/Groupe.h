#ifndef GROUPE_H
#define GROUPE_H

#include "Head.h" /**< Include Head.h header file. */
#include <list>   /**< Include list header file for std::list. */

/// @brief define alias type
typedef std::shared_ptr<Head> HeadPtr;

class DataBase;

/**
 * Declaration of Groupe class, inheriting from std::list<HeadPtr>.
 */
class Groupe : public std::list<HeadPtr> {
  friend class DataBase; /**<Allow DataBase class to access private members. */

private:
  std::string name; /**<Name of the group*/

  /* Private constructor to prevent instantiation outside DataBase class. */
  Groupe(std::string name);

public:
  /* Method to display details of objects in the group. */
  std::string displayObjectDetails();

  /* Method to retrieve the name of the group. */
  std::string getName();
};

#endif // GROUPE_H
