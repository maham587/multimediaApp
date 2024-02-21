#ifndef HEAD
#define HEAD

#include <iostream>
#include <string>

class DataBase;

/// @brief Interface which describes the common characteristics of multimedia
/// objects. All other multimedia classes will inherit from this interface.
class Head {
  friend class DataBase;

protected:
  std::string multimediaName; /**< Multimedia name */
  std::string filePathName;   /**< File path name */

  /**
   * @brief Constructor with parameters.
   * @param multimedia The name of the multimedia.
   * @param filePath The file path of the multimedia.
   */
  Head(std::string multimedia, std::string filePath);

  /// @brief Default constructor.
  Head();

public:
  /// @brief Destructor.
  virtual ~Head();

  /**
   * @brief Sets the name of the multimedia.
   * @param name The name to set.
   */
  void setMultimediaName(std::string name);

  /**
   * @brief Sets the file path of the multimedia.
   * @param path The file path to set.
   */
  void setFilePathName(std::string path);

  /**
   * @brief Gets the name of the multimedia.
   * @return The name of the multimedia.
   */
  std::string getMultimediaName() const;

  /**
   * @brief Gets the file path of the multimedia.
   * @return The file path of the multimedia.
   */
  std::string getFilePathName() const;

  /**
   * @brief Displays information about the multimedia object.
   * @param os The output stream to write to.
   */
  virtual void display(std::ostream &os) const;

  /// @brief Virtual function to play the multimedia object.
  virtual void play() const = 0;
};

#endif
