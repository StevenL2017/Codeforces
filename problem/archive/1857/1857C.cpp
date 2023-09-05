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
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    vi a;
    for (auto [k, v]: cnt) {
        int cur = 0, m = ssz(a);
        for (int i = n - 1 - m; i > 0; i--) {
            cur += i;
            if (cur == v) {
                for (int j = 0; j < n - 1 - m - i + 1; j++) {
                    a.push_back(k);
                }
                break;
            }
        }
    }
    a.push_back(a.back());
    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}