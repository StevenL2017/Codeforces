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
    int n, m, k;
    cin >> n >> m >> k;

    if (k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO" << endl;
        return;
    }

    vector<pair<int, string>> a;
    string s3 = "UDL";
    for (int i = 0; i < n; i++) {
        if (m > 1) {
            a.emplace_back(m - 1, "R");
            if (i == 0) {
                a.emplace_back(m - 1, "L");
            } else {
                a.emplace_back(m - 1, s3);
            }
        }
        if (i < n - 1) {
            a.emplace_back(1, "D");
        } else {
            if (n > 1) {
                a.emplace_back(n - 1, "U");
            }
        }
    }

    vector<pair<int, string>> ans;
    int tot = 0;
    for (auto [c, s]: a) {
        if (tot + c * ssz(s) <= k) {
            ans.emplace_back(c, s);
            tot += c * ssz(s);
            continue;
        }
        int d = k - tot;
        if (d <= 0) {
            break;
        }
        if (ssz(s) == 1) {
            ans.emplace_back(d, s);
        } else if (ssz(s) == 3) {
            if (d / 3) {
                ans.emplace_back(d / 3, s);
            }
            if (d % 3) {
                ans.emplace_back(1, s3.substr(0, d % 3));
            }
        }
        break;
    }

    cout << "YES" << endl;
    cout << ssz(ans) << endl;
    for (auto [c, s]: ans) {
        cout << c << " " << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}