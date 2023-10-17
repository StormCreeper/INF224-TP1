#ifndef PHOTO_OBJECT_H
#define PHOTO_OBJECT_H

#include "MultimediaObject.h"

class PhotoObject : public MultimediaObject {
private:
	int width{};
	int height{};

public:
	PhotoObject() : MultimediaObject() {}
	PhotoObject(std::string name, std::string pathname) : MultimediaObject(name, pathname) { }
	PhotoObject(std::string name, std::string pathname, int width, int height) : MultimediaObject(name, pathname) {
		this->width = width;
		this->height = height;
	}
	
public: // Getters and setters
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	void setWidth(int width) { this->width = width; };
	void setHeight(int height) { this->height = height; }

public: // Other functions
	void print(std::ostream &os) const override {
		os << "Photo object (name = \"" << getName() << "\", pathname = \"" << getPathname() << "\", width=" << getWidth() << ", height=" << getHeight() <<")\n";
	};

	const void play() override {
		std::string command = "imagej \"" + getPathname() + "\" &";
		system(command.c_str());
	}
};

#endif