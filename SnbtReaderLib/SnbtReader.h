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
		std::wstring originalText = "";
		std::wstring translatedText = "";
	};

	class Quest {
	public:
		Quest(std::wstring quest);
		std::vector<Text> getTextArray() const;
		void setTranslatedArray(std::string originalText, std::string translatedText);
		std::wstring getQuest();
		void replaceTranslate(); //replace orinial text to translated text in quest
	protected:
		std::wstring quest = "";
		std::vector<Text> textArray;

		void textAnalyzing(std::wstring text);
		void setArrayText(Type type, std::wstring originalText);
	};

	class SnbtReader {
	public:
		SnbtReader(std::wstring text);
		std::wstring getBuiltFile();
		std::vector<Quest> getQuestArray() const;
		void writeQuestArray(std::vector<Quest> questArray);
	private:
		std::wstring inputString = "";
		std::wstring metaInf1 = "";
		std::wstring metaInf2 = "";
		std::vector<Quest> questArray;
		void AnalizeFile(std::wstring text);
		void allocationQuests(std::wstring quests);
		std::wstring buildFile();
	};

};