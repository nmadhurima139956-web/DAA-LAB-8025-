
#include <stdio.h>

int main()
{
    int coins[100], n, amount;
    int dp[1000];
    int i, j;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter coin values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    dp[0] = 0;

    for(i = 1; i <= amount; i++)
    {
        dp[i] = 9999;

        for(j = 0; j < n; j++)
        {
            if(coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
            {
                dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    if(dp[amount] == 9999)
        printf("Change cannot be made");
    else
        printf("Minimum number of coins = %d", dp[amount]);

    return 0;
}
