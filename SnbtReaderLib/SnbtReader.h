#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class Type {
	title,
	subtitle,
	description
};

namespace depozit {
	std::string typeToString(Type type);
}


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

class Quest {
public:
	Quest(std::string quest);
	std::vector<Text> getTextArray() const;
	void setTranslatedArray(std::string originalText, std::string translatedText);
protected:
	std::string quest = "";
	std::vector<Text> textArray;

	void textAnalyzing(std::string text);
	void setArrayText(Type type, std::string originalText);
};