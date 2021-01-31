#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector <vector <double>> getMat(char*);

int detA(vector <vector <double>>);

vector <vector <double>> invMat(vector <vector <double>>);

vector <vector <double>> mulMat(vector <vector <double>>);