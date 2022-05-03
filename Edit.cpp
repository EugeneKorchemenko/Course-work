#include "Structs.h"
#include "Edit.h"
#include "AddProject.h"
#include "GenerateData.h"

void chooseKindOfEdition(vector<TypeOfWork>& vector_of_works)
{
	int choice;
	cout << "\t\t_______EDITION_______" << endl;
	cout << "Choose Project which tou want to edit:" << endl;
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		if (i == 0 || vector_of_works.at(i - 1).project_name != vector_of_works.at(i).project_name)
			cout << i + 1 << ")" << vector_of_works.at(i).project_name << endl;// ��������� ����� �������
	}
	cin >> choice;
	cout << "1)Edit all information about project\n2)Edit name of project\n3)Edit employee\n4)Add employees in prject\n5)Delete employee from project" << endl;
	editPoject(vector_of_works, choice);
}
void editPoject(vector<TypeOfWork>& vector_of_works, int choice)
{
	int ed;
	cin >> ed;
	switch (ed)
	{
	case 1: // ������� ���� ������ �������
		editWholeProject(vector_of_works, choice);
		break;
	case 2:// ������ ��� � ���������� ���� ����� �������
		changeProjectName(vector_of_works, choice);
		break;
	case 3:// �������� ��������� ��� ����� � �������
		editEmployeeInProject(vector_of_works, choice);
		break;
	case 4:// ��������� ����������� � ������������ ������
		addEmployeesInProject(vector_of_works, choice);
		break;
	case 5:// ��������� ����������� � ������������ ������
		deleteEmployee(vector_of_works, choice);
		break;
	}
}
void editWholeProject(vector<TypeOfWork>& vector_of_works, int choice)
{
	string name;
	TypeOfWork work_temp;
	int size;
	name = vector_of_works.at(choice - 1).project_name;
	for (int i = 0; i < vector_of_works.size(); i++)
	{
		if (vector_of_works.at(i).project_name == name)
		{
			vector_of_works.erase(vector_of_works.begin() + i);
			i--;
		}
	}
	writeFileProjects(vector_of_works);
	cout << "Enter how many employees include into project" << endl;
	int em;
	cin >> em;
	vector_of_works.resize(vector_of_works.size() + em);
	size = vector_of_works.size();
	for (int m = (vector_of_works.size() - em); m < size; m++)
	{
		inputInformation(work_temp, name, vector_of_works);// ������������� ������� ���������� ��������� � AddProject.h
		vector_of_works.push_back(work_temp);
		writeEndFileProject(work_temp, vector_of_works);
	}
}
void changeProjectName(vector<TypeOfWork>& vector_of_works, int choice)
{
	string new_name, name;
	name = vector_of_works.at(choice).project_name;
	cout << "Enter new name of project" << endl;
	cin >> new_name;
	for (int i = 0; i < vector_of_works.size(); i++)
		if (vector_of_works.at(i).project_name == name)
			vector_of_works.at(i).project_name = new_name;
	writeFileProjects(vector_of_works);
}
void editEmployeeInProject(vector<TypeOfWork>& vector_of_works, int choice)
{
	int i = 0, k = 0;
	cout << "Choose:" << endl;
	while (i != vector_of_works.size())
	{
		if (vector_of_works.at(i).project_name == vector_of_works.at(choice).project_name)
			cout << i << ")" << vector_of_works.at(i).FIO << endl;
		i++;
	}
	cin >> k;
	inputInformation(vector_of_works, k);
	writeFileProjects(vector_of_works);
}
void addEmployeesInProject(vector<TypeOfWork>& vector_of_works, int choice)
{
	TypeOfWork work_temp;
	string name = vector_of_works.at(choice - 1).project_name;
	int number_of_employees;
	cout << "Enter how many employees do you want to add in project" << endl;
	cin >> number_of_employees;
	for (int i = choice; vector_of_works.at(i).project_name == name; i++)
	{
		if (vector_of_works.at(i + 1).project_name != vector_of_works.at(i).project_name)
		{
			for (int n = 0; n < number_of_employees; n++)
			{
				inputInformation(work_temp, name, vector_of_works);
				vector_of_works.emplace(vector_of_works.begin() + i++, work_temp);
			}
		}
		writeFileProjects(vector_of_works);
	}
}
void deleteEmployee(vector<TypeOfWork>& vector_of_works, int choice)
{
	int descission;
	cout << "Choose employee:" << endl;
	string name = vector_of_works.at(choice).project_name;
	for (int i = choice - 1; vector_of_works.at(i).project_name == name; i++)
	{
		cout << i + 1 << ")" << vector_of_works.at(i).FIO << endl;// ��������� ����� ����������
	}
	cin >> choice;
	cout << "Are you shure?" << endl;
	cout << "1)YES\t2)NO" << endl;
	cin >> descission;
	if (descission == 1)
	{
		vector_of_works.erase(vector_of_works.cbegin() + (choice - 1));
		writeFileProjects(vector_of_works);
	}
}