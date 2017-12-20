#include <iostream>

using namespace std;

int n, t;
int a[30000];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    int index = 0;
    while (index + 1 < t)
        index += a[index];
    cout << (index + 1 == t ? "YES" : "NO");
    return 0;
}
