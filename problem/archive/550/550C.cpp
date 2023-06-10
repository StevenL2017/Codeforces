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

    int n = ssz(s);
    for (int i = 0; i < n; i++) {
        int a = s[i] - '0';
        if (a % 8 == 0) {
            cout << "YES\n";
            cout << a << endl;
            return;
        }
        for (int j = i + 1; j < n; j++) {
            int b = a * 10 + s[j] - '0';
            if (b % 8 == 0) {
                cout << "YES\n";
                cout << b << endl;
                return;
            }
            for (int k = j + 1; k < n; k++) {
                int c = b * 10 + s[k] - '0';
                if (c % 8 == 0) {
                    cout << "YES\n";
                    cout << c << endl;
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}