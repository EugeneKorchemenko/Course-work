#pragma once
#include <iostream>

using namespace std;

struct TypeOfWork
{
	string name, FIO, project_name;
	int ammount_of_hours = 0, cost_of_type_of_work = 0, priority_of_type_of_work = 0;
	double cost_per_hour = 0;
};
struct Project
{
	string name;
	int cost = 0, ammount_of_employees = 0;
};
struct Account
{
	string login, password, salt;
	int status, role;
};