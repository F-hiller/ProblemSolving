#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define nl '\n'
#define pb push_back

using namespace std;

const ll md = 1e9 + 7;

int t;

ll sol()
{
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if (n != 3)
    {
      cout << 2 << nl;
      for (int i = 1; i <= n; i += 2)
      {
        for (int j = i; j <= n; j *= 2)
        {
          cout << j << " ";
        }
      }
      cout << nl;
    }
    else
    {
      cout << 3 << nl << 2 << " " << 1 << " " << 3 << nl;
    }
  }
}
int main()
{
  cout << "Hello" << endl;
  sol();
  cout << "Hello" << endl;
  return 0;
}