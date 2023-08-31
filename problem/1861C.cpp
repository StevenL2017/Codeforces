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
    int cnt = 0, must_one = 0, before_zero = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            cnt++;
        }
        else if (s[i] == '-') {
            cnt--;
            if (cnt == before_zero) {
                before_zero = 0;
            }
            must_one = min(must_one, cnt);
        }
        else if (s[i] == '0') {
            if (cnt < 2 || must_one == cnt) {
                cout << "NO\n";
                return;
            }
            if (!before_zero) before_zero = cnt - 1;
        }
        else {
            if (before_zero) {
                cout << "NO\n";
                return;
            }
            must_one = cnt;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}