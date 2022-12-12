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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int m; cin >> m;
    string c1, c2; cin >> c1 >> c2;

    bool ok = true;
    int i = 0, pre = -1;
    while (i < m) {
        if (c1[i] == c2[i]) i++;
        else {
            if (c1[i] == 'B') {
                pre = 0;
            } else {
                pre = 1;
            }
            i++;
            break;
        }
    }
    int cnt = 0;
    while (i < m) {
        if (c1[i] == c2[i]) {
            cnt++;
        } else {
            if (c1[i] == 'B') {
                if (pre == 0 && (cnt & 1)) {
                    ok = false;
                    break;
                }
                if (pre == 1 && !(cnt & 1)) {
                    ok = false;
                    break;
                }
                pre = 0;
            } else {
                if (pre == 1 && (cnt & 1)) {
                    ok = false;
                    break;
                }
                if (pre == 0 && !(cnt & 1)) {
                    ok = false;
                    break;
                }
                pre = 1;
            }
            cnt = 0;
        }
        i++;
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}