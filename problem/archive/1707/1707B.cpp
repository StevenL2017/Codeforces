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
    int n; cin >> n;
    vi a(n); in(a);

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    while (n - (cnt.count(0) ? cnt[0] : 0) > 1) {
        map<int, int> ncnt;
        int pre = -1;
        n--;
        for (auto [k, v]: cnt) {
            if (v > 1) ncnt[0] += v - 1;
            if (pre != -1) {
                ncnt[k - pre]++;
            }
            pre = k;
        }
        cnt = ncnt;
    }
    cnt.erase(0);

    cout << (cnt.empty() ? 0 : cnt.begin()->first) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}