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
    vector<ll> a(n);
    in(a);

    vector<pair<ll, int>> s;
    for (auto x: a) {
        ll tot = x;
        int cnt = 1;
        while (!s.empty() && s.back().first >= tot / cnt) {
            tot += s.back().first * s.back().second;
            cnt += s.back().second;
            s.pop_back();
        }
        s.emplace_back(tot / cnt, cnt - tot % cnt);
        if (tot % cnt) {
            s.emplace_back(tot / cnt + 1, tot % cnt);
        }
    }

    cout << s.back().first - s.front().first << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}