#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
#include "Constants.h"

using namespace std;

// Заполнение массива проектов
void generateProjectsVector(vector<TypeOfWork>& vector_of_works);
// ввести информацию для добавления
void inputInformation(vector<TypeOfWork>& vector_of_works, int m);
void chooseWorkName(vector<TypeOfWork>& vector_of_works, int m);
// Запись в файл (если что-то было в файле, то исходные данные будут удалены):
void writeFileProjects(vector<TypeOfWork> vector_of_works);