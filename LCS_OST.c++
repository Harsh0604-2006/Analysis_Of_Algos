#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1;
    cin >> s1;
    int m = s1.length();
    string s2;
    cin >> s2;
    int n = s2.length();

    vector<vector<int>> LCS(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    cout << LCS[m][n] << endl;

    int i = m;
    int j = n;
    string lcs;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else if (LCS[i - 1][j] > LCS[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
}