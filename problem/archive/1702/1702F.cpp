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
    multiset<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x % 2 == 0) {
            x >>= 1;
        }
        a.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    while (!b.empty()) {
        int x = *b.rbegin();
        if (a.find(x) != a.end()) {
            b.erase(b.find(x));
            a.erase(a.find(x));
        } else {
            if (x == 1) {
                cout << "NO" << endl;
                return;
            }
            b.erase(b.find(x));
            b.insert(x >> 1);
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}