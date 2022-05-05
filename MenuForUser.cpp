
#include "MenuForUser.h"

void menuForUser(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works)
{
	vector_of_works.resize(getCountOfTypesOfWorkInFile(FILE_DATA));
	doesFileExist(vector_of_works);
	int choice, n = 1;
	while (n != 0)
	{
		cout << "\t________MENU_______" << endl;
		cout << "1 Show information about projects\n2 Search by projects\n0 Exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			showProjectVector(vector_of_works);
			break;
		case 2:
			searchForProject(vector_of_works);
			break;
		case 0: break;
		default:
			cout << "Invalid input. Please try again" << endl;
		}
	}
}