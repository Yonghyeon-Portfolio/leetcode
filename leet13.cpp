#include <iostream>
using namespace std;

int symbolToInt(char c){
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

int romanToInt(string s){
    int values[s.size()];
    for (int i = 0; i < s.size(); i++)
        values[i] = symbolToInt(s[i]);
    
    int total = 0;
    for (int i = 0; i < s.size() - 1; i++)
        total += values[i] < values[i + 1] ? -values[i] : values[i];
    return total + values[s.size() - 1];
}


int main(){
    string s1 = "I";
    string s2 = "II";
    string s4 = "IV";
    string s9 = "IX";
    string s39 = "XXXIX";
    string s999 = "CMXCIX";
    cout << romanToInt(s1) << endl;
    cout << romanToInt(s2) << endl;
    cout << romanToInt(s4) << endl;
    cout << romanToInt(s9) << endl;
    cout << romanToInt(s39) << endl;
    cout << romanToInt(s999) << endl;
    return 0;
}