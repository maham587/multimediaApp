#ifndef FILM_H
#define FILM_H

#include "Head.h"
#include "Video.h"

/*Forward declaration of DataBase class */
class DataBase;
/**
 * Declaration of Film class, inheriting from Video
 */
class Film : public Video {
  friend class DataBase; // Allowing DataBase class to access private members

private:
  int *chapters; /**< Pointer to array of chapter durations */

public:
  /* Constructor */
  Film(std::string multimedia, std::string filePath, unsigned int duration,
       int *chapters);

  /* Copy constructor */
  Film(const Film &from);

  /* Assignment operator */
  Film &operator=(const Film &from);

  /* Destructor */
  ~Film();

  /* Getter method to retrieve the number of chapters */
  int getChapterNumber() const;

  /* Getter method to retrieve the array of chapter durations */
  const int *getChapters() const;

  /* Setter method to set the array of chapter durations */
  void setChapters(int *chapters);

  /* Method to display the duration of each chapter */
  void showChapterDuration() const;

  /* Method to display film details */
  void display(std::ostream &s) const override;
};

#endif
