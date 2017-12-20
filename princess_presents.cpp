#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))

typedef long long ll;
const int INF = 1e9;

const int MOD = 1e9+7;

const int N = 1e5;
const int T = 5;
vector<pii> g[N];

/* just for //asserting if graph is connected */
bool visited[N];
void dfs_connected(int v, int parent) {
    visited[v] = 1;
    for (auto edge : g[v]) {
        int u = edge.fi;
        if (u == parent) continue;
        dfs_connected(u, v);
    }
}

//////////////////// CASE k > 0 //////////////////////////////////////////////////

//cnt_special[v] denotes the number of special edges in v's subtree in a rooted tree
int cnt_special[N];

//cnt_subtree[v] denotes the number of subtrees of v's subtree in a rooted tree containing v (so, like hanging down from v)
ll cnt_subtree[N];

void dfs_special(int v, int p) 
{
    for (auto edge : g[v])   //this should be node instead of edge
    {
        int u = edge.fi;
        if (u == p) continue;
        int special = edge.se;
        if (special) cnt_special[v]++;
        dfs_special(u, v);
        cnt_special[v] += cnt_special[u];
    }
}

void dfs_subtrees(int v, int p) 
{
    cnt_subtree[v] = 1;
    for (auto edge : g[v]) {
        int u = edge.fi;
        if (u == p) continue;
        dfs_subtrees(u, v);
        cnt_subtree[v] *= (1 + cnt_subtree[u]); //do not take any u's subtree or take any u's subtree
        cnt_subtree[v] %= MOD;// the case of subtree is same as the include case because you always have to 
        // include the root from where you are counting the subtree
    }
}

ll res = 1;
void dfs_solve(int v, int p) 
{
    if (cnt_special[v] == 0)    // if this does not contain any special edges (fall outside blue region)
    {
        res *= cnt_subtree[v];  // multiply the result by the no. of subtrees it has
        res %= MOD;
        return;
    }

    for (auto edge : g[v])  // falls inside blue region
    {
        int u = edge.fi;
        if (u == p) continue;
        bool special = edge.se;
        
        if (cnt_special[u] > 0) // if it has some special node in its subtree than we find the node that 
          dfs_solve(u, v); // has no special nodes in its subtree (last node of the blue region)
        else 
        {
            if (special)  // if this is the special node
            {
                res *= cnt_subtree[u]; // we always have to take this into consideration, all of its subtrees
                res %= MOD; // will be multiplied
            } 
            else 
            {
                res *= (1 + cnt_subtree[u]); // if this is not the special node then we can either leave it or 
                res %= MOD; // take its subtress
            } 
        }
    }
}

//////////////////// CASE k = 0 //////////////////////////////////////////////////

ll dp_include[N]; //dp_include[v] := number of subgraphs of v's subtree in a rooted tree containing v
ll dp_exclude[N]; //dp_exclude[v] := number of subgraphs of v's subtree in a rooted tree NOT containing v

void dfs_solve_k0(int v, int parent) 
{
    dp_include[v] = 1;
    dp_exclude[v] = 0;
    for (pii edge : g[v]) 
    {
        int u = edge.fi;
        if (u == parent) continue;
        dfs_solve_k0(u, v);

        dp_include[v] *= (1 + dp_include[u]);
        dp_include[v] %= MOD;

        dp_exclude[v] += (dp_include[u] + dp_exclude[u]);
        dp_exclude[v] %= MOD;
    }
}

int main()
{
    int t; 
    cin >> t;
    //assert(t >= 1 && t <= T);
    while (t--) {
        int n;
        cin >> n;
        //assert(n >= 2 && n <= N);
        int k = 0;
        int R = -1;
        FOR(i, n) //clearing everything 
        {
            g[i].clear();
            visited[i] = 0;
            cnt_special[i] = 0;
            cnt_subtree[i] = 0;
            dp_exclude[i] = 0;
            dp_include[i] = 0;
            res = 1;
        }
        
        FOR(i, n-1) 
        {
            int v, u;
            bool special;
            cin >> v >> u >> special;
            --v, --u;
            g[v].push_back(make_pair(u,special)); // graph in addition to containing the node it is connected to
            //also contains whether that node is special or not
            g[u].push_back(make_pair(v,special));
            if (special) ++k;
            if (special && k == 1) //if this is the first special node then it is the root
                R = v;
        }
        //assert (k >= 0);
        dfs_connected(0, -1);   //perform dfs to check if the graph is connected or not
        FOR(i, n) assert(visited[i]); //assert only fails on zero

        if (k == 0) 
        {
            //special case
            int root = 0;
            dfs_solve_k0(root, -1);
            ll res = dp_include[root] + dp_exclude[root];
            res %= MOD;
            cout << res << endl;
        } 
        else 
        {
            dfs_special(R, -1); // gives the number of special edges starting from any node 'i'
            dfs_subtrees(R, -1);// gives the total number of subtress of a node (always including it)

            dfs_solve(R, -1);
            cout << res << endl;

        }
    }

    return 0;
}