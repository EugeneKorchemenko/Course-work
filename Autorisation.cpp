#include "Autorisation.h"

void autorisatie()
{
	vector<Account> vector_of_accaunts;
	vector_of_accaunts.resize(getCountOfAccounts(FILE_ACCOUNTS));
	readAccountsBase(vector_of_accaunts);
	system("chcp 437");
	system("cls");
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
		cout << "File doesn't exist!\nYou became admin\n!!! CONGRATULATIONS !!!" << endl;
		singUp(vector_of_accaunts);
	}
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			fin >> vector_of_accaunts[i].login
				>> vector_of_accaunts[i].salt
				>> vector_of_accaunts[i].password
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
		cout << "1 Log in\n2 Sing up\n0 Exit" << endl;
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
	Account account_temp;
	cout << "Enter login: ";
	cin >> account_temp.login;
	// проверяем на уникальность

	cout << "Enter password: ";
	cin >> account_temp.password;
	cout << "Enter it again: ";
	cin >> account_temp.password;
	// прверяем что они совпадают и соответсвуют нашим стандартам ( X+1 и более 5 символов)

	hashPassword(account_temp);
	
	// условие если список аккаунтов пуст то создаём администратора  status
	if (vector_of_accaunts.size() == 0 || vector_of_accaunts.at(0).login.empty())
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


void logIn(vector <Account>& vector_of_accaunts)
{
	Account account_temp;
	for (int i = 0; i < 3; i++)
	{
		system("cls");
		cout << "Enter login: ";
		cin >> account_temp.login;
		cout << "Enter password: ";
		hideInput(account_temp);
		if (compareInputData(account_temp, vector_of_accaunts) == true)
		{
			cout << "Log in completed !!!" << endl;
			system("pause");
			system("cls");
			enterMenu(account_temp, vector_of_accaunts);
			break;
		}
		else
		{
			cout << "Incorrect input. Please try again" << endl;
			account_temp.password.clear();
			if (i + 1 == 3)
			{
				cout << "The limit of attempts has been exceeded!!!" << endl;
				return;
			}
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
			if (account_temp.hash_password_with_salt == vector_of_accaunts.at(i).password)
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
	if (account_temp.status == 1 && (account_temp.role == 2 || account_temp.role == 3))
		menuForAdmin(vector_of_accaunts, vector_of_works);
	if (account_temp.status == 1 && account_temp.role == 1)
		menuForUser(vector_of_accaunts, vector_of_works);
	else
		cout << "Wait for the confirmation of registration" << endl;
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
