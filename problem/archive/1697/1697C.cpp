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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int cur = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' && t[i] == 'c' || s[i] == 'c' && t[i] == 'a') {
            cout << "NO" << endl;
            return;
        }
        if (s[i] == 'a' || t[i] == 'a') {
            if (cur == 1) {
                if (cnt != 0) {
                    cout << "NO" << endl;
                    return;
                } else {
                    cnt = 0;
                }
            }
            cur = 0;
        }
        else if (s[i] == 'c' || t[i] == 'c') {
            if (cur == 0) {
                if (cnt != 0) {
                    cout << "NO" << endl;
                    return;
                } else {
                    cnt = 0;
                }
            }
            cur = 1;
        }
        if (s[i] == t[i]) {
            continue;
        }
        if (cur == 0) {
            cnt += (s[i] == 'a' ? 1 : -1);
        }
        else {
            cnt += (t[i] == 'c' ? 1 : -1);
        }
        if (cnt < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << (cnt == 0 ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}