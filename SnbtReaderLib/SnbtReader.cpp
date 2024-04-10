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
				this->metaInf1 = metainf;
				metainf.clear();

				for (int j = this->fileByLine.size() - 1; j > 0; j--) {
					if (this->fileByLine[j].find("]")) {

						questBoundaryPosition2 = j;

						for (int c = this->fileByLine.size(); c >= j; c--) {
							metainf = fileByLine[c] + metainf;
						}
						this->metaInf2 = metainf;
						metainf.clear();
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

	void SnbtReader::allocationQuests(std::vector<std::string> quests) { //splitting quests and adding them to the vector

		int questBracketPositions = quests[0].find("{");
		int firstBorder = 0;

		std::vector<std::string> quest;

		for (int i = 0; i < quests.size(); i++) {
			if (quests[i][questBracketPositions] == '}') {
				for (int j = firstBorder; j <= i; j++) {
					quest.push_back(quest[j]);
				}
				this->questArray.push_back(Quest{ quest });
				quest.clear();

				firstBorder = i + 1;
			}
		}
	};

	std::string SnbtReader::buildFile() {
		std::string output = metaInf1 + "\n";
		for (int i = 0; i < this->questArray.size(); i++) {
			output += questArray[i].getQuest();
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