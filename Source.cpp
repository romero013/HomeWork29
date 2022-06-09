#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool overwrite(string path, string str);

int main() {
	setlocale(LC_ALL, "ru");

	// Задача 1
	cout << "Задача 1.\n";
	string path = "file.txt", str;

	ofstream out;
	out.open(path, ios::app); // Открытие файла с возможностью добавления

	// Запись в файл
	do {
		if (out.is_open()) {
			cout << "Файл открыт.\n";
			cout << "Введите строку:\n";
			getline(cin, str);
			if (str == "end")
				break;
			else {
				out << str + "\n";
				cout << "Запись добавлена в файл.\n";
			}
		}
		else {
			cout << "Ошибка открытия файла.\n";
			break;
		}
		system("cls");
	} while (str != "end");

	out.close();

	// Чтение из файла
	ifstream in;
	in.open(path);
	if (in.is_open()) {
		in.seekg(0, ios::beg);
		char sym;
		cout << "Содержимое файла:\n";
		while (in.get(sym))
			cout << sym;
	}
	else
		cout << "Ошибка открытия файла.\n";

	in.close();

	// Удаление файла
	if (!remove("file.txt"))
		cout << "Файл удалён!\n";
	else
		cout << "Файл отсутствует!\n";
	cout << endl;

	// Задача 2
	cout << "Задача 2.\n";
	string path1 = "file1.txt", str1;
	cout << "Введите строку:\n";
	getline(cin, str1);
	if (overwrite(path1, str1))
		cout << "Данные файла успешно обновлены!\n";
	else
		cout << "Ошибка открытия файла.\nЛибо файла не существует.\n";


	return 0;
}
// Перезапись данных
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