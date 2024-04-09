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
		Text(Type type, std::wstring originalText);
		Text(Type type, std::wstring originalText, std::wstring translatedText);
		void setTranslate(std::wstring translatedText);
		Type getType() const;
		std::wstring getOriginalText() const;
		std::wstring getTranslatedText() const;
	protected:
		Type type = Type::title;
		std::wstring originalText = L"";
		std::wstring translatedText = L"";
	};

	class Quest {
	public:
		Quest(std::wstring quest);
		std::vector<Text> getTextArray() const;
		void setTranslatedArray(std::wstring originalText, std::wstring translatedText);
		std::wstring getQuest();
		void replaceTranslate(); //replace orinial text to translated text in quest
	protected:
		std::wstring quest = L"";
		std::vector<Text> textArray;

		void textAnalyzing(std::wstring text);
		void setArrayText(Type type, std::wstring originalText);
	};

	class SnbtReader {
	public:
		SnbtReader(std::vector<std::string> fileByLine);
		std::wstring getBuiltFile();
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
		std::wstring buildFile();
	};

};