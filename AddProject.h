#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
#include "Constants.h"


using namespace std;

// ƒобавление студента в массив
void addProjectsInVector(vector<TypeOfWork>& vector_of_works);
// ввести информацию дл€ добавлени€
void inputInformation(TypeOfWork& work_temp, string name, vector<TypeOfWork> vector_of_works);
//проверка не задействован ли сотрудник на одном и том же ваиде работ на проекте
bool chekIfEmployeeDoSameWorkOnProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);
void chooseWorkName(TypeOfWork& work);
// ƒобавление в конец файла одной строки:
void writeEndFileProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);
