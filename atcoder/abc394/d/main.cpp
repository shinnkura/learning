#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '[' || c == '<') {
            st.push(c);
        } else {
            if(st.empty()){
                cout << "No" << "\n";
                return 0;
            }
            char top = st.top();


            if((c == ')' && top != '(') ||
               (c == ']' && top != '[') ||
               (c == '>' && top != '<')) {
                cout << "No" << "\n";
                return 0;
            }
        }
    }

    cout << (st.empty() ? "Yes" : "No") << "\n";
    return 0;
}
