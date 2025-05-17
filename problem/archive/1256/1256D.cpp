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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string ans;
    int cnt = 0;
    for (auto c: s) {
        if (c == '0') {
            if (cnt <= k) {
                ans += '0';
                k -= cnt;
            } else {
                ans += string(cnt - k, '1');
                ans += '0';
                ans += string(k, '1');
                cnt = 0;
                k = 0;
            }
        } else {
            cnt++;
        }
    }
    ans += string(cnt, '1');
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}