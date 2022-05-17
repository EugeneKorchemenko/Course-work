#pragma once
#include <iostream>

using namespace std;

// Структура типов работ на проекте
struct TypeOfWork
{
	string name, FIO, project_name;                                  // Название типа работ, Фамилия сотрудника, Имя проекта
	int ammount_of_hours = 0, cost_of_type_of_work = 0, priority_of_type_of_work = 0, cost_per_hour = 0;  // Количество часов, стоимость этого типа работ, приориткт типа работ, стоимость часа сотрудника
};
// Структура проекта
struct Project
{
	string name;													 // Имя проекта
	int cost = 0, ammount_of_employees = 0, number_of_first_work = 0;  // Стоимость проекта, Количество сотрудников на проекте, Номер первой работы на проекте 
};
// Структура аккаунта
struct Account
{
	string login, password, salt, hash_password_with_salt;  // Логин аккаунта; Пароль; Соль; Зашифрованный пароль
	int status;											    /* Статус:  0 – ожидает подтверждения, 1 – Доступ разрешен, 2 - Заблокирован;*/
	int	role;									            /* Роль пользователя: 1 – пользователь, 2 - администратор, 3 - главгый администратор */
};  