//
//  prog2.cpp
//  Project1
//
//  Created by Joesh Bautista on 6/6/19.
//  Copyright © 2019 Joesh Bautista. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string removeSpaces(string &str);

int main(){
    
    string line;
    ifstream myfile ("/Users/joeshbautista/Desktop/CPSC323/Project1/Project1/data.txt");
    if (myfile.fail()) {
        cerr << "Error opening a file" << endl;
        myfile.close();
        exit(1);
    }
    ofstream outFile;
    outFile.open("/Users/joeshbautista/Desktop/CPSC323/Project1/Project1/newdata.txt");
    
    while (getline(myfile,line)){
        char c;
        string str;
        
        //Finds reserved word "int" and prints it to file
        size_t pos = line.find("int");
        if (pos != string::npos){
            str = line.substr(pos,3);
            outFile << str << ' ';
            line.erase(pos,3);
        }
        
        //Finds reserved word "cout<<" and prints it to file
        size_t pos2 = line.find("cout<<");
        if (pos2 != string::npos){
            str = line.substr(pos2,6);
            outFile << str << ' ';
            line.erase(pos2,6);
        }
        
        //Remove all unnecessary white spaces before string processing
        removeSpaces(line);
        
        //Process the string character by character
        istringstream iss(line);
        for (int i=0; i < line.size(); i++) {
            iss >> c;
            if(c == '/')
                break;
            else if(c == ';')
                outFile << ' ' << c << '\n';
            else if(c == '=')
                outFile << ' ' << c << ' ';
            else if(c == ',')
                outFile << ' ' << c << ' ';
            else if(c == '+'|| c == '-' || c == '*')
                outFile << ' ' << c << ' ';
            else
                outFile << c;
        }
    }
    myfile.close();
    
    outFile << '\n';
    outFile.close();
    return 0;
}

//Function removes beginning and trailing white spaces
string removeSpaces(string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}