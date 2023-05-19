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

int n, k, v;
void solve(){

    double ans = 0;
    vector<pair<double,ii>> x(n); // diff, vida, aumento de dano

    for (int i = 0; i < n; i++)
        cin >> x[i].s.f >> x[i].s.s;

    for (int i = 0 ; i < n; i++)
        x[i].f = (double)x[i].s.f/v - (double)x[i].s.f/(v + x[i].s.s);

    sort(x.begin(), x.end(), greater<pair<double, ii>>());
    
    for (int i = 0; i < n; i++)
    {
        if (k > 0)
            ans += (double)x[i].s.f/(v + x[i].s.s);
        else
            ans += (double)x[i].s.f/v;
        k--;
    }
    cout << ans << endl;
}

int main(){ _
    
    while(cin >> n >> k >> v)
        solve();
}
