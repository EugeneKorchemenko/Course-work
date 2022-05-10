#include "Write.h"

void generateProjectsVector(vector<TypeOfWork>& vector_of_works)
{
	int choice, size = 0;
	clearConsole();
	cout << "Enter how many projects do you want to add" << endl;
	choice = input();
	string name;
	vector_of_works.resize(0);
	for (int i = 0; i < choice; i++)
	{
		cout << "Enter name of the project (max size is 18):" << endl;
		inputLine(name, 18);
		cout << "Enter how many employees include into project" << endl;
		int em;
		em = input();
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
	chooseWorkName(vector_of_works, m);
	cout << "Enter FIO of employee (max size is 25)" << endl;
	inputLine(vector_of_works.at(m).FIO,25);
	cout << "Enter ammount of hours" << endl;
	vector_of_works.at(m).ammount_of_hours = input();
	cout << "Enter " << vector_of_works.at(m).FIO << "'s hourly cost" << endl;
	vector_of_works.at(m).cost_per_hour = input();
}
void chooseWorkName(vector<TypeOfWork>& vector_of_works, int m)
{
	int n;
	cout << "Choose type of work" << endl;
	cout << "1)Work on requirements\n2)Development\n3)Implementation\n4)Testing" << endl;
	n = input();
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
	cout << "Enter how many projects you want to add" << endl;
	int choice;
	choice = input();
	string name;
	for (int i = 0, employees = 0; i < choice; i++)
	{
		cout << "Enter name of the project: (max size is 18)" << endl;
		inputLine(name, 18);
		cout << "Enter how many employees include into project" << endl;
		employees = input();
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
		cout << "Enter FIO of employee (max size is 25)" << endl;
		inputLine(work_temp.FIO, 25);
		cout << "Enter ammount of hours" << endl;
		work_temp.ammount_of_hours = input();
		cout << "Enter " << work_temp.FIO << "'s hourly cost" << endl;
		work_temp.cost_per_hour = input();
		if (chekIfEmployeeDoSameWorkOnProject(work_temp, vector_of_works))
			break;
		else
			continue;
	}
}
void chooseWorkName(TypeOfWork& work)
{
	int n;
	cout << "Choose type of work" << endl;
	cout << "1)Work on requirements\n2)Development\n3)Implementation\n4)Testing" << endl;
	n = input();
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