#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
#include "Constants.h"
#include "Interfaces.h"
#include "Validation.h"

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

void chooseWorkName(TypeOfWork& work);
// ���������� � ����� ����� ����� ������: ���� �����
void writeEndFileProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);

void writeProjectInVector(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search, int j, int i);

// ������ � ���� (���� ���-�� ���� � �����, �� �������� ������ ����� �������):
void writeFileAccounts(vector<Account> vector_of_accaunts);
// ���������� � ����� ����� ����� ������: ��������
void writeAccountInTheEnd(Account& account_temp);
// �������������� ������ ������� � ���� ��� ������� ������������
void rewriteAccount(Account& account_temp);