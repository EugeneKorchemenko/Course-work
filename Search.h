#pragma once
#include <iostream>
#include <vector>
#include "Structs.h"
#include "Interfaces.h"
#include "Validation.h"
#include "Write.h"
#include "ViewData.h"

using namespace std;

// поиск по заданнным параметрам
void searchForProject(vector<TypeOfWork> vector_of_works);
void seerchProjectByName(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search);
void searchProjectByAmmountOfEmployees(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search);
void countAmmountOfEmploeyeesInProject(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search, int choice, bool& flag);
//ищем повторяющихся сотрудников, которые задействованы в разных видах работ
void findRepeatingEmployees(vector<TypeOfWork> search, int& ammount_of_employees);
void searchProjectsWhereEmployeeWork(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search);
//
void searchProjectsWithSuitableCost(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search);