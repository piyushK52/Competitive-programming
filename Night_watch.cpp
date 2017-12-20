#include <bits/stdc++.h>
using namespace std;

map<int, int> re;

int main()
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (re.find(a) != re.end())
            re[a] = 1;
        else
            re[a]++;
    }
    
    int size = 0;
    vector<int> v;
    int t = 0;
    for (auto it = re.begin(); it != re.end(); ++it)
    {
        v.push_back(it->first);
        ++t;
    }
    
    /for (int i = 1; i < re.size() - 1; i++)
        if (v[i] > v[i - 1] && v[i] < v[i + 1])
            size += re[v[i]];

    cout << size << endl;
}