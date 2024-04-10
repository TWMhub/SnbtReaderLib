#include "SnbtReader.h"

namespace depozit {

	Quest::Quest(std::vector<std::string> quest) {
		this->quest = quest;
		textAnalyzing(quest);
	}

	void Quest::textAnalyzing(std::vector<std::string> quest) {
		size_t firstQuote;
		size_t secondQuote;
		//bool isTranslatable = false;
		//std::vector<std::string> descStrings;
		for (int i = 0; i < quest.size(); i++) {
			if (quest[i].find("subtitle") != std::string::npos) {
				firstQuote = quest[i].find("\"");
				secondQuote = quest[i].find_last_of("\"");
				if(quest[i].find("{") == std::string::npos && firstQuote != std::string::npos && secondQuote != std::string::npos)
					this->textArray.push_back(Text{ i, Type::subtitle, quest[i].substr(firstQuote + 1,secondQuote - firstQuote - 1) });
			}
			else if (quest[i].find("title") != std::string::npos) {
				firstQuote = quest[i].find("\"");
				secondQuote = quest[i].find_last_of("\"");
				if (quest[i].find("{") == std::string::npos && firstQuote != std::string::npos && secondQuote != std::string::npos)
					this->textArray.push_back(Text{ i, Type::title, quest[i].substr(firstQuote + 1, secondQuote - firstQuote - 1) });
			}
			else if (quest[i].find("description") != std::string::npos) {
				firstQuote = quest[i].find("[");
				for (int j = i; j < quest.size(); j++) {
					if (quest[j].find("\"") != std::string::npos && quest[j].find_last_of("\"") != std::string::npos && 
						(quest[j].find("{") == std::string::npos || quest[j].find("}") == std::string::npos)) 
							this->textArray.push_back(Text{ j, Type::description, quest[j].substr(quest[j].find("\"") + 1,quest[j].find_last_of("\"") - quest[j].find("\"") - 1) });
					
					if (quest[j].find("]") != std::string::npos) {
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

	std::vector<Text> Quest::getTextArray() const {
		return this->textArray;
	}

	void Quest::setTranslatedArray(int line, std::string translatedText) {//tut huinia
		quest[line].replace(quest[line].find("\"") + 1, quest[line].find_last_of("\"") - quest[line].find("\"") - 1, translatedText);
	}

	std::string Quest::getQuest() {
		std::string outputQuest;
		for (int i = 0; i < this->quest.size(); i++) {
			outputQuest += this->quest[i];
			if (i != this->quest.size() - 1) {
				outputQuest += "\n";
			}
		}
		return outputQuest;
	}

	void Quest::replaceTranslate() {//dopisat' posle fixa herowogo chtenia

	};

};