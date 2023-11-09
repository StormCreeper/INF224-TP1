#ifndef FILM_OBJECT_H
#define FILM_OBJECT_H

#include "VideoObject.h"

class FilmObject : public VideoObject {
private:
	float* chapterLengths {};
	int numChapters{};

public: // Constructors
	FilmObject() : VideoObject() {}
	FilmObject(std::string name, std::string pathname) : VideoObject(name, pathname) {}
	FilmObject(std::string name, std::string pathname, float length) : VideoObject(name, pathname, length) {}
	FilmObject(std::string name, std::string pathname, float length, float* chapterLengths, int numChapters)
		: VideoObject(name, pathname, length) {
			setChapterLengths(chapterLengths, numChapters);
	}

public: // Getters et setters

	float* const getChapterLengths() const { return chapterLengths; }
	int getNumChapters() const { return numChapters; }

	void setChapterLengths(float* chapterLengths, int numChapters) {
		if (chapterLengths != nullptr) delete[] this->chapterLengths;
		this->chapterLengths = new float[numChapters]();
		this->numChapters = numChapters;
		if (this->chapterLengths && chapterLengths) {
			for (int i = 0; i < numChapters; i++) {
				this->chapterLengths[i] = chapterLengths[i];
			}
		} else {
			if (chapterLengths != nullptr) delete[] this->chapterLengths;
			this->numChapters = 0;
			std::cerr << "One array is null\n";
		}
	}

	void setNumChapters(int numChapters) { this->numChapters = numChapters; }

public: // Opérateurs de copie
	FilmObject(const FilmObject &from) : FilmObject(from.getPathname(), from.getName(), from.getLength(), from.getChapterLengths(), from.getNumChapters()) { }
	
	FilmObject& operator=(const FilmObject& from);


public: // Autres méthodes

	void print(std::ostream& os) const override {
		os << "Film object (name = \"" << getName() << "\", pathname = \"" << getPathname() << "\", length=" << getLength() << ")\n";
		os << "Chapter lengths : \n";
		for (int i = 0; i < numChapters; i++) {
			os << "    " << chapterLengths[i] << "seconds \n";
		}
	}

	~FilmObject() {
		if (chapterLengths != nullptr)
			delete[] this->chapterLengths;
	}
};

#endif // !FILM_OBJECT_H
