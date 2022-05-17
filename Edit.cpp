#include "Edit.h"

void chooseEditingProject(vector<TypeOfWork>& vector_of_works)
{
	clearConsole();
	vector <Project> vector_of_projects;
	int choice;
	if (printFileIsEmpty(vector_of_works))
		return;	
	cout << CHOOSE_EDITING_PROJECT << endl;
	showProjects(vector_of_works, vector_of_projects);
	cout << endl << O_TO_TURN_BACK << endl;
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
		cout << EDIT_DATA << endl;
		ed = input(0, 5);
		switch (ed)
		{
		case 1: // изменяет весь проект целиком
			editWholeProject(vector_of_works, choice);
			break;
		case 2:// меняет имя проекта
			changeProjectName(vector_of_works, choice);
			break;
		case 3:// изменяет выбранный тип работ в проекте
			editEmployeeInProject(vector_of_works, choice);
			break;
		case 4:// добавляет сотрудников в существующий проект
			addEmployeesInProject(vector_of_works, choice);
			break;
		case 5:// удаляет сотрудников в существующий проект
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
	cout << SURE << endl;
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
		cout << HOW_MANY_EMPLOYEES << endl;
		em = input();
		vector_of_works.resize(vector_of_works.size() + em);
		size = vector_of_works.size();
		for (int m = (vector_of_works.size() - em); m < size; m++)
		{
			inputInformation(work_temp, name, vector_of_works);// перегруженная функция. Pеализация находится в Write.h
			vector_of_works.push_back(work_temp);
			writeEndFileProject(work_temp, vector_of_works);
		}
	}
	cout << "Editing was successful" << endl;
	pause();
	clearConsole();
}
void changeProjectName(vector<TypeOfWork>& vector_of_works, int choice)
{
	string new_name, name;
	int approve;
	clearConsole();
	name = vector_of_works.at(choice).project_name;
	cout << "Enter new name of project" << endl;
	inputLine(new_name, PROJECT_SIZE);
	cout << "Accept changes?\nChoose:\t1 YES\t2 NO" << endl;
	approve = input(1, 2);	
	if (approve == 1)
	{
		for (int i = 0; i < vector_of_works.size(); i++)
			if (vector_of_works.at(i).project_name == name)
				vector_of_works.at(i).project_name = new_name;
		writeFileProjects(vector_of_works);
		clearConsole();
		cout << "Name has been changed" << endl;
		pause();
	}
	clearConsole();
}
void editEmployeeInProject(vector<TypeOfWork>& vector_of_works, int choice)
{
	int descission, i = 0;
	clearConsole();
	chooseEditingEmployee(vector_of_works, choice);
	cout << SURE << endl;
	descission = input();
	if (descission == 1)
	{ 
		clearConsole();
		TypeOfWork edit = vector_of_works.at(choice);
		showPersonalInformationAboutEmployee(edit);
		cout << "Choose what information about " << vector_of_works.at(choice).FIO << " would you like to edit: " << endl;
		cout << CHOOSE_PARAM_OF_EMPLOYEE << endl;
		descission = input(0, 5);
		switch (descission)
		{
		case 1: editSurname(vector_of_works, choice);
			break;
		case 2: chooseWorkName(vector_of_works, choice);
			break;
		case 3: editAmmountOfHours(vector_of_works, choice);
			break;
		case 4: editCostPerHour(vector_of_works, choice);
			break;
		case 5: inputInformation(vector_of_works, choice);
			break;
		}
		clearConsole();		
		writeFileProjects(vector_of_works);
	}
	clearConsole();
}
void editSurname(vector<TypeOfWork>& vector_of_works, int choice)
{
	cout << ENTER_SURNAME << endl;
	inputLine(vector_of_works.at(choice).FIO, SURNAME_SIZE);
}
void editAmmountOfHours(vector<TypeOfWork>& vector_of_works, int choice)
{
	cout << ENTER_HOURS << endl;
	vector_of_works.at(choice).ammount_of_hours = input(1, MAX_HOURS);
}
void editCostPerHour(vector<TypeOfWork>& vector_of_works, int choice)
{
	cout << "Enter " << vector_of_works.at(choice).FIO << "'s hourly cost: ";
	vector_of_works.at(choice).cost_per_hour = input(1, MAX_COST_OF_HOUR);
}
void addEmployeesInProject(vector<TypeOfWork>& vector_of_works, int choice)
{
	TypeOfWork work_temp;
	string name = vector_of_works.at(choice).project_name;
	int number_of_employees;
	clearConsole();
	cout << ADD_EMPLOYEES;
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
	cout << "Employes have been added" << endl;
	pause();
	clearConsole();
}
void deleteEmployee(vector<TypeOfWork>& vector_of_works, int choice)
{
	int descission, i = 0;
	clearConsole();
	chooseEditingEmployee(vector_of_works, choice);
	cout << SURE << endl;
	descission = input(1, 2);
	if (descission == 1)
	{
		vector_of_works.erase(vector_of_works.cbegin() + (choice));
		writeFileProjects(vector_of_works);
		clearConsole();
		cout << DELITION << endl;
	}
	pause();
	clearConsole();
}
void chooseEditingEmployee(vector<TypeOfWork> vector_of_works, int& choice)
{
	int i = 0 , j = 0, first, last;
	cout << "-------------------------------------------------" << endl;
	cout << "|  ID  | SURNAME OF THE EMPLOYEE | TYPE OF WORK |" << endl;
	cout << "-------------------------------------------------" << endl;
	while (i != vector_of_works.size())
	{
		if (vector_of_works.at(i).project_name == vector_of_works.at(choice).project_name)
		{
			cout << "|" << i + 1 << setw(7 - num(i + 1)) << "|"
				 << vector_of_works.at(i).FIO << setw(26 - vector_of_works.at(i).FIO.size()) << "|"
				 << vector_of_works.at(i).name << setw(15 - vector_of_works.at(i).name.size())<< "|" << endl;
			j++; // считает количество выводимых сотрудников
			if (j == 1)
				first = i + 1;
		}
		i++;
	}
	last = first - 1 + j;
	cout << "-------------------------------------------------" << endl;
	cout << "Input ID of the employee: ";
	choice = input(first, last) - 1;
}

void delProjectFromVector(vector<TypeOfWork>& vector_of_works)
{
	int choice, descission;
	vector <Project> vector_of_projects;
	clearConsole();
	if (printFileIsEmpty(vector_of_works))
		return;
	cout << "Choose Project which tou want to delete:" << endl;
	showProjects(vector_of_works, vector_of_projects);
	cout << endl << O_TO_TURN_BACK << endl;
	cout << "Choice: ";
	choice = input(0, vector_of_projects.size()) - 1;
	if (choice != -1)
	{
		cout << SURE << endl;
		descission = input(1, 2);
		if (descission == 1)
		{
			string name = vector_of_projects.at(choice).name;
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
		clearConsole();
		cout << DELITION << endl;
	}
	pause();
	clearConsole();
}

void editAccounts(vector <Account>& vector_of_accaunts, vector <TypeOfWork>& vector_of_works, string login)
{
	int ed = 10;
	while (ed != 0)
	{
		clearConsole();
		cout << "\t\t_______EDITING_______" << endl;
		showListOfAccounts(vector_of_accaunts);
		cout << EDIT_ACCOUNT << endl;
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
		case 6: changePassword(vector_of_accaunts);
		case 0:
			break;
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
	cout << SURE << endl;
	approve = input();
	if (approve == 1)
	{
		if (vector_of_accaunts.at(choice).role == HEAD_ADMIN)
		{
			cout << "You can't delete head admin" << endl;
			pause();
			clearConsole();
			return;
		}
		if (vector_of_accaunts.at(choice).login == login) // если удаляем свой аккаунт выходим в меню
		{
			vector_of_accaunts.erase(vector_of_accaunts.cbegin() + choice);
			writeFileAccounts(vector_of_accaunts);
			clearConsole();
			autorisatie();
		}
		vector_of_accaunts.erase(vector_of_accaunts.cbegin() + choice);
		writeFileAccounts(vector_of_accaunts);
		clearConsole();
	}
}
void blockAccount(vector <Account>& vector_of_accaunts, string login)
{
	int choice, approve;
	choice = chooseAccount(vector_of_accaunts);
	if (choice == -1)
		return;
	if (vector_of_accaunts.at(choice).role == HEAD_ADMIN)
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
	if (vector_of_accaunts.at(choice).status == UNACTIVATED_ACCOUNT)
	{
		cout << "You have to activate this account first" << endl;
		pause();
		clearConsole();
		return;
	}
	if (vector_of_accaunts.at(choice).status == BLOCKED_ACCOUNT)
	{
		cout << "This account is already blocked" << endl;
		pause();
		clearConsole();
	}
	cout << SURE << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		vector_of_accaunts.at(choice).status = BLOCKED_ACCOUNT;
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
	if (vector_of_accaunts.at(choice).status == UNACTIVATED_ACCOUNT)
	{
		cout << "You have to activate this account first" << endl;
		pause();
		clearConsole();
	}
	if (vector_of_accaunts.at(choice).status == ACTIVATED_ACCOUNT)
	{
		cout << "This account is already activated" << endl;
		pause();
		clearConsole();
	}
	if (vector_of_accaunts.at(choice).status == BLOCKED_ACCOUNT)
	{
		vector_of_accaunts.at(choice).status = ACTIVATED_ACCOUNT;
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
	cout << SURE << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		if (vector_of_accaunts.at(choice).role == HEAD_ADMIN)
		{
			clearConsole();
			cout << "You can't change role of head admin" << endl;
			pause();
			return;
		}
		if (vector_of_accaunts.at(choice).role == USER)
		{
			vector_of_accaunts.at(choice).role = ADMIN;
			writeFileAccounts(vector_of_accaunts);
			return;
		}
		if (vector_of_accaunts.at(choice).role == ADMIN)
		{
			if (vector_of_accaunts.at(choice).login == login)
			{
				clearConsole();
				cout << "You can't change your role" << endl;
				pause();
			}
			else
				vector_of_accaunts.at(choice).role = USER;
			writeFileAccounts(vector_of_accaunts);
			return;
		}
	}
}
int chooseAccount(vector <Account>& vector_of_accaunts)
{
	int choice;
	showListOfAccounts(vector_of_accaunts);
	cout << O_TO_TURN_BACK << endl;
	cout << "Choose account which you want to edit:" << endl;
	choice = input(0, vector_of_accaunts.size());
	if (choice == 0)
		return -1;
	return choice - 1;
}
void changePassword(vector <Account>& vector_of_accaunts)
{
	Account account_temp;
	string password1, password2, login;
	int choice;
	char approve;
	clearConsole();
	choice = chooseAccount(vector_of_accaunts);
	login = vector_of_accaunts.at(choice).login;
	if (vector_of_accaunts.at(choice).role == HEAD_ADMIN)
	{
		cout << "You can't change password of head admin" << endl;
		pause();
		return;
	}
	account_temp.login = login;
	cout << SURE << endl;
	approve = input(1, 2);
	clearConsole();
	if (approve == 1)
	{
		if (!inputNewPassword(vector_of_accaunts, account_temp, password1, password2))// если возращает false выходим из функции
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
					clearConsole();
					cout << "Password has been chaanged successfully" << endl;
					pause();
				}
			}
		}
		else
			return;
	}
}
void changePassword(vector <Account>& vector_of_accaunts, string login)
{
	Account account_temp;
	string password1, password2;
	int choice;
	char approve;
	clearConsole();
	account_temp.login = login;
	cout << SURE << endl;
	approve = input(1, 2);
	clearConsole();
	if (approve == 1)
	{
		if (!inputNewPassword(vector_of_accaunts, account_temp, password1, password2))// если возращает false выходим из функции
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
					clearConsole();
					cout << "Password has been changed successfully" << endl;
					pause();
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
		flag = compareInputData(account_temp, vector_of_accaunts); // проверяем правильно ли введен текущий пароль
		if (flag == true)
		{
			cout << "Enter new password: ";
			inputLine(password1, PASSWORD_SIZE);
			cout << ENTER_PASSWORD_AGAIN;
			inputLine(password2, PASSWORD_SIZE);
			clearConsole();
			flag = isPasswordSuitable(account_temp, password1, password2);  // проверяем что пароли совпадают и соответсвуют нашим стандартам ( X+1 и более 5 символов) flag == true
			if (flag == false)
			{
				cout << endl << O_TO_TURN_BACK << endl;
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
			cout << endl << "Incorrect  input. This password does not match the current " << endl;
			cout << "If you want go back press 0, else press another key" << endl;
			approve = _getch();
			clearConsole();
			account_temp.password.clear();
			if (approve == '0')
				return false;
		}
		attempts++; // количество попыток
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
	}
	clearConsole();
	showListOfAccounts(vector_unverified_accounts);
}
void approveAllApplications(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	clearConsole();
	int approve;
	cout << SURE << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		for (int i = 0; i < vector_of_accaunts.size(); i++) // меняем статус в векторе всех аккаунтов
		{
			if (vector_of_accaunts.at(i).status == UNACTIVATED_ACCOUNT)
			{
				vector_of_accaunts.at(i).status = ACTIVATED_ACCOUNT;
				vector_unverified_accounts.clear();
			}
		}
		writeFileAccounts(vector_of_accaunts); // сохраняем измененив файл
	}
	clearConsole();
}
void approveOneApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	int choice, approve;
	cout << "Enter number of the appliction: ";
	choice = input(1, vector_unverified_accounts.size());
	clearConsole();
	cout << SURE << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		vector_unverified_accounts.at(choice - 1).status = ACTIVATED_ACCOUNT;
		for (int i = 0; i < vector_of_accaunts.size(); i++) // меняем статус в векторе всех аккаунтов
		{
			if (vector_unverified_accounts.at(choice - 1).login == vector_of_accaunts.at(i).login)
				vector_of_accaunts.at(i).status = UNACTIVATED_ACCOUNT;
		}
		vector_unverified_accounts.erase(vector_unverified_accounts.cbegin() + (choice - 1)); // удаляем из списка неподтвержденных аккаунтов
		writeFileAccounts(vector_of_accaunts); // сохраняем измененив файл
	}
	clearConsole();
}
void deleteApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts)
{
	clearConsole();
	showListOfAccounts(vector_unverified_accounts);
	int choice;
	cout << "Choose: \n1Deny all\n2 Deny one\n0 Back" << endl;
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
	cout << SURE << endl;
	approve = input(1, 2);
	if (approve == 1)
	{
		for (int i = 0; i < vector_of_accaunts.size(); i++) // меняем статус в векторе всех аккаунтов
		{
			if (vector_of_accaunts.at(i).status == UNACTIVATED_ACCOUNT)
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
		// удаляем аккаунт везде
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