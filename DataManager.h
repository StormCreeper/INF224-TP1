#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <map>
#include <string>
#include <memory>

#include "MultimediaObject.h"
#include "ObjectGroup.h"

#include "PhotoObject.h"
#include "VideoObject.h"
#include "FilmObject.h"

typedef std::map<std::string, std::shared_ptr<MultimediaObject>> ObjectMap;
typedef std::map<std::string, std::shared_ptr<ObjectGroup>> GroupMap;

class DataManager {
private:
    ObjectMap multimediaObjects {};
    GroupMap groups {};
public:
    std::shared_ptr<PhotoObject> addNewPhoto(std::string name, std::string pathname, int width = 0, int height = 0) {
        std::shared_ptr<PhotoObject> obj {new PhotoObject(name, pathname, width, height) };
        multimediaObjects[name] = obj;
        return obj;
    }
    std::shared_ptr<VideoObject> addNewVideo(std::string name, std::string pathname, float length) {
        std::shared_ptr<VideoObject> obj = std::make_shared<VideoObject>(name, pathname, length);
        multimediaObjects[name] = obj;
        return obj;
    }
    std::shared_ptr<FilmObject> addNewFilm(std::string name, std::string pathname, float length, float *chapters, int nChapters) {
        std::shared_ptr<FilmObject> obj = std::make_shared<FilmObject>(name, pathname, length, chapters, nChapters);
        multimediaObjects[name] = obj;
        return obj;
    }
    std::shared_ptr<ObjectGroup> addNewGroup(std::string name) {
        std::shared_ptr<ObjectGroup> obj = std::make_shared<ObjectGroup>(name);
        groups[name] = obj;
        return obj;
    }

    std::shared_ptr<MultimediaObject> addObject(std::shared_ptr<MultimediaObject> obj) {
        multimediaObjects[obj->getName()] = obj;
        return obj;
    }

    std::shared_ptr<MultimediaObject> getObject(std::string name) {
        auto it = multimediaObjects.find(name);
        if (it != multimediaObjects.end()) {
            return it->second;
        } else {
            return nullptr;
        }
    }

    void printObject(std::string name, std::ostream& os) {
        auto itObj = multimediaObjects.find(name);
        auto itGroup = groups.find(name);
        if (itObj != multimediaObjects.end()) itObj->second->print(os);
        else if (itGroup != groups.end()) itGroup->second->print(os);
        else std::cerr << "Object not found : " << name << "\n";
    }

    void playObject(std::string name) {
        auto it = multimediaObjects.find(name);
        if (it != multimediaObjects.end()) {
            it->second->play();
        } else {
            std::cerr << "Object not found : " << name << "\n";
        }
    }

    void deleteObject(std::string name) {
        auto it = multimediaObjects.find(name);
        if (it != multimediaObjects.end()) {
            multimediaObjects.erase(it);
        } else {
            std::cerr << "Object not found : " << name << "\n";
        }
    }

    void print(std::ostream& os) {
        os << "Multimedia objects : \n";
        for (auto it = multimediaObjects.begin(); it != multimediaObjects.end(); it++) {
            it->second->print(os);
        }
        os << "Groups : \n";
        for (auto it = groups.begin(); it != groups.end(); it++) {
            it->second->print(os);
        }
    }

    void serialize(std::ostream& os) {
        os << multimediaObjects.size() << " ";
        for (auto it = multimediaObjects.begin(); it != multimediaObjects.end(); it++) {
            it->second->serialize(os);
        }
    }

    void deserialize(std::istream& is) {
        int nObjects;
        is >> nObjects;
        std::cout << "nObjects = " << nObjects << "\n";
        for (int i = 0; i < nObjects; i++) {
            std::string objType;
            is >> objType;

            std::cout << "objType = " << objType << "\n";

            std::shared_ptr<MultimediaObject> obj;
            if (objType == "Photo") {
                obj = std::make_shared<PhotoObject>("", "", 0, 0);
            } else if (objType == "Video") {
                obj = std::make_shared<VideoObject>("", "", 0);
            } else if (objType == "Film") {
                obj = std::make_shared<FilmObject>("", "", 0, nullptr, 0);
            } else {
                std::cerr << "Unknown object type : " << objType << "\n";
                return;
            }

            obj->deserialize(is);
            addObject(obj);
        }

        std::cout << "Number of objects : " << multimediaObjects.size() << "\n";
    }

};

#endif // DATA_MANAGER_H