#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // For std::reverse

using namespace std;

// Template class to handle the removal of k digits
class KDigitsRemover {
public:
    // Constructor to initialize the number and the count of digits to remove
    KDigitsRemover(const std::string& number, int removeCount)
        : num(number), k(removeCount) {}

    std::string removeKdigits() {
        stack<char> s;
        
        for (char digit : num) {
            while (!s.empty() && k > 0 && s.top() > digit) {
                s.pop();
                k--;
            }
            if (!s.empty() || digit != '0') {
                s.push(digit);
            }
        }
        
        while (!s.empty() && k > 0) {
            s.pop();
            k--;
        }
        
        string result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result.empty() ? "0" : result;
    }

private:
    std::string num; // Number as a string
    int k;           // Number of digits to remove
};

int main() {
    std::string num;
    int k;

    // Input handling
    std::cin >> num;
    std::cin >> k;

    // Create an instance of KDigitsRemover
    KDigitsRemover remover(num, k);

    // Call the method to get the smallest number
    std::string smallestNumber = remover.removeKdigits();

    // Output the result
    std::cout << smallestNumber << std::endl;

    return 0;
}