#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize)
{
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        for (int j = i + 1; j < pricesSize; j++)
        {
            if (prices[i] < prices[j])
            {
                maxProfit = ((prices[j] - prices[i]) > maxProfit) ? (prices[j] - prices[i]) : maxProfit;
            }
        }
    }
    return maxProfit;
}
