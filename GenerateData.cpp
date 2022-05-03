#include "Structs.h"
#include "GenerateData.h"
#include "Constants.h"

void generateProjectsVector(vector<TypeOfWork>& vector_of_works)
{
	int choice, size = 0;
	cout << "Enter how many projects do you want to add" << endl;
	cin >> choice;
	string name;
	vector_of_works.resize(0);
	for (int i = 0; i < choice; i++)
	{
		cout << "Enter name of the project:" << endl;
		cin >> name;
		cout << "Enter how many employees include into project" << endl;
		int em;
		cin >> em;
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
	cout << "Enter FIO of employee" << endl;
	cin >> vector_of_works.at(m).FIO;
	cout << "Enter ammount of hours" << endl;
	cin >> vector_of_works.at(m).ammount_of_hours;
	cout << "Enter " << vector_of_works.at(m).FIO << "'s hourly cost" << endl;
	cin >> vector_of_works.at(m).cost_per_hour;
}
void chooseWorkName(vector<TypeOfWork>& vector_of_works, int m)
{
	int n;
	cout << "Choose type of work" << endl;
	cout << "1)Work on requirements\n2)Development\n3)Implementation\n4)Testing" << endl;
	cin >> n;
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