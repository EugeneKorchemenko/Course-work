#pragma once
#include <iostream>
#include <vector>
#include "Structs.h"
#include "Constants.h"
#include "ViewData.h"
#include "Edit.h"
#include "Write.h"
#include "Search.h"
#include "Write.h"

using namespace std;

void menuForAdmin(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works, string login);

void workWithData(vector <TypeOfWork>& vector_of_works);

void workWithAcccounts(vector <Account>& vector_of_accaunts, string login);
// �������� �� ������������� �����
void doesFileExist(vector <TypeOfWork>& vector_of_works, int access);
// �������� �� ����� ���������� ����� �����
int getCountOfTypesOfWorkInFile(string file_path);