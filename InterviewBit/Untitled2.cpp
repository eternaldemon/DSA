#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countDiceSequences' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER_ARRAY rollMax
 */
#define MODULO 1000000007
int countDiceSequences(int N, vector<int> rollMax) {
    rollMax.insert(rollMax.begin(), 0);
        int n = N;
        vector<vector<long long>> dynamic_plan(n + 1, vector<long long>(7, 0));
        dynamic_plan[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 6; j++){
                long long sum = 0;
                for(int num_depth = 1; num_depth <= rollMax[j] && i - num_depth >= 0; num_depth++)
                    sum += (dynamic_plan[i - num_depth][0] - dynamic_plan[i - num_depth][j] + MODULO) % MODULO;  
                dynamic_plan[i][j] = sum;
                dynamic_plan[i][0] = (sum + dynamic_plan[i][0]) % MODULO;
            }
        }
        return dynamic_plan[n][0];
}
int main()
