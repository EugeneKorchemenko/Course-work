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