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

int n, m; // dimensoes do tabuleiro
vector<vector<int>> tab(200, vector<int>(200)); // peças no tabuleiro
vector<vector<bool>> vis(200, vector<bool>(200, false));

int mkmove(int y, int x, int score){

    int maior = 0;
    vector<int> j(4, 0);

    tab[y][x] = 0;

    // baixo direita
    if (y > 1 && x < m - 2 && tab[y - 1][x + 1] == 2 && tab[y - 2][x + 2] == 0)
    {
        if (!vis[y - 1][x + 1])
        {
            vis[y - 1][x + 1] = true;
            j[0] = mkmove(y - 2, x + 2, score + 1);
            vis[y - 1][x + 1] = false;
        }
    }

    // baixo esquerda
    if (y > 1 && x > 1 && tab[y - 1][x - 1] == 2 && tab[y - 2][x - 2] == 0)
    {
        if (!vis[y - 1][x - 1])
        {
            vis[y - 1][x - 1] = true;
            j[1] = mkmove(y - 2, x - 2, score + 1);
            vis[y - 1][x - 1] = false;
        }
    }
    
    // topo direita
    if (y < n - 2 && x < m - 2 && tab[y + 1][x + 1] == 2 && tab[y + 2][x + 2] == 0)
    {
        if (!vis[y + 1][x + 1])
        {
            vis[y + 1][x + 1] = true;
            j[2] = mkmove(y + 2, x + 2, score + 1);
            vis[y + 1][x + 1] = false;
        }
    }
    
    // topo esquerda
    if (y < n - 2 && x > 1 && tab[y + 1][x - 1] == 2 && tab[y + 2][x - 2] == 0)
    {
        if (!vis[y + 1][x - 1])
        {
            vis[y + 1][x - 1] = true;
            j[3] = mkmove(y + 2, x - 2, score + 1);
            vis[y + 1][x - 1] = false;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (j[i] > maior)
            maior = j[i];
    }

    return max(maior, score);
}

void solve(){

    int t = (n*m)/2; // tamanho do tabuleiro
    vector<ii> mine;
    vector<int> his;

    // cria o tabuleiro
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        if (i % 2 != 0)
        {
            tab[i][j] = -1;
            j++;
        }
        while(j < m)
        {
            cin >> tab[i][j];
            if (tab[i][j] == 1)
                mine.pb({i, j});
            j++;
            if (j < m)
            {
                tab[i][j] = -1;
                j++;
            }
        }
    }

    int maior = 0;
    for (int i = 0; i < mine.size(); i++)
    {
        maior = max(maior, mkmove(mine[i].f, mine[i].s, 0));
        tab[mine[i].f][mine[i].s] = 1;
    }
    cout << maior << endl; 
}

int main(){ _

    while (cin >> n >> m)
    {
        if (n == 0) break;

        solve();
    }
}
