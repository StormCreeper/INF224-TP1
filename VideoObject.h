#pragma once
#include "MultimediaObject.h"
class VideoObject : public MultimediaObject {
private:
	float length{};

public:
	VideoObject() : MultimediaObject() {}
	VideoObject(std::string name, std::string pathname) : MultimediaObject(name, pathname) {}
	VideoObject(std::string name, std::string pathname, float length) : MultimediaObject(name, pathname) { this->length = length; };

public:
	float getLength() const { return length; }
	void setLenght(float length) { this->length = length; }

public:
	void print(std::ostream& os) const override {
		os << "Video object (name = \"" << getName() << "\", pathname = \"" << getPathname() << "\", length=" << getLength() << ")\n";
	};
	const void play() override {
		std::string command = "mpv \"" + getPathname() + "\" &";
		system(command.c_str());
	}
};

