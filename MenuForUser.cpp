#include "MenuForUser.h"

void menuForUser(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works, string login)
{
	vector_of_works.resize(getCountOfTypesOfWorkInFile(FILE_DATA));
	doesFileExist(vector_of_works);
	int n = 1;
	while (n != 0)
	{
		clearConsole();
		cout << "\tMode: User" << endl;
		cout << "Choose:\n1 Show information about projects\n2 Search by projects\n3 Change password\n0 Exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1: showProjectVector(vector_of_works);
			break;
		case 2: searchForProject(vector_of_works);
			break;
		case 3: changePassword(vector_of_accaunts, login);
			break;
		case 0: break;
		default:
		{
			cout << "Invalid input. Please try again" << endl;
			pause();
		}
		}
	}
	clearConsole();
}