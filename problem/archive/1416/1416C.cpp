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

const int K = 30;

class Trie {
public:
    vector<Trie*> children;
    vector<int> idx;

    Trie() : children(2), idx() {}

    void insert(int val, int j) {
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
            node->idx.push_back(j);
        }
    }
};

ll f[2][K + 1];

void dfs(Trie* node, int k) {
    Trie *left = node->children[0], *right = node->children[1];
    if (left != nullptr) dfs(left, k - 1);
    if (right != nullptr) dfs(right, k - 1);
    if (left == nullptr || right == nullptr) return;
    ll cnt = 0;
    int cur = 0;
    for (auto i : left->idx) {
        while (cur < ssz(right->idx) && right->idx[cur] < i) {
            cur++;
        }
        cnt += cur;
    }
    f[0][k] += cnt;
    f[1][k] += ssz(left->idx) * 1ll * ssz(right->idx) - cnt;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    Trie* tree = new Trie();
    for (int i = 0; i < n; i++) {
        tree->insert(a[i], i);
    }
    dfs(tree, K);

    ll inv = 0;
    int x = 0;
    for (int i = K; i >= 0; i--) {
        inv += min(f[0][i], f[1][i]);
        if (f[1][i] < f[0][i]) {
            x |= 1 << i;
        }
    }

    cout << inv << " " << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}