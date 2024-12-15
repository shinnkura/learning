#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> vec = {
        "ABCDE", "BCDE", "ACDE", "ABDE", "ABCE", "ABCD",
        "CDE", "BDE", "ADE", "BCE", "ACE", "BCD", 
        "ABE", "ACD", "ABD", "ABC", 
        "DE", "CE", "BE", "CD", "AE", "BD", "AD", "BC", "AC", "AB", 
        "E", "D", "C", "B", "A"
    };

    /*for (const string& str : vec) {*/
    /*    cout << str << endl;*/
    /*}*/

    int A = 1;
    int B = 2;
    int C = 3;
    int D = 4;
    int E = 5;

    vector<int> ans;
    for (string str :vec) {
        int sum = 0;
        for (char c : str) {
            if (c == 'A') sum += A;
            if (c == 'B') sum += B;
            if (c == 'C') sum += C;
            if (c == 'D') sum += D;
            if (c == 'E') sum += E;
        }
        ans.push_back(sum);
    }


    /*for (string& str : vec) {*/
    /*    cout << str << endl;*/
    /*}*/
    /*for (int i : ans) {*/
    /*    cout << i << endl;*/
    /*}*/
}
