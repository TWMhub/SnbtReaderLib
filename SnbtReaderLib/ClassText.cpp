#include "SnbtReader.h"

namespace depozit {

	Text::Text(int pos, Type type, std::string originalText) {
		this->posTextIndex = pos;
		this->type = type;
		this->originalText = originalText;
		this->translatedText = "";
	};

	/*Text::Text(Type type, std::wstring originalText, std::wstring translatedText) {
		this->type = type;
		this->originalText = originalText;
		this->translatedText = translatedText;
	};*/

	void Text::setTranslate(std::string translatedText) {
		this->translatedText = translatedText;
	}

	Type Text::getType() const {
		return this->type;
	}

	std::string Text::getOriginalText() const {
		return this->originalText;
	}

	std::string Text::getTranslatedText() const {
		return this->translatedText;
	}

}