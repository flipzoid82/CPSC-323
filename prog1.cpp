//
//  main.cpp
//  Project1
//
//  Created by Joesh Bautista on 6/6/19.
//  Copyright © 2019 Joesh Bautista. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void checkState(char &S, char str);

int main(){
    bool exit = true;
    char yesOrNo;
    do {
        string str;
        cout << "Please enter a string. Make sure to end it with a '$': ";
        cin >> str;
        int i = 0;
        char state = 'A'; //initial state
        
        while (str[i] != '$') {
            if (str[i] == 'a' || str[i] == 'b') {
                checkState(state, str[i]);
                i++;
            } else {
                cout << "Character is not in the language. Please try again.\n";
                state = 'Z'; //error state
                break;
            }
        }
        if (state == 'D') {
            cout << "YES!\n";
        } else if (state == 'Z')
            ;//do nothing
        else
            cout << "NO!\n";
        
        cout << "Input another string (y/n)?: ";
        cin >> yesOrNo;
        if (tolower(yesOrNo) == 'y') {
            exit = false;
        } else
            exit = true;
    } while(!exit);
    return 0;
}

void checkState(char &S, char str){
    switch (S) {
        //Initial state
        case 'A':
            if(str == 'a')
                S = 'B';
            else
                S = 'C';
            break;
            
        case 'B':
            if(str == 'a')
                S = 'B';
            else
                S = 'C';
            break;
            
        case 'C':
            if(str == 'a')
                S = 'D';
            else
                S = 'E';
            break;
        
        //Accept state
        case 'D':
            if(str == 'a')
                S = 'B';
            else
                S = 'C';
            break;
            
        case 'E':
            if(str == 'a')
                S = 'D';
            else
                S = 'E';
            break;
    }
}
