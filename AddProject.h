#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
#include "Constants.h"


using namespace std;

// ���������� �������� � ������
void addProjectsInVector(vector<TypeOfWork>& vector_of_works);
// ������ ���������� ��� ����������
void inputInformation(TypeOfWork& work_temp, string name, vector<TypeOfWork> vector_of_works);
//�������� �� ������������ �� ��������� �� ����� � ��� �� ����� ����� �� �������
bool chekIfEmployeeDoSameWorkOnProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);
void chooseWorkName(TypeOfWork& work);
// ���������� � ����� ����� ����� ������:
void writeEndFileProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);
