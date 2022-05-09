#include "Validation.h"

int input()
{
	int number;
	while (true)
	{
		cin >> number;
		if (cin.get() == '\n') //если удалось считать число, останется n т.е ввод выполнен корректно
			break;
		else
		{
			cin.clear(); // сбрасывает флаги ошибок.Если возникает ошибка, устанавливается флаг ошибки, и будущие попытки получить ввод не удастся
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорирует (очищает) ввод '\n' устанавливает разделитель, то есть символ, после которого cin перестает игнорировать numeric_limits<streamsize>::max() устанавливает максимальное количество символов для игнорирования 
			cout << "\nIncorrect input\n\n";
		}
	}
	return number;
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
	return true;
}
bool isPasswordSuitable(Account& account_temp, string password1, string password2)
{
	int  capital = 0, number = 0, space = 0;
	if (password1 == password2)
		account_temp.password = password2;
	else
	{
		cout << "Passwords mismatch!!!" << endl;
		return false;
	}
	if (account_temp.password.size() < 6) //проверяем что пароль содержит более 6 символов
	{
		cout << "Your password is too short! The password must be more than 6 characters long. Please try again" << endl;
		return false;
	}
	for (int i = 0; i < account_temp.password.size(); i++) // смотрим на наличее заглавных букв и цифр и пробелов
	{
		if (account_temp.password.at(i) >= 'A' || account_temp.password.at(i) >= 'Z')
			capital++;
		if (account_temp.password.at(i) >= '0' || account_temp.password.at(i) >= '9')
			number++;
		if (account_temp.password.at(i) == ' ')
			space++;
	}
	if (capital == 0 || number == 0)
	{
		cout << "Please use at least one capital letter and one number" << endl;
		return false;
	}
	if (space != 0)
	{
		cout << "Please don't use spces in your password" << endl;
		return false;
	}
	else
		return true;
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

bool chekIfEmployeeDoSameWorkOnProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works)
{
	int j = 0;
	while (j < vector_of_works.size())
	{
		if (work_temp.FIO == vector_of_works.at(j).FIO && work_temp.name == vector_of_works.at(j).name && work_temp.project_name == vector_of_works.at(j).project_name)
		{
			cout << endl << "This employee has already involved in this type of work in this project. Try again" << endl << endl;
			return false;
		}
		j++;
	}
	return true;
}
void inputLine(string& string, int size) // login fio 
{
	int i = 1, approve;
	char temp;
	string.clear();
	while (true)
	{
		if (i == size)
		{
			cout << endl << "You have exceeded the maximum string size(" << size << ")" << endl;
			cout << "Do you want to use these inputs?" << endl;
			cout << "\nChoose:\t1 YES\t2 NO" << endl;
			cin >> approve;
			if (approve == 1)
				return;
			else
			{
				string.clear();
				i = 1;
				cout << "Input: ";
				continue;
			}
		}
		else
			temp = _getch();
		if (temp != '\r')
		{
			if (temp == '\b' && !string.empty())
			{
				string.pop_back();
				printf_s("\b \b");
				continue;
			}
			if (temp >= 'A' && temp <= 'z' && temp >= '0' && temp <= '9')
				continue;
				if (temp >= '0' && temp <= '9' && size != 17 && size != 20) // запрет на ввод цивр везде кроме логина и пароля
					continue;
			string.push_back(temp);
			cout << temp;
			i++;
			continue;
		}
		cout << endl;
		return;
	}
}