#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>

/**
 * Custom exception class for indicating a duplicate name error
 */
class DuplicateNameException : public std::runtime_error {

public:
  /**
   *  Constructor accepting an error message
   */
  DuplicateNameException(const std::string &message)
      : std::runtime_error(message) {}
};

/**
 * Custom exception class for indicating an invalid name error
 */
class InvalidNameException : public std::runtime_error {
public:
  /* Constructor accepting an error message */
  InvalidNameException(const std::string &message)
      : std::runtime_error(message) {}
};

/**
 * Custom exception class for indicating a nonexistent object error
 */
class NonexistentObjectException : public std::runtime_error {
public:
  /* Constructor accepting an error message */
  NonexistentObjectException(const std::string &message)
      : std::runtime_error(message) {}
};

/**
 * Custom exception class for indicating an invalid duration error
 */
class InvalidDurationException : public std::runtime_error {
public:
  /* Constructor accepting an error message */
  InvalidDurationException(const std::string &message)
      : std::runtime_error(message) {}
};

#endif
