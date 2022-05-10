#include "ViewData.h"

void showProjectVector(vector <TypeOfWork>& vector_of_works)
{
	clearConsole();
	if (printFileIsEmpty(vector_of_works))
		return;
	sortProjectByTypeOfWork(vector_of_works);
	int cost = 0, employees = 0, ammount_of_projects = 0, *pointer_ammount_of_projects = &ammount_of_projects;
	cout << "--------------------------------------------------------------------------" << endl;
	for (int i = 0, first = 0; i < vector_of_works.size(); i++, first++) // first - индекс первого типа работ в проекте
	{
		if (i == 0 || vector_of_works.at(i).project_name != vector_of_works.at(i - 1).project_name)
		{
			cout << setw(74) << "|" << endl << "Project: " << vector_of_works.at(i).project_name << setw(65 - vector_of_works.at(i).project_name.size()) << "|" << endl << setw(74) << "|" << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "| TYPE OF WORK | SURNAME OF THE EMPLOYEE | HOURS | COST/HOUR" << setw(16) << "| \n";
			*pointer_ammount_of_projects += 1;
		}
		cost += vector_of_works.at(i).ammount_of_hours * vector_of_works.at(i).cost_per_hour;
		cout << "|" << vector_of_works.at(i).name << setw(15 - vector_of_works.at(i).name.size())
			<< "|" << vector_of_works.at(i).FIO << setw(26 - vector_of_works.at(i).FIO.size())
			<< "|" << vector_of_works.at(i).ammount_of_hours << setw(8 - num(vector_of_works.at(i).ammount_of_hours))
			<< "|" << vector_of_works.at(i).cost_per_hour << '\t' << setw(18) << "|" << endl;
		vector_of_works.at(i).cost_of_type_of_work = vector_of_works.at(i).ammount_of_hours * vector_of_works.at(i).cost_per_hour;

		if (i + 1 == vector_of_works.size() || vector_of_works.at(i).project_name != vector_of_works.at(i + 1).project_name)
			showInfoAboutAllTypesOfWork(vector_of_works, cost, employees, first, i);
		else
			first--;
	}
	if (ammount_of_projects > 1)
		sortProjects(vector_of_works);
}
void showInfoAboutAllTypesOfWork(vector<TypeOfWork> vector_of_works, int& cost, int& employees, int& first, int i)
{
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "| Cost of project: " << cost << setw(55 - num(cost)) << "|" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	calculateTypeOfWork(vector_of_works, cost, employees, first, i, "Requirements");
	if (employees != 0)
	{
		cout << "|Work on requirements \tCost: ";
		cout << cost << "\t";
		cout << "Number of employees involved: ";
		cout << setw(4 - num(employees)) << employees << "|" << endl;
	}
	calculateTypeOfWork(vector_of_works, cost, employees, first, i, "Development");
	if (employees != 0)
	{
		cout << "|Development\t\tCost: ";
		cout << cost << "\t";
		cout << "Number of employees involved: ";
		cout << setw(4 - num(employees)) << employees << "|" << endl;
	}
	calculateTypeOfWork(vector_of_works, cost, employees, first, i, "Implementation");
	if (employees != 0)
	{
		cout << "|Implementation\t\tCost: ";
		cout << cost << "\t";
		cout << "Number of employees involved: ";
		cout << setw(4 - num(employees)) << employees << "|" << endl;
	}
	calculateTypeOfWork(vector_of_works, cost, employees, first, i, "Testing");
	if (employees != 0)
	{
		cout << "|Testing\t\tCost: ";
		cout << cost << "\t";
		cout << "Number of employees involved: ";
		cout << setw(4 - num(employees)) << employees << "|" << endl;
	}
	cout << "--------------------------------------------------------------------------" << endl;
	cost = 0;
	employees = 0;
}
void calculateTypeOfWork(vector<TypeOfWork> vector_of_works, int& cost, int& employees, int& first, int i, string type_of_work)
{
	cost = 0;
	employees = 0;
	while (first <= i)
	{
		if (vector_of_works.at(first).name == type_of_work)
		{
			cost += vector_of_works.at(first).cost_of_type_of_work;
			employees++;
			if ((first + 1) == vector_of_works.size() || vector_of_works.at(first).project_name != vector_of_works.at(first + 1).project_name)
				break;
			else
				first++;
		}
		else
			break;
	}
}
void sortProjectByTypeOfWork(vector<TypeOfWork>& vector_of_works)
{
	setPriorityOfTypeOfWork(vector_of_works);
	sort(vector_of_works.begin(), vector_of_works.end(), compareByPriorityOfTypeOfWork);
}
void setPriorityOfTypeOfWork(vector<TypeOfWork>& vector_of_works)
{
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		vector_of_works.at(i).priority_of_type_of_work = getPriorityOfTypeOfWork(vector_of_works.at(i).name);
	}
}
int getPriorityOfTypeOfWork(string name)
{
	if (name == "Requirements")
		return 4;
	if (name == "Development")
		return 3;
	if (name == "Implementation")
		return 2;
	if (name == "Testing")
		return 1;
}
bool compareByPriorityOfTypeOfWork(const TypeOfWork& first, const TypeOfWork& second)
{
	if (first.project_name == second.project_name)
		return first.priority_of_type_of_work > second.priority_of_type_of_work;
}
void showPersonalInformationAboutEmployee(vector<TypeOfWork>& search)
{
	sortProjectByTypeOfWork(search);
	int cost = 0, hours = 0;
	cout << "-----------------------------------------------------" << endl;
	cout << endl << "Employee: " << search.at(0).FIO << endl << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "|      POJECT      | TYPE OF WORK | HOURS | COST/HOUR|\n";
	for (int i = 0; i < search.size(); i++)
	{
		cost += search.at(i).ammount_of_hours * search.at(i).cost_per_hour;
		hours += search.at(i).ammount_of_hours;
		cout << "|" << search.at(i).project_name << setw(19 - search.at(i).project_name.size())
			<< "|" << search.at(i).name << setw(15 - search.at(i).name.size())
			<< "|" << search.at(i).ammount_of_hours << setw(8 - num(search.at(i).ammount_of_hours))
			<< "|" << search.at(i).cost_per_hour << '\t' << "    |" << endl;
		search.at(i).cost_of_type_of_work = search.at(i).ammount_of_hours * search.at(i).cost_per_hour;
		if (i + 1 == search.size() /*|| search.at(i).project_name != search.at(i + 1).project_name*/)
			showInfoAboutAllProjects(search, cost, hours, i);
	}
}
void showInfoAboutAllProjects(vector<TypeOfWork> search, int& cost, int& hours, int i)
{
	cout << "-----------------------------------------------------" << endl;
	cout << " Hours: " << hours << "\tEarnings: " << cost << endl;
	cout << "-----------------------------------------------------" << endl;
	// выводим более детальную информацию если сатрудник работает на нескольких проектах
	if (search.size() != 1)
	{
		for (int i = 0, first = 0; i < search.size(); i++, first++)
		{
			if (i + 1 == search.size() || search.at(i).project_name != search.at(i + 1).project_name)
			{
				calculateProject(search, cost, hours, first, i, search.at(i).project_name);
				cout << " Project: " << search.at(i).project_name << "\t";
				cout << "Hours: " << hours << "\t";
				cout << "Earnings: " << cost << endl;
			}
			else
				first--;
		}
		cout << "-----------------------------------------------------" << endl;
	}
	cost = 0;
	hours = 0;
}
void calculateProject(vector<TypeOfWork> search, int& cost, int& hours, int& first, int i, string project_name)
{
	cost = 0;
	hours = 0;
	while (first <= i)
	{
		if (search.at(first).project_name == project_name)
		{
			cost += search.at(first).cost_of_type_of_work;
			hours += search.at(first).ammount_of_hours;
			if ((first + 1) == search.size() || search.at(first).project_name != search.at(first + 1).project_name)
				break;
			else
				first++;
		}
		else
			break;
	}
}

int num(int x) //getCountOfNumbersInNumber
{
	int numbers = 1;
	while ((x /= 10) > 0)
		numbers++;
	return numbers;
}

void showListOfAccounts(vector <Account>& vector_of_accaunts)
{
	if (vector_of_accaunts.size() != 0)
	{
		clearConsole();
		//header
		cout << "-----------------------------------------" << endl;
		cout << "| # |      LOGIN      | ROLE |  STATUS  |" << endl;
		cout << "-----------------------------------------" << endl;
		for (int i = 0; i < vector_of_accaunts.size(); i++)
		{
			cout << "|" << i + 1 << setw(4 - num(i)) << "|" << vector_of_accaunts.at(i).login << setw(18 - vector_of_accaunts.at(i).login.size()) <<
				"|" << getRole(vector_of_accaunts.at(i).role) << /*setw(8 - size) <<*/
				"|" << getStatus(vector_of_accaunts.at(i).status) /*<< setw(11 - size)*/ << "|" << endl;
		}
		cout << "-----------------------------------------" << endl;
	}
}
string getStatus(int status)
{
	string s;
	switch (status)
	{
	case 0: s = "Unverified";
		break;
	case 1: s = "Activated ";
		break;
	case 2: s = "Blockeded ";
		break;
	}
	return s;
}
string getRole(int role)
{
	string s;
	switch (role)
	{
	case 1: s = "User  ";
		break;
	case 2:
	case 3: s = "Admin ";
		break;
	}
	return s;
}

void showApplications(vector <Account>& vector_of_accaunts)
{
	vector <Account> vector_unverified_accounts;
	clearConsole();
	for (int i = 0; i < vector_of_accaunts.size(); i++)
	{
		if (vector_of_accaunts.at(i).status == 0)
			vector_unverified_accounts.push_back(vector_of_accaunts.at(i));
	}
	if (vector_unverified_accounts.size() != 0)
	{
		showListOfAccounts(vector_unverified_accounts);
		int choice;
		while (vector_unverified_accounts.size() != 0)
		{
			cout << "Choose:\n1 Sort alphabetically\n2 Approve the application\n3 Deny the application\n0 Back" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: sortAccountByLogin(vector_unverified_accounts);
				break;
			case 2: approveApplication(vector_unverified_accounts, vector_of_accaunts);
				break;
			case 3: deleteApplication(vector_unverified_accounts, vector_of_accaunts);
				break;
			case 0: return; 
				break;
			}
			clearConsole();
			showListOfAccounts(vector_unverified_accounts);
		}
	}
	else
	{
		cout << "There are no outgoing requests for application" << endl;
		pause();
		clearConsole();
	}
}