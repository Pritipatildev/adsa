
#include <stdio.h>
///to find the max of a and
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W, i, w;
    int weight[n], profit[n];
    int dp[n + 1][W + 1];

//enter the no of item n and weigths
    printf("Enter number of items: ");
    scanf("%d", &n);

    
// entring the wiegths of the items
    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
//entering the profits ofthe the of item
    printf("Enter profits of items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }
//entert he cpacisity of the knapsack
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

   
//actual knpsack 
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum profit = %d\n", dp[n][W]);

    return 0;
}
