#include <iostream>
#include "..\header\read.h"
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <limits>
using namespace std;

fileReader ::fileReader()
{
}

fileReader ::~fileReader()
{
}

void fileReader ::readFromFile(string filename)
{
    string line;
    ifstream read{filename};
    ofstream write{"..\\src\\gnufile.txt", std::ios::app};
    int count = 0;
    string firstline = "";
    while (getline(read, line))
    {
        int index = -1;
        index = line.find("vertex");

        if (index != -1)
        {
            if (count == 0)
            {
                firstline = line.substr(index + 7);
            }
            count += 1;
            write << line.substr(index + 7) << endl;
        }
        if (count == 3)
        {
            write << firstline << endl;
            firstline = "";
            count = 0;
        }
    }
    write << endl;
    read.close();
    write.close();
}

vector<double> fileReader ::boundryPoints(string filePath)
{

    ifstream readfile{filePath};
    vector<double> boundry;
    double x_max, x_min, y_max, y_min, z_max, z_min;
    x_max = numeric_limits<double>::min();
    x_min = numeric_limits<double>::max();
    y_max = numeric_limits<double>::min(),
    y_min = numeric_limits<double>::max();
    z_max = numeric_limits<double>::min();
    z_min = numeric_limits<double>::max();
    string line;
    int index = -1;
    while (getline(readfile, line))
    {
        index = line.find("vertex");

        if (index != -1)
        {
            int k = 7;
            while (line[index + k] == ' ')
            {
                k += 1;
            }
            k = k + index;

            line = line.substr(k);
            string variable = "";
            vector<double> vec;
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ' ')
                {
                    double var{0};
                    if (variable.length() != 0)
                    {
                        try
                        {
                            double var = stod(variable);
                            vec.push_back(var);
                        }
                        catch (const std::exception &e)
                        {

                            vec.push_back(var);
                        }
                        variable = "";
                    }
                }
                else
                {
                    variable += line[i];
                }
            }
            vec.push_back(stod(variable));
            if (x_max < vec.at(0))
            {
                x_max = vec.at(0);
            }
            if (x_min > vec.at(0))
            {
                x_min = vec.at(0);
            }

            if (y_max < vec.at(1))
            {
                y_max = vec.at(1);
            }
            if (y_min > vec.at(1))
            {
                y_min = vec.at(1);
            }

            if (z_max < vec.at(2))
            {
                z_max = vec.at(2);
            }
            if (z_min > vec.at(2))
            {
                z_min = vec.at(2);
            }
        }
    }
    boundry.push_back(x_min);
    boundry.push_back(x_max);
    boundry.push_back(y_min);
    boundry.push_back(y_max);
    boundry.push_back(z_min);
    boundry.push_back(z_max);

    return boundry;
}

vector<vector<double>> fileReader::modifyedPoints(string filePath, double value)
{
    ifstream readfile{filePath};
    vector<vector<double>> boundry;
    string line;
    int index = -1;
    int count = 0;
    vector<double> store;
    while (getline(readfile, line))
    {
        index = line.find("vertex");
        if (index != -1)
        {
            vector<double> vec;

            line = line.substr(index + 7);
            string variable = "";
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ' ')
                {
                    double var{};
                    if (variable.length() != 0)
                    {
                        try
                        {
                            double var = stod(variable);
                            vec.push_back(var);
                        }
                        catch (const std::exception &e)
                        {

                            vec.push_back(var);
                        }
                        variable = "";
                    }
                }
                else
                {
                    variable += line[i];
                }
            }

            vec.push_back(stod(variable));
            if (count == 0)
            {
                store = vec;
            }
            boundry.push_back(vec);
            count += 1;
            if (count == 3)
            {
                boundry.push_back(store);
                count = 0;
            }
        }
    }
    return boundry;
}

void fileReader ::writeInFile(string data, string fileName)
{
    ofstream obj{"..\\src\\" + fileName + ".txt", std::ios::app};
    obj << data << endl;
    obj.close();
}