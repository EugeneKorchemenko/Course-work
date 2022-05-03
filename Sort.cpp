#include "Structs.h"
#include "Sort.h"
#include "ViewData.h"
#include "Search.h"

void sortProjects(vector<TypeOfWork> vector_of_works)
{
	vector <Project> vector_of_projects;
	vector <TypeOfWork> sorted;
	int choice = 0;
	cout << "\t\t________SORT________" << endl;
	cout << "Choose how you want to sort projects:" << endl;
	cout << "1)By project's cost\n2)By ammount of employees\n3)By name\n0)Exit view" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: sortProjectsByCost(sorted, vector_of_projects, vector_of_works);
		break;
	case 2: sortProjectsByAmmountOfEmployees(sorted, vector_of_projects, vector_of_works);
		break;
	case 3: sortProjectsByName(sorted, vector_of_works);
		break;
	case 0: break;
	}
}
void sortProjectsByCost(vector<TypeOfWork>& sorted, vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works)
{
	int choice;
	cout << "Choose how you wnat to sort projects\n1)By cost ascending\n2)By cost descending" << endl;
	cin >> choice;
	countCostOfProjects(vector_of_projects, vector_of_works);
	if (choice == 1)
		sort(vector_of_projects.begin(), vector_of_projects.end(), compareByCostAscending);
	else
		sort(vector_of_projects.begin(), vector_of_projects.end(), compareByCostDescending);
	writeSortedVectorOfProjects(sorted, vector_of_projects, vector_of_works);
	showProjectVector(sorted);
}
void countCostOfProjects(vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works)
{
	for (int i = 0, j = 0; i < vector_of_works.size(); j++)
	{
		if (i == 0 || vector_of_works.at(i).project_name != vector_of_works.at(i - 1).project_name)
		{
			vector_of_projects.resize(j + 1);
			vector_of_projects.at(j).name = vector_of_works.at(i).project_name;
			while (i < vector_of_works.size() && vector_of_works.at(i).project_name == vector_of_projects.at(j).name)
			{
				vector_of_projects.at(j).cost += vector_of_works.at(i).ammount_of_hours * vector_of_works.at(i).cost_per_hour;
				i++;
			}
		}

	}
}
bool compareByCostAscending(const Project& first, const Project& second)
{
	return first.cost < second.cost;
}
bool compareByCostDescending(const Project& first, const Project& second)
{
	return first.cost > second.cost;
}
void writeSortedVectorOfProjects(vector<TypeOfWork>& sorted, vector <Project> vector_of_projects, vector<TypeOfWork> vector_of_works)
{
	for (int i = 0, j = 0; j < vector_of_projects.size(); j++)
	{
		while (i < vector_of_works.size())
		{
			if (vector_of_works.at(i).project_name == vector_of_projects.at(j).name)
				sorted.push_back(vector_of_works.at(i));
			i++;
		}
		i = 0;
	}
}
void sortProjectsByAmmountOfEmployees(vector<TypeOfWork>& sorted, vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works)
{
	int choice;
	cout << "Choose how you wnat to sort projects\n1)By ascending of number of employees\n2)By descending of number of employees" << endl;
	cin >> choice;
	countAmmountOfEmployees(vector_of_projects, vector_of_works);
	if (choice == 1)
		sort(vector_of_projects.begin(), vector_of_projects.end(), compareByAscendingOfEmployees);
	else
		sort(vector_of_projects.begin(), vector_of_projects.end(), compareByCostDescendingOfEmployees);
	writeSortedVectorOfProjects(sorted, vector_of_projects, vector_of_works);
	showProjectVector(sorted);
}
void countAmmountOfEmployees(vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works)
{
	for (int i = 0, j = 0; i < vector_of_works.size(); j++)
	{
		if (i == 0 || vector_of_works.at(i).project_name != vector_of_works.at(i - 1).project_name)
		{
			vector_of_projects.resize(j + 1);
			vector_of_projects.at(j).name = vector_of_works.at(i).project_name;
			while (i < vector_of_works.size() && vector_of_works.at(i).project_name == vector_of_projects.at(j).name)
			{
				vector_of_projects.at(j).ammount_of_employees++;
				i++;
			}
			findRepeatingEmployees(vector_of_works, vector_of_projects.at(j).ammount_of_employees);
		}
	}
}
bool compareByAscendingOfEmployees(const Project& first, const Project& second)
{
	return first.ammount_of_employees < second.ammount_of_employees;
}
bool compareByCostDescendingOfEmployees(const Project& first, const Project& second)
{
	return first.ammount_of_employees > second.ammount_of_employees;
}
void sortProjectsByName(vector<TypeOfWork>& sorted, vector <TypeOfWork> vector_of_works)
{
	int choice;
	cout << "Choose how you wnat to sort projects\n1)By A-Z\n2)By Z-A" << endl;
	cin >> choice;
	for (int i = 0; i < vector_of_works.size(); i++)
		sorted.push_back(vector_of_works.at(i));
	if (choice == 1)
		sort(sorted.begin(), sorted.end(), compareByNameAscending);
	else
		sort(sorted.begin(), sorted.end(), compareByNameDescending);
	showProjectVector(sorted);
}
bool compareByNameAscending(const TypeOfWork& first, const TypeOfWork& second)
{
	return first.project_name < second.project_name;
}
bool compareByNameDescending(const TypeOfWork& first, const TypeOfWork& second)
{
	return first.project_name > second.project_name;
}