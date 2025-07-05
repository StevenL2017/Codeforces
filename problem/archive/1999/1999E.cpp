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

const int N = 2e5 + 1;
ll pre[N + 1];

void calc() {
    for (int i = 1; i < N; i++) {
        int x = i, cnt = 0;
        while (x) {
            x /= 3;
            cnt++;
        }
        pre[i] = pre[i - 1] + cnt;
    }
}

void solve() {
    int l, r;
    cin >> l >> r;

    ll ans = 0, x = l;
    while (x) {
        ans += 2;
        x /= 3;
    }
    l++;
    cout << ans + pre[r] - pre[l - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}