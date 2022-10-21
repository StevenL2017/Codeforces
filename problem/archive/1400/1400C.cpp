#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD
#define endl '\n'

#define ll long long
#define vi vector<int>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)

void solve() {
    string s;
    int x;
    cin >> s >> x;

    int n = s.size();
    vector<char> ans(n, '2');
    bool ok = true;
    rep(i, n) {
        if (s[i] == '0') {
            if (i - x >= 0) {
                if (ans[i - x] == '1') {
                    ok = false;
                    break;
                }
                ans[i - x] = '0';
            }
            if (i + x < n) {
                if (ans[i + x] == '1') {
                    ok = false;
                    break;
                }
                ans[i + x] = '0';
            }
        } else {
            if (i - x < 0 && i + x >= n) {
                ok = false;
                break;
            }
            else if (i + x >= n) {
                if (ans[i - x] == '0') {
                    ok = false;
                    break;
                }
                ans[i - x] = '1';
            }
            else if (i - x < 0) {
                if (ans[i + x] == '0') {
                    ok = false;
                    break;
                }
                ans[i + x] = '1';
            }
            else {
                if (ans[i - x] == '0' && ans[i + x] == '0') {
                    ok = false;
                    break;
                }
                else if (ans[i - x] == '1' || ans[i + x] == '1') {
                    continue;
                }
                else if (ans[i - x] == '0') {
                    ans[i + x] = '1';
                }
                else {
                    ans[i - x] = '1';
                }
            }
        }
    }

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    rep(i, n) {
        if (ans[i] == '2') {
            cout << '0';
        } else {
            cout << ans[i];
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