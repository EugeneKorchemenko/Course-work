#include "Accounts.h"

void showListOfAccounts(vector <Account>& vector_of_accaunts)
{
	//header
	cout << "-------------------------------------" << endl;
	cout << "|      LOGIN      | ROLE |  STATUS  |" << endl;
	cout << "-------------------------------------" << endl;
	for (int i = 0; i < vector_of_accaunts.size(); i++)
	{
		cout << "|" << vector_of_accaunts.at(i).login << setw(18 - vector_of_accaunts.at(i).login.size()) <<
			"|" << getRole(vector_of_accaunts.at(i).role) << /*setw(8 - size) <<*/
			"|" << getStatus(vector_of_accaunts.at(i).status) /*<< setw(11 - size)*/ << "|" << endl;
	}
	cout << "-------------------------------------" << endl;
}
string getStatus(int status)
{
	string s;
	switch (status)
	{
	case 0: s = "Unverified";
		break;
	case 1: s = "Activated ";
		break;
	case 2: s = "Baned     ";
		break;
	}
	return s;
}
string getRole(int role)
{
	string s;
	switch (role)
	{
	case 1: s = "User  ";
		break;
	case 2: 
	case 3: s = "Admin ";
		break;
	}
	return s;
}

void showApplications(vector <Account>& vector_of_accaunts)
{

}
