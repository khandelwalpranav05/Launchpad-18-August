//Given an unbalanced bracket sequence of ‘(‘ and ‘)’, convert it into a balanced sequence by adding the minimum number of ‘(‘ at the beginning of the string and ‘)’ at the end of the string.

#include <bits/stdc++.h> 
using namespace std; 
  

string balancedBrackets(string str) 
{ 
    int depth = 0; 
  
    int minDep = 0; 
  
    for (int i = 0; i < str.length(); i++) { 
        if (str[i] == '(') 
            depth++; 
        else
            depth--; 
  
        if (minDep > depth) 
            minDep = depth; 
    } 
  
    if (minDep < 0) { 
        for (int i = 0; i < abs(minDep); i++) 
            str = '(' + str; 
    } 
  
    depth = 0; 
  
    for (int i = 0; i < str.length(); i++) { 
        if (str[i] == '(') 
            depth++; 
        else
            depth--; 
    } 
  
    if (depth != 0) { 
        for (int i = 0; i < depth; i++) 
            str = str + ')'; 
    } 
    return str; 
} 
  

int main() 
{ 
    string str = "())))()("; 
    cout << balancedBrackets(str); 
} 