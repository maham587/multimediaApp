#ifndef VIDEO_H
#define VIDEO_H

#include "Head.h"
#include <iostream>

// Forward declaration of DataBase class to avoid circular dependency
class DataBase;

/// @brief declaration and definition of the Video class inheriting from Head
class Video : public Head {
  friend class DataBase; // Allowing DataBase class to access private members

protected:
  unsigned duration; // Duration of the video in seconds

public:
  // Constructor initializing multimedia name, file path, and duration
  Video(std::string multimedia, std::string filePath, unsigned int duration)
      : Head(multimedia, filePath), duration(duration){};

  // Method to retrieve the duration of the video
  unsigned int getDuration() const { return duration; };

  // Method to display details of the video
  void display(std::ostream &s) const override {
    s << "Multimedia type: VIDEO, "
      << "Multimedia name: " << this->getMultimediaName() << ", "
      << "File path: " << this->getFilePathName() << ", "
      << "Duration: " << this->getDuration() << ", ";
  };

  // Method to play the video
  std::string play() const override {
    std::string arg =
        "mpv " + this->getFilePathName() + " &"; // Command to play video
    int status = system(arg.data()); // Execute command to play video in background
    if(status != 0){
      return "Failed to play video : " + this->getMultimediaName();
    }
    return "Video played successfully !";

  };

  // Destructor (currently commented out)
  // ~Video() {
  //     /*std::cout << "décédé" << std::endl;*/ // Uncomment for debugging
  //     purposes
  // }
};
#endif // VIDEO_H
