#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countWays(int n) {
    if (n % 4 == 1 || n %4 ==2) {
        return 0; // If the sum of numbers from 1 to n is odd, it's not possible to divide them equally.
    }

    int targetSum = (n * (n + 1)) / 4;

    // Create a 2D DP table to store the results.
    vector<vector<int> > dp(n + 1, vector<int>(targetSum + 1, 0));



    // Base case: there is one way to make a sum of 0 (not selecting any numbers).
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int num = 1; num <= n; num++) {
        for (int sum = 1; sum <= targetSum; sum++) {
            dp[num][sum] = dp[num - 1][sum];
            if (sum >= num) {
                dp[num][sum] = (dp[num][sum] + dp[num - 1][sum - num]) % MOD;
            }
        }
    }
    
    int rows = dp.size();
    int cols = dp[0].size(); // Assuming all rows have the same number of columns

    // Output the elements of the 2D vector
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][targetSum];
}

int main() {
    int n;
    cin >> n;


    int ways = countWays(n);
    cout << ways << endl;

    return 0;
}
