#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        int i;
        vector<pair<int, int>> pairs;
        map<pair<int, int>, int> hash;
        for (i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            pairs.push_back(make_pair(x, y));
            pairs.push_back(make_pair(y, x));
            pairs.push_back(make_pair(y, z));
            pairs.push_back(make_pair(z, y));
            pairs.push_back(make_pair(x, z));
            pairs.push_back(make_pair(z, x));
            hash[make_pair(x, y)] = z < hash[make_pair(x, y)] ? hash[make_pair(x, y)] : z;
            hash[make_pair(y, x)] = z < hash[make_pair(y, x)] ? hash[make_pair(y, x)] : z;
            hash[make_pair(z, y)] = x < hash[make_pair(z, y)] ? hash[make_pair(z, y)] : x;
            hash[make_pair(y, z)] = x < hash[make_pair(y, z)] ? hash[make_pair(y, z)] : x;
            hash[make_pair(x, z)] = y < hash[make_pair(x, z)] ? hash[make_pair(x, z)] : y;
            hash[make_pair(z, x)] = y < hash[make_pair(z, x)] ? hash[make_pair(z, x)] : y;
        }
        sort(pairs.begin(), pairs.end());
        // for(i=0;i<30;i++)
        // {
        // 	cout<<pairs[i].first<<", "<<pairs[i].second<<endl;
        // }

        int dp[n * 6] = {0};
        int temp;
        for (i = 0; i < n * 6; i++)
        {
            dp[i] = hash[pairs[i]];
            for (int j = 0; j < i; j++)
            {

                if (pairs[j].first < pairs[i].first && pairs[j].second < pairs[i].second)
                {
                    if (dp[i] < dp[j] + hash[pairs[i]])
                        dp[i] = dp[j] + hash[pairs[i]];
                }
            }
        }
        temp = 0;
        for (i = 0; i < n * 6; i++)
        {
            if (dp[i] > temp)
                temp = dp[i];
        }

        cout << temp << endl;

        cin >> n;
    }

    return 0;
}