#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "Structs.h"
#include "Constants.h"

using namespace std;

void showListOfAccounts(vector <Account>& vector_of_accaunts);
string getStatus(int status);
string getRole(int role);

void showApplications(vector <Account>& vector_of_accaunts);