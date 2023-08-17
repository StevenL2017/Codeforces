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
    string s; cin >> s;

    if (s == "()") {
        cout << "NO\n";
        return;
    }

    int n = ssz(s);
    bool eq = false;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            eq = true;
            break;
        }
    }

    cout << "YES\n";
    if (eq) {
        for (int i = 0; i < n; i++) {
            cout << "()";
        }
    } else {
        for (int i = 0; i < n; i++) {
            cout << "(";
        }
        for (int i = 0; i < n; i++) {
            cout << ")";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}