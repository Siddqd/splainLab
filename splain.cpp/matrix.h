#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void showMat(vector < vector <double>>);

vector <vector <double>> getMat(const char*);

int detA(vector <vector <double>>);

vector <vector <double>> invMat(vector <vector <double>>);

vector <vector <double>> mulMat(vector <vector <double>>);