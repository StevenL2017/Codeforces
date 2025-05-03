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

const int N = 1 << 20;
const int K = 20;

class Trie {
public:
    vector<Trie*> children;

    Trie() : children(2) {}

    void insert(int val) {
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
    }

    int query(int val) {
        int ans = 0;
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            if (node->children[bit] != nullptr) {
                node = node->children[bit];
            } else {
                ans |= 1 << i;
                node = node->children[bit ^ 1];
            }
        }
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi vis(N);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vis[x] = 1;
    }

    Trie* tree = new Trie();
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            tree->insert(i);
        }
    }

    int cur = 0;
    while (m--) {
        int x;
        cin >> x;
        cur ^= x;
        cout << tree->query(cur) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}