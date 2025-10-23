#include <iostream>
#include <string>
#include <unordered_map>

void countCharCount(const std::string& s){
    std::unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;
    for (const auto& [ch, count] : freq)
        std::cout << ch << " -> " << count << std::endl;
}

int main(){
    countCharCount("hello, world");
    return 0;
}