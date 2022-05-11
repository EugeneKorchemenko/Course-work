#include "MenuForUser.h"

void menuForUser(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works, string login)
{
	int n = 1;
	while (n != 0)
	{
		clearConsole();
		cout << "\tMode: User" << endl;
		cout << "\t________MENU_______" << endl;
		cout << "1 Show information about projects\n2 Search by projects\n3 Change password\n0 Exit" << endl;
		n = input();
		switch (n)
		{
		case 1: showProjectVector(vector_of_works);
			break;
		case 2: searchForProject(vector_of_works);
			break;
		case 3: changePassword(vector_of_accaunts, login);
			break;
		case 0: break;
		default:printOutofRangeInMenu(3);
		}
	}
	//clearConsole();
}