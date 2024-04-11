#include "SnbtReader.h"

namespace depozit {

	SnbtReader::SnbtReader(const std::vector<std::string>& fileByLine) { //basic constructor
		this->fileByLine.clear();
		this->fileByLine = fileByLine;
		this->AnalizeFile();
	}

	std::vector<Quest> SnbtReader::getQuestArray() const { //return quests array
		return this->questArray;
	}

	void SnbtReader::writeQuestArray(const std::vector<Quest>& questArray) { //set new quest array
		this->questArray = questArray;
	}

	void SnbtReader::setTranslate() { //replace original string to traslated
		for (int i = 0; i < questArray.size(); i++) {
			questArray[i].replaceTranslate();
		}
	}

	std::string SnbtReader::getBuiltFile(){ //return complete file as string //is needed to write the translated file back to the file
		return buildFile();
	}

	void SnbtReader::AnalizeFile() { //extracts metainf and transfers all the quests to allocationQuests
		std::vector<std::string> quests;
		std::string metainf = "";
		int questBoundaryPosition1 = 0;
		int questBoundaryPosition2 = 0;
		for (int i = 0; i < this->fileByLine.size(); i++) {
			if (this->fileByLine[i].find("quests") != std::string::npos && questBoundaryPosition1 == 0) {
				
				questBoundaryPosition1 = i;

				for (int j = 0; j <= i; j++) {
					metainf += this->fileByLine[j]+"\n";
				}
				this->metaInf1 = metainf;
				metainf.clear();


				for (int j = this->fileByLine.size() - 1; j >= 0; j--) {
					if (this->fileByLine[j].find("]") != std::string::npos) {

						questBoundaryPosition2 = j;

						for (int c = this->fileByLine.size() - 1; c >= j; c--) {
							metainf = fileByLine[c] + "\n" + metainf;
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

	}

	void SnbtReader::allocationQuests(const std::vector<std::string>& quests) { //splitting quests and adding them to the vector

		int questBracketPositions = quests[0].find("{");
		int firstBorder = 0;

		std::vector<std::string> questArray;
		

		for (int i = 0; i < quests.size(); i++) {
			if (quests[i].length() >= questBracketPositions) {
				if (quests[i][questBracketPositions] == '}') {
					for (int j = firstBorder; j <= i; j++) {
						questArray.push_back(quests[j]);
					}
					this->questArray.push_back(Quest{ questArray });
					questArray.clear();

					firstBorder = i + 1;
				}
			}
		}
	}

	std::string SnbtReader::buildFile() { //build file as string
		std::string output = metaInf1;
		for (int i = 0; i < this->questArray.size(); i++) {
			output += questArray[i].getQuest()+"\n";
		}
		output += this->metaInf2;
		return output;
	}
	
}