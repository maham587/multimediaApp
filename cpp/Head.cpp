#include "Head.h"

// Default constructor
Head::Head() {}

// Parameterized constructor
Head::Head(std::string multimedia, std::string filePath)
    : multimediaName{multimedia}, filePathName{filePath} {}

// Getter for multimediaName
std::string Head::getMultimediaName() const { return this->multimediaName; }

// Getter for filePathName
std::string Head::getFilePathName() const { return this->filePathName; }

// Display function
void Head::display(std::ostream &s) const {
  s << "Multimedia name: " << this->getMultimediaName() << ", "
    << "File path: " << this->getFilePathName() << std::endl;
}

// Destructor
Head::~Head() {
  /*std::cout << "process complete, cleaning ..." << std::endl;*/
}
