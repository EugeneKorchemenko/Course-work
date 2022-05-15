#include "Autorisation.h"

void autorisatie()
{
	vector<Account> vector_of_accaunts;
	vector <TypeOfWork> vector_of_works;
	vector_of_accaunts.resize(getCountOfAccounts(FILE_ACCOUNTS));
	readAccountsBase(vector_of_accaunts);
	vector_of_works.resize(getCountOfTypesOfWorkInFile(FILE_DATA));
	doesFileExist(vector_of_works, 0);
	menu(vector_of_accaunts, vector_of_works);
}

int getCountOfAccounts(string file_path)
{
	ifstream file(file_path, ios::in); // Открыли текстовый файл для чтения
	int number_of_accaunts = 0, i = 1;
	if (file.is_open())
		while (file.ignore((numeric_limits<streamsize>::max)(), '\n'))
			number_of_accaunts++;
	file.close();
	return number_of_accaunts;
}
void readAccountsBase(vector <Account>& vector_of_accaunts)
{
	ifstream fin(FILE_ACCOUNTS, ios::binary | ios::in);
	if (!fin.is_open())
	{
		cout << "File doesn't exist!\nYou became head admin\n!!! CONGRATULATIONS !!!" << endl;
		singUp(vector_of_accaunts);
	}
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			fin >> vector_of_accaunts[i].login
				>> vector_of_accaunts[i].salt
				>> vector_of_accaunts[i].hash_password_with_salt
				>> vector_of_accaunts[i].role
				>> vector_of_accaunts[i].status;
			if (i + 1 == vector_of_accaunts.size())
				break;
			else
				i++;
		}
		if (vector_of_accaunts[i].login.empty()) //файл создан, но пуст
		{
			cout << "You became head admin\n!!! CONGRATULATIONS !!!" << endl;
			singUp(vector_of_accaunts);
		}
	}
	fin.close();
}

void doesFileExist(vector <TypeOfWork>& vector_of_works, int access)
{
	ifstream fin(FILE_DATA, ios::binary | ios::in);
	if (!fin.is_open())
	{
		clearConsole();
		cout << "File with data doesn't exist!" << endl;
		pause();
		if (access == 1) // если админ считывает файл, а он пустой то предлагаем создать новый
		{
			cout << "Do you want to create new one?" << endl;
			cout << "1)YES\n2)NO" << endl;
			int choice;
			cin >> choice;
			if (choice == 1)
				generateProjectsVector(vector_of_works);
			else
				return;
		}
		else
			return;
	}
	else
	{
		int i = 0, m = 0;
		while (!fin.eof())
		{
			fin >> vector_of_works[i].project_name
				>> vector_of_works[i].name
				>> vector_of_works[i].FIO
				>> vector_of_works[i].ammount_of_hours
				>> vector_of_works[i].cost_per_hour;
			if (i + 1 == vector_of_works.size())
				break;
			else
				i++;
		}
	}
	fin.close();
}
int getCountOfTypesOfWorkInFile(string file_path)
{
	ifstream file(file_path, ios::in); // Открыли текстовый файл для чтения
	int number_of_strings = 0, i = 1;
	if (file.is_open())
		while (file.ignore((numeric_limits<streamsize>::max)(), '\n'))
			number_of_strings++;
	file.close();
	return number_of_strings;
}

void menu(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works)
{
	int choice = 10;
	// лого 
	while (choice != 0)
	{
		cout << MENU_AUTORISATION << endl;
		choice = input(0, 2);
		switch (choice)
		{
		case 1: logIn(vector_of_accaunts, vector_of_works);
			break;
		case 2: singUp(vector_of_accaunts);
			break;
		case 0:
			break;
		}
	}
}

void singUp(vector <Account>& vector_of_accaunts)
{
	int choice = 0;
	Account account_temp;
	clearConsole();
	createLoginAndPassword(account_temp, vector_of_accaunts, choice);
	hashPassword(account_temp);
	if (vector_of_accaunts.size() == 0 || vector_of_accaunts.at(0).login.empty()) // условие если список аккаунтов пуст то создаём администратора  status
	{
		account_temp.role = HEAD_ADMIN; // главный администратор
		account_temp.status = ACTIVATED_ACCOUNT;
		vector_of_accaunts.at(0) = account_temp;
		rewriteAccount(account_temp);
	}
	else
	{
		account_temp.role = USER;
		account_temp.status = UNACTIVATED_ACCOUNT;
		vector_of_accaunts.push_back(account_temp);
		writeAccountInTheEnd(account_temp);
	}
	clearConsole();
}
void createLoginAndPassword(Account& account_temp, vector <Account>& vector_of_accaunts, int choice)
{
	bool flag = false;
	char approve;
	string password1, password2;
	while (flag == false)
	{
		cout << ENTER_LOGIN;
		inputLine(account_temp.login, LOGIN_SIZE);
		flag = isLoginUnique(account_temp, vector_of_accaunts);   // проверяем логин на уникальность
		cout << ENTER_PASSWORD;
		inputLine(password1, PASSWORD_SIZE);
		cout << ENTER_PASSWORD_AGAIN;
		inputLine(password2, PASSWORD_SIZE);
		flag = isPasswordSuitable(account_temp, password1, password2);  // проверяем что пароли совпадают и соответсвуют нашим стандартам (X, 1 и более 5 символов)
		if (flag == false)
		{
			pause();
			clearConsole();
			cout << endl << INCORRECT_INPUT << endl;
			approve = _getch();
			clearConsole();
			account_temp.password.clear();
			if (approve == '0')
				break;
		}
	}
}
void hashPassword(Account& account_temp)
{
	account_temp.salt = generateSalt(SALT_SIZE);
	account_temp.hash_password_with_salt = sha256(sha256(account_temp.password + account_temp.salt) + sha256(account_temp.password));
}
string generateSalt(int salt_size)
{
	string symbols = getSymbolsForSalt();

	srand(time(NULL));

	string salt;
	salt.reserve(salt_size);

	for (int i = 0; i < salt_size; i++)
	{
		salt.push_back(symbols[rand() % SYMBOLS_SIZE]);
	}

	return salt;
}
string getSymbolsForSalt()
{
	string symbols;
	symbols.reserve(SYMBOLS_SIZE);

	char little_letter = 'a';
	char big_letter = 'A';
	char number = '0';
	int i = 0;
	for (int k = 0; k < 26; k++)
	{
		symbols.push_back(little_letter++);
		symbols.push_back(big_letter++);
		if (k < 10) symbols.push_back(number++);
	}

	return symbols;
}

void logIn(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works)
{
	Account account_temp;
	char back;
	for (int i = 0; i < 3; i++)
	{
		clearConsole();
		cout << ENTER_LOGIN;
		inputLine(account_temp.login, LOGIN_SIZE);
		cout << ENTER_PASSWORD;
		hideInput(account_temp); // скрытый ввод пароля со *
		if (compareInputData(account_temp, vector_of_accaunts) == true) // проверка при авторизации на правильность лгина и пароля 
		{
			clearConsole();
			cout << LOG_IN_COMPLETED << endl;
			enterMenu(account_temp, vector_of_accaunts, vector_of_works);
			break;
		}
		else
		{
			if (i + 1 == 3)
			{
				cout << LIMIT_OF_ATTEMPTS << endl;
				pause();
				clearConsole();
				return;
			}
			cout << endl << INCORRECT_INPUT << endl;
			back = _getch();
			account_temp.password.clear();
			clearConsole();
			if (back == '0')
				break;
		}
	}
}
void enterMenu(Account account_temp, vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works)
{
	if (account_temp.status == UNACTIVATED_ACCOUNT)
	{
		cout << WAIT_FOR_CONFORMITION << endl;
		pause();
		clearConsole();
	}
	if (account_temp.status == BLOCKED_ACCOUNT)
	{
		cout << ACCOUNT_BLOCKED << endl;
		pause();
		clearConsole();
	}
	if (account_temp.status == ACTIVATED_ACCOUNT && (account_temp.role == ADMIN || account_temp.role == HEAD_ADMIN))
	{
		pause();
		menuForAdmin(vector_of_accaunts, vector_of_works, account_temp.login);
	}
	if (account_temp.status == ACTIVATED_ACCOUNT && account_temp.role == USER)
	{
		pause();
		menuForUser(vector_of_accaunts, vector_of_works, account_temp.login);
	}
}
void hideInput(Account& account_temp)
{
	char temp;
	while (true)
	{
		temp = _getch();
		if (temp != '\r')
		{
			if (temp == '\b')
			{
				account_temp.password.pop_back();
				printf_s("\b \b");
				continue;
			}
			account_temp.password.push_back(temp);
			cout << "*";
			continue;
		}
		cout << endl;
		return;
	}
}