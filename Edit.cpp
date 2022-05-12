#include "Edit.h"

void chooseEditingProject(vector<TypeOfWork>& vector_of_works)
{
	clearConsole();
	vector <Project> vector_of_projects;
	int choice;
	if (printFileIsEmpty(vector_of_works))
		return;	cout << "Choose Project which you want to edit: " << endl;
	showProjects(vector_of_works, vector_of_projects);
	cout << endl << "Press 0 to turn back" << endl;
	cout << "Choice: ";
	choice = input() - 1;
	if (choice == -1)
		return;
	choice = vector_of_projects.at(choice).number_of_first_work;
	chooseKindOfEditing(vector_of_works, choice);
}
void showProjects(vector<TypeOfWork> vector_of_works, vector <Project>& vector_of_projects)
{
	for (int i = 0, j = 0; i < vector_of_works.size(); i++)
	{
		if (i == 0 || vector_of_works.at(i - 1).project_name != vector_of_works.at(i).project_name)
		{
			vector_of_projects.resize(vector_of_projects.size() + 1);
			vector_of_projects.at(j).name = vector_of_works.at(i).project_name;
			vector_of_projects.at(j).number_of_first_work = i;
			cout << j + 1 << " - " << vector_of_projects.at(j).name << endl;
			j++;
		}
	}
}
void chooseKindOfEditing(vector<TypeOfWork>& vector_of_works, int choice)
{
	clearConsole();
	int ed = 10;
	while (ed != 0)
	{
		cout << "\t\t_______EDITING_______" << endl;
		cout << "Project: " << vector_of_works.at(choice).project_name << endl << endl;
		cout << "1 Edit all information about project\n2 Edit name of project\n3 Edit employee\n4 Add employees in prject\n5 Delete employee from project\n0 Back" << endl;
		ed = input(0, 5);
		switch (ed)
		{
		case 1: // �������� ���� ������ �������
			editWholeProject(vector_of_works, choice);
			break;
		case 2:// ������ ��� � ���������� ���� ����� �������
			changeProjectName(vector_of_works, choice);
			break;
		case 3:// �������� ��������� ��� ����� � �������
			editEmployeeInProject(vector_of_works, choice);
			break;
		case 4:// ��������� ����������� � ������������ ������
			addEmployeesInProject(vector_of_works, choice);
			break;
		case 5:// ������� ����������� � ������������ ������
			deleteEmployee(vector_of_works, choice);
		case 0:return;
			break;
		}
	}
}
void editWholeProject(vector<TypeOfWork>& vector_of_works, int choice)
{
	string name;
	TypeOfWork work_temp;
	int size, em, approve;
	clearConsole();
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input();
	if (approve == 1)
	{
		clearConsole();
		name = vector_of_works.at(choice).project_name;
		for (int i = 0; i < vector_of_works.size(); i++)
		{
			if (vector_of_works.at(i).project_name == name)
			{
				vector_of_works.erase(vector_of_works.begin() + i);
				i--;
			}
		}
		writeFileProjects(vector_of_works);
		cout << "Enter how many employees include into project" << endl;
		em = input();
		vector_of_works.resize(vector_of_works.size() + em);
		size = vector_of_works.size();
		for (int m = (vector_of_works.size() - em); m < size; m++)
		{
			inputInformation(work_temp, name, vector_of_works);// ������������� ������� ���������� ��������� � Write.h
			vector_of_works.push_back(work_temp);
			writeEndFileProject(work_temp, vector_of_works);
		}
	}
	clearConsole();
}
void changeProjectName(vector<TypeOfWork>& vector_of_works, int choice)
{
	string new_name, name;
	int approve;
	clearConsole();
	name = vector_of_works.at(choice).project_name;
	cout << "Enter new name of project" << endl;
	inputLine(new_name, 18);
	cout << "Accept changes?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input();	
	if (approve == 1)
	{
		for (int i = 0; i < vector_of_works.size(); i++)
			if (vector_of_works.at(i).project_name == name)
				vector_of_works.at(i).project_name = new_name;
		writeFileProjects(vector_of_works);
	}
	clearConsole();
}
void editEmployeeInProject(vector<TypeOfWork>& vector_of_works, int choice)
{
	int i = 0;
	clearConsole();
	chooseEditingEmployee(vector_of_works, choice);
	inputInformation(vector_of_works, choice);
	writeFileProjects(vector_of_works);
	clearConsole();
}
void addEmployeesInProject(vector<TypeOfWork>& vector_of_works, int choice)
{
	TypeOfWork work_temp;
	string name = vector_of_works.at(choice).project_name;
	int number_of_employees;
	clearConsole();
	cout << "Enter how many employees do you want to add in project" << endl;
	number_of_employees = input(1, 100);
	for (int i = choice, j = choice; i < choice + number_of_employees; i++)
	{
		inputInformation(work_temp, name, vector_of_works);
		if (vector_of_works.size() == i)
			vector_of_works.push_back(work_temp);
		else
			vector_of_works.emplace(vector_of_works.begin() + i + 1, work_temp);
	}
	writeFileProjects(vector_of_works);
	clearConsole();
}
void deleteEmployee(vector<TypeOfWork>& vector_of_works, int choice)
{
	int descission, i = 0;
	clearConsole();
	chooseEditingEmployee(vector_of_works, choice);
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	descission = input();
	if (descission == 1)
	{
		vector_of_works.erase(vector_of_works.cbegin() + (choice - 1));
		writeFileProjects(vector_of_works);
	}
	clearConsole();
}
void chooseEditingEmployee(vector<TypeOfWork> vector_of_works, int& choice)
{
	int i = 0 , j = 0, first, last;
	cout << "----------------------------------" << endl;
	cout << "|  ID  | SURNAME OF THE EMPLOYEE |" << endl;
	cout << "----------------------------------" << endl;
	while (i != vector_of_works.size())
	{
		if (vector_of_works.at(i).project_name == vector_of_works.at(choice).project_name)
		{
			cout << "|" << i + 1 << setw(7 - num(i + 1)) << "|" << vector_of_works.at(i).FIO << setw(26 - vector_of_works.at(i).FIO.size()) << "|" << endl;
			j++; // ������� ���������� ��������� �����������
			if (j == 1)
				first = i + 1;
		}
		i++;
	}
	last = first - 1 + j;
	cout << "----------------------------------" << endl;
	cout << "Input ID of the employee: ";
	choice = input(first, last);
}

void delProjectFromVector(vector<TypeOfWork>& vector_of_works)
{
	int choice, descission;
	vector <Project> vector_of_projects;
	clearConsole();
	if (printFileIsEmpty(vector_of_works))
		return;
	cout << "_______DELITING_______" << endl;
	cout << "Choose Project which tou want to delete:" << endl;
	showProjects(vector_of_works, vector_of_projects);
	cout << endl << "Press 0 to turn back" << endl;
	cout << "Choice: ";
	choice = input(1, vector_of_projects.size()) - 1;
	if (choice != -1)
	{
		cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
		descission = input(1, 2);
		if (descission == 1)
		{
			string name = vector_of_works.at(choice).project_name;
			for (int i = 0; i < vector_of_works.size(); i++)
			{
				if (vector_of_works.at(i).project_name == name)
				{
					vector_of_works.erase(vector_of_works.begin() + i);
					i--;
				}
			}
		}
		writeFileProjects(vector_of_works);
	}
	clearConsole();
}


void editAccounts(vector <Account>& vector_of_accaunts, vector <TypeOfWork>& vector_of_works, string login)
{
	int choice, ed = 10;
	while (ed != 0)
	{
		clearConsole();
		cout << "\t\t_______EDITING_______" << endl;
		showListOfAccounts(vector_of_accaunts);
		cout << "Choose action:\n1 Add new account\n2 Delete account\n3 Block account\n4 Unlock accountt\n5 Change role of the account\n6 Change password\n0 Back" << endl;
		ed = input(0, 6);
		switch (ed)
		{
		case 1: singUp(vector_of_accaunts);
			break;
		case 2: deleteAccount(vector_of_accaunts, login);
			break;
		case 3: blockAccount(vector_of_accaunts, login);
			break;
		case 4: unlockAccount(vector_of_accaunts);
			break;
		case 5: changeRole(vector_of_accaunts, vector_of_works, login);
			break;
		case 6: 
		{
			choice = chooseAccount(vector_of_accaunts);
			changePassword(vector_of_accaunts, vector_of_accaunts.at(choice).login);
		}
		case 0:
			break;
		default:printOutofRangeInMenu(6);
		}
		clearConsole();
	}
	clearConsole();
}
void deleteAccount(vector <Account>& vector_of_accaunts, string login)
{
	int approve, choice;
	choice = chooseAccount(vector_of_accaunts);
	if (choice == -1)
		return;
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input();
	if (approve == 1)
	{
		if (vector_of_accaunts.at(choice).role == 3)
		{
			cout << "You can't delete head admin" << endl;
			pause();
			clearConsole();
			return;
		}
		vector_of_accaunts.erase(vector_of_accaunts.cbegin() + choice);
		writeFileAccounts(vector_of_accaunts);
		clearConsole();
		if (vector_of_accaunts.at(choice).login == login) // ���� ������� ���� ������� ������� � ����
			autorisatie();
	}
}
void blockAccount(vector <Account>& vector_of_accaunts, string login)
{
	int choice, approve;
	choice = chooseAccount(vector_of_accaunts);
	if (choice == -1)
		return;
	if (vector_of_accaunts.at(choice).role == 3)
	{
		cout << "You can't block main admin" << endl;
		pause();
		clearConsole();
		return;
	}
	if (vector_of_accaunts.at(choice).login == login)
	{
		cout << "You can't block yourself" << endl;
		pause();
		clearConsole();
		return;
	}
	if (vector_of_accaunts.at(choice).status == 0)
	{
		cout << "You have to activate this account first" << endl;
		pause();
		clearConsole();
		return;
	}
	if (vector_of_accaunts.at(choice).status == 2)
	{
		cout << "This account is already blocked" << endl;
		pause();
		clearConsole();
	}
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		vector_of_accaunts.at(choice).status = 2;
		writeFileAccounts(vector_of_accaunts);
		clearConsole();
	}
}
void unlockAccount(vector <Account>& vector_of_accaunts)
{
	int choice;
	choice = chooseAccount(vector_of_accaunts);
	if (choice == -1)
		return;
	if (vector_of_accaunts.at(choice).status == 0)
	{
		cout << "You have to activate this account first" << endl;
		pause();
		clearConsole();
	}
	if (vector_of_accaunts.at(choice).status == 1)
	{
		cout << "This account is already activated" << endl;
		pause();
		clearConsole();
	}
	if (vector_of_accaunts.at(choice).status == 2)
	{
		vector_of_accaunts.at(choice).status = 1;
		writeFileAccounts(vector_of_accaunts);
		clearConsole();
	}
}
void changeRole(vector <Account>& vector_of_accaunts, vector <TypeOfWork>& vector_of_works, string login)
{
	int approve, choice;
	choice = chooseAccount(vector_of_accaunts);
	if (choice == -1)
		return;
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		if (vector_of_accaunts.at(choice).role == 3)
		{
			clearConsole();
			cout << "You can't change role of head admin" << endl;
			pause();
			return;
		}
		if (vector_of_accaunts.at(choice).role == 1)
		{
			vector_of_accaunts.at(choice).role = 2;
			writeFileAccounts(vector_of_accaunts);
			return;
		}
		if (vector_of_accaunts.at(choice).role == 2)
		{
			if (vector_of_accaunts.at(choice).login == login)
			{
				clearConsole();
				cout << "You can't change your role" << endl;
				pause();
			}
			else
				vector_of_accaunts.at(choice).role = 1;
			writeFileAccounts(vector_of_accaunts);
			return;
		}
	}
}
int chooseAccount(vector <Account>& vector_of_accaunts)
{
	int choice;
	showListOfAccounts(vector_of_accaunts);
	cout << "Enter 0 to come back" << endl;
	cout << "Choose account which you want to edit:" << endl;
	choice = input(0, vector_of_accaunts.size());
	if (choice == 0)
		return -1;
	return choice - 1;
}
void changePassword(vector <Account>& vector_of_accaunts, string login)
{
	Account account_temp;
	string password1, password2;
	char approve;
	clearConsole();
	account_temp.login = login;
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input(1, 2);
	clearConsole();
	if (approve == 1)
	{
		if (!inputNewPassword(vector_of_accaunts, account_temp, password1, password2))// ���� ��������� false ������� �� �������
			return;
		cout << "Are you sure you want to change password?\nChoose:\t1 YES\t2 NO" << endl;
		approve = input(1, 2);
		if (approve == 1)
		{
			account_temp.password = password1;
			for (int i = 0; i < vector_of_accaunts.size(); i++)
			{
				if (account_temp.login == vector_of_accaunts.at(i).login)
				{
					vector_of_accaunts.at(i).hash_password_with_salt = sha256(sha256(account_temp.password + account_temp.salt) + sha256(account_temp.password));
					writeFileAccounts(vector_of_accaunts);
				}
			}
		}
		else
			return;
	}
}
bool inputNewPassword(vector <Account>& vector_of_accaunts, Account& account_temp, string& password1, string& password2)
{
	bool flag = false;
	char approve;
	int attempts = 0;
	while (flag == false)
	{
		if (attempts == 3)
		{
			cout << "The limit of attempts has been exceeded!!!" << endl;
			pause();
			clearConsole();
			return false;
		}
		cout << "Enter current password: ";
		hideInput(account_temp);
		flag = compareInputData(account_temp, vector_of_accaunts); // ��������� ��������� �� ������ ������� ������
		if (flag == true)
		{
			cout << "Enter new password: ";
			inputLine(password1, 20);
			cout << "Enter it again: ";
			inputLine(password2, 20);
			clearConsole();
			flag = isPasswordSuitable(account_temp, password1, password2);  // ��������� ��� ������ ��������� � ������������ ����� ���������� ( X+1 � ����� 5 ��������) flag == true
			if (flag == false)
			{
				cout << endl << "If you want go back press 0" << endl;
				approve = _getch();
				pause();
				clearConsole();
				if (approve == '0')
					return false;
			}
			else
				return true;
		}
		else
		{
			cout << "Incorrect  input. This password does not match the current " << endl;
			cout << endl << "If you want go back press 0" << endl;
			approve = _getch();
			clearConsole();
			if (approve == '0')
				return false;
			else
				continue;
		}
		attempts++; // ���������� �������
	}
}
void approveApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	clearConsole();
	showListOfAccounts(vector_unverified_accounts);
	int choice;
	cout << "Choose: \n1 Approve all\n2 Approve one\n0 Back" << endl;
	choice = input(0, 2);
	switch (choice)
	{
	case 1: approveAllApplications(vector_unverified_accounts, vector_of_accaunts);
		break;
	case 2: approveOneApplication(vector_unverified_accounts, vector_of_accaunts);
		break;
	case 0: return;
		break;
	default:printOutofRangeInMenu(2);
	}
	clearConsole();
	showListOfAccounts(vector_unverified_accounts);
}
void approveAllApplications(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	clearConsole();
	int approve;
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		for (int i = 0; i < vector_of_accaunts.size(); i++) // ������ ������ � ������� ���� ���������
		{
			if (vector_of_accaunts.at(i).status == 0)
			{
				vector_of_accaunts.at(i).status = 1;
				vector_unverified_accounts.clear();
			}
		}
	}
	clearConsole();
}
void approveOneApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	int choice, approve;
	cout << "Enter number of the appliction: ";
	choice = input(1, vector_unverified_accounts.size());
	clearConsole();
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		vector_unverified_accounts.at(choice - 1).status = 1;
		for (int i = 0; i < vector_of_accaunts.size(); i++) // ������ ������ � ������� ���� ���������
		{
			if (vector_unverified_accounts.at(choice - 1).login == vector_of_accaunts.at(i).login)
				vector_of_accaunts.at(i).status = 1;
		}
		vector_unverified_accounts.erase(vector_unverified_accounts.cbegin() + (choice - 1)); // ������� �� ������ ���������������� ���������
		writeFileAccounts(vector_of_accaunts); // ��������� ��������� ����
	}
	clearConsole();
}
void deleteApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	clearConsole();
	showListOfAccounts(vector_unverified_accounts);
	int choice;
	cout << "Choose: \t1 Delete all\t2 Delete one\t0 Back\n" << endl;
	choice = input(0, 2);
	switch (choice)
	{
	case 1: deleteAllApplications(vector_unverified_accounts, vector_of_accaunts);
		break;
	case 2: deleteOneApplication(vector_unverified_accounts, vector_of_accaunts);
		break;
	case 0: return;
		break;
	}
	clearConsole();
	showListOfAccounts(vector_unverified_accounts);
}
void deleteAllApplications(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	int approve;
	cout << "Are you sure?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		for (int i = 0; i < vector_of_accaunts.size(); i++) // ������ ������ � ������� ���� ���������
		{
			if (vector_of_accaunts.at(i).status == 0)
			{
				vector_of_accaunts.erase(vector_of_accaunts.cbegin() + i);
				vector_unverified_accounts.clear();
			}
		}
		writeFileAccounts(vector_of_accaunts);
	}
	clearConsole();
}
void deleteOneApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	int choice, approve;
	cout << "Enter number of the appliction: ";
	choice = input(1, vector_unverified_accounts.size());
	clearConsole();
	cout << "Are you sure?\nChoose:\n1 YES\n2 NO" << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		// ������� ������� �����
		for (int i = 0; i < vector_of_accaunts.size(); i++)
		{
			if (vector_unverified_accounts.at(choice - 1).login == vector_of_accaunts.at(i).login)
			{
				vector_of_accaunts.erase(vector_of_accaunts.cbegin() + i);
				vector_unverified_accounts.erase(vector_unverified_accounts.cbegin() + (choice - 1));
				writeFileAccounts(vector_of_accaunts);
			}
		}
	}
	clearConsole();
}