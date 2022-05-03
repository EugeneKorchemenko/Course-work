#include "Structs.h"
#include "Autorisation.h"
#include "Constants.h"
#include "PrintHeader.h"

void autorisatie()
{
	vector<Account> vector_of_accaunts;
	vector_of_accaunts.resize(getCountOfAccounts(FILE_DATA));
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
	ifstream fin(FILE_DATA, ios::binary | ios::in);
	if (!fin.is_open())
	{
		cout << "File doesn't exist!\nYou became admin\n!!! CONGRATULATIONS !!!" << endl;
		registerAcount(vector_of_accaunts);
	}
	else
	{
		int i = 0, m = 0;
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
	}
	fin.close();
}

void menu(vector <Account>& vector_of_accaunts)
{
	print("vault tec");
	// лого
	cout << "\t__________ENTER__________" << endl;
}

void registerAcount(vector <Account>& vector_of_accaunts)
{

}