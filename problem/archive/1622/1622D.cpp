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

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int tot = 0;
    for (auto c: s) {
        tot += c - '0';
    }
    if (tot < k) {
        cout << 1 << endl;
        return;
    }

    vector<vi> comb(n + 1, vi(n + 1));
    for (int i = 0; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1;
        if (i == 0) continue;
        for (int j = 1; j < i; j++) {
            comb[i][j] = add(comb[i - 1][j - 1], comb[i - 1][j]);
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int c1 = int(s[i] == '1');
        for (int j = i + 1; j < n; j++) {
            if (s[j] == '1') c1++;
            if (c1 <= k) {
                int cnt = j - i + 1 - 2, cnt1 = c1;
                if (s[i] == '0') cnt1--;
                if (s[j] == '0') cnt1--;
                if (cnt >= cnt1 && cnt >= 0 && cnt1 >= 0) {
                    ans = add(ans, comb[cnt][cnt1]);
                }
            } else {
                break;
            }
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