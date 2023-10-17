#ifndef OBJECT_GROUP_H
#define OBJECT_GROUP_H

#include <list>
#include "MultimediaObject.h"

class ObjectGroup : public std::list<MediaPtr> {

private:
	const std::string name;
public: // Constructeurs
	ObjectGroup() : std::list<MediaPtr>() {}
	ObjectGroup(std::string name) : std::list<MediaPtr>(), name(name) { };

public: // Setters et getters
	std::string const getName() const { return name; };

public: // Autres méthodes
	void print(std::ostream& os) const;
};

#endif