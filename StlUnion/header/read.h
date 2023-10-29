#pragma once
#include <iostream>
using namespace std;
#include<vector>


class fileReader
{
    public :
        fileReader();
        ~fileReader();
        void readFromFile(string filename);
        vector<double> boundryPoints(string filePath);
        vector<vector<double>> modifyedPoints(string filepath,double value);
        void  writeInFile(string data,string fileName);

};