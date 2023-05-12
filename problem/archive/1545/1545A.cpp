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

    int mx = *max_element(a.begin(), a.end());
    vector<vi> idx(mx + 1);
    for (int i = 0; i < n; i++) {
        idx[a[i]].push_back(i);
    }

    sort(a.begin(), a.end());
    for (int i = 0, j = 0; i < n; ) {
        vi st;
        while (j < n && a[j] == a[i]) {
            auto cur = abs(j - idx[a[i]][j - i]) & 1;
            if (!st.empty() && st.back() == cur) {
                st.pop_back();
            } else {
                st.push_back(cur);
            }
            j++;
        }
        if (ssz(st) > 1 || ssz(st) == 1 && st[0] % 2 == 1) {
            cout << "NO\n";
            return;
        }
        i = j;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}