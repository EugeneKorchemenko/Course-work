#include "MenuForAdmin.h"

void menuForAdmin(vector <Account>& vector_of_accaunts, vector <TypeOfWork>& vector_of_works, string login)
{
	int choice = 10;
	while (choice != 0)
	{
		clearConsole();
		cout << ADMIN_MODE << endl;
		cout << MENU_ADMIN << endl;
		choice = input(0, 2);
		switch (choice)
		{
		case 1: workWithData(vector_of_works);
			break;
		case 2: workWithAcccounts(vector_of_accaunts, vector_of_works, login);
			break;
		case 0:
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
		cout << MENU_ACCONTS << endl;
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
		cout << MENU_DATA << endl;
		choice = input(0, 5);
		switch (choice)
		{
		case 1: showProjectVector(vector_of_works);
			break;
		case 2:
		{
			clearConsole();
			cout << ADD_REWRITE << endl;
			choice = input(0, 2);
			switch (choice)
			{
			case 1: addProjectsInVector(vector_of_works);
				break;
			case 2:
			{
				cout << SURE_DESTROY << endl;
				choice = input(1, 2);
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