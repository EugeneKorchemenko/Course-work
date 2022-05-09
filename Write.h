#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
#include "Constants.h"
#include "Interfaces.h"
#include "Validation.h"

using namespace std;

// Заполнение вектора проектов
void generateProjectsVector(vector<TypeOfWork>& vector_of_works);
// ввести информацию для добавления
void inputInformation(vector<TypeOfWork>& vector_of_works, int m);
void chooseWorkName(vector<TypeOfWork>& vector_of_works, int m);
// Запись в файл (если что-то было в файле, то исходные данные будут удалены):
void writeFileProjects(vector<TypeOfWork> vector_of_works);

// Добавление проекта в вектор
void addProjectsInVector(vector<TypeOfWork>& vector_of_works);
// ввести информацию для добавления
void inputInformation(TypeOfWork& work_temp, string name, vector<TypeOfWork> vector_of_works);

void chooseWorkName(TypeOfWork& work);
// Добавление в конец файла одной строки: типа работ
void writeEndFileProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);

void writeProjectInVector(vector<TypeOfWork> vector_of_works, vector<TypeOfWork>& search, int j, int i);

// Запись в файл (если что-то было в файле, то исходные данные будут удалены):
void writeFileAccounts(vector<Account> vector_of_accaunts);
// Добавление в конец файла одной строки: аккаунта
void writeAccountInTheEnd(Account& account_temp);
// Первоначальная запись аккаунт в файл для первого пользователя
void rewriteAccount(Account& account_temp);