#pragma once
#include <iostream>
#include <vector>
#include "Structs.h"
#include "Constants.h"
#include "MenuForAdmin.h"//doesFileExist getCountOfTypesOfWorkInFile
#include "ViewData.h"
#include "Sort.h"

using namespace std;

void menuForUser(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works);