#pragma once
#include "iostream"

using namespace std;

template <typename T1>
bool DataImportCheck(const string& InputFile, unsigned int* S,
                     unsigned int* n, T1*& VecW, T1*& VecR);

template <typename T>
string ArrayToStringConv(const size_t& n,
                     const T* const& v);
