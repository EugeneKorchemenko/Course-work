#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Structs.h"
#include "Interfaces.h"
#include "Validation.h"
#include "ViewData.h"
#include "Search.h"

using namespace std;

//сортировка проектов
void sortProjects(vector<TypeOfWork> vector_of_works);
//сортировка по стоимости проекта 
void sortProjectsByCost(vector<TypeOfWork>& sorted, vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works);
bool compareByCostAscending(const Project& first, const Project& second);
bool compareByCostDescending(const Project& first, const Project& second);
void countCostOfProjects(vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works);
void writeSortedVectorOfProjects(vector<TypeOfWork>& sorted, vector <Project> vector_of_projects, vector<TypeOfWork> vector_of_works);
//сортировка по количеству сотрудников
void sortProjectsByAmmountOfEmployees(vector<TypeOfWork>& sorted, vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works);
void countAmmountOfEmployees(vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works);
bool compareByAscendingOfEmployees(const Project& first, const Project& second);
bool compareByCostDescendingOfEmployees(const Project& first, const Project& second);
//сортировка по имени
void sortProjectsByName(vector<TypeOfWork>& sorted, vector <TypeOfWork> vector_of_works);
bool compareByNameAscending(const TypeOfWork& first, const TypeOfWork& second);
bool compareByNameDescending(const TypeOfWork& first, const TypeOfWork& second);

//сортировка аккаунтов
void sortAccounts(vector <Account> vector_of_accaunts);
//сортировка аакунтов по логину
void sortAccountByLogin(vector <Account> vector_unverified_accounts);
bool compareByLoginAscending(const Account& first, const Account& second);
bool compareByLoginDescending(const Account& first, const Account& second);
//сортировка аакунтов роли
void sortAccountByRole(vector <Account> vector_of_accaunts);
bool compareByRole(const Account& first, const Account& second);
//сортировка аакунтов по статусу
void sortAccountByStatus(vector <Account> vector_of_accaunts);
bool compareByStatus(const Account& first, const Account& second);