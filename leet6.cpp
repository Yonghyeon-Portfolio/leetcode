#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 0)
            return "";
        if (numRows == 1)
            return s;
        
        string rows[numRows];
        int i = 0;
        bool to_right = true;
        for (char c: s){
            rows[i] += c;
            to_right = i == 0 ? true : i == numRows - 1 ? false : to_right;
            to_right ? i++ : i--;
        }
        string result = "";
        for (string r : rows)
            result += r;
        return result;
    }
};

int main(){
    Solution s = Solution();
    string str_input = "PAYPALISHIRING";

    if (s.convert(str_input, 3) == "PAHNAPLSIIGYIR")
        cout << "testcase 1 passed\n";
    else
        cout << "testcase 1 failed\n";

    if (s.convert(str_input, 4) == "PINALSIGYAHRPI")
        cout << "testcase 2 passed\n";
    else
        cout << "testcase 2 failed\n";
}