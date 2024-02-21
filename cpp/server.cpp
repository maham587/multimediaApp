//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//
#include "DataBase.h"
#include "tcpserver.h"
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
const int PORT = 3331;
int main(int argc, char *argv[]) {
  int *chapters = new int[3];
  chapters[0] = 2000;
  chapters[1] = 2000;
  chapters[2] = -1;

  DataBase dataBase;
  HeadPtr film1 =
      dataBase.createFilm("7 anos", "/bin/movies/7-anos.mp4", 400, chapters);
  HeadPtr film2 = dataBase.createFilm(
      "Macha and the bear", "/bin/movies/Macha-and-the-bear", 400, chapters);
  HeadPtr video1 =
      dataBase.createVideo("appDemo", "./assets/appDemo.mp4", 178000);
  HeadPtr video2 =
      dataBase.createVideo("crosswalk", "./assets/crosswalk.mp4", 1800);
  HeadPtr photo1 =
      dataBase.createPhoto("birds", "./assets/birds.png", 1024, 1024);
  HeadPtr photo2 = dataBase.createPhoto("traffic-light",
                                        "./assets/traffic-light.png", 580, 387);
  HeadPtr photo3 =
      dataBase.createPhoto("blind", "./assets/blind.png", 512, 512);
  HeadPtr photo4 =
      dataBase.createPhoto("portrait", "./assets/portrait.jpeg", 512, 512);

  GroupePtr favorites = dataBase.createGroupe("favorites");

  favorites->push_back(photo1);
  favorites->push_back(film2);
  favorites->push_back(photo2);

  GroupePtr privates = dataBase.createGroupe("privates");
  privates->push_back(photo4);
  privates->push_back(video1);
  privates->push_back(film1);
  privates->push_back(video1);

  // cree le TCPServer
  auto *server =
      new TCPServer([&](std::string const &request, std::string &response) {
        std::cout << "request: " << request << std::endl;
        if (request.find("findMultimedia") == 0) {
          std::string name = request.substr(15);
          HeadPtr found = dataBase.findMultimedia(name);
          std::stringstream ss;
          if (found != nullptr) {
            found->display(ss);
            response = ss.str();
          } else
            response = "Multimedia : " + name + " not found !";

        } else if (request.find("playMultimedia") == 0) {

          std::string name = request.substr(15);
          response = dataBase.playMultimedia(name);
        } else if (request == "getAllMultimedia") {
          response = dataBase.showAllMultimedia();
        }

        else if (request == "showAllGroup") {
          response = dataBase.showAllgroup();
        } else {
          response = "Invalid request";
        }
        // return false would close the connecytion with the client
        return true;
      });
  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;
  int status = server->run(PORT);
  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }
  return 0;
}
