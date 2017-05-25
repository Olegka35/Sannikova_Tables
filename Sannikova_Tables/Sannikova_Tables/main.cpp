#include <fstream>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	ofstream fout("TestText.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	fout << "Супер пупер длинный текст который нам даст СА"; // запись строки в файл
	fout.close(); // закрываем файл

	
	char buff[50]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("TestText.txt"); // открыли файл для чтения

	//fin >> buff; // считали первое слово из файла
	//cout << buff << endl; // напечатали это слово

	fin.getline(buff, 50); // считали строку из файла
	fin.close(); // закрываем файл
	cout << buff << endl<<endl; // напечатали эту строку

	cout << "Топ 10 самых частых слов" << endl;
	cout << "+---------------+--------------+"<<endl;
	cout << "|  слово        |   число слов |"<<endl;

	system("pause");
	return 0;
}