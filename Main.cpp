#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Structs.h"
#include "Constants.h"
#include "MenuForAdmin.h"
#include "ViewData.h"
#include "Delete.h"
#include "Edit.h"
#include "GenerateData.h"
#include "Search.h"
#include "Sort.h"
#include "AddProject.h"

#include "Autorisation.h"
#include "Constants.h"
#include "PrintHeader.h"

using namespace std;

// проверка на существование файла
void doesFileExist(vector <TypeOfWork>& vector_of_works);
// считывем из файла количество типов работ
int getCountOfTypesOfWorkInFile(string file_path);

int main()
{
	vector <TypeOfWork> vector_of_works;
	vector_of_works.resize(getCountOfTypesOfWorkInFile(FILE_DATA));
	doesFileExist(vector_of_works);
	autorisatie();
	menuForAdmin(vector_of_works);
	return 0;
}

void doesFileExist(vector <TypeOfWork>& vector_of_works)
{
	ifstream fin(FILE_DATA, ios::binary | ios::in);
	if (!fin.is_open())
	{
		cout << "File doesn't exist!" << endl << "Do you want to create new one?" << endl;
		cout << "1)YES\n2)NO" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
			generateProjectsVector(vector_of_works);
	}
	else
	{
		int i = 0, m = 0;
		while (!fin.eof())
		{
			fin >> vector_of_works[i].project_name
				>> vector_of_works[i].name
				>> vector_of_works[i].FIO
				>> vector_of_works[i].ammount_of_hours
				>> vector_of_works[i].cost_per_hour;
			if (i + 1 == vector_of_works.size())
				break;
			else
				i++;
		}
	}
	fin.close();
}
int getCountOfTypesOfWorkInFile(string file_path)
{
	ifstream file(file_path, ios::in); // Открыли текстовый файл для чтения
	int number_of_strings = 0, i = 1;
	if (file.is_open())
		while (file.ignore(numeric_limits<streamsize>::max(), '\n'))
			number_of_strings++;
	file.close();
	return number_of_strings;
}