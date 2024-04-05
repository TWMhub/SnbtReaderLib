#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>


namespace depozit {

	enum class Type {
		title,
		subtitle,
		description
	};

	std::string typeToString(Type type);
	std::wstring stringToWstring(const std::string& str);
	std::string wstringToString(const std::wstring& wstr);


	class Text {
	public:
		//Text();
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
		//Quest();
		Quest(std::string quest);
		std::vector<Text> getTextArray() const;
		void setTranslatedArray(std::string originalText, std::string translatedText);
		std::string getQuest();
		void replaceTranslate(); //replace orinial text to translated text in quest
	protected:
		std::string quest = "";
		std::vector<Text> textArray;

		void textAnalyzing(std::string text);
		void setArrayText(Type type, std::string originalText);
	};

	class SnbtReader {
	public:
		SnbtReader(std::string text);
		std::string getBuiltFile();
		std::vector<Quest> getQuestArray() const;
		void writeQuestArray(std::vector<Quest> questArray);
	private:
		std::string inputString = "";
		std::string metaInf1 = "";
		std::string metaInf2 = "";
		std::vector<Quest> questArray;
		void AnalizeFile(std::string text);
		void allocationQuests(std::string quests);
		std::string buildFile();
	};

};