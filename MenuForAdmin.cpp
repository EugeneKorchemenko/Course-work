#include "Structs.h"
#include "MenuForAdmin.h"
#include "ViewData.h"
#include "Delete.h"
#include "Edit.h"
#include "GenerateData.h"
#include "Search.h"
#include "AddProject.h"
#include "Sort.h"

void menuForAdmin(vector <TypeOfWork>& vector_of_works)
{
	int choice, n = 1;
	while (n != 0)
	{
		cout << "\t________MENU_______" << endl;
		cout << "1 Show information about project\n2 Add new project\n3 Edit project\n4 Search by projects\n5 Delete project\n0 Exit" << endl;
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