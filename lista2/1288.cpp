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

vector<ii> balas(51); // poder, peso
vector<vector<int>> m(51, vector<int>(101, 0));

void solve(){

    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> balas[i].f >> balas[i].s;
    
    int k; cin >> k;
    int r; cin >> r;

    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 0; j--)
        {
            if (balas[i].s > j)
                m[i][j] = m[i - 1][j];
            else
                m[i][j] = max(m[i - 1][j], balas[i].f + m[i - 1][j - balas[i].s]);
        }
    }
    if (m[n - 1][k] >= r)
        cout << "Missao completada com sucesso" << endl;
    else
        cout << "Falha na missao" << endl;
}

int main(){ _
    
    int d; cin >> d;
    while (d--)
        solve();
}
