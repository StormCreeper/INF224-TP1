#include "ObjectGroup.h"

void ObjectGroup::print(std::ostream& os) const {
	std::cout << "Object group : [";
	for (MediaPtr media : *this) {
		std::cout << " | "; media->print(os);
	}
	std::cout << " ]";
}
