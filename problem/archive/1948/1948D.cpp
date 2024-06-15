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
    string s;
    cin >> s;

    int n = ssz(s);
    for (int d = n / 2; d > 0; d--) {
        int cnt = 0;
        for (int i = 0; i < d; i++) {
            if (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?') {
                cnt++;
            }
        }
        if (cnt == d) {
            cout << 2 * d << endl;
            return;
        }
        for (int i = d; i < n - d; i++) {
            if (s[i - d] == s[i] || s[i - d] == '?' || s[i] == '?') {
                cnt--;
            }
            if (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?') {
                cnt++;
            }
            if (cnt == d) {
                cout << 2 * d << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}