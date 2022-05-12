#include "MenuForAdmin.h"

void menuForAdmin(vector <Account>& vector_of_accaunts, vector <TypeOfWork>& vector_of_works, string login)
{
	/*vector_of_works.resize(getCountOfTypesOfWorkInFile(FILE_DATA));
	doesFileExist(vector_of_works, 1);*/
	int choice = 10;
	while (choice != 0)
	{
		clearConsole();
		cout << "\tMode: Admin" << endl;
		cout << "Choose:\n1 Work with data\n2 Work with accounts\n0 Exit" << endl;
		choice = input(0, 2);
		switch (choice)
		{
		case 1: workWithData(vector_of_works);
			break;
		case 2: workWithAcccounts(vector_of_accaunts, vector_of_works, login);
			break;
		case 0:/*
		{
			clearConsole();
			return;
		}*/
			break;
		}
	}
	clearConsole();
}
void workWithAcccounts(vector <Account>& vector_of_accaunts, vector <TypeOfWork>& vector_of_works, string login)
{
	int choice = 10;
	while (choice != 0)
	{
		clearConsole();
		cout << "\t________MENU_______" << endl;
		cout << "1 Show list of accounts\n2 Show outgoing registration applications\n3 Edit accounts\n4 Change password\n0 Exit" << endl;
		choice = input(0, 4);
		switch (choice)
		{
		case 1: showListOfAccounts(vector_of_accaunts); sortAccounts(vector_of_accaunts);
			break;
		case 2: showApplications(vector_of_accaunts);
			break;
		case 3: editAccounts(vector_of_accaunts,vector_of_works, login);
			break;
		case 4: changePassword(vector_of_accaunts, login);
			break;
		case 0: break;
		}
	}
	clearConsole();
}
void workWithData(vector <TypeOfWork>& vector_of_works)
{
	int  choice = 10;
	while (choice != 0)
	{
		clearConsole();
		cout << "\t________MENU_______" << endl;
		cout << "1 Show information about projects\n2 Add new project\n3 Edit project\n4 Search by projects\n5 Delete project\n0 Exit" << endl;
		choice = input(0, 5);
		switch (choice)
		{
		case 1: showProjectVector(vector_of_works);
			break;
		case 2:
		{
			clearConsole();
			cout << "\t______CHOOSE______" << endl;
			cout << "1 Add project\n2 Add project with delete\n0 Exit" << endl;
			choice = input(0, 2);
			switch (choice)
			{
			case 1: addProjectsInVector(vector_of_works);
				break;
			case 2:
			{
				cout << "Are you shure? It will destroy all data wich was in file.\n1 YES\n2 NO" << endl;
				choice = input();
				if (choice == 2)
					break;
				else
				{
					clearConsole();
					generateProjectsVector(vector_of_works);
				}
				clearConsole();
			}
			break;
			case 0: choice = 10;
				continue;
			}
		}
		break;
		case 3: chooseEditingProject(vector_of_works);
			break;
		case 4: searchForProject(vector_of_works);
			break;
		case 5: delProjectFromVector(vector_of_works);
			break;
		case 0: break;
		}
	}
	clearConsole();
}