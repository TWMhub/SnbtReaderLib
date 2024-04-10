#include "SnbtReader.h"

namespace depozit {
	Quest::Quest(std::vector<std::string> quest) {
		this->quest = quest;
		textAnalyzing(quest);
	}

	void Quest::textAnalyzing(std::vector<std::string> quest) {
		size_t firstQuote;
		size_t secondQuote;
		for (int i = 0; i < quest.size(); i++) {
			if (quest[i].find("subtitle")) {
				firstQuote = quest[i].find("\"");
			}
		}
	}

	void Quest::setArrayText(int pos, Type type, std::string originalText) {
		textArray.push_back(Text{ pos, type, originalText });
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
	}

};