#include "Film.h"
#include "Video.h"

// Constructor
Film::Film(std::string multimedia, std::string filePath, unsigned int duration,
           int *chapters)
    : Video(multimedia, filePath, duration) {
  setChapters(chapters);
}

// Copy constructor
Film::Film(const Film &from) : Video(from) {
  if (from.chapters) {
    int size = from.getChapterNumber() + 1;
    chapters = new int[size];
    for (int i = 0; i < size; ++i) {
      chapters[i] = from.chapters[i];
    }
  } else {
    chapters = nullptr;
  }
}

// Setter method for chapters
void Film::setChapters(int *arg) {
  if (arg == nullptr) {
    chapters = nullptr;
    return;
  }
  int i = 0;
  while (arg[i++] != -1)
    ;
  delete[] chapters;
  chapters = new int[i];
  chapters[--i] = -1;
  while (--i >= 0)
    chapters[i] = arg[i];
}

// Getter method for chapter number
int Film::getChapterNumber() const {
  if (chapters == nullptr)
    return 0;
  int i = 0;
  while (chapters[i++] != -1)
    ;
  return i - 1;
}

// Method to display chapter durations
void Film::showChapterDuration() const {
  int i = 0;
  if (chapters == nullptr) {
    std::cout << "This film is empty!" << std::endl;
    return;
  }
  std::cout << "Chapters duration are (in second): ";
  while (chapters[i] != -1) {
    std::cout << chapters[i] << std::endl;
    i++;
  }
}

// Getter method for chapters
const int *Film::getChapters() const { return chapters; }

// Destructor
Film::~Film() {
  delete[] chapters; // Deallocate the memory when the object is destroyed
}

// Assignment operator
Film &Film::operator=(const Film &from) {
  Video::operator=(from);
  const int *array = from.getChapters();
  if (array)
    chapters = nullptr;
  else {
    if (chapters)
      delete[] chapters;
    else {
      int n = from.getChapterNumber() + 1;
      chapters = new int[n];
      while (n > 0) {
        n = n - 1;
        chapters[n] = from.getChapters()[n];
      }
    }
  }
  return *this;
}

// Method to display film details
void Film::display(std::ostream &s) const {
  s << "Multimedia type : FILM,"
    << "Multimedia name: " << this->getMultimediaName() << ","
    << "File path: " << this->getFilePathName() << ","
    << "Duration: " << this->getDuration() << ",";
  s << "chapter number :" << Film::getChapterNumber() << ",";
  s << "Chapters duration : ,";
  if (chapters) {
    for (int i = 0; i <= Film::getChapterNumber() - 1; i++) {
      s << "chapter" << i << " duration : " << Film::chapters[i] << ",";
    }
  }
}

 std::string Film::play() const {
  return "Can not play film media !";
 }
