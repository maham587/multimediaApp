#if !defined(PHOTO)
#define PHOTO

#include "DataBase.h"
#include "Head.h"
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/// @brief Class representing a photo multimedia object.
class Photo : public Head {
  friend class DataBase;

private:
  unsigned int length; /**< Length of the photo */
  unsigned int height; /**< Height of the photo */

  /**
   * @brief Constructor for Photo objects.
   * @param multimedia The name of the photo.
   * @param filePath The file path of the photo.
   * @param length The length of the photo.
   * @param height The height of the photo.
   */
  Photo(std::string multimedia, std::string filePath, unsigned int length,
        unsigned int height)
      : Head(multimedia, filePath), length(length), height(height){};

public:
  /**
   * @brief Gets the height of the photo.
   * @return The height of the photo.
   */
  unsigned int getHeight() const { return height; };

  /**
   * @brief Gets the length of the photo.
   * @return The length of the photo.
   */
  unsigned int getLength() const { return length; };

  /**
   * @brief Displays information about the photo.
   * @param s The output stream to write to.
   */
  virtual void display(std::ostream &s) const override {

    s << "Multimedia type: PHOTO, "
      << "Multimedia name: " << this->getMultimediaName() << ", "
      << "File path: " << this->getFilePathName() << ", "
      << "Height: " << this->getHeight() << ", "
      << "Length: " << this->getLength() << ", ";
  };

  /**
   * @brief Plays the photo.
   */
std::string play() const override {
  
   //Construct the command to open the image with ImageJ in the background
    std::string command = "imagej " + getFilePathName() + " &";

    // Execute the command
    int status = std::system(command.c_str());

    // Check if the command was successfully executed
    if (status == 0) {
        return "Image played successfully!";
    } else {
        return "Failed to play photo '" + getMultimediaName() + "'.";
    }
}

  /// @brief Destructor.
  ~Photo() {
    // std::cout << "décédé" << std::endl;
  }
};

#endif
