#include <iostream>
using namespace std;

int getPalinLength(string &s, int lcenter, int rcenter){
    int i = 0;
    while ((lcenter - i) >= 0 && (rcenter + i) < s.size()){
        if (s[lcenter - i] != s[rcenter + i])
            break;
        i++;
    }
    return (i * 2) - (lcenter == rcenter);
}


string longestPalindrome(string s){
    if (s.size() == 0)
        return "";

    int center = 0;
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++){
        int len1 = getPalinLength(s, i, i);
        int len2 = getPalinLength(s, i, i+1);
        if (len1 > maxLen){
            maxLen = len1;
            center = i;
        }
        if (len2 > maxLen){
            maxLen = len2;  
            center = i + 1;
        }
    }
    return s.substr(center - (maxLen) / 2, maxLen);
}

int main(){
    string s = "abcccc12321";
    cout << longestPalindrome(s) << endl;
    return 0;
}