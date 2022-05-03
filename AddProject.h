#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Добавление студента в массив
void addProjectsInVector(vector<TypeOfWork>& vector_of_works);
// ввести информацию для добавления
void inputInformation(TypeOfWork& work_temp, string name, vector<TypeOfWork>& vector_of_works);
void chooseWorkName(TypeOfWork& work);
// Добавление в конец файла одной строки:
void writeEndFileProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);