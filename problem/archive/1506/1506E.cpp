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

    vi mn, mx;
    set<int> s1, s2;
    int pre = 0;
    for (int i = 0; i < n; i++) {
        if (pre != a[i]) {
            mn.push_back(a[i]);
            mx.push_back(a[i]);
            while (pre + 1 < a[i]) {
                pre++;
                s1.insert(pre);
                s2.insert(pre);
            }
            pre = a[i];
        } else {
            mn.push_back(*s1.begin());
            mx.push_back(*s2.rbegin());
            s1.erase(*s1.begin());
            s2.erase(*s2.rbegin());
        }
    }

    out(mn);
    out(mx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}