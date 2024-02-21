//
// main.cpp
// Created on 21/10/2018
//
#include "DataBase.h"
#include <iostream>
#include <tuple>
typedef std::shared_ptr<Head> HeadPtr;
using namespace std;
int main(int argc, const char *argv[]) {
  int *chapters = new int[3];
  chapters[0] = 100;
  chapters[1] = 200;
  chapters[2] = -1;

  // Groupe *privateGroup = new Groupe("private");
  // Groupe *favorites = new Groupe("favorite");

  DataBase dataBase;
  HeadPtr film1 =
      dataBase.createFilm("7 anos", "/bin/movies/movie1.mp4", 400, chapters);
  HeadPtr film2 = dataBase.createFilm("Macha and the bear",
                                      "/bin/movies/movie2.mp4", 400, chapters);
  HeadPtr video1 = dataBase.createVideo(
      "walker", "/Users/mahamadoutogola/Downloads/walker-1.mov", 400);
  HeadPtr photo1 = dataBase.createPhoto(
      "crosswalk", "/Users/mahamadoutogola/Downloads/crosswalk.png", 400, 400);
  dataBase.findMultimedia("crosslk");
  dataBase.deleteMultimedia("crosswalk");
  dataBase.playMultimedia("crosswalk");
  photo1->play();
  return 0;
}
