#pragma once
#include <iostream>
#include <vector>
#include "Structs.h"
#include "Constants.h"
#include "Accounts.h"
#include "ViewData.h"
#include "Delete.h"
#include "Edit.h"
#include "GenerateData.h"
#include "Search.h"
#include "AddProject.h"

using namespace std;

void menuForAdmin(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);

void workWithData(vector <TypeOfWork>& vector_of_works);

void workWithAcccounts(vector <Account>& vector_of_accaunts);
// проверка на существование файла
void doesFileExist(vector <TypeOfWork>& vector_of_works);
// считывем из файла количество типов работ
int getCountOfTypesOfWorkInFile(string file_path);