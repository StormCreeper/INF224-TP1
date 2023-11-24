#include "ObjectGroup.h"

void ObjectGroup::print(std::ostream& os) const {
	std::cout << "Object group : \n";
	for (MediaPtr media : *this) {
		std::cout << "\t"; media->print(os);
	}
}
