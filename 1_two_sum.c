#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *arr = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
                return arr;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int size;
    int input[] = {3, 5, 4, 8};
    int output[] = twoSum(input, 2, 7, &size);
    printf("%d\t", output[0]);
    printf("%d\t", output[1]);
}