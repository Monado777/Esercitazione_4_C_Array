#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

template <typename T1>
bool DataImportCheck(const string& InputFile,
                     unsigned int* S,
                     unsigned int* n,
                     T1*& VecW,
                     T1*& VecR)
{
    ifstream Data;
    Data.open(InputFile);

    if (Data.fail())
    {
        cerr<< "File could not be opened."<< endl;
        return false;
    }

    // S
    string Line;
    string TempString;
    while (!Data.eof())
    {
        getline(Data, Line, ';');
        if (Line == "S")
        {
            getline(Data, Line);
            TempString = Line;
            break;
        }
    }
    *S = stoi(TempString);

    // n
    while (!Data.eof())
    {
        getline(Data, Line, ';');
        if (Line == "n")
        {
            getline(Data, Line);
            TempString = Line;
            break;
        }
    }
    *n = stoi(TempString);

    // w & r
    VecW = new T1[*n];
    VecR = new T1[*n];
    unsigned int i;
    unsigned int j = 0;
    unsigned int k = 0;
    string a;
    string b;
    while (!Data.eof())
    {
        getline(Data, Line);
        if (Line == "w;r")
            break;
    }

    unsigned int c = 0;
    vector<string> TempVec;
    while (!Data.eof() && j < *n && k < *n)
    {
        for (i=0; i<(*n); i++)
        {
            getline(Data, Line);
            stringstream WRVals(Line);
            while( WRVals.good())
            {
                string NewSTR;
                getline( WRVals, NewSTR, ';');
                TempVec.push_back(NewSTR);
                c++;
            }
        }
    }
    for (c=0; c < 2*(*n); c++)
    {
        if (c % 2 == 0)
        {
            VecW[j] = stod(TempVec[c]);
            j++;
        }
        if (c % 2 != 0)
        {
            VecR[k] = stod(TempVec[c]);
            k++;
        }

    }

    Data.close();
    return true;
}

template <typename T>
string ArrayToStringConv(const size_t& n, const T* const& v)
{
    ostringstream toString;
    toString << "[ ";
    for (size_t i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << " ]";

    return toString.str();
}

template bool DataImportCheck<double>(const string& InputFile, unsigned int* S, unsigned int* n, double*& VecW, double*& VecR);
template string ArrayToStringConv<unsigned int>(const size_t& n, const unsigned int* const& v);
template string ArrayToStringConv<double>(const size_t& n, const double* const& v);
