#include <iostream>
#include "MultimediaObject.h"
#include "PhotoObject.h"
#include "VideoObject.h"
#include "FilmObject.h"
#include "ObjectGroup.h"
#include "DataManager.h"

int main(int argc, const char* argv[]) {

    float chapterLengths[4]{ 2, 3, 1, 6 };

    /*objects[0] = 
    objects[1] = new PhotoObject("Space Invader >:(", "C:/Users/telop/Desktop/invader.png");
    objects[2] = new FilmObject("BB Cravate <333333", "C:/Users/telop/Downloads/IMG_0177.mov", 10, chapterLengths, 4);*/

    DataManager dataManager{ };

    std::shared_ptr<ObjectGroup> objGroup = dataManager.addNewGroup("Test");

    objGroup->push_back(dataManager.addNewPhoto("Dragonnnnn", "C:/Users/telop/Desktop/Dragon.png"));
    objGroup->push_back(dataManager.addNewPhoto("Space Invader >:(", "C:/Users/telop/Desktop/invader.png"));
    objGroup->push_back(dataManager.addNewVideo("BB Cravate <333333 Video", "C:/Users/telop/Downloads/IMG_0177.mov", 10));
    objGroup->push_back(dataManager.addNewFilm("BB Cravate <333333 Film", "C:/Users/telop/Downloads/IMG_0177.mov", 10, chapterLengths, 4));

    dataManager.print(std::cout);

    return 0;
}