#include "ClassTextLine.h"

Text::Text(Type type, std::string originalText) {
	this->type = type;
	this->originalText = originalText;
	this->translatedText = "";
};

Text::Text(Type type, std::string originalText, std::string translatedText) {
	this->type = type;
	this->originalText = originalText;
	this->translatedText = translatedText;
};

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