#include <bits/stdc++.h>
using namespace std;

void  calculateLetters(string s){
    int vowels = 0, consonants = 0;
    vector<char> v;
    vector<char> c;
    for(int i=0; i<s.size(); ++i){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
           s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I'  || s[i]== 'O' || s[i] == 'U'){
            vowels++;
            v.push_back(s[i]);
        }else{
            consonants++;
            c.push_back(s[i]);
        }
    }
}