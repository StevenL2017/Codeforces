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
    vector<string> a(n);
    in(a);

    vector<vi> e(n);
    vi deg(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == '1') {
                e[i].push_back(j);
                deg[j]++;
            } else {
                e[j].push_back(i);
                deg[i]++;
            }
        }
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            s.insert(i);
        }
    }

    vi ans;
    while (!s.empty()) {
        set<int> ns;
        while (!s.empty()) {
            int u = *s.rbegin();
            ans.push_back(u + 1);
            s.erase(u);
            for (auto v: e[u]) {
                deg[v]--;
                if (deg[v] == 0) {
                    ns.insert(v);
                }
            }
        }
        s = ns;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}