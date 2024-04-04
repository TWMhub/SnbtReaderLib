#include "SnbtReader.h"

SnbtReader::SnbtReader(std::string text) {
	this->inputString = text;
	AnalizeFile(text);
};

std::string SnbtReader::getBuiltFile() {
	return buildFile();
};

void SnbtReader::AnalizeFile(std::string text) {
	int counterSquareBracket = 0;
	size_t globalBracket1;
	size_t globalBracket2;
	for (int i = 0; i < text.length(); i++) {
		if (text.substr(i, 6) == "quests") {
			globalBracket1 = text.find("{", i + 6);
			if (globalBracket1 != std::string::npos) {
				metaInf1 = text.substr(0, globalBracket1 - 1);
				globalBracket2 = text.find_last_of("}",text.find_last_of("]"));
				if (globalBracket2 != std::string::npos) {
					metaInf2 = text.substr(globalBracket2 + 1);
					this->allocationQuests(text.substr(globalBracket1, globalBracket2 - globalBracket1));
				}
			}
			break;
		}
	}
};

void SnbtReader::allocationQuests(std::string quests) {
	std::vector<std::string> lines;
	int posGlobalBracket = 0;
	int lastBraket = 0;
	std::string ouputQuest = "";
	std::istringstream iss(quests);
	std::string line = "";
	while (std::getline(iss, line)) {
		lines.push_back(line);
	}
	posGlobalBracket = lines[0].find("{");

	for (int i = 0; i < lines.size(); i++) {
		if (lines[i][posGlobalBracket] == '}') {
			ouputQuest = "";
			for (int j = lastBraket; j < i + 1; i++) {
				ouputQuest += lines[j] + "\n";
				lastBraket = j + 1;
			}

			this->questArray.push_back(Quest{ ouputQuest });
		}
	}
};

std::string SnbtReader::buildFile() {
	std::string output = metaInf1;
	for (int i = 0; i < this->questArray.size(); i++) {
		output += this->questArray[i].getQuest();
	}
	output += this->metaInf2;
	return output;
};