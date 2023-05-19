#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<pair<int, ii>> mx;
vector<ii> parent;

int find(int i){

    if (parent[i].f == i)
        return i;
    return parent[i].f = find(parent[i].f);
}

void unite(int fromp, int top){

    if (parent[fromp].s > parent[top].s) 
        parent[top].f = fromp;
    else
    {
        if (parent[top].s == parent[fromp].s)
            parent[top].s++;
        parent[fromp].f = top;
    } 
}

bool iscycle(ii p){

    int fromp = find(p.f), top = find(p.s);
    if (fromp == top)
        return true;
    unite(fromp, top);
    return false;
}

int kruskal(pair<int, ii> p){

    if (iscycle(p.s))
        return 0;
    return p.f;
}

int main(){ _

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int from, to, w; 
        cin >> from >> to >> w;
        mx.pb({w, {from - 1, to - 1}});
    }
    sort(mx.begin(), mx.end());

    for (int i = 0; i < n; i++)
        parent.pb({i, 0});

    int M = 0;
    for (int i = mx.size() - 1 ; i >= 0; i--)
        M += kruskal(mx[i]);
    cout << M << endl;

    for (int i = 0; i < n; i++)
        parent[i] = ii(i, 0);

    int m = 0;
    for (int i = 0; i < mx.size(); i++)
        m += kruskal(mx[i]);
    cout << m << endl;
}
