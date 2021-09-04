#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct Student {
public:
	char name[50];
	char sex;
	int course;
	char group[50];
	int year;
	int month;
	int day;
} student;

bool RW(const char* filename, int n)
{

	ofstream outFile(filename, ios::out | ios::binary);

	if (!outFile) return false;
	for (int i = 0; i < n; i++)
	{
		cout << "name ";
		cin >> student.name;
		cout << "sex ";
		cin >> student.sex;
		cout << "course ";
		cin >> student.course;
		cout << "group ";
		cin >> student.group;

		// запис структурної змінної B у файл
		outFile.write((char*)&student, sizeof(Student));
	}
	outFile.close(); // закрити файл
	return true;
}
bool RD(const char* filename, int k)
{
	ifstream inFile(filename, ios::in | ios::binary);
	if (!inFile) return false;
	// отримати структурну змінну B з файлу
	for (int i = 0; i < k; i++) {
		inFile.read((char*)&student, sizeof(Student));
		if (student.sex == 'j') {
			cout << "Name = " << student.name << endl;
			cout << "Sex = " << student.sex << endl;
			cout << "Coure = " << student.course << endl;
			cout << "Group = " << student.group << endl;
		}
	}
	inFile.close();
	return true;
}
bool RW(const char* filename, int n, int y)
{

	ofstream outFile(filename, ios::out | ios::binary);

	if (!outFile) return false;
	for (int i = 0; i < n; i++)
	{
		cout << "name ";
		cin >> student.name;
		cout << "year  ";
		cin >> student.year;
		cout << "month  ";
		cin >> student.month;
		cout << "day  ";
		cin >> student.day;
		// запис структурної змінної B у файл
		outFile.write((char*)&student, sizeof(Student));
	}
	outFile.close(); // закрити файл
	return true;
}
bool RD(const char* filename, int k, int y)
{
	Student* arr = new Student[k];
	ifstream inFile(filename, ios::in | ios::binary);
	if (!inFile) return false;
	// отримати структурну змінну B з файлу
	for (int i = 0; i < k; i++)
	{inFile.read((char*)&arr[i], sizeof(Student));
	}
	for (int i = 1; i < k; i++) {
		

		for (int j = 0; j < k - 1; j++)
		{
			if (arr[j].year > arr[j + 1].year) {
				Student tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			else if ((arr[j].year == arr[j + 1].year)&&(arr[j].month > arr[j + 1].month)) {
				Student tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			else if ((arr[j].year == arr[j + 1].year) && (arr[j].month == arr[j + 1].month)&& (arr[j].day > arr[j + 1].day)) {
				Student tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
				
	}
	for (int i = 0; i < k; i++)
	{
		cout << "Name = " << arr[i].name << endl;
		cout << "Birthday = " << arr[i].year << ":" << arr[i].month << ":" << arr[i].day << endl;
	}
	inFile.close();
	return true;
}


int  main() {
	setlocale(LC_ALL, "ukr");
	int n;
	cin >> n;
	RW("data.dat", n);
	RD("data.dat", n);
	RW("info.txt", n,2);
	RD("info.txt", n,2);

}