#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct node {
    char value;
    node* left;
    node* right;
} node;

node* root;
string pre, in;

char side (char c, node* aux){

    bool left = true;
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == c)
            return 'l';
        else if (in[i] == aux->value)
            return 'r';
    }
    return 'l';
}

void insert(char c){

    node* aux = root;

    while (true)
    {
        char s = side(c, aux);
        if (s == 'l')
        {
            if (aux->left == nullptr)
            {
                aux->left = new node{c, nullptr, nullptr};
                return;
            }
            else
                aux = aux->left;
        }
        else
        {
            if (aux->right == nullptr)
            {
                aux->right = new node{c, nullptr, nullptr};
                return;
            }
            else
                aux = aux->right;
        }
    }
}

void cpost(node* aux) {

    if (aux == nullptr)
        return;
    cpost(aux->left);
    cpost(aux->right);
    cout << aux->value;
}

void free(node* aux){

    if (aux == nullptr)
        return;
    free(aux->left);
    free(aux->right);
    delete aux;
}

void solve(){
    
    int x; cin >> x;
    cin >> pre >> in;
    root = new node{pre[0], nullptr, nullptr};    

    for (int i = 1; i < pre.size(); i++)
        insert(pre[i]);

    cpost(root); 
    cout << endl;
    free(root);
}

int main(){ _
    
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
}
