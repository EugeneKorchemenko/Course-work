#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void chooseKindOfEdition(vector<TypeOfWork>& vector_of_works);
// изменение проекта
void editPoject(vector<TypeOfWork>& vector_of_works, int choice);
void editWholeProject(vector<TypeOfWork>& vector_of_works, int choice);
void changeProjectName(vector<TypeOfWork>& vector_of_works, int choice);
void editEmployeeInProject(vector<TypeOfWork>& vector_of_works, int choice);
void addEmployeesInProject(vector<TypeOfWork>& vector_of_works, int choice);
void deleteEmployee(vector<TypeOfWork>& vector_of_works, int choice);