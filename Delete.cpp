#include "Delete.h"

void delProjectsFromVector(vector<TypeOfWork>& vector_of_works)
{
	int choice;
	cout << "_______DELITING_______" << endl;
	cout << "Choose Project which tou want to delete:" << endl;
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		if (i == 0 || vector_of_works.at(i - 1).project_name != vector_of_works.at(i).project_name)
			cout << i + 1 << ")" << vector_of_works.at(i).project_name << endl;// исправитьь номер проекта
	}
	cin >> choice;
	string name = vector_of_works.at(choice - 1).project_name;
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		if (vector_of_works.at(i).project_name == name)
		{
			vector_of_works.erase(vector_of_works.begin() + i);
			i--;
		}
	}
	writeFileProjects(vector_of_works);
}