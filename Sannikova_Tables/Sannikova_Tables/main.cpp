#include <fstream>
#include <iostream>
#include <string>
#include "Table.h"
//#include "List.h"
using namespace std;


int isAlpha(const char sym)
{
	return ((sym >= '�') && (sym <= '�') ||
		(sym >= '�') && (sym <= '�') ||
		(sym >= 'A') && (sym <= 'Z') ||
		(sym >= 'a') && (sym <= 'z'));

}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
	/*ofstream fout("TestText.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ cppstudio.txt
	fout << "����� ����� ������� ����� ������� ��� ���� ��"; // ������ ������ � ����
	fout.close(); // ��������� ����
	*/
	
	BST table;
	char buff[256]; // ����� �������������� �������� ������������ �� ����� ������
	ifstream fin("TestText.txt"); // ������� ���� ��� ������
	
	while (fin.getline(buff, 256)) { // ������� ������ �� �����
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

	fin.close(); // ��������� ����
	cout << buff << endl<<endl; // ���������� ��� ������

	cout << "��� 10 ����� ������ ����" << endl;
	cout << "+---------------+--------------+"<<endl;
	cout << "|  �����        |   ����� ���� |"<<endl;

	system("pause");
	return 0;
}