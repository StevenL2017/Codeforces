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
    int r, g, b;
    cin >> r >> g >> b;
    vi rr(r), gg(g), bb(b);
    rep(i, r) cin >> rr[i];
    rep(i, g) cin >> gg[i];
    rep(i, b) cin >> bb[i];

    sortD(rr);
    sortD(gg);
    sortD(bb);

    int i = 0, j = 0, k = 0, ans = 0;
    while (i < r || j < g || k < b) {
        if (i < r && j < g && k < b) {
            int mn = min(rr[i], min(gg[j], bb[k]));
            if (rr[i] == mn) {
                ans += gg[j] * bb[k];
                j++; k++;
            }
            else if (gg[j] == mn) {
                ans += rr[i] * bb[k];
                i++; k++;
            }
            else if (bb[k] == mn) {
                ans += rr[i] * gg[j];
                i++; j++;
            }
        }
        else if (i < r && j < g) {
            ans += rr[i] * gg[j];
            i++; j++;
        }
        else if (i < r && k < b) {
            ans += rr[i] * bb[k];
            i++; k++;
        }
        else if (j < g && k < b) {
            ans += gg[j] * bb[k];
            j++; k++;
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}