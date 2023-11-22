#include <iostream>

#include <memory>
#include <string>
#include <sstream>
#include "tcpserver/tcpserver.h"

const int PORT = 3331;

#include "DataManager.h"
#include "FilmObject.h"
#include "MultimediaObject.h"
#include "ObjectGroup.h"
#include "PhotoObject.h"
#include "VideoObject.h"

int main(int argc, const char* argv[]) {
    float chapterLengths[4]{2, 3, 1, 6};

    /*objects[0] =
    objects[1] = new PhotoObject("Space Invader >:(", "C:/Users/telop/Desktop/invader.png");
    objects[2] = new FilmObject("BB Cravate <333333", "C:/Users/telop/Downloads/IMG_0177.mov", 10, chapterLengths, 4);*/

    DataManager dataManager{};

    std::shared_ptr<ObjectGroup> objGroup = dataManager.addNewGroup("Test");

    objGroup->push_back(dataManager.addNewPhoto("Dragonnnnn", "C:/Users/telop/Desktop/Dragon.png"));
    objGroup->push_back(dataManager.addNewPhoto("Space Invader >:(", "C:/Users/telop/Desktop/invader.png"));
    objGroup->push_back(dataManager.addNewVideo("BB Cravate <333333 Video", "C:/Users/telop/Downloads/IMG_0177.mov", 10));
    objGroup->push_back(dataManager.addNewFilm("BB Cravate <333333 Film", "C:/Users/telop/Downloads/IMG_0177.mov", 10, chapterLengths, 4));

    dataManager.print(std::cout);

    // cree le TCPServer
    auto* server = new TCPServer([&](std::string const& request, std::string& response) {
        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;

        std::stringstream ss{request};

        std::string command {};
        ss >> command;

        // The rest is the name of the object
        std::string name {};
        std::getline(ss, name);
        name.erase(0, 1);

        // Commands are "display" and "play"
        
        if(command == "display") {
            if(dataManager.getObject(name) != nullptr) {
                std::stringstream stream{};
                dataManager.printObject(name, stream);
                response = stream.str();
            } else {
                response = "Object not found : " + name;
            }
        } else if(command == "play") {
            if(dataManager.getObject(name) != nullptr) {
                dataManager.playObject(name);
                response = "Playing object : " + name;
            } else {
                response = "Object not found : " + name;
            }
        } else {
            response = "Unknown command : " + command;
        }

        // return false would close the connecytion with the client
        return true;
    });

    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}