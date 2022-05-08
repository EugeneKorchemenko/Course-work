#include "Autorisation.h"

void autorisatie()
{
	vector<Account> vector_of_accaunts;
	vector_of_accaunts.resize(getCountOfAccounts(FILE_ACCOUNTS));
	readAccountsBase(vector_of_accaunts);
	menu(vector_of_accaunts);
}

int getCountOfAccounts(string file_path)
{
	ifstream file(file_path, ios::in); // Открыли текстовый файл для чтения
	int number_of_accaunts = 0, i = 1;
	if (file.is_open())
		while (file.ignore(numeric_limits<streamsize>::max(), '\n'))
			number_of_accaunts++;
	file.close();
	return number_of_accaunts;
}
void readAccountsBase(vector <Account>& vector_of_accaunts)
{
	ifstream fin(FILE_ACCOUNTS, ios::binary | ios::in);
	if (!fin.is_open())
	{
		cout << "File doesn't exist!\nYou became main admin\n!!! CONGRATULATIONS !!!" << endl;
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
			cout << "You became admin\n!!!CONGRATULATIONS !!!" << endl;
			singUp(vector_of_accaunts);
		}
	}
	fin.close();
}

int menu(vector <Account>& vector_of_accaunts)
{
	int choice;
	// лого и заголовок
	while (true)
	{
		cout << "\t__________ENTARANCE__________" << endl;
		cout << "1 Log in\n2 Create new account\n0 Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: logIn(vector_of_accaunts);
			break;
		case 2: singUp(vector_of_accaunts);
			break;
		case 0: return 0;
			break;
		}
	}
}

void singUp(vector <Account>& vector_of_accaunts)
{
	int choice;
	bool flag = false;
	string password1, password2;
	Account account_temp;
	while (flag == false)
	{
		cout << "Enter login: ";
		cin >> account_temp.login;
		flag = isLoginUnique(account_temp, vector_of_accaunts);   // проверяем логин на уникальность
		cout << "Enter password: ";
		cin >> password1;
		cout << "Enter it again: ";
		cin >> password2;
		flag = isPasswordSuitable(account_temp, password1, password2);  // проверяем что пароли совпадают и соответсвуют нашим стандартам (X, 1 и более 5 символов)
		if (flag == false)
		{
			cout << endl << "Incorrect input. Please try again" << endl;
			cout << endl << "If you want go back press 0" << endl;;
			choice = _getch();
			account_temp.password.clear();
			if (choice == '0')
				break;
		}
	}
	hashPassword(account_temp);
	if (vector_of_accaunts.size() == 0 || vector_of_accaunts.at(0).login.empty()) // условие если список аккаунтов пуст то создаём администратора  status
	{
		account_temp.role = 3; // админ админов )
		account_temp.status = 1;
		vector_of_accaunts.at(0) = account_temp;
		rewriteAccount(account_temp);
	}
	else
	{
		cout << "Choose role: ";
		cout << "1 User\t2 Admin" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: account_temp.role = 1;
			break;
		case 2:account_temp.role = 2;
			break;
		default: cout << "Please, enter 1 or 2";
		}
		account_temp.status = 0;
		vector_of_accaunts.push_back(account_temp);
		writeAccountInTheEnd(account_temp);
	}
}
bool isLoginUnique(Account account_temp, vector <Account> vector_of_accaunts)
{
	for (int i = 0; i < vector_of_accaunts.size(); i++)
	{
		if (account_temp.login == vector_of_accaunts.at(i).login)
		{
			cout << "Account with the same login has already exist. Input another one." << endl;
			return false;
		}
	}
}
bool isPasswordSuitable(Account& account_temp, string password1, string password2)
{
	int  capital = 0, number = 0;
	if (password1 == password2)
		account_temp.password = password2;
	else
	{
		cout << "Passwords mismatch!!!" << endl;
		return false;
	}
	if (account_temp.password.size() < 6) //проверяем что пароль содержит более 6 символов
	{
		cout << "Your password is too short! Please try again" << endl;
		return false;
	}
	for (int i = 0; i < account_temp.password.size(); i++) // смотрим на наличее заглавных букв и цифр
	{
		if (account_temp.password.at(i) >= 'A' || account_temp.password.at(i) >= 'Z')
			capital++;
		if (account_temp.password.at(i) >= '0' || account_temp.password.at(i) >= '9')
			number++;
	}
	if (capital == 0 || number == 0)
	{
		cout << "Please use at least one capital letter and one number" << endl;
		return false;
	}
	else
		return true;
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

void logIn(vector <Account>& vector_of_accaunts)
{
	Account account_temp;
	char back;
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Enter login: ";
		cin >> account_temp.login;
		cout << "Enter password: ";
		hideInput(account_temp); // скрытый ввод пароля со *
		if (compareInputData(account_temp, vector_of_accaunts) == true) // проверка при авторизации на правильность лгина и пароля
		{
			cout << endl << "Log in completed !!!" << endl;
			/*system("pause");
			system("cls");*/
			enterMenu(account_temp, vector_of_accaunts);
			break;
		}
		else
		{
			if (i + 1 == 3)
			{
				cout << "The limit of attempts has been exceeded!!!" << endl;
				return;
			}
			cout << endl << "Incorrect input. Please try again" << endl;
			cout << endl << "If you want go back press 0" << endl;;
			back = _getch();
			account_temp.password.clear();
			if (back == '0')
				break;
		}
	}
}
bool compareInputData(Account& account_temp, vector <Account>& vector_of_accaunts)
{
	int i = 0;
	while (i < vector_of_accaunts.size())
	{
		if (vector_of_accaunts.at(i).login == account_temp.login)
		{
			account_temp.salt = vector_of_accaunts.at(i).salt;
			account_temp.hash_password_with_salt = sha256(sha256(account_temp.password + account_temp.salt) + sha256(account_temp.password));
			if (account_temp.hash_password_with_salt == vector_of_accaunts.at(i).hash_password_with_salt)
			{
				account_temp = vector_of_accaunts.at(i);
				return true;
			}
			else
				return false;
		}
		i++;
	}
	return false;
}
void enterMenu(Account account_temp, vector <Account>& vector_of_accaunts)
{
	vector <TypeOfWork> vector_of_works;
	if(account_temp.status == 0)
		cout << "Wait for the confirmation of registration" << endl;
	if (account_temp.status == 2)
		cout << "Your account is temporarily blocked" << endl;
	if (account_temp.status == 1 && (account_temp.role == 2 || account_temp.role == 3))
		menuForAdmin(vector_of_accaunts, vector_of_works, account_temp.login);
	if (account_temp.status == 1 && account_temp.role == 1)
		menuForUser(vector_of_accaunts, vector_of_works, account_temp.login);
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