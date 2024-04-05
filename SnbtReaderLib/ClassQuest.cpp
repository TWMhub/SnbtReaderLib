#include "SnbtReader.h"

namespace depozit {
	Quest::Quest(std::wstring quest) {
		this->quest = quest;
		textAnalyzing(quest);
	}

	void Quest::textAnalyzing(std::wstring text) {
		size_t firstQuote;
		size_t secondQuote;
		for (int i = 0; i < text.length(); i++) {
			if (text.substr(i, 8) == "subtitle") {
				firstQuote = text.find("\"", i + 8);
				if (firstQuote != std::wstring::npos) {
					secondQuote = text.find("\"", firstQuote + 1);
					if (secondQuote != std::wstring::npos) {
						setArrayText(Type::subtitle, text.substr(firstQuote + 1, secondQuote - firstQuote - 1));
					}
				}
				i = secondQuote;
			}
			else if (text.substr(i, 5) == "title") {
				firstQuote = text.find("\"", i + 5);
				if (firstQuote != std::string::npos) {
					secondQuote = text.find("\"", firstQuote + 1);
					if (secondQuote != std::string::npos) {
						setArrayText(Type::title, text.substr(firstQuote + 1, secondQuote - firstQuote - 1));
					}
				}
				i = secondQuote;
			}
			else if (text.substr(i, 11) == "description") {
				firstQuote = text.find("\"", i + 11);
				if (firstQuote != std::string::npos) {
					secondQuote = text.find("\"", firstQuote + 1);
					if (secondQuote != std::string::npos) {
						setArrayText(Type::description, text.substr(firstQuote + 1, secondQuote - firstQuote - 1));
					}
				}
				i = secondQuote;
			}
		}
	}

	void Quest::setArrayText(Type type, std::string originalText) {
		textArray.push_back(Text{ type,originalText });
	}

	std::vector<Text> Quest::getTextArray() const {
		return this->textArray;
	}

	void Quest::setTranslatedArray(std::string originalText, std::string translatedText) {
		for (int i = 0; i < this->textArray.size(); i++) {
			if (this->textArray[i].getOriginalText() == originalText) {
				this->textArray[i].setTranslate(translatedText);
				break;
			}
		}
	}

	std::string Quest::getQuest() {
		return quest;
	}

};