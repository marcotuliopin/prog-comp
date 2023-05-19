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

void solve(){

}

int main(){ _
    
    int n, p; 
    while (cin >> n >> p)
    {
        vector<vector<int>> mana(n, vector<int>(p + 1, INF));
        vector<ii> f(n);
        for (int i = 0; i < n; i++)
            cin >> f[i].f >> f[i].s;
        
        for (int i = 0; i < p; i++)
        {
            if (i - f[0].f <= 0)
                mana[0][i] = f[0].s;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = p; j >= 0; j--)
            {
                if (j - f[i].f <= 0)
                    mana[i][j] = f[i].s;

                else if (j - f[i].f >= 0 && mana[i - 1][j - f[i].f] != INF)
                    mana[i][j] = f[i].s + mana[i - 1][j - f[i].f];

                mana[i][j]  = min(mana[i][j], mana[i - 1][j]);
            }
        }
        if (mana[n - 1][p] != INF)
            cout << mana[n - 1][p] << endl;
        else
            cout << "-1" << endl;
    }
}
