#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    string digit;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7') {
            digit.push_back(s[i]);
        }
        else if (s[i] == '4') {
            digit.push_back('3');
            digit.push_back('2');
            digit.push_back('2');
        }
        else if (s[i] == '6') {
            digit.push_back('3');
            digit.push_back('5');
        }
        else if (s[i] == '8') {
            digit.push_back('2');
            digit.push_back('2');
            digit.push_back('2');
            digit.push_back('7');
        }
        else if (s[i] == '9') {
            digit.push_back('3');
            digit.push_back('3');
            digit.push_back('2');
            digit.push_back('7');
        }
    }

    sort(digit.begin(), digit.end());
    reverse(digit.begin(), digit.end());

    cout << digit << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}