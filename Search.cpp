#include "Structs.h"
#include "Search.h"
#include "ViewData.h"

void searchForProject(vector<TypeOfWork> vector_of_works)
{
	cout << "\t\t________SEARCH________" << endl;
	cout << "Enter the parameters by which the search will be performed:" << endl;
	cout << "1)Project name\n2)Ammount of employees\n3)FIO of employee\n4)Cost of the project\n";
	int choice;
	vector<TypeOfWork> search;
	cin >> choice;
	switch (choice)
	{
	case 1: seerchProjectByName(vector_of_works, search);
		break;
	case 2: searchProjectByAmmountOfEmployees(vector_of_works, search);
		break;
	case 3: searchProjectsWhereEmployeeWork(vector_of_works, search);
		break;
	case 4: searchProjectsWithSuitableCost(vector_of_works, search);
		break;
	}
	search.clear();
}
void seerchProjectByName(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search)
{
	string name;
	cout << "Enter name of the project: ";
	cin >> name;
	cout << endl;
	for (int i = 0, k = 0; i < vector_of_works.size(); i++)
	{
		if (vector_of_works.at(i).project_name == name)
		{
			search.resize(search.size() + 1);
			search.at(k) = vector_of_works.at(i);
			k++;
		}
	}
	if (!search.empty())
		showProjectVector(search);
	else
		cout << "There isn't any project with the same name" << endl;
}
void searchProjectByAmmountOfEmployees(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search)
{
	int choice;
	bool flag = false;
	cout << "Enter ammount of employees in the project: ";
	cin >> choice;
	cout << endl;
	// считаем количество работников в проекте
	countAmmountOfEmploeyeesInProject(vector_of_works, search, choice, flag);
	if (flag == false)
		cout << "There isn't any project with the same ammount of employees" << endl;
	else
		showProjectVector(search);
}
void countAmmountOfEmploeyeesInProject(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search, int choice, bool& flag)
{
	int ammount_of_employees = 0;
	for (int i = 0, writed_emploeeys = 0, j = 0, first_employee_of_project = 0; i < vector_of_works.size(); i++)
	{
		if (i == 0 || vector_of_works.at(i).project_name == vector_of_works.at(j).project_name)
			ammount_of_employees++;
		if (vector_of_works.at(i).project_name != vector_of_works.at(j).project_name || i + 1 == vector_of_works.size())
		{
			if (ammount_of_employees < choice)
			{
				ammount_of_employees = 1;
				j = i;
				continue;
			}
			else
			{
				first_employee_of_project = j; //first_employee_of_project и j - первый сотрудник запиываемого проекта
				// переписываем проект в вектор
				while (writed_emploeeys < ammount_of_employees)
				{
					search.push_back(vector_of_works.at(j));
					writed_emploeeys++;
					j++;
				}
				findRepeatingEmployees(search, ammount_of_employees); //  ищем повторяющихся сотрудников, если нашли то уменьшоем количество сотрудников (изначльно считвем количество видов работ)
				if (ammount_of_employees == choice)
					flag = true;
				else
					search.erase(search.cbegin() + first_employee_of_project, search.cend());
			}
			ammount_of_employees = 1;
			writed_emploeeys = 0;
		}
	}
}
void findRepeatingEmployees(vector<TypeOfWork> search, int& ammount_of_employees)
{
	for (int n = 0; n < search.size() - 1; n++)
	{
		for (int m = n + 1; m < search.size(); m++)
		{
			if (search.at(m).FIO == search.at(n).FIO)
				ammount_of_employees--; //уменьшаем счетчик сотрудников на проекте
		}
	}
}
void searchProjectsWhereEmployeeWork(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search)
{
	string name;
	cout << "Enter the employee you wnat to find: ";
	cin >> name;
	cout << endl;
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		if (vector_of_works.at(i).FIO == name)
			search.push_back(vector_of_works.at(i));
	}
	if (!search.empty())
		showPersonalInformationAboutEmployee(search);
	else
		cout << "There isn't any project with this employee" << endl;
}
void searchProjectsWithSuitableCost(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search)
{
	int min_cost, max_cost, cost = 0;
	cout << "Enter the lower limit of the range: ";
	cin >> min_cost;
	cout << "Enter the upper limit of the range: ";
	cin >> max_cost;
	for (int i = 0, j = 0; i < vector_of_works.size(); i++)
	{
		if (i == 0 || vector_of_works.at(i).project_name == vector_of_works.at(i - 1).project_name)
			cost += vector_of_works.at(i).ammount_of_hours * vector_of_works.at(i).cost_per_hour;
		else
		{
			if (cost > max_cost || cost < min_cost)
			{
				cost = 0;
				j = i;
				continue;
			}
			else
			{
				writeProjectInVector(vector_of_works, search, j, i - 1);
				j = i;
				cost = 0;
			}
		}
	}
	if (!search.empty())
		showProjectVector(search);
	else
		cout << "There isn't any project with the same cost" << endl;
}
void writeProjectInVector(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search, int j, int i)
{
	while (j != vector_of_works.size())
	{
		if (j == 0 || vector_of_works.at(j).project_name == vector_of_works.at(i).project_name)
		{
			search.push_back(vector_of_works.at(j));
			j++;
		}
		else
			break;
	}
}