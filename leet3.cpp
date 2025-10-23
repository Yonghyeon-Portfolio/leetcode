// Given a string s, find the length of the longest 
// substring without duplicate characters.
#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstr(string& s){
    if (s.size() == 0)
        return 0;
    
    int maxlen = 1;
    int currlen = 1;
    unordered_map<char, int> char_map;
    char_map[s[0]] = 0;

    for (int i = 1; i < s.size(); i++){
        char c = s[i];
        if (char_map.count(c) && (i - char_map[c]) <= currlen)
            currlen = i - char_map[c];
        else
            currlen += 1;
        maxlen = currlen > maxlen ? currlen : maxlen;
        char_map[c] = i;
    }
    return maxlen;
}

int main(){
    string s = "mom";
    int result = lengthOfLongestSubstr(s);
    cout << result << endl;
    return 0;
}