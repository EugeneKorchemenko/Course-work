#include "AddProject.h"

void addProjectsInVector(vector<TypeOfWork>& vector_of_works)
{
	TypeOfWork work_temp;
	cout << "Enter how many projects you want to add" << endl;
	int choice;
	cin >> choice;
	string name;
	for (int i = 0; i < choice; i++)
	{
		cout << "Enter name of the project:" << endl;
		cin >> name;
		cout << "Enter how many employees include into project" << endl;
		int emoloyees;
		cin >> emoloyees;
		//vector_of_works.resize(vector_of_works.size() + emoloyees);
		for (int m = 0; m < emoloyees; m++)
		{
			inputInformation(work_temp, name, vector_of_works);
			vector_of_works.push_back(work_temp);
			writeEndFileProject(work_temp, vector_of_works);
		}
	}
}
void inputInformation(TypeOfWork& work_temp, string name, vector<TypeOfWork> vector_of_works)
{
	while (1)
	{
		work_temp.project_name = name;
		chooseWorkName(work_temp);
		cout << "Enter FIO of employee" << endl;
		cin >> work_temp.FIO;
		cout << "Enter ammount of hours" << endl;
		cin >> work_temp.ammount_of_hours;
		cout << "Enter " << work_temp.FIO << "'s hourly cost" << endl;
		cin >> work_temp.cost_per_hour;
		if (chekIfEmployeeDoSameWorkOnProject(work_temp, vector_of_works))
			break;
		else
			continue;
	}
}
void chooseWorkName(TypeOfWork& work)
{
	int n;
	cout << "Choose type of work" << endl;
	cout << "1)Work on requirements\n2)Development\n3)Implementation\n4)Testing" << endl;
	cin >> n;
	switch (n)
	{
	case 1: work.name = "Requirements";
		break;
	case 2: work.name = "Development";
		break;
	case 3: work.name = "Implementation";
		break;
	case 4: work.name = "Testing";
		break;
	}
}
void writeEndFileProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works)
{
	ofstream fout(FILE_DATA, ios::app);
	if (!fout.is_open())
		cout << "File doesn't exist";
	else
	{
		fout << "\n" << work_temp.project_name << "\t"
			<< work_temp.name << "\t"
			<< work_temp.FIO << "\t"
			<< work_temp.ammount_of_hours << "\t"
			<< work_temp.cost_per_hour;
	}
	fout.close();
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