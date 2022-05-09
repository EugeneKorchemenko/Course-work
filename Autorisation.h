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
void readAccountsBase(vector<Account>& vector_of_accaunts);
int getCountOfAccounts(string file_path);

int menu(vector <Account>& vector_of_accaunts);

void singUp(vector <Account>& vector_of_accaunts);
void createLoginAndPassword(Account& account_temp, vector <Account>& vector_of_accaunts, int choice);
void hashPassword(Account& account_temp);
string generateSalt(int salt_size); // функция генерации соли
string getSymbolsForSalt(); // функция формирования набора символов

void logIn(vector <Account>& vector_of_accaunts);
bool compareInputData(Account& account_temp, vector <Account>& vector_of_accaunts); // проверка при авторизации на правильность лгина и пароля 
void enterMenu(Account account_temp, vector <Account>& vector_of_accaunts);
void hideInput(Account& account_temp); // скрытый ввод пароля со *