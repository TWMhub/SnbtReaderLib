#include "SnbtReader.h"

namespace depozit {

	Quest::Quest(const std::vector<std::string>& quest) { //basic constructor
		this->quest = quest;
		textAnalyzing(quest);
	}

	std::vector<Text> Quest::getTextArray() const { //return all depozit::Text in quest to translate
		return this->textArray;
	}

	void Quest::setTranslatedArray(int line, std::string translatedText) { //I don't know why I added this feature
		quest[line].replace(quest[line].find("\"") + 1, quest[line].find_last_of("\"") - quest[line].find("\"") - 1, translatedText);
	}

	void Quest::replaceTranslate() { //replace orinial text to translated text in quest //last step before writing to file
		for (int i = 0; i < this->textArray.size(); i++) {

		}
	}

	std::string Quest::getQuest() { //return quest in formating string 
		std::string outputQuest;
		for (int i = 0; i < this->quest.size(); i++) {
			outputQuest += this->quest[i];
			if (i != this->quest.size() - 1) {
				outputQuest += "\n";
			}
		}
		return outputQuest;
	}

	//private||protected
	void Quest::textAnalyzing(const std::vector<std::string>& quest) { //analyzes the quest and extracts text for translation
		size_t firstQuote;
		size_t secondQuote;
		std::string textLine;
		//bool isTranslatable = false;
		//std::vector<std::string> descStrings;
		for (int i = 0; i < quest.size(); i++) {
			if (quest[i].find("subtitle") != std::string::npos) {
				firstQuote = quest[i].find("\"");
				secondQuote = quest[i].find_last_of("\"");
				if (quest[i].find("{") == std::string::npos && firstQuote != std::string::npos && secondQuote != std::string::npos)
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
					if (quest[j].find("\"") != std::string::npos && quest[j].find_last_of("\"") != std::string::npos && (quest[j].find("{") == std::string::npos)) {
						textLine = quest[j].substr(quest[j].find("\"") + 1, quest[j].find_last_of("\"") - quest[j].find("\"") - 1);
						if(textLine.length()>0)
							this->textArray.push_back(Text{ j, Type::description, textLine });
					}

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

}