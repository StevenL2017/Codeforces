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
    int n, w; cin >> n >> w;
    vi a(n); in(a);

    map<int, int> cnt;
    for (auto x : a) {
        cnt[x]++;
    }

    int ans = 0;
    while (true) {
        bool ok = true;
        int cur = w;
        for (int i = 20; i >= 0; i--) {
            int c = min(cnt[1 << i], cur / (1 << i));
            cnt[1 << i] -= c;
            cur -= c * (1 << i);
            if (c) ok = false;
        }
        if (ok) break;
        ans++;
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