#include "SnbtReader.h"

namespace depozit {

	Text::Text(Type type, std::wstring originalText) {
		this->type = type;
		this->originalText = originalText;
		this->translatedText = "";
	};

	Text::Text(Type type, std::wstring originalText, std::wstring translatedText) {
		this->type = type;
		this->originalText = originalText;
		this->translatedText = translatedText;
	};

	void Text::setTranslate(std::wstring translatedText) {
		this->translatedText = translatedText;
	}

	Type Text::getType() const {
		return this->type;
	}

	std::wstring Text::getOriginalText() const {
		return this->originalText;
	}

	std::wstring Text::getTranslatedText() const {
		return this->translatedText;
	}

}