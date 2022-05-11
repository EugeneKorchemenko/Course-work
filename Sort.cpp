#include "Sort.h"

void sortProjects(vector<TypeOfWork> vector_of_works)
{
	vector <Project> vector_of_projects;
	vector <TypeOfWork> sorted;
	int choice = 10;
	while (choice != 0)
	{
		cout << "\t\t________SORT________" << endl;
		cout << "Choose how you want to sort projects:" << endl;
		cout << "1 By project's cost\n2 By ammount of employees\n3 By name\n0 Exit view" << endl;
		choice = input();
		switch (choice)
		{
		case 1: sortProjectsByCost(sorted, vector_of_projects, vector_of_works);
			break;
		case 2: sortProjectsByAmmountOfEmployees(sorted, vector_of_projects, vector_of_works);
			break;
		case 3: sortProjectsByName(sorted, vector_of_works);
			break;
		case 0:
			break;
		default:printOutofRangeInMenu(4);
		}
	}
}
void sortProjectsByCost(vector<TypeOfWork>& sorted, vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works)
{
	int choice;
	clearConsole();
	cout << "Choose how you wnat to sort projects\n1)By cost ascending\n2)By cost descending" << endl;
	choice = input();
	countCostOfProjects(vector_of_projects, vector_of_works);
	if (choice == 1)
		sort(vector_of_projects.begin(), vector_of_projects.end(), compareByCostAscending);
	else
		sort(vector_of_projects.begin(), vector_of_projects.end(), compareByCostDescending);
	writeSortedVectorOfProjects(sorted, vector_of_projects, vector_of_works);
	clearConsole();
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
	clearConsole();
	cout << "Choose how you wnat to sort projects\n1)By ascending of number of employees\n2)By descending of number of employees" << endl;
	choice = input();
	countAmmountOfEmployees(vector_of_projects, vector_of_works);
	if (choice == 1)
		sort(vector_of_projects.begin(), vector_of_projects.end(), compareByAscendingOfEmployees);
	else
		sort(vector_of_projects.begin(), vector_of_projects.end(), compareByCostDescendingOfEmployees);
	writeSortedVectorOfProjects(sorted, vector_of_projects, vector_of_works);
	clearConsole();
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
	clearConsole();
	cout << "Choose how you wnat to sort projects\n1)By A-Z\n2)By Z-A" << endl;
	choice = input();
	for (int i = 0; i < vector_of_works.size(); i++)
		sorted.push_back(vector_of_works.at(i));
	if (choice == 1)
		sort(sorted.begin(), sorted.end(), compareByNameAscending);
	else
		sort(sorted.begin(), sorted.end(), compareByNameDescending);
	clearConsole();
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

void sortAccounts(vector <Account> vector_of_accaunts)
{
	int choice = 10;
	while (choice != 0)
	{
		cout << "\t\t________SORT________" << endl;
		cout << "Choose how you want to sort accounts:\n1 By login\n2 By Role\n3 By status\n0 Exit view" << endl;
		choice = input();
		switch (choice)
		{
		case 1: sortAccountByLogin(vector_of_accaunts);
			break;
		case 2: sortAccountByRole(vector_of_accaunts);
			break;
		case 3: sortAccountByStatus(vector_of_accaunts);
			break;
		case 0:
			break;
		default:printOutofRangeInMenu(4);
		}
	}
}
void sortAccountByLogin(vector <Account> vector_of_accaunts)
{
	int choice;
	clearConsole();
	cout << "Choose how you wnat to sort logins\n1)By A-Z\n2)By Z-A" << endl;
	choice = input();
	if (choice == 1)
		sort(vector_of_accaunts.begin(), vector_of_accaunts.end(), compareByLoginAscending);
	else
		sort(vector_of_accaunts.begin(), vector_of_accaunts.end(), compareByLoginDescending);
	clearConsole();
	//showListOfAccounts(vector_of_accaunts);
	//sortAccounts(vector_of_accaunts);
}
bool compareByLoginAscending(const Account& first, const Account& second)
{
	return first.login < second.login;
}
bool compareByLoginDescending(const Account& first, const Account& second)
{
	return first.login > second.login;
}
void sortAccountByRole(vector <Account> vector_of_accaunts)
{
	sort(vector_of_accaunts.begin(), vector_of_accaunts.end(), compareByRole);
	clearConsole(); 
	showListOfAccounts(vector_of_accaunts);
	sortAccounts(vector_of_accaunts);
}
bool compareByRole(const Account& first, const Account& second)
{
	return first.role > second.role;
}
void sortAccountByStatus(vector <Account> vector_of_accaunts)
{
	sort(vector_of_accaunts.begin(), vector_of_accaunts.end(), compareByStatus);
	clearConsole();
	showListOfAccounts(vector_of_accaunts);
	sortAccounts(vector_of_accaunts);
}
bool compareByStatus(const Account& first, const Account& second)
{
	return first.status > second.status;
}