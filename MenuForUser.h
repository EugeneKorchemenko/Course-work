#pragma once
#include <iostream>
#include <vector>
#include "Structs.h"
#include "Constants.h"
#include "Interfaces.h"
#include "MenuForAdmin.h"
#include "ViewData.h"
#include "Sort.h"

using namespace std;

void menuForUser(vector <Account>& vector_of_accaunts, vector<TypeOfWork>& vector_of_works, string login);