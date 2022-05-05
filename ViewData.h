#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Structs.h"
#include "Sort.h"

using namespace std;

// вывод на экран вектора проектов
void showProjectVector(vector<TypeOfWork>& vector_of_works);
// вывод на экран информации о видах работ
void showInfoAboutAllTypesOfWork(vector<TypeOfWork> vector_of_works, int& cost, int& employees, int& r, int i);
void sortProjectByTypeOfWork(vector<TypeOfWork>& vector_of_works);
void setPriorityOfTypeOfWork(vector<TypeOfWork>& vector_of_works);
int getPriorityOfTypeOfWork(string name);
bool compareByPriorityOfTypeOfWork(const TypeOfWork& first, const TypeOfWork& second);
// считает количество сотрудников и стоимость вида работ проекта (ИЗ)
void calculateTypeOfWork(vector<TypeOfWork> vector_of_works, int& cost, int& employees, int& r, int i, string type_of_work);
// функция для вывода и подсчёта информации об сотруднике
void showPersonalInformationAboutEmployee(vector<TypeOfWork>& search);
void showInfoAboutAllProjects(vector<TypeOfWork> search, int& cost, int& hours, int i);
void calculateProject(vector<TypeOfWork> search, int& cost, int& hours, int& r, int i, string project_name);

//getCountOfNumbersInNumber
int num(int x);