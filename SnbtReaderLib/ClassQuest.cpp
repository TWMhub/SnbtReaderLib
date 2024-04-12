#include "SnbtReader.h"

namespace depozit
{

    Quest::Quest(const std::vector<std::wstring>& quest)   //basic constructor
    {
        this->quest = quest;
        textAnalyzing(quest);
    }

    std::vector<Text> Quest::getTextArray() const   //return all depozit::Text in quest to translate
    {
        return this->textArray;
    }

    void Quest::setTranslatedArray(int line, std::wstring translatedText)   //I don't know why I added this feature
    {
        quest[line].replace(quest[line].find(L"\"") + 1, quest[line].find_last_of(L"\"") - quest[line].find(L"\"") - 1, translatedText);
    }

    void Quest::replaceTranslate()   //replace orinial text to translated text in quest //last step before writing to file
    {

    }

    std::wstring Quest::getQuest()   //return quest in formating string
    {
        std::wstring outputQuest;
        for (size_t i = 0; i < this->quest.size(); i++)
        {
            outputQuest += this->quest[i];
            if (i != this->quest.size() - 1)
            {
                outputQuest += L"\n";
            }
        }
        return outputQuest;
    }

    //private||protected
    void Quest::textAnalyzing(const std::vector<std::wstring>& quest)   //analyzes the quest and extracts text for translation
    {
        size_t firstQuote;
        size_t secondQuote;
        //bool isTranslatable = false;
        //std::vector<std::string> descStrings;
        for (size_t i = 0; i < quest.size(); i++)
        {
            if (quest[i].find(L"subtitle") != std::string::npos)
            {
                firstQuote = quest[i].find(L"\"");
                secondQuote = quest[i].find_last_of(L"\"");
                if (quest[i].find(L"{") == std::string::npos && firstQuote != std::string::npos && secondQuote != std::string::npos)
                    this->textArray.push_back(Text{ i, Type::subtitle, quest[i].substr(firstQuote + 1,secondQuote - firstQuote - 1) });
            }
            else if (quest[i].find(L"title") != std::string::npos)
            {
                firstQuote = quest[i].find(L"\"");
                secondQuote = quest[i].find_last_of(L"\"");
                if (quest[i].find(L"{") == std::string::npos && firstQuote != std::string::npos && secondQuote != std::string::npos)
                    this->textArray.push_back(Text{ i, Type::title, quest[i].substr(firstQuote + 1, secondQuote - firstQuote - 1) });
            }
            else if (quest[i].find(L"description") != std::string::npos)
            {
                firstQuote = quest[i].find(L"[");
                for (size_t j = i; j < quest.size(); j++)
                {
                    if (quest[j].find(L"\"") != std::string::npos && quest[j].find_last_of(L"\"") != std::string::npos &&
                        (quest[j].find(L"{") == std::string::npos || quest[j].find(L"}") == std::string::npos))
                        this->textArray.push_back(Text{ j, Type::description, quest[j].substr(quest[j].find(L"\"") + 1,quest[j].find_last_of(L"\"") - quest[j].find(L"\"") - 1) });

                    if (quest[j].find(L"]") != std::string::npos)
                    {
                        i = j + 1;
                        break;
                    }
                }
            }
        }
    }

    /*void Quest::setArrayText(int pos, Type type, std::string originalText) {
    this->textArray.push_back(Text{ pos, type, originalText });
    }*/

}
