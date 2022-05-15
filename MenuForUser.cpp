#include "MenuForUser.h"

void menuForUser(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works, string login)
{
	int n = 1;
	while (n != 0)
	{
		clearConsole();
		cout << MENU_USER << endl;
		n = input(0, 3);
		switch (n)
		{
		case 1: showProjectVector(vector_of_works);
			break;
		case 2: searchForProject(vector_of_works);
			break;
		case 3: changePassword(vector_of_accaunts, login);
			break;
		case 0: break;
		}
	}
	clearConsole();
}