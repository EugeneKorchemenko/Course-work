#pragma once
#include <iostream>
#include <Windows.h>
#include "conio.h"

using namespace std;

// Отчистка консоли
void clearConsole();
void cls(HANDLE hConsole);
// Остановка программы
void pause();