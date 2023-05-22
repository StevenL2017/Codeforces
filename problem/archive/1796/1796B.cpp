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
    string a, b;
    cin >> a >> b;

    if (a.front() == b.front()) {
        cout << "YES\n";
        cout << a.front() << '*' << endl;
    }
    else if (a.back() == b.back()) {
        cout << "YES\n";
        cout << '*' << a.back() << endl;
    }
    else {
        for (int i = 0; i < ssz(a) - 1; i++) {
            for (int j = 0; j < ssz(b) - 1; j++) {
                if (b[j] == a[i] && b[j + 1] == a[i + 1]) {
                    cout << "YES\n";
                    cout << '*' << a[i] << a[i + 1] << '*' << endl;
                    return;
                }
            }
        }
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}