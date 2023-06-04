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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [&] (const pair<int, int> x, const pair<int, int> y) { return x.first < y.first || x.first == y.first && x.second > y.second; });

    ll ans = 0;
    int cnt = 0;
    map<int, int> c;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && a[j].first == a[i].first) {
            if (cnt < a[i].first) {
                ans += a[j].second;
                cnt++;
                c[a[i].first]++;
                int x = cnt;
                cnt -= c[cnt];
                c[x] = 0;
                if (x == a[i].first) {
                    break;
                }
            }
            j++;
        }
        while (j < n && a[j].first == a[i].first) {
            j++;
        }
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