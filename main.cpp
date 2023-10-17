#include <iostream>
#include "MultimediaObject.h"
#include "PhotoObject.h"
#include "VideoObject.h"
#include "FilmObject.h"
#include "ObjectGroup.h"

int main(int argc, const char* argv[]) {

    float chapterLengths[4]{ 2, 3, 1, 6 };

    /*objects[0] = 
    objects[1] = new PhotoObject("Space Invader >:(", "C:/Users/telop/Desktop/invader.png");
    objects[2] = new FilmObject("BB Cravate <333333", "C:/Users/telop/Downloads/IMG_0177.mov", 10, chapterLengths, 4);*/

    ObjectGroup objGroup{ };
    objGroup.push_back(std::make_shared<PhotoObject>("Dragonnnnn", "C:/Users/telop/Desktop/Dragon.png"));
    objGroup.push_back(std::make_shared <PhotoObject>("Space Invader >:(", "C:/Users/telop/Desktop/invader.png"));
    objGroup.push_back(std::make_shared <VideoObject>("BB Cravate <333333 Video", "C:/Users/telop/Downloads/IMG_0177.mov", 10));
    objGroup.push_back(std::make_shared <FilmObject>("BB Cravate <333333 Film", "C:/Users/telop/Downloads/IMG_0177.mov", 10, chapterLengths, 4));

    objGroup.print(std::cout);

    objGroup.pop_front();
    std::cout << "Before death\n";

    return 0;
}