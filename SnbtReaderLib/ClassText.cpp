#include "SnbtReader.h"

namespace depozit {

	Text::Text(int pos, Type type, std::string originalText) { //basic constructor
		this->posTextIndex = pos;
		this->type = type;
		this->originalText = originalText;
		this->translatedText = "";
	}

	Text::Text(int pos, Type type, std::string originalText, std::string translatedText) { //constructor to save the progress of the previous session 
		this->posTextIndex = pos;
		this->type = type;
		this->originalText = originalText;
		this->translatedText = translatedText;
	}

	std::string Text::getOriginalText() const { //return original text
		return this->originalText;
	}

	std::string Text::getTranslatedText() const { //return traslated text
		if (translatedText.length() > 0)
			return translatedText;
		else
			return originalText;
	}

	Type Text::getType() const { //return depozit::Type of line
		return this->type;
	}

	void Text::setTranslate(const std::string& translatedText) { //add traslate text
		this->translatedText = translatedText;
	}

	int Text::getPos() const {
		return this->posTextIndex;
	}
}