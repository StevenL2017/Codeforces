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

vi a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool query(int x) {
    cout << x << endl;
    cout.flush();
    string ans;
    cin >> ans;
    return (ans == "yes" ? true : false);
}

void solve() {
    int cnt = 0;
    for (auto x: a) {
        if (query(x)) {
            cnt++;
            if (x * x <= 100 && query(x * x)) {
                cnt++;
            }
            if (cnt > 1) {
                break;
            }
        }
    }
    cout << (cnt > 1 ? "composite" : "prime") << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}