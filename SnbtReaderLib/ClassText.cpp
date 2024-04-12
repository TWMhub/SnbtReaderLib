#include "SnbtReader.h"

namespace depozit
{

    Text::Text(size_t pos, Type type, std::wstring originalText)   //basic constructor
    {
        this->posTextIndex = pos;
        this->type = type;
        this->originalText = originalText;
        this->translatedText = L"";
    }

    Text::Text(size_t pos, Type type, std::wstring originalText, std::wstring translatedText)   //constructor to save the progress of the previous session
    {
        this->posTextIndex = pos;
        this->type = type;
        this->originalText = originalText;
        this->translatedText = translatedText;
    }

    std::wstring Text::getOriginalText() const   //return original text
    {
        return this->originalText;
    }

    std::wstring Text::getTranslatedText() const   //return traslated text
    {
        return this->translatedText;
    }

    Type Text::getType() const   //return depozit::Type of line
    {
        return this->type;
    }

    void Text::setTranslate(const std::wstring& translatedText)   //add traslate text
    {
        this->translatedText = translatedText;
    }

}