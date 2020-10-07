#include <bits/stdc++.h>
using namespace std;

map<long long int, long long int> val;
long long int getprofit(int n)
{
    if (n < 12)
        return n;
    if (val[n] != 0)
    {
        return val[n];
    }
    long long int ans = getprofit(n / 2) + getprofit(n / 3) + getprofit(n / 4);
    val[n] = ans;
    return ans;
}

int main()
{
    long long int n;
    while (cin >> n)
    {
        cout << getprofit(n) << endl;
    }
    return 0;
}