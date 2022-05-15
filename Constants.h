#pragma once
#include <iostream>

using namespace std;

const string FILE_DATA = "Myfile.txt";

const string FILE_ACCOUNTS = "Database.txt";
const int SALT_SIZE = 16; // длина соли
const int SYMBOLS_SIZE = 62; // набор символов, из которых генерируется соль

const int HEAD_ADMIN = 3;
const int ADMIN = 2;
const int USER = 1;
const int BLOCKED_ACCOUNT = 2;
const int ACTIVATED_ACCOUNT = 1;
const int UNACTIVATED_ACCOUNT = 0;
const int LOGIN_SIZE = 17;
const int PASSWORD_SIZE = 20;
const int PROJECT_SIZE = 18;
const int SURNAME_SIZE = 25;
const int MAX_HOURS = 3000;
const int MAX_COST_OF_HOUR = 300;


const string MENU_AUTORISATION = "\t__________AUTORISATION__________\n1 Log in\n2 Create new account\n0 Exit";
const string ENTER_LOGIN = "Enter login (max size is 17): ";
const string ENTER_PASSWORD = "Enter password: ";
const string ENTER_PASSWORD_AGAIN = "Enter it again: ";
const string INCORRECT_INPUT = "Incorrect input. Please try again \nIf you want go back press 0";
const string LOG_IN_COMPLETED = "Log in completed !!!";
const string LIMIT_OF_ATTEMPTS = "The limit of attempts has been exceeded!!!";
const string WAIT_FOR_CONFORMITION = "Wait for the confirmation of registration";
const string ACCOUNT_BLOCKED = "Your account is temporarily blocked";

const string ADMIN_MODE = "\tMode: Admin";
const string MENU_ADMIN = "Choose:\n1 Work with data\n2 Work with accounts\n0 Exit";
const string MENU_ACCONTS = "\t________MENU_______\n1 Show list of accounts\n2 Show outgoing registration applications\n3 Edit accounts\n4 Change password\n0 Exit";
const string MENU_DATA = "\t________MENU_______\n1 Show information about projects\n2 Add new project\n3 Edit project\n4 Search by projects\n5 Delete project\n0 Exit";
const string SURE_DESTROY = "Are you shure? It will destroy all data wich was in file.\n1 YES\n2 NO";
const string ADD_REWRITE = "\t______CHOOSE______\n1 Add project\n2 Rewrite project (delete old data)\n0 Exit";

const string MENU_USER = "\t________MENU_______\nMode: User\n1 Show information about projects\n2 Search by projects\n3 Change password\n0 Exit";
const string SORT_PROJECTS = "\t\t________SORT________\nChoose how you want to sort projects:\n1 By project's cost\n2 By ammount of employees\n3 By name\n0 Exit view";
const string ASCENDING_OR_DESCENDING = "Choose how you wnat to sort\n1)By ascending\n2)By descending";
const string A_TO_Z_OR_Z_TO_A = "Choose how you want to sort\n1)By A-Z\n2)By Z-A";
const string SORT_ACCOUNTS = "\t\t________SORT________\nChoose how you want to sort accounts:\n1 By login\n2 By Role\n3 By status\n0 Exit view";
const string CHOOSE_EDITING_PROJECT = "Choose project which you want to edit: ";
const string O_TO_TURN_BACK = "Press 0 to turn back";
const string EDIT_DATA = "1 Edit all information about project\n2 Edit name of project\n3 Edit employee\n4 Add employees in project\n5 Delete employee from project\n0 Back";
const string SURE = "Are you sure?\nChoose:\t1 YES\t2 NO";
const string HOW_MANY_EMPLOYEES = "Enter how many employees include into project: ";
const string CHOOSE_PARAM_OF_EMPLOYEE = "1 Surname\n2 Type of work\n3 Ammount of hours\n4 Cost per hour\n5 All infomation\n0 Back";
const string ENTER_SURNAME = "Enter surname of employee (max size is 25): ";
const string ADD_EMPLOYEES = "Enter how many employees do you want to add in project: ";
const string DELITION = "Deletion was successful";
const string EDIT_ACCOUNT = "Choose action:\n1 Add new account\n2 Delete account\n3 Block account\n4 Unlock accountt\n5 Change role of the account\n6 Change password\n0 Back";
const string ADD_PROJECTS = "Enter how many projects do you want to add:";
const string ENTER_NAME_OF_PROJECT = "Enter name of the project (max size is 18): ";
const string ENTER_HOURS = "How many hours employee spend on this project: ";
const string CHOOSE_TYPE_OF_WORK = "Choose type of work\n1)Work on requirements\n2)Development\n3)Implementation\n4)Testing";
const string SEARCH = "\t\t________SEARCH________\nEnter the parameters by which the search will be performed:\n1 Project name\n2 Ammount of employees\n3 FIO of employee\n4 Cost of the project\n0 Exit";
const string LINE_75 = "--------------------------------------------------------------------------";
const string LINE_57 = "--------------------------------------------------------";
const string LINE_42 = "-----------------------------------------";