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

vector<pair<int, int>> knapsacks(101); // {weight, value}
vector<vector<pair<int, pair<int, int>>>> decision_matrix(101); // {weight, value, n}
int n;

void imprime(int brinquedos, int peso, int mochilas){

    cout << brinquedos << " brinquedos" << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "sobra(m) " << n - mochilas << " pacote(s)" << endl;
    cout << endl;
}

void add1(int i, int pi){

    decision_matrix[i][pi].f = decision_matrix[i - 1][pi].f; // weight
    decision_matrix[i][pi].s.f = decision_matrix[i - 1][pi].s.f; // value
    decision_matrix[i][pi].s.s = decision_matrix[i - 1][pi].s.s; // number of knapsacks
}

void add2(int i, int pi){

    decision_matrix[i][pi].f = decision_matrix[i - 1][pi - knapsacks[i].first].f + knapsacks[i].f;
    decision_matrix[i][pi].s.f = decision_matrix[i - 1][pi - knapsacks[i].f].s.f + knapsacks[i].s;
    decision_matrix[i][pi].s.s = decision_matrix[i - 1][pi - knapsacks[i].f].s.s + 1;
}

void knapsack(){

    int p = 50;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> knapsacks[i].second >> knapsacks[i].first; 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= p; j++)
            decision_matrix[i].pb({0, {0, 0}});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int pi = p; pi >= 0; pi--)
        {
            if (knapsacks[i].first > pi)
            {
                add1(i, pi);
                continue;
            }
            int choice1 = decision_matrix[i - 1][pi].s.f;
            int choice2 = knapsacks[i].second + decision_matrix[i - 1][pi - knapsacks[i].first].s.f;
            if (choice1 >= choice2)
                add1(i, pi);
            else
                add2(i, pi);
        }
    }
    imprime(decision_matrix[n][p].s.f, decision_matrix[n][p].f, decision_matrix[n][p].s.s);
}

int main(){ _

    int x; cin >> x;
    while (x--)
        knapsack();
}
