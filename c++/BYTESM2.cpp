#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int h, w, i, j;
        cin >> h >> w;
        long long int stone[h][w], dp[h][w];
        memset(dp, 0, sizeof(dp));
        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {
                cin >> stone[i][j];
            }
        }

        for (i = 0; i < w; i++)
            dp[h - 1][i] = stone[h - 1][i];

        for (i = h - 1; i >= 1; i--)
        {
            for (j = 0; j < w; j++)
            {
                if (j - 1 >= 0 && dp[i - 1][j - 1] < dp[i][j] + stone[i - 1][j - 1])
                    dp[i - 1][j - 1] = dp[i][j] + stone[i - 1][j - 1];

                if (dp[i - 1][j] < dp[i][j] + stone[i - 1][j])
                    dp[i - 1][j] = dp[i][j] + stone[i - 1][j];

                if (j + 1 < w && dp[i - 1][j + 1] < dp[i][j] + stone[i - 1][j + 1])
                    dp[i - 1][j + 1] = dp[i][j] + stone[i - 1][j + 1];
            }
        }

        long long int max = INT_MIN;
        for (i = 0; i < w; i++)
        {
            if (dp[0][i] > max)
                max = dp[0][i];
        }

        cout << max << endl;
    }
}