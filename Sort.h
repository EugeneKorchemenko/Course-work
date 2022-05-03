#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����������
void sortProjects(vector<TypeOfWork> vector_of_works);
//���������� �� ��������� ������� 
void sortProjectsByCost(vector<TypeOfWork>& sorted, vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works);
bool compareByCostAscending(const Project& first, const Project& second);
bool compareByCostDescending(const Project& first, const Project& second);
void countCostOfProjects(vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works);
void writeSortedVectorOfProjects(vector<TypeOfWork>& sorted, vector <Project> vector_of_projects, vector<TypeOfWork> vector_of_works);
//���������� �� ���������� �����������
void sortProjectsByAmmountOfEmployees(vector<TypeOfWork>& sorted, vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works);
void countAmmountOfEmployees(vector <Project>& vector_of_projects, vector<TypeOfWork> vector_of_works);
bool compareByAscendingOfEmployees(const Project& first, const Project& second);
bool compareByCostDescendingOfEmployees(const Project& first, const Project& second);
//���������� �� �����
void sortProjectsByName(vector<TypeOfWork>& sorted, vector <TypeOfWork> vector_of_works);
bool compareByNameAscending(const TypeOfWork& first, const TypeOfWork& second);
bool compareByNameDescending(const TypeOfWork& first, const TypeOfWork& second);