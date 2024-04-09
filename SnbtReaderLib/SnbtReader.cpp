#include "SnbtReader.h"

namespace depozit {

	SnbtReader::SnbtReader(std::vector<std::string> fileByLine) {
		this->fileByLine.clear();
		this->fileByLine = fileByLine;
	};

	std::string SnbtReader::getBuiltFile() {
		return buildFile();
	};

	void SnbtReader::AnalizeFile() { //metaInf(1,2) + start allocationQuests
		std::vector<std::string> quests;
		std::string metainf = "";
		int questBoundaryPosition1 = 0;
		int questBoundaryPosition2 = 0;

		for (int i = 0; i < this->fileByLine.size(); i++) {
			if (this->fileByLine[i].find("quests") != std::string::npos && questBoundaryPosition1 == 0) {
				
				questBoundaryPosition1 = i;

				for (int j = 0; j <= i; j++) {
					metainf += this->fileByLine[j];
				}
				this->metaInf1 = metaInf1;
				metainf.clear();

				for (int j = this->fileByLine.size(); j > 0; j++) {
					if (this->fileByLine[j].find("]")) {

						questBoundaryPosition2 = j;

						for (int c = this->fileByLine.size(); c >= j; c++) {
							metainf = fileByLine[c] + metainf;
							this->metaInf2 = metainf;
							metainf.clear();
						}
						break;
					}
				}
				break;
			}
		}

		for (int i = questBoundaryPosition1 + 1; i < questBoundaryPosition2; i++) {
			quests.push_back(this->fileByLine[i]);
		}
		this->allocationQuests(quests);

	};

	void SnbtReader::allocationQuests(std::vector<std::string> quests) {
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
		for (int i = 0; i < lines.size() - 1; i++) {
			if (lines[i][posGlobalBracket] == '}') {
				ouputQuest = "";
				for (int j = lastBraket; j < i + 1; j++) {
					ouputQuest += lines[j] + "\n";
					lastBraket = j + 1;
				}
				this->questArray.push_back(Quest{ ouputQuest });

			}
		}
	};

	std::string SnbtReader::buildFile() {
		std::string output = metaInf1 + "\n";
		for (int i = 0; i < this->questArray.size(); i++) {
			output += this->questArray[i].getQuest();
		}
		output += this->metaInf2;
		return output;
	};

	std::vector<Quest> SnbtReader::getQuestArray() const {
		return this->questArray;
	}
	void SnbtReader::writeQuestArray(std::vector<Quest> questArray) {
		this->questArray = questArray;
	};
}