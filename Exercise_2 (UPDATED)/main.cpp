#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include <vector>

using namespace std;

int main()
{
    vector<string> FinalValue;
    double TempFV;
    int i;
    std::ofstream OutFile("results.txt");
    string InputFile = "./data.csv";
    unsigned int S = 0;
    unsigned int n = 0;
    double* VecW = nullptr;
    double* VecR = nullptr;

    if (!DataImportCheck(InputFile, &S, &n, VecW, VecR))
    {
        cerr<< "Error: please make sure the input data is coherent."<< endl;
        return -1;
    }
    else
    {
        cout << "S = " << S << endl;
        cout << "n = " << n << endl;
        OutFile << "S = " << S << ", " <<  "n = " << n << endl;
        cout << "w = " << ArrayToStringConv(n, VecW) << endl;
        OutFile << "w = " << ArrayToStringConv(n, VecW) << endl;
        cout << "r = " << ArrayToStringConv(n, VecR) << endl;
        OutFile << "r = " << ArrayToStringConv(n, VecR) << endl;

        cout << "Final Values:" <<endl;
        OutFile << "Final Values:" <<endl;
        for (i=0; i < n; i++)
        {
            TempFV = (1+ VecR[i])*S;
            cout << TempFV << endl;
            OutFile << TempFV << endl;
        }
    }

    delete[] VecW;
    delete[] VecR;
    OutFile.close();
    return 0;
}
