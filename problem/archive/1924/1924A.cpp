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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    string ans;
    bool ok = true;
    for (int i = 0, j = 0; i < n; i++) {
        int cnt = 0;
        vi vis(k);
        while (cnt < k && j < m) {
            cnt += !vis[s[j] - 'a'];
            vis[s[j] - 'a'] = 1;
            j++;
        }
        if (cnt < k) {
            ok = false;
            for (int x = 0; x < k; x++) {
                if (!vis[x]) {
                    ans += x + 'a';
                    break;
                }
            }
        } else {
            ans += s[j - 1];
        }
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}