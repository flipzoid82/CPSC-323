//
// prog3.cpp
//  Project1
//
//  Created by Joesh Bautista on 6/6/19.
//  Copyright © 2019 Joesh Bautista. All rights reserved.
//
#include <iostream>
#include <string>
#include <sstream>
#include <locale>

using namespace std;

bool isReservedWord(string token);
bool isSpecial(string token);
bool isNumber(string token);
bool isIdentifier(string token);

int main(){
    /*
     Write a program to read from the user a single line (up to 255 characters) statement at a time and determine whether each token is a number, identifier, a reserved word, or special character. A number is an unsigned integer or a signed integer. An identifier starts with a letter or _ followed by any number of letters, _, and digits. Suppose the following arrays are already given:
     
     char reservedWords[4][10]={ “cout<<”, “for”, “int”, “while”};
     char special[10][3]={“<”, “=” , “*” , “-“ , “;” , “(“ , “)” , “<=” ,”+”, “,”};
     First check whether the token is a reserved word, if not is it special symbol, if not is it a number or an identifier. The program must be case insensitive. Save it Prog3.
     
     For ( int i = 10 ; i <=  100 ; i = i + 1 ) cout<< 2i ;
     */
    
    string str, tok, delimiter = " ";
    cout << "Enter a statement: ";
    getline(cin, str);

    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != string::npos) {
        token = str.substr(0, pos);
        if (token[0]==' ') {
            str.erase(0, pos + delimiter.length());
        } else if (isReservedWord(token)) {
            //formatting purposes only
            if (token == "cout<<")
                cout << token << "\treserved word\n";
            //formatting purposes only
            else if (token == "while")
                cout << token << " \treserved word\n";
            else
                cout << token << "\t\treserved word\n";
        } else if (isSpecial(token)){
            cout << token << "\t\tspecial symbol\n";
        } else if (isNumber(token)){
            cout << token << "\t\tnumber\n";
        } else if (isIdentifier(token)){
            cout << token << "\t\tidentifier\n";
        }
        else {
            cout << token << "\t\tnot identifier\n";
        }
        
        str.erase(0, pos + delimiter.length());
        
    }
    std::cout << str << std::endl;
    
    return 0;
}

bool isReservedWord(string token){
    locale loc;
    string tok;
    for (size_t i=0; i<token.length(); i++)
        tok += tolower(token[i],loc);
    char reservedWords[4][10]={ "cout<<", "for", "int", "while"};
    for (int i = 0; i < 4; i++) {
        string word;
        for (int j = 0; j < 10; j++) {
            if (reservedWords[i][j] != '\0') {
                word += reservedWords[i][j];
            }
        }
        if (tok == word) {
            return true;
        }
    }
    return false;
}

bool isSpecial(string token){
    locale loc;
    string tok;
    for (size_t i=0; i<token.length(); i++)
        tok += tolower(token[i],loc);
    char special[10][3]={"<", "=" , "*" , "-" , ";" , "(" , ")" , "<=" ,"+", ","};
    for (int i = 0; i < 10; i++) {
        string word;
        for (int j = 0; j < 3; j++) {
            if (special[i][j] != '\0') {
                word += special[i][j];
            }
        }
        if (tok == word) {
            return true;
        }
    }
    return false;
}

bool isNumber(string token){
    for (int i = 0; i < token.length(); i++) {
        if (token[0] == ' ')
            return false;
        else if(token[0] == '-' || isdigit(token[i])){
            //do nothing - move on to the next character
        } else
            return false;
    }
    return true;
}

bool isIdentifier(string token){
    for (int i = 0; i < token.length(); i++) {
        if(token[0] == '_' || isalpha(token[0])){
            //do nothing - move on to the next character
        }else
            return false;
    }
    return true;
}
