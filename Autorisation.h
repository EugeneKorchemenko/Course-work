#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include "Structs.h"
#include "Constants.h"
#include "Validation.h"
#include "Interfaces.h"
#include "MenuForAdmin.h"
#include "MenuForUser.h"
#include "sha256.h"

using namespace std;

void autorisatie();
//чтение акквунтов из файла
void readAccountsBase(vector<Account>& vector_of_accaunts);
int getCountOfAccounts(string file_path);
//чтение данных о проекте из файла
void doesFileExist(vector <TypeOfWork>& vector_of_works, int access);  // проверка на существование файла
int getCountOfTypesOfWorkInFile(string file_path);  // считывем из файла количество типов работ

void menu(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
//регистрация
void singUp(vector <Account>& vector_of_accaunts);
void createLoginAndPassword(Account& account_temp, vector <Account>& vector_of_accaunts, int choice);
void hashPassword(Account& account_temp);
string generateSalt(int salt_size); // функция генерации соли
string getSymbolsForSalt(); // функция формирования набора символов
//вход
void logIn(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
bool compareInputData(Account& account_temp, vector <Account>& vector_of_accaunts); // проверка при авторизации на правильность лгина и пароля 
void enterMenu(Account account_temp, vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
void hideInput(Account& account_temp); // скрытый ввод пароля со *