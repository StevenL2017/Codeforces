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
    string s, t;
    cin >> n >> s >> t;

    string ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            for (int k = 0; k < 3; k++) {
                if (i == k || j == k) continue;
                string u, cur;
                u += (char)(i + 'a');
                u += (char)(j + 'a');
                u += (char)(k + 'a');
                bool ok = true;
                for (int i = 1; i < ssz(u); i++) {
                    string temp = u.substr(i - 1, 2);
                    if (temp == s || temp == t) {
                        ok = false;
                        break;
                    }
                }
                if (ok && (n == 1 || s[0] != s[1] && t[0] != t[1])) {
                    for (int i = 0; i < n; i++) {
                        ans += u[0];
                    }
                    for (int i = 0; i < n; i++) {
                        ans += u[1];
                    }
                    for (int i = 0; i < n; i++) {
                        ans += u[2];
                    }
                    cout << "YES" << endl;
                    cout << ans << endl;
                    return;
                }
                string v = u;
                v += u;
                ok = true;
                for (int i = 1; i < ssz(v); i++) {
                    string temp = v.substr(i - 1, 2);
                    if (temp == s || temp == t) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    for (int i = 0; i < n; i++) {
                        ans += u;
                    }
                    cout << "YES" << endl;
                    cout << ans << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}