#include "Write.h"

void generateProjectsVector(vector<TypeOfWork>& vector_of_works)
{
	int choice, size = 0;
	clearConsole();
	cout << ADD_PROJECTS;
	choice = input();
	string name;
	vector_of_works.resize(0);
	for (int i = 0; i < choice; i++)
	{
		cout << ENTER_NAME_OF_PROJECT;
		inputLine(name, PROJECT_SIZE);
		cout << endl << HOW_MANY_EMPLOYEES;
		int em;
		em = input(1, 10);
		vector_of_works.resize(vector_of_works.size() + em);
		for (int m = size; m < vector_of_works.size(); m++)
		{
			vector_of_works.at(m).project_name = name;
			inputInformation(vector_of_works, m);
			size++;
		}
	}
	writeFileProjects(vector_of_works);
}
void inputInformation(vector<TypeOfWork>& vector_of_works, int m)
{
	while (1)
	{
		chooseWorkName(vector_of_works, m);
		cout << ENTER_SURNAME;
		inputLine(vector_of_works.at(m).FIO, SURNAME_SIZE);
		if (chekIfEmployeeDoSameWorkOnProject(vector_of_works, m))
		{
			continue;
			clearConsole();
		}
		cout << endl << ENTER_HOURS;
		vector_of_works.at(m).ammount_of_hours = input(1, MAX_HOURS);
		cout << "Enter " << vector_of_works.at(m).FIO << "'s hourly cost: ";
		vector_of_works.at(m).cost_per_hour = input(1, MAX_COST_OF_HOUR);
		break;
	}
}
void chooseWorkName(vector<TypeOfWork>& vector_of_works, int m)
{
	int n = 10;
	cout << CHOOSE_TYPE_OF_WORK << endl;
	n = input(1, 4);
	switch (n)
	{
	case 1: vector_of_works.at(m).name = "Requirements";
		break;
	case 2: vector_of_works.at(m).name = "Development";
		break;
	case 3: vector_of_works.at(m).name = "Implementation";
		break;
	case 4: vector_of_works.at(m).name = "Testing";
		break;
	}
}
void writeFileProjects(vector<TypeOfWork> vector_of_works)
{
	ofstream fout(FILE_DATA, ios::out);
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		fout << vector_of_works.at(i).project_name << "\t"
			<< vector_of_works.at(i).name << "\t"
			<< vector_of_works.at(i).FIO << "\t"
			<< vector_of_works.at(i).ammount_of_hours << "\t"
			<< vector_of_works.at(i).cost_per_hour;
		if (i < vector_of_works.size() - 1)
			fout << "\n";
	}
	fout.close();
}

void addProjectsInVector(vector<TypeOfWork>& vector_of_works)
{
	TypeOfWork work_temp;
	clearConsole();
	if (printFileIsEmpty(vector_of_works))
		return;
	cout << ADD_PROJECTS;
	int choice;
	choice = input();
	string name;
	for (int i = 0, employees = 0; i < choice; i++)
	{
		cout << ENTER_NAME_OF_PROJECT;
		inputLine(name, PROJECT_SIZE);
		cout << HOW_MANY_EMPLOYEES;
		employees = input(1, 100);
		for (int m = 0; m < employees; m++)
		{
			inputInformation(work_temp, name, vector_of_works);
			vector_of_works.push_back(work_temp);
			writeEndFileProject(work_temp, vector_of_works);
		}
	}
}
void inputInformation(TypeOfWork& work_temp, string name, vector<TypeOfWork> vector_of_works)
{
	while (1)
	{
		work_temp.project_name = name;
		chooseWorkName(work_temp);
		cout << ENTER_SURNAME;
		inputLine(work_temp.FIO, SURNAME_SIZE);
		if (chekIfEmployeeDoSameWorkOnProject(work_temp, vector_of_works))
		{
			continue;
			clearConsole();
		}
		cout << ENTER_HOURS;
		work_temp.ammount_of_hours = input(1, MAX_HOURS);
		cout << "Enter " << work_temp.FIO << "'s hourly cost: ";
		work_temp.cost_per_hour = input(1, MAX_COST_OF_HOUR);
		break;
	}
}
void chooseWorkName(TypeOfWork& work)
{
	int n = 10;
	cout << CHOOSE_TYPE_OF_WORK << endl;
	n = input(1, 4);
	switch (n)
	{
	case 1: work.name = "Requirements";
		break;
	case 2: work.name = "Development";
		break;
	case 3: work.name = "Implementation";
		break;
	case 4: work.name = "Testing";
		break;
	}
}
void writeEndFileProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works)
{
	ofstream fout(FILE_DATA, ios::app);
	if (!fout.is_open())
		cout << "File doesn't exist";
	else
	{
		fout << "\n" << work_temp.project_name << "\t"
			<< work_temp.name << "\t"
			<< work_temp.FIO << "\t"
			<< work_temp.ammount_of_hours << "\t"
			<< work_temp.cost_per_hour;
	}
	fout.close();
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

void writeFileAccounts(vector<Account> vector_of_accaunts)
{
	ofstream fout(FILE_ACCOUNTS, ios::out);
	for (int i = 0; i < vector_of_accaunts.size(); i++)
	{
		fout << vector_of_accaunts.at(i).login << "\t"
			<< vector_of_accaunts.at(i).salt << "\t"
			<< vector_of_accaunts.at(i).hash_password_with_salt << "\t"
			<< vector_of_accaunts.at(i).role << "\t"
			<< vector_of_accaunts.at(i).status;
		if (i < vector_of_accaunts.size() - 1)
			fout << "\n";
	}
	fout.close();
}
void writeAccountInTheEnd(Account& account_temp)
{
	ofstream fout(FILE_ACCOUNTS, ios::app);
	if (!fout.is_open())
		cout << "File doesn't exist";
	else
	{
		fout << "\n" << account_temp.login << "\t"
			<< account_temp.salt << "\t"
			<< account_temp.hash_password_with_salt << "\t"
			<< account_temp.role << "\t"
			<< account_temp.status;
	}
	fout.close();
}
void rewriteAccount(Account& account_temp)
{
	ofstream fout(FILE_ACCOUNTS, ios::out);
	if (!fout.is_open())
		cout << "File doesn't exist";
	else
	{
		fout << account_temp.login << "\t"
			<< account_temp.salt << "\t"
			<< account_temp.hash_password_with_salt << "\t"
			<< account_temp.role << "\t"
			<< account_temp.status;
	}
	fout.close();
}