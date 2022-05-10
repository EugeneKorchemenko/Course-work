#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
#include "Interfaces.h"
#include "Validation.h"
#include "Write.h"
#include "Autorisation.h"

using namespace std;

// изменение проекта
void chooseEditingProject(vector<TypeOfWork>& vector_of_works);
void showProjects(vector<TypeOfWork> vector_of_works, vector <Project>& vector_of_projects);
void chooseKindOfEditing(vector<TypeOfWork>& vector_of_works, int choice);
void editWholeProject(vector<TypeOfWork>& vector_of_works, int choice);
void changeProjectName(vector<TypeOfWork>& vector_of_works, int choice);
void editEmployeeInProject(vector<TypeOfWork>& vector_of_works, int choice);
void addEmployeesInProject(vector<TypeOfWork>& vector_of_works, int choice);
void deleteEmployee(vector<TypeOfWork>& vector_of_works, int choice);
void delProjectFromVector(vector<TypeOfWork>& vector_of_works);
// изменение аккаунта
void editAccounts(vector <Account>& vector_of_accaunts, string login);
void deleteAccount(vector <Account>& vector_of_accaunts, string login);
void blockAccount(vector <Account>& vector_of_accaunts, string login);
void unlockAccount(vector <Account>& vector_of_accaunts);
int chooseAccount(vector <Account>& vector_of_accaunts);
void changePassword(vector <Account>& vector_of_accaunts, string login);
// подтвердить заявки на добавление аккаунтов
void approveApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts);
void approveAllApplications(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts);
void approveOneApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts);
//  удалить заявки на добавление аккаунтов
void deleteApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts);
void deleteAllApplications(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts);
void deleteOneApplication(vector <Account>& vector_unverified_accounts, vector <Account>& vector_of_accaunts);