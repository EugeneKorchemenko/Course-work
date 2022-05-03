#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void autorisatie();
void readAccountsBase(vector<Account>& vector_of_accaunts);
int getCountOfAccounts(string file_path);
void registerAcount(vector <Account>& vector_of_accaunts);