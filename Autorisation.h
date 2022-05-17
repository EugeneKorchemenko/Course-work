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
// ������ ��������� �� �����
void readAccountsBase(vector<Account>& vector_of_accaunts);
int getCountOfAccounts(string file_path);
/* ������ ������ � ������� �� �����*/
// �������� �� ������������� �����
void doesFileExist(vector <TypeOfWork>& vector_of_works, int access);  
// �������� �� ����� ���������� ����� �����
int getCountOfTypesOfWorkInFile(string file_path);  

void menu(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
// �����������
void singUp(vector <Account>& vector_of_accaunts);
// �������� ������ � ������
void createLoginAndPassword(Account& account_temp, vector <Account>& vector_of_accaunts, int choice);
// ���������� ������
void hashPassword(Account& account_temp);
// ������� ��������� ����
string generateSalt(int salt_size); 
// ������� ������������ ������ ��������
string getSymbolsForSalt(); 
// ����
void logIn(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
// �������� ��� ����������� �� ������������ ����� � ������ 
bool compareInputData(Account& account_temp, vector <Account>& vector_of_accaunts); 
// ���� � ���� ��������������� ���� ��������
void enterMenu(Account account_temp, vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);
// ������� ���� ������ �� *
void hideInput(Account& account_temp); 