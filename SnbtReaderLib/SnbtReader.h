#pragma once
#include <iostream>
#include <string>

enum class Type {
	title,
	subtitle,
	description
};

class Text {
public:
	Text(Type type, std::string originalText);
	Text(Type type, std::string originalText, std::string translatedText);
	void setTranslate(std::string translatedText);
	Type getType() const;
	std::string getOriginalText() const;
	std::string getTranslatedText() const;
protected:
	Type type = Type::title;
	std::string originalText = "";
	std::string translatedText = "";
};