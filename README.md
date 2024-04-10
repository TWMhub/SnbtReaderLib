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
    // Open the FTB Quests file
    std::ifstream inputFile("quest_file.snbt");

    // Create a SnbtReader object and pass the file to it
    depozit::SnbtReader reader(inputFile);

    // Get the array of quests from the file
    std::vector<depozit::Quest> quests = reader.getQuestArray();

    // Further according to your needs
    
    // Write the modified quests back to the file
    reader.writeQuestArray(quests);

    // Get the complete string to rewrite the file with quests
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
    // Открываем файл FTB Quests
    std::ifstream inputFile("quest_file.snbt");

    // Создаем объект SnbtReader и передаем ему файл
    depozit::SnbtReader reader(inputFile);

    // Получаем массив квестов из файла
    std::vector<depozit::Quest> quests = reader.getQuestArray();

    // Дальше по вашему усмотрению
    
    // Записываем измененные квесты обратно в файл
    reader.writeQuestArray(quests);

    //получаем полную строку для перезаписи файла с квестами
    std::string ouputString = reader.getBuiltFile();
    return 0;
}
```
- Вклад и обратная связь
Если у вас есть предложения по улучшению библиотеки или вы столкнулись с проблемой, не стесняйтесь создать issue в репозитории или предложить свои изменения через pull request.

- Лицензия
Этот проект лицензирован в соответствии с лицензией [MIt](https://mit-license.org/).
