
#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float ratio[10], temp;
    float total = 0;
    int i, j;

    // Calculate profit / weight ratio
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items by ratio in descending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // Fill the knapsack
    for (i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            total = total + profit[i];
            capacity = capacity - weight[i];
        }
        else
        {
            total = total + ratio[i] * capacity;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f", total);
}

int main()
{
    int n, i;
    float weight[10], profit[10], capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &weight[i]);

    printf("Enter profits of items:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    knapsack(n, weight, profit, capacity);

    return 0;
}
