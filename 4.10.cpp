#include<iostream>
#include<algorithm>

using namespace std;

string myreverse(string &input) {
    int l = 0, r = (int) input.length() - 1;
    while (l < r) {
        swap(input[l++], input[r--]);
    }
    return input;
}

int main() {
    string input;
    printf("Please enter a string:\n");
    getline(cin, input);
    cout << "Original String:" << ' ' << input << endl;
    cout << "Reversed String:" << ' ' << myreverse(input) << endl;
    return 0;
}