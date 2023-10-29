#include <iostream>
#include "..\header\read.h"
using namespace std;
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
    fileReader obj;
    int choice;
    cout<<"Choose the geometry that u want to merge"<<endl;
    cout<<"1.Cube and Cube"<<endl;
    cout<<"2.Cube and Sphere"<<endl;
    cout<<"3.Sphere and Sphere"<<endl;
    cin>>choice;
    vector<double> vec1 ;
    vector<double> vec2 ;
    vector<double> vec1Copy ;
    vector<double> vec2Copy ;
    vector<vector<double>> vec3 ;
    vector<vector<double>> vec4 ;
    string filepath1 = "..\\src\\sphere.stl";
    string filepath2 = "..\\src\\cube1.stl";
    string filepathmodifer1 ;
    string filepathmodifer2 ;
    obj.readFromFile("..\\src\\cube1.stl");
    vec1Copy = obj.boundryPoints(filepath1);
    
    vec2Copy = obj.boundryPoints(filepath2);


    if(vec1Copy.at(0)<vec2Copy.at(0))
    {
        for(int i= 0;i<vec2Copy.size();i++)
        {
            vec1.push_back(vec2Copy[i]);
        }
        for(int i= 0;i<vec1Copy.size();i++)
        {
            vec2.push_back(vec1Copy[i]);
        }
        filepathmodifer1 = filepath2;
        filepathmodifer2 = filepath1;
    }
    else
    {
        for(int i= 0;i<vec1Copy.size();i++)
        {
            vec1.push_back(vec1Copy[i]);
        }
        for(int i= 0;i<vec2Copy.size();i++)
        {
            vec2.push_back(vec2Copy[i]);
        }
        filepathmodifer1 = filepath1;
        filepathmodifer2 = filepath2;
    }

        for(int i=0;i<vec1.size();i++)
    {
        cout<<vec1.at(i)<<endl;
    }


    for(int i=0;i<vec2.size();i++)
    {
        cout<<vec2.at(i)<<endl;
    }

    
    double value = 0;
    double value1 =0;
    double value2 = 0;
    
        if(choice==1)
        {
            value = vec1.at(0) - vec2.at(0);
            value1 = vec1.at(2) - vec2.at(3);
            value2 = vec1.at(4) - vec2.at(4);
        }else if(choice==2)
        {
            value = vec1.at(0) - vec2.at(1);
            value1 = vec1.at(2) - vec2.at(3);
            value2 = vec1.at(4) - vec2.at(4);
        }
        




    vec3 = obj.modifyedPoints(filepathmodifer1,value);
    string data ="";
    
    for(int i=0;i<vec3.size();i++)
    {
        vec3.at(i).at(0)=vec3.at(i).at(0)-value;
        vec3.at(i).at(1)=vec3.at(i).at(1)-value1;
        vec3.at(i).at(2)=vec3.at(i).at(2)-value2;
        data = to_string(vec3.at(i).at(0))+" "+to_string(vec3.at(i).at(1))+" "+to_string(vec3.at(i).at(2));
        obj.writeInFile(data,"file1");
    }


    vec4 = obj.modifyedPoints(filepathmodifer2,value);
    for(int i=0;i<vec4.size();i++)
    {
        if(choice==2)
        {
            vec4.at(i).at(1)=vec4.at(i).at(1)+((vec1.at(3)-vec1.at(2))/2.0);
            vec4.at(i).at(2)=vec4.at(i).at(2)+((vec1.at(5)-vec1.at(4))/2.0);
        }
        data = to_string(vec4.at(i).at(0))+" "+to_string(vec4.at(i).at(1))+" "+to_string(vec4.at(i).at(2));
        obj.writeInFile(data,"file2");
    }
    return 0;
}
