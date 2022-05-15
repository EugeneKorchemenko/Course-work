#include "Validation.h"

int input(int min, int max)
{
	int number;
	while (true)
	{
		cin >> number;
		if (cin.get() == '\n') //���� ������� ������� �����, ��������� n �.� ���� �������� ���������
		{
			if (number > max || number < min)
			{
				cout << "Incorrect input. Number is out of range(" << min << " - " << max << ")" << endl;
				continue;
			}
			break;
		}
		else
		{
			cin.clear(); // ���������� ����� ������.���� ��������� ������, ��������������� ���� ������, � ������� ������� �������� ���� �� �������
			cin.ignore((numeric_limits<streamsize>::max)(), '\n'); // ���������� (�������) ���� '\n' ������������� �����������, �� ���� ������, ����� �������� cin ��������� ������������ numeric_limits<streamsize>::max() ������������� ������������ ���������� �������� ��� ������������� 
			cout << "Incorrect input" << endl;
		}
	}
	return number;
}
int input()
{
	int number;
	while (true)
	{
		cin >> number;
		if (cin.get() == '\n') //���� ������� ������� �����, ��������� n �.� ���� �������� ���������
			break;
		else
		{
			cin.clear(); // ���������� ����� ������.���� ��������� ������, ��������������� ���� ������, � ������� ������� �������� ���� �� �������
			cin.ignore((numeric_limits<streamsize>::max)(), '\n'); // ���������� (�������) ���� '\n' ������������� �����������, �� ���� ������, ����� �������� cin ��������� ������������ numeric_limits<streamsize>::max() ������������� ������������ ���������� �������� ��� ������������� 
			cout << "Incorrect input" << endl;
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
	if (account_temp.password.size() < 6) //��������� ��� ������ �������� ����� 6 ��������
	{
		cout << "Your password is too short! The password must be more than 6 characters long. Please try again" << endl;
		return false;
	}
	for (int i = 0; i < account_temp.password.size(); i++) // ������� �� ������� ��������� ���� � ���� � ��������
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
			cout << endl << "This employee has already involved in this type of work in this project. Try again" << endl;
			return true;
		}
		j++;
	}
	return false;
}
bool chekIfEmployeeDoSameWorkOnProject(vector<TypeOfWork> vector_of_works, int m)
{
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		if (vector_of_works.at(i).FIO == vector_of_works.at(m).FIO && vector_of_works.at(i).name == vector_of_works.at(m).name && vector_of_works.at(i).project_name == vector_of_works.at(m).project_name)
		{
			cout << vector_of_works.at(m).FIO << " has already included in this stage of the project" << endl;
			pause();
			return true;
		}
	}
	return false;
}

void inputLine(string& string, int size) // login fio 
{
	int i = 0, approve;
	char temp;
	string.clear();
	while (true)
	{
		while (i == size) // ���� �������� ������������� �������� ��� ����� ����� ������ backspace � enter
		{
			temp = _getch();
			if (temp == '\b')
			{
				string.pop_back();
				printf_s("\b \b");
				i--;
			}
			if (temp == '\r')
				return;
		}
		temp = _getch();
		if (temp != '\r')
		{
			if (temp == '\b')
			{
				if (i == 0)
					continue;
				string.pop_back();
				printf_s("\b \b");
				i--;
				continue;
			}
			if ((temp <= '0' || temp >= '9') && (temp < 'A' || temp > 'z') || temp == 94)
				continue;
			if (temp >= '0' && temp <= '9' && (size != 17 && size != 20)) // ������ �� ���� ���� ����� ����� ������ � ������
				continue;
			string.push_back(temp);
			cout << temp;
			i++;
			continue;
		}
		if (temp == '\r' && string.empty())
			continue;
		cout << endl;
		return;
	}
}

bool printFileIsEmpty(vector<TypeOfWork>& vector_of_works)
{
	if (vector_of_works.empty())
	{
		cout << "File with data is empty !!!" << endl;
		pause();
		clearConsole();
		return true;
	}
}