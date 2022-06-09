#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool overwrite(string path, string str);

int main() {
	setlocale(LC_ALL, "ru");

	// ������ 1
	cout << "������ 1.\n";
	string path = "file.txt", str;

	ofstream out;
	out.open(path, ios::app); // �������� ����� � ������������ ����������

	// ������ � ����
	do {
		if (out.is_open()) {
			cout << "���� ������.\n";
			cout << "������� ������:\n";
			getline(cin, str);
			if (str == "end")
				break;
			else {
				out << str + "\n";
				cout << "������ ��������� � ����.\n";
			}
		}
		else {
			cout << "������ �������� �����.\n";
			break;
		}
		system("cls");
	} while (str != "end");

	out.close();

	// ������ �� �����
	ifstream in;
	in.open(path);
	if (in.is_open()) {
		in.seekg(0, ios::beg);
		char sym;
		cout << "���������� �����:\n";
		while (in.get(sym))
			cout << sym;
	}
	else
		cout << "������ �������� �����.\n";

	in.close();

	// �������� �����
	if (!remove("file.txt"))
		cout << "���� �����!\n";
	else
		cout << "���� �����������!\n";
	cout << endl;

	// ������ 2
	cout << "������ 2.\n";
	string path1 = "file1.txt", str1;
	cout << "������� ������:\n";
	getline(cin, str1);
	if (overwrite(path1, str1))
		cout << "������ ����� ������� ���������!\n";
	else
		cout << "������ �������� �����.\n���� ����� �� ����������.\n";


	return 0;
}
// ���������� ������
bool overwrite(string path, string str) {
	ifstream in;
	in.open(path);
	if (!in.is_open()) {
		in.close();
		return false;
	}
	ofstream out;
	out.open(path);
	out << str;
	out.close();
	return true;
}