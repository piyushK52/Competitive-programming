#include <bits/stdc++.h>
using namespace std;

char s[3000], t[3000];
int edist(int i, int j)
{
    if (i == -1)
        return j + 1;
    if (j == -1)
        return i + 1;
    if (s[i] == t[j])
        return edist(i - 1, j - 1);
    else
        return min(edist(i - 1, j - 1) + 1, min(edist(i - 1, j) + 1, edist(i, j - 1) + 1));
}
int main()
{

    gets(s);
    gets(t);
    int sl = 0, st = 0;
    while (s[sl] != '\0')
        sl++;
    while (t[st] != '\0')
        st++;
    cout << edist(sl - 1, st - 1);
}