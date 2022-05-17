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
// Чтение аккаунтов из файла
void readAccountsBase(vector<Account>& vector_of_accaunts);
int getCountOfAccounts(string file_path);
/* Чтение данных о проекте из файла*/
// Проверка на существование файла
void doesFileExist(vector <TypeOfWork>& vector_of_works, int access);  
// Считывем из файла количество типов работ
int getCountOfTypesOfWorkInFile(string file_path);  

void menu(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
// Регистрация
void singUp(vector <Account>& vector_of_accaunts);
// Создания логина и пароля
void createLoginAndPassword(Account& account_temp, vector <Account>& vector_of_accaunts, int choice);
// Шифрование пароля
void hashPassword(Account& account_temp);
// Функция генерации соли
string generateSalt(int salt_size); 
// Функция формирования набора символов
string getSymbolsForSalt(); 
// Вход
void logIn(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
// Проверка при авторизации на правильность лгина и пароля 
bool compareInputData(Account& account_temp, vector <Account>& vector_of_accaunts); 
// Вход в меню соответствующее роли аккаунта
void enterMenu(Account account_temp, vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
// Скрытый ввод пароля со *
void hideInput(Account& account_temp); 