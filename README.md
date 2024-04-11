# SnbtReaderLib
-- en --

### The SnbtReader library is designed to work with files in the SNBT (Simplified NBT) format, which is created by FTB Quests. This library provides convenient tools for analyzing and working with quests created using the FTB Quests mod, including convenient means for translating these quests.

- Installation
To use the library in your project:

1. Clone the repository or add it as a dependency to your project.
2. Include the header file SnbtReader.h in your project.
3. Utilize the available classes and functions to work with FTB Quests files.
- Usage Example
An example of using the library to analyze an FTB Quests file and translate its contents:

```cpp
#include "SnbtReader.h"

int main() {
    //open the FTB Quests file
    std::ifstream inputFile("quest_file.snbt");

    //create a SnbtReader object and pass the file to it
    std::vector<std::string> fileByLine;
    std::string a;
    if (file.is_open()) {
	    while (std::getline(file, a)) {
		    fileByLine.push_back(a);
	    }
    }
    depozit::SnbtReader reader(fileByLine);

    //get the array of quests from the file
    std::vector<depozit::Quest> quests = reader.getQuestArray();

    //getting all texts for translation
    for (int i = 0; i < reader.getQuestArray().size(); i++) {
    	for (int j = 0; j < reader.getQuestArray()[i].getTextArray().size(); j++) {
    		std::cerr << "type: " << depozit::typeToString(reader.getQuestArray()[i].getTextArray()[j].getType()) << " text: " << reader.getQuestArray()[i].getTextArray()[j].getOriginalText() << "\n";
    	}
    }

    //example of a translation replacement
    reader.getQuestArray()[indexArray].getTextArray()[indexText].setTranslate("translatedText");

    //after making the transfer, you can replace it
    reader.getQuestArray()[indexArray].replaceTranslate();
    
    //get the complete string to rewrite the file with quests
    std::string ouputString = reader.getBuiltFile();
    return 0;
}
```
- Contributions and Feedback
If you have suggestions for improving the library or encounter any issues, feel free to create an issue in the repository or propose your changes through a pull request.

- License
This project is licensed under the [MIT License](https://mit-license.org/).
---
-- ru --
### Библиотека SnbtReader предназначена для работы с файлами в формате SNBT (Simplified NBT), которые создаёт FTB Quests. Эта библиотека предоставляет удобные инструменты для анализа и работы с квестами, созданными с помощью мода FTB Quests, включая удобные средства для перевода этих квестов.

- Установка
Для использования библиотеки в вашем проекте:

1. Склонируйте репозиторий или добавьте его в качестве зависимости вашего проекта.
2. Подключите заголовочный файл SnbtReader.h к вашему проекту.
3. Воспользуйтесь доступными классами и функциями для работы с файлами FTB Quests.
- Пример использования
Пример использования библиотеки для анализа файла FTB Quests и перевода его содержимого:

```cpp
#include "SnbtReader.h"

int main() {
    //открываем файлик с квестами
    std::ifstream inputFile("quest_file.snbt");

    //созданние объекта класса SnbtReader
    std::vector<std::string> fileByLine;
    std::string a;
    if (file.is_open()) {
	    while (std::getline(file, a)) {
		    fileByLine.push_back(a);
	    }
    }
    depozit::SnbtReader reader(fileByLine);

    //получение массива векторов
    std::vector<depozit::Quest> quests = reader.getQuestArray();

    //получение текстов для перевода, с указанием типа строки
    for (int i = 0; i < reader.getQuestArray().size(); i++) {
    	for (int j = 0; j < reader.getQuestArray()[i].getTextArray().size(); j++) {
    		std::cerr << "type: " << depozit::typeToString(reader.getQuestArray()[i].getTextArray()[j].getType()) << " text: " << reader.getQuestArray()[i].getTextArray()[j].getOriginalText() << "\n";
    	}
    }

    //пример добавления перевода
    reader.getQuestArray()[indexArray].getTextArray()[indexText].setTranslate("translatedText");

    //после замены переведённых текстов, можете заменить оригинальный текст на переведенный 
    reader.getQuestArray()[indexArray].replaceTranslate();
    
    //получение полность готовой строки, которую можно использовать для записи в файл (финальный этап)
    std::string ouputString = reader.getBuiltFile();
    return 0;
}
```
- Вклад и обратная связь
Если у вас есть предложения по улучшению библиотеки или вы столкнулись с проблемой, не стесняйтесь создать issue в репозитории или предложить свои изменения через pull request.

- Лицензия
Этот проект лицензирован в соответствии с лицензией [MIt](https://mit-license.org/).
