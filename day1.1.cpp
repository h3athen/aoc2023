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
    while (getline(file, line)) {
        vector<int> digits;
        for(int i=0; i<line.length(); i++) {
            const auto c = line[i];
            if(c>='0' && c<='9') {
                digits.push_back(c-'0');
            }
        }
        calibration.push_back(digits[0] * 10 + digits.back());
    }
    for (int i: calibration)
        sum += i;
    cout << sum << endl;
    file.close();
}