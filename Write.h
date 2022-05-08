#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
#include "Constants.h"

using namespace std;

// ���������� ������� ��������
void generateProjectsVector(vector<TypeOfWork>& vector_of_works);
// ������ ���������� ��� ����������
void inputInformation(vector<TypeOfWork>& vector_of_works, int m);
void chooseWorkName(vector<TypeOfWork>& vector_of_works, int m);
// ������ � ���� (���� ���-�� ���� � �����, �� �������� ������ ����� �������):
void writeFileProjects(vector<TypeOfWork> vector_of_works);

// ���������� ������� � ������
void addProjectsInVector(vector<TypeOfWork>& vector_of_works);
// ������ ���������� ��� ����������
void inputInformation(TypeOfWork& work_temp, string name, vector<TypeOfWork> vector_of_works);
//�������� �� ������������ �� ��������� �� ����� � ��� �� ����� ����� �� �������
bool chekIfEmployeeDoSameWorkOnProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);
void chooseWorkName(TypeOfWork& work);
// ���������� � ����� ����� ����� ������: ���� �����
void writeEndFileProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);

// ������ � ���� (���� ���-�� ���� � �����, �� �������� ������ ����� �������):
void writeFileAccounts(vector<Account> vector_of_accaunts);
// ���������� � ����� ����� ����� ������: ��������
void writeAccountInTheEnd(Account& account_temp);
// �������������� ������ ������� � ���� ��� ������� ������������
void rewriteAccount(Account& account_temp);