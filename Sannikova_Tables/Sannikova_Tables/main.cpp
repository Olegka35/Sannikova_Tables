#include <fstream>
#include <iostream>
#include <string>
#include "Table.h"
//#include "List.h"
using namespace std;


int isAlpha(const char sym)
{
	return ((sym >= 'А') && (sym <= 'Я') ||
		(sym >= 'а') && (sym <= 'я') ||
		(sym >= 'A') && (sym <= 'Z') ||
		(sym >= 'a') && (sym <= 'z'));

}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	/*ofstream fout("TestText.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	fout << "Супер пупер длинный текст который нам даст СА"; // запись строки в файл
	fout.close(); // закрываем файл
	*/
	
	BST table;
	char buff[256]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("TestText.txt"); // открыли файл для чтения
	
	while (fin.getline(buff, 256)) { // считали строку из файла
		int i = 0;
		bool readWord = false;
		string word;
		while (buff[i] == ' ' && buff[i] != '\0') i++;
		while (buff[i] != '\0') {
			if (buff[i] != ' ' && isAlpha(buff[i])) {
				if (readWord == false) {
					word = towlower(buff[i]);
					readWord = true;
				}
				else if(isAlpha(buff[i]))
					word += towlower(buff[i]);
			}
			else if (buff[i] == ' ' && readWord == true) {
				//table.Insert(new TableNode(word, 1));
				//table.
				cout << word << endl;
				readWord = false;
			}
			i++;
		}
		if(word[0] != '\0') cout << word << endl;
	}

	fin.close(); // закрываем файл
	cout << buff << endl<<endl; // напечатали эту строку

	cout << "Топ 10 самых частых слов" << endl;
	cout << "+---------------+--------------+"<<endl;
	cout << "|  слово        |   число слов |"<<endl;

	system("pause");
	return 0;
}