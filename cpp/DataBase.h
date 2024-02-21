#ifndef DATABASE_H
#define DATABASE_H

#include "Film.h"
#include "Groupe.h"
#include "Head.h"
#include "Photo.h"
#include "Video.h"
#include <map>
#include <memory>
#include <string>

// Define aliases for convenience
using HeadPtr = std::shared_ptr<Head>;
using GroupePtr = std::shared_ptr<Groupe>;
using HEAD_TABLE = std::map<std::string, HeadPtr>;
using GROUPE_TABLE = std::map<std::string, GroupePtr>;

/**
 * @brief The DataBase class represents a database of multimedia objects.
 * This dataBase contains all multimedia objects, with wich the server will
 * interact It contains two tables, one to store all multimedias and another to
 * store groupes
 */
class DataBase {

private:
  HEAD_TABLE headTable;     // Map to store multimedia objects
  GROUPE_TABLE groupeTable; // Map to store group objects

public:
  /**
   * @brief Constructor for the DataBase class.
   */
  DataBase();

  // Methods for adding A Film object in the dataBase
  HeadPtr createFilm(std::string multimediaName, std::string filePath,
                     unsigned int duration, int *chapters);
  // Methods for adding A Video object in the dataBase
  HeadPtr createVideo(std::string multimediaName, std::string filePath,
                      unsigned int duration);
  // Methods for adding A Photo object in the dataBase
  HeadPtr createPhoto(std::string multimediaName, std::string filePath,
                      unsigned int length, unsigned int height);
  // Methods for adding A Groupe object in the dataBase
  GroupePtr createGroupe(std::string name);

  /**
   * @brief Finds a multimedia object by its name.
   * @param multimediaName The name of the multimedia to find.
   * @return A shared pointer to the found multimedia object, or nullptr if not
   * found.
   */
  HeadPtr findMultimedia(std::string multimediaName);

  /**
   * @brief Plays a multimedia object.
   * @param multimediaName The name of the multimedia to play.
   * @return A string indicating the status of the operation.
   */
  std::string playMultimedia(std::string multimediaName);

  /**
   * @brief Deletes a multimedia object.
   * @param name The name of the multimedia object to delete.
   */
  void deleteMultimedia(std::string name);

  /**
   * @brief Checks if a name is valid.
   * @param name The name to check.
   * @return true if the name is valid, false otherwise.
   */
  bool isValidName(const std::string &name);

  /**
   * @brief Displays details of all multimedia objects.
   * @return A string containing details of all multimedia objects.
   */
  std::string showAllMultimedia();

  /**
   * @brief Displays details of all group objects.
   * @return A string containing details of all group objects.
   */
  std::string showAllgroup();
};

#endif // DATABASE_H
