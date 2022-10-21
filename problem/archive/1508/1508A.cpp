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
    int n; cin >> n;
    vector<pair<int, string>> s(3);
    rep(i, 3) {
        cin >> s[i].second;
        int cnt = 0;
        rep(j, 2 * n) {
            if (s[i].second[j] == '0') {
                cnt++;
            }
        }
        s[i].first = cnt;
    }

    sortA(s);
    string ans, base;
    string add = s[1].second;
    int k = 0;
    if (s[1].first <= n) {
        base = s[0].second;
        rep(j, 2 * n) {
            if (base[j] == '1') {
                while (k < 2 * n && add[k] == '0') {
                    ans += add[k];
                    k++;
                }
                k++;
            }
            ans += base[j];
        }

    } else {
        base = s[2].second;
        rep(j, 2 * n) {
            if (base[j] == '0') {
                while (k < 2 * n && add[k] == '1') {
                    ans += add[k];
                    k++;
                }
                k++;
            }
            ans += base[j];
        }
    }
    while (k < 2 * n) {
        ans += add[k];
        k++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}