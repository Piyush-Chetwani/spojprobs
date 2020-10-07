#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int i, j;
        vector<vector<int>> a(n + 1, vector<int>(n));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        long long int max = 1 << n;

        vector<long long int> dp(max, 0);
        dp[max - 1] = 1;
        long long int student;
        for (i = max - 1; i >= 0; i--)
        {
            j = i;
            student = 0;
            while (j)
            {
                student += (j & 1);
                j /= 2;
            }

            for (int k = 0; k < n; k++)
            {
                if ((a[student][k] == 1) && !(i & (1 << k)))
                {
                    dp[i] += dp[i | (1 << k)];
                }
            }
        }

        cout << dp[0] << endl;
    }
}