#include <iostream>
#include <cstdio>
using namespace std;

#define LL unsigned long long

const int SZ = 51;
LL startPT[SZ];
LL speed[SZ];

int main()
{
  int T;
  cin >> T;
  int t = 1;
  while (T--)
  {
    int swap = 0;
    int N, K;
    LL B, T;
    cin >> N >> K >> B >> T;
    for (int i = 1; i <= N; i++)
    {
      cin >> startPT[i];
    }

    for (int i = 1; i <= N; i++)
    {
      cin >> speed[i];
    }

    int count = 0;
    int cantReach = 0;

    for (int i = N; i >= 1; i--)
    {
      LL distance = B - startPT[i];
      //LL time = distance / speed[i];   // this was a mistake time was gettig rounded off
      LL canCover = T * speed[i];
      if (distance <= canCover)
      {
        count++;
        if (cantReach > 0)
        {
          swap = swap + cantReach;
          //cantReach = 0; dont reset it swap has to be done for all
        }
      }
      else
      {
        cantReach++;
      }

      if (count == K)
        break;
    }

    if (count < K)
    {
      cout << "Case #" << t++ << ": "
           << "IMPOSSIBLE" << endl;
    }
    else
    {
      cout << "Case #" << t++ << ": " << swap << endl;
    }
  }

  return 0;
}

//You have to find the minimum no. of swaps so that 'k' chicks reach the finish line.
//steps:
//1. You start counting from the first chick.
//2. If it can cover the distance then you increase the count by one and if it can't then you increase the
//   cant_reach count by 1.
//3. To find the no. of swaps you just shift all the cant_reach chicks behind the one which can reach
//   => swap=swap+cantreach for every chick which can reach.
