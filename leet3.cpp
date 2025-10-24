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
    unordered_map<char, int> last_seen;
    last_seen[s[0]] = 0;

    for (int i = 1; i < s.size(); i++){
        char c = s[i];
        if (last_seen.count(c) && (i - last_seen[c]) <= currlen)
            currlen = i - last_seen[c];
        else
            currlen += 1;
       
        maxlen = currlen >= maxlen ? currlen : maxlen;
        last_seen[c] = i;
    }
    return maxlen;
}

int main(){
    string s = "omlmabcdo";
    int result = lengthOfLongestSubstr(s);
    cout << result << endl;
    return 0;
}