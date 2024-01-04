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
    string s;
    cin >> s;

    vector<ll> ans(2);
    vi cnta(2), cntb(2);
    for (int i = 0; i < ssz(s); i++) {
        ans[1]++;
        if (s[i] == 'a') {
            ans[0] += cnta[(i & 1) ^ 1];
            ans[1] += cnta[(i & 1)];
            cnta[i & 1]++;
        } else {
            ans[0] += cntb[(i & 1) ^ 1];
            ans[1] += cntb[(i & 1)];
            cntb[i & 1]++;
        }
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}