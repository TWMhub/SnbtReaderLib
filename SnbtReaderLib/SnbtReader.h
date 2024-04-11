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

	std::string typeToString(Type type); //convert enum class Type to string
	std::wstring stringToWstring(const std::string& str); //convert string to wstring 
	std::string wstringToString(const std::wstring& wstr); //convert wstring to string


	class Text {
	public:
		Text(int pos, Type type, std::string originalText); //basic constructor
		Text(int pos, Type type, std::string originalText, std::string translatedText); //constructor to save the progress of the previous session 
		std::string getOriginalText() const; //return original text
		std::string getTranslatedText() const; //return traslated text
		Type getType() const; //return depozit::Type of line

		void setTranslate(std::string translatedText); //add traslate text
		
	protected:
		int posTextIndex = 0;
		Type type = Type::title;
		std::string originalText = "";
		std::string translatedText = "";
	};

	class Quest {
	public:
		Quest(std::vector<std::string> quest); //basic constructor
		std::vector<Text> getTextArray() const; //return all depozit::Text in quest to translate

		void setTranslatedArray(int line, std::string translatedText); //I don't know why I added this feature
		void replaceTranslate(); //replace orinial text to translated text in quest //last step before writing to file

		std::string getQuest(); //return quest in formating string 

	protected:
		std::vector<std::string> quest; 
		std::vector<Text> textArray;

		void textAnalyzing(std::vector<std::string> quest); //analyzes the quest and extracts text for translation
		//void setArrayText(int pos, Type type, std::string originalText);
	};

	class SnbtReader {
	public:
		SnbtReader(std::vector<std::string> fileByLine); //basic constructor

		std::vector<Quest> getQuestArray() const; //return quests array
		void writeQuestArray(std::vector<Quest> questArray); //set new quest array
		void setTranslate(); //replace original string to traslated

		std::string getBuiltFile(); //return complete file as string //is needed to write the translated file back to the file
	private:
		//std::wstring inputString = L"";
		std::vector<std::string> fileByLine;

		std::string metaInf1 = "";
		std::string metaInf2 = "";
		std::vector<Quest> questArray;

		void AnalizeFile(); //extracts metainf and transfers all the quests to allocationQuests
		void allocationQuests(std::vector<std::string> quests); //splitting quests and adding them to the vector

		std::string buildFile(); //build file as string
	};

};