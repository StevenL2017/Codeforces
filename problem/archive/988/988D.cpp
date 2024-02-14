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
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    int two = 0, a1, a2;
    for (auto x: s) {
        for (int i = 0; i < 31; i++) {
            int cur = 1 << i;
            if (s.count(x - cur) && s.count(x - 2 * cur)) {
                cout << 3 << endl;
                cout << x << " " << x - cur << " " << x - 2 * cur << endl;
                return;
            } else if (s.count(x - cur)) {
                two = 1;
                a1 = x;
                a2 = x - cur;
            }
        }
    }

    if (two) {
        cout << 2 << endl;
        cout << a1 << " " << a2 << endl;
        return;
    }

    cout << 1 << endl;
    cout << *s.begin() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}