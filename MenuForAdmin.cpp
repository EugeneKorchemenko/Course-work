#include "MenuForAdmin.h"


void menuForAdmin(vector <Account>& vector_of_accaunts, vector <TypeOfWork>& vector_of_works)
{
	vector_of_works.resize(getCountOfTypesOfWorkInFile(FILE_DATA));
	doesFileExist(vector_of_works);
	int choice;
	while (1)
	{
		cout << "\tMode: Admin" << endl;
		cout << "Choose:\n1 Work with data\n2 Work with accounts\n0 Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: workWithData(vector_of_works);
			break;
		case 2: workWithAcccounts(vector_of_accaunts);
			break;
		case 0: return;
			break;
		}
	}
}
void workWithAcccounts(vector <Account>& vector_of_accaunts)
{
	int n = 1, choice;
	while (n != 0)
	{
		cout << "\t________MENU_______" << endl;
		cout << "1 Show list of accounts\n2 Show current registration applications\n0 Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: showListOfAccounts(vector_of_accaunts);
			break;
		case 2: showApplications(vector_of_accaunts);
			break;
		case 0: return;
			break;
		}
	}
}
void workWithData(vector <TypeOfWork>& vector_of_works)
{
	int n = 1, choice;
	while (n != 0)
	{
		cout << "\t________MENU_______" << endl;
		cout << "1 Show information about projects\n2 Add new project\n3 Edit project\n4 Search by projects\n5 Delete project\n0 Exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			showProjectVector(vector_of_works);
			break;
		case 2:
		{
			cout << "\t______CHOOSE______" << endl;
			cout << "1 Add project \n2 Add project with delete" << endl;
			cin >> choice;
			if (choice == 1)
				addProjectsInVector(vector_of_works);
			else
			{
				cout << "Are you shure? It will destroy all data wich was in file.\n1 YES\n2 NO" << endl;
				cin >> choice;
				if (choice == 2)
					break;
				else
				{
					generateProjectsVector(vector_of_works);
				}
			}
		}
		break;
		case 3:
			chooseKindOfEdition(vector_of_works);
			break;
		case 4:
			searchForProject(vector_of_works);
			break;
		case 5:
			delProjectsFromVector(vector_of_works);
			break;
		case 0: break;
		default:
			cout << "Invalid input. Please try again" << endl;
		}
	}
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