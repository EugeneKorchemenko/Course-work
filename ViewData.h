#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Structs.h"
#include "Sort.h"

using namespace std;

// ����� �� ����� ������� ��������
void showProjectVector(vector<TypeOfWork>& vector_of_works);
// ����� �� ����� ���������� � ����� �����
void showInfoAboutAllTypesOfWork(vector<TypeOfWork> vector_of_works, int& cost, int& employees, int& r, int i);
void sortProjectByTypeOfWork(vector<TypeOfWork>& vector_of_works);
void setPriorityOfTypeOfWork(vector<TypeOfWork>& vector_of_works);
int getPriorityOfTypeOfWork(string name);
bool compareByPriorityOfTypeOfWork(const TypeOfWork& first, const TypeOfWork& second);
// ������� ���������� ����������� � ��������� ���� ����� ������� (��)
void calculateTypeOfWork(vector<TypeOfWork> vector_of_works, int& cost, int& employees, int& r, int i, string type_of_work);
// ������� ��� ������ � �������� ���������� �� ����������
void showPersonalInformationAboutEmployee(vector<TypeOfWork>& search);
void showInfoAboutAllProjects(vector<TypeOfWork> search, int& cost, int& hours, int i);
void calculateProject(vector<TypeOfWork> search, int& cost, int& hours, int& r, int i, string project_name);

//getCountOfNumbersInNumber
int num(int x);