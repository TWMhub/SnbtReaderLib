#ifndef HEADER_B1271E79EA687DF1
#define HEADER_B1271E79EA687DF1

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <Windows.h>


namespace depozit
{

    enum class Type
    {
        title,
        subtitle,
        description
    };

    std::wstring typeToString(const Type type); //convert enum class Type to string
    std::wstring stringToWstring(const std::string& str); //convert string to wstring
    std::string wstringToString(const std::wstring& wstr); //convert wstring to string


    class Text
    {
    public:
        Text(size_t pos, Type type, std::wstring originalText); //basic constructor
        Text(size_t pos, Type type, std::wstring originalText, std::wstring translatedText); //constructor to save the progress of the previous session
        std::wstring getOriginalText() const; //return original text
        std::wstring getTranslatedText() const; //return traslated text
        Type getType() const; //return depozit::Type of line

        void setTranslate(const std::wstring& translatedText); //add traslate text

    protected:
        size_t posTextIndex = 0;
        Type type = Type::title;
        std::wstring originalText{ L"" };
        std::wstring translatedText{ L"" };
    };

    class Quest
    {
    public:
        Quest(const std::vector<std::wstring>& quest); //basic constructor
        std::vector<Text> getTextArray() const; //return all depozit::Text in quest to translate

        void setTranslatedArray(int line, std::wstring translatedText); //I don't know why I added this feature
        void replaceTranslate(); //replace orinial text to translated text in quest //last step before writing to file

        std::wstring getQuest(); //return quest in formating string

    protected:
        std::vector<std::wstring> quest;
        std::vector<Text> textArray;

        void textAnalyzing(const std::vector<std::wstring>& quest); //analyzes the quest and extracts text for translation
        //void setArrayText(int pos, Type type, std::string originalText);
    };

    class SnbtReader
    {
    public:
        SnbtReader(const std::vector<std::wstring>& fileByLine); //basic constructor

        std::vector<Quest> getQuestArray() const; //return quests array
        void writeQuestArray(const std::vector<Quest>& questArray); //set new quest array
        void setTranslate(); //replace original string to traslated

        std::wstring getBuiltFile(); //return complete file as string //is needed to write the translated file back to the file
    private:
        //std::wstring inputString = L"";
        std::vector<std::wstring> fileByLine;

        std::wstring metaInf1{ L"" };
        std::wstring metaInf2{ L"" };
        std::vector<Quest> questArray;

        void AnalizeFile(); //extracts metainf and transfers all the quests to allocationQuests
        void allocationQuests(const std::vector<std::wstring>& quests); //splitting quests and adding them to the vector

        std::wstring buildFile(); //build file as string
    };

};
#endif // header guard
