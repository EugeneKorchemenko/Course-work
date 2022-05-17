#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include "Structs.h"
#include "sha256.h"
#include "Interfaces.h"

using namespace std;

// ¬вод чисел с проверкой на корректность
int input();
int input(int min, int max);

bool isLoginUnique(Account account_temp, vector <Account> vector_of_accaunts);
bool isPasswordSuitable(Account& account_temp, string password1, string password2);
bool isNameOfProjectUnique(vector<TypeOfWork> vector_of_works, string name);
// ѕроверка при авторизации на существование логина и  правильность парол€ 
bool compareInputData(Account& account_temp, vector <Account>& vector_of_accaunts);

// ѕроверка не задействован ли сотрудник на одном и том же ваиде работ на проекте
bool chekIfEmployeeDoSameWorkOnProject(TypeOfWork work_temp, vector<TypeOfWork> vector_of_works);
bool chekIfEmployeeDoSameWorkOnProject(vector<TypeOfWork> vector_of_works, int m);
// ¬вод с проверкой строки на корректность
void inputLine(string& string, int SIZE);
// ≈сли файл пуст выводит соответствующее сообщение
bool printFileIsEmpty(vector<TypeOfWork>& vector_of_works);