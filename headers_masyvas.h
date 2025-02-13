#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Stud {
    string vardas, pavarde;
    int *pazymiai=nullptr;
    int dydis=0;
    int egzaminas;
};