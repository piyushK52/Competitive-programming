#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 100004;
static const int MAXW = 100003;
static const int MAXT = 100002;

int n, w, h;
int g[MAXN], p[MAXN], t[MAXN];

vector<int> s[MAXW + MAXT];
int ans_x[MAXN], ans_y[MAXN];

int main()
{
    scanf("%d%d%d", &n, &w, &h);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &g[i], &p[i], &t[i]);
        s[p[i] - t[i] + MAXT].push_back(i); // dividing into groups
    }

    vector<int> xs, ys; //xs -> moving in x-direction (present on y-axis)
    for (int i = 0; i < MAXW + MAXT; ++i) 
    if (!s[i].empty()) 
    {
        for (int u : s[i]) 
        {
            if (g[u] == 1) xs.push_back(p[u]); // divide into vertical and horizontal groups
            else ys.push_back(p[u]);
        }
        sort(xs.begin(), xs.end()); // sorted in ascending order
        sort(ys.begin(), ys.end()); // sorted in ascending order
        sort(s[i].begin(), s[i].end(), [] (int u, int v) 
        {
            if (g[u] != g[v]) return (g[u] == 2); // places points on the Y-axis before X-axis
            else return (g[u] == 2 ? p[u] > p[v] : p[u] < p[v]);
        });
        //final sorting order
        //1. all Y-axis points placed in the descending order of points
        //2. all X-axis points placed in the ascending order of points
        for (int j = 0; j < xs.size(); ++j) 
        {
            ans_x[s[i][j]] = xs[j];
            ans_y[s[i][j]] = h;
        }
        for (int j = 0; j < ys.size(); ++j) 
        {
            ans_x[s[i][j + xs.size()]] = w;
            ans_y[s[i][j + xs.size()]] = ys[ys.size() - j - 1];
        }
        xs.clear();
        ys.clear();
    }

    for (int i = 0; i < n; ++i) printf("%d %d\n", ans_x[i], ans_y[i]);

    return 0;
}