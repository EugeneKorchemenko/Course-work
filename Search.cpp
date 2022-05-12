#include "Search.h"

void searchForProject(vector<TypeOfWork> vector_of_works)
{
	clearConsole();
	int choice = 10;
	vector<TypeOfWork> search;
	if (printFileIsEmpty(vector_of_works))
		return;
	while (choice != 0)
	{
		cout << "\t\t________SEARCH________" << endl;
		cout << "Enter the parameters by which the search will be performed:" << endl;
		cout << "1 Project name\n2 Ammount of employees\n3 FIO of employee\n4 Cost of the project\n0 Exit" << endl;
		choice = input(0, 4);
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
		case 0:
			break;
		}
		search.clear();
	}
}
void seerchProjectByName(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search)
{
	string name;
	clearConsole();
	cout << "Enter name of the project: ";
	inputLine(name, 18);
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
	{
		showProjectVector(search);
		clearConsole();
	}
	else
	{
		clearConsole();
		cout << "There isn't any project with the same name" << endl;
		pause();
		clearConsole();
	}
}
void searchProjectByAmmountOfEmployees(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search)
{
	int choice;
	bool flag = false;
	clearConsole();
	cout << "Enter ammount of employees in the project: ";
	choice = input(0, 100);
	cout << endl;
	// считаем количество работников в проекте
	countAmmountOfEmploeyeesInProject(vector_of_works, search, choice, flag);
	clearConsole();
	if (flag == false)
	{
		cout << "There isn't any project with the same ammount of employees" << endl;
		pause();
		clearConsole();
	}
	else
	{
		showProjectVector(search);
		pause();
		clearConsole();
	}
}
void countAmmountOfEmploeyeesInProject(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search, int choice, bool& flag)
{
	for (int i = 0, j = 0, firs_employee_in_project = 0, ammount_of_employees = 0, num = 0; i < vector_of_works.size(); i++)
	{
		if (vector_of_works.at(i).project_name == vector_of_works.at(firs_employee_in_project).project_name)
			ammount_of_employees++;
		if (i + 1 == vector_of_works.size() || vector_of_works.at(i).project_name != vector_of_works.at(firs_employee_in_project).project_name)
		{
			if (ammount_of_employees < choice)
			{
				firs_employee_in_project = i;
				ammount_of_employees = 1;
				continue;
			}
			else
			{
				j = firs_employee_in_project;
				num = search.size(); // номер первого записывемого в векторе поиска
				if (search.empty())
					firs_employee_in_project = 0;
				while (j < i)
				{
					search.push_back(vector_of_works.at(j));
					j++;
				}
				findRepeatingEmployees(search, ammount_of_employees);
				if (ammount_of_employees == choice)
					flag = true;
				else
					search.erase(search.cbegin() + num, search.cend());
			}
			ammount_of_employees = 1;
			if (i + 1 == vector_of_works.size() && (/*choice == ammount_of_employees ||*/ vector_of_works.at(i).project_name == vector_of_works.at(firs_employee_in_project).project_name))
			{
				search.push_back(vector_of_works.at(i));
				flag = true;
			}
			if (vector_of_works.size() - i + 1 == choice && i + 1 != vector_of_works.size())
			{
				search.push_back(vector_of_works.at(i));
				flag = true;
			}
			if (i + 1 == vector_of_works.size() == choice && choice == ammount_of_employees && vector_of_works.at(i).project_name != vector_of_works.at(i - 1).project_name)
			{
				search.push_back(vector_of_works.at(i));
				flag = true;
			}
			firs_employee_in_project = i;
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
	clearConsole();
	cout << "Enter the employee you wnat to find: ";
	inputLine(name, 25);
	cout << endl;
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		if (vector_of_works.at(i).FIO == name)
			search.push_back(vector_of_works.at(i));
	}
	clearConsole();
	if (!search.empty())
	{
		showPersonalInformationAboutEmployee(search);
		clearConsole();
	}
	else
	{
		cout << "There isn't any project with this employee" << endl;
		pause();
		clearConsole();
	}
}
void searchProjectsWithSuitableCost(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search)
{
	int min_cost, max_cost, cost = 0;
	clearConsole();
	cout << "Enter the lower limit of the range: ";
	min_cost = input(0, pow(10, 6));
	cout << "Enter the upper limit of the range: ";
	max_cost = input(min_cost, pow(10, 8));
	for (int i = 0, j = 0; i < vector_of_works.size(); i++)
	{
		if (i == 0 || vector_of_works.at(i).project_name == vector_of_works.at(j).project_name)
			cost += vector_of_works.at(i).ammount_of_hours * vector_of_works.at(i).cost_per_hour;
		if (vector_of_works.at(i).project_name != vector_of_works.at(j).project_name || i + 1 == vector_of_works.size())
		{
			if (cost > max_cost || cost < min_cost)
			{
				cost = 0;
				j = i;
				if (i + 1 == vector_of_works.size() || vector_of_works.at(i - 1).project_name != vector_of_works.at(j).project_name) // иначе никогда не выйдем
					i--;
				continue;
			}
			else
			{
				if (i + 1 == vector_of_works.size())
					writeProjectInVector(vector_of_works, search, j, i);
				else
					writeProjectInVector(vector_of_works, search, j, i - 1);
				j = i;
				if (i + 1 != vector_of_works.size())
					i--;
				cost = 0;
			}
		}
	}
	clearConsole();
	if (!search.empty())
	{
		showProjectVector(search);
		clearConsole();
	}
	else
	{
		cout << endl << "There isn't any project with the same cost" << endl;
		pause();
		clearConsole();
	}
}