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

// mapeia cada carta para um indice
map<char, int> order = {{'A', 1}, {'2', 2}, {'3', 3},
{'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
{'8', 8}, {'9', 9}, {'D', 10}, {'Q', 11},
{'J', 12}, {'K', 13}, {'X', 14}};

// para cada jogador, armazena um vetor de cartas. cada carta é indicada
// pelo indice da posicao e o valor na posicao é a quantidade de cartas
vector<vector<int>> m(14, vector<int>(15, 0));

// checa se o jogador p esta em estado vencedor
bool check(int p){
 
    // para cada carta verifica se o jogador tem 4 dela
    for (int i = 1; i < 14; i++)
    {
        if (m[p][i] == 4 && m[p][14] == 0)
            return true; 
    }
    return false;
}

// escolhe qual carta o jogador p passara para frente
int play(int p){

    int M = INF, index = -1;
    for (int i = 1; i < 14; i++) 
    {
        if (m[p][i] > 0 && m[p][i] < M) // busca a menor quantidade de cartas iguais
        {
            M = m[p][i];
            index = i;
        }
    }
    return index;
}

int main(){ _

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            char c; cin >> c;
            m[i][order[c]]++;
        }
    }
    m[k][14]++; // coringa comeca com o jogador k

    int M = INF;
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
            M = min(M, i);
    }
    if (M < INF)
    {
        cout << M << endl;
        return 0;
    }


    int p = k; // p: quem esta fazendo a jogada
    bool J = false; // J: eh possivel ou nao passar o coringa para frente
    while (true)
    {
        int next = (p == n)? 1 : p + 1; // next: jogador que vai receber a carta

        int carta = (J && m[p][14] > 0)? 14 : play(p); // joga o coringa se possivel
        m[next][carta]++; 
        m[p][carta]--;

        // caso p e next estejam em estado de vitoria, escolhe o de menor indice
        if (check(p))
            break;

        p = next;
        // caso o jogador nao acabou de passar o coringa, o proximo podera
        // passa-lo adiante se o tiver
        J = (carta == 14)? false : true; 
    }
    cout << p << endl;
    return 0;
}
