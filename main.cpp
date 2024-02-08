#include <iostream>
#include <vector>

bool valid(std::string const &s) {
    std::vector<char> temp;

    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') {
            temp.push_back(c);
        } else if (c == ')' && !temp.empty() && temp.back() == '(') {
            temp.pop_back();
        } else if (c == ']' && !temp.empty() && temp.back() == '[') {
            temp.pop_back();
        } else if (c == '}' && !temp.empty() && temp.back() == '{') {
            temp.pop_back();
        } else {
            return false;
        }
    }
    return temp.empty();
}

int main() {
    std::string test1 = "()[]{}";
    std::string test2 = "([{}])";
    std::string test3 = "({)}";

    std::cout << valid(test1) << std::endl;
    std::cout << valid(test2) << std::endl;
    std::cout << valid(test3) << std::endl;

    //expected: 1, 1, 0 (true, true, false)
}