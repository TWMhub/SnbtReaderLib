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
		Text(int pos, Type type, std::string originalText);
		//Text(int pos, Type type, std::wstring originalText, std::wstring translatedText);
		void setTranslate(std::string translatedText);
		Type getType() const;
		std::string getOriginalText() const;
		std::string getTranslatedText() const;
	protected:
		int posTextIndex = 0;
		Type type = Type::title;
		std::string originalText = "";
		std::string translatedText = "";
	};

	class Quest {
	public:
		Quest(std::vector<std::string> quest);
		std::vector<Text> getTextArray() const;
		std::string getQuest();
		void setTranslatedArray(int line, std::string translatedText);
		void replaceTranslate(); //replace orinial text to translated text in quest //last step before writing to file
	protected:
		std::vector<std::string> quest;
		std::vector<Text> textArray;

		void textAnalyzing(std::vector<std::string> quest);
		//void setArrayText(int pos, Type type, std::string originalText);
	};

	class SnbtReader {
	public:
		SnbtReader(std::vector<std::string> fileByLine);
		std::string getBuiltFile();
		std::vector<Quest> getQuestArray() const;
		void writeQuestArray(std::vector<Quest> questArray);
	private:
		//std::wstring inputString = L"";
		std::vector<std::string> fileByLine;

		std::string metaInf1 = "";
		std::string metaInf2 = "";
		std::vector<Quest> questArray;
		void AnalizeFile();
		void allocationQuests(std::vector<std::string> quests);
		std::string buildFile();
	};

};