#include <iostream>
#include <fstream>
#include <string> 
#include <vector>


using namespace std;

int main(void) {
    ifstream file("input.txt");
    string line;
    int sum = 0;

    vector<int> calibration;
    vector<string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while (getline(file, line)) {
        vector<int> digits;
        for(int i=0; i<line.length(); i++) {
            const auto c = line[i];
            if(c>='0' && c<='9') {
                digits.push_back(c-'0');
            }
            for (int j = 0; j < numbers.size(); j++) {
            const auto& n = numbers[j];
            if (line.size() >= i + n.size()) {
                if (line.substr(i, n.size()) == n) {
                    digits.push_back(j+1);
                }
            }
        }
        }
        calibration.push_back(digits[0] * 10 + digits.back());
    }
    for (int i: calibration)
        sum += i;
    cout << sum << endl;
    file.close();
}