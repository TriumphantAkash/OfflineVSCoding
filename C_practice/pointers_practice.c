#include<stdio.h>
#include<stdlib.h>

void Print2DArray(int** pArr, int row, int column)
{
    int k = 0;
    for(int i = 0; i < row;i++)
    {
        for(int j = 0; j < column; j++)
        {
            printf("%d ",pArr[i][j]);
            k++;
        }
        printf("\n");
    }
}

void TwoDArray(int row, int column)
{
    int* arr[row];
    for(int i = 0; i < row; i++)
    {
        arr[i] = (int*)malloc(column*sizeof(int));
    }

    //populate 2D array
    int k = 0;
    for(int i = 0; i < row;i++)
    {
        for(int j = 0; j < column; j++)
        {
            arr[i][j] = k;
            k++;
        }
    }
    Print2DArray(arr,2,3);;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* retArr = (int*)malloc(2*sizeof(int));

  for(int i = 0; i< numsSize;i++ )
  {
    if (nums[abs(nums[i])-1] < 0)
    {
      retArr[0] = nums[i];
    }else
    {
      nums[nums[i]-1] *= -1;
    }
  }
  for(int i =0; i< numsSize; i++)
  {
    if(nums[i] > 0)
    {
      retArr[1] = i+1;
    }
  }
    return retArr;
}

int main()
{
    int nums[3] = {2,3,2};
    int numsSize = 3;
    int* returnSize;
    int* ret = findErrorNums(nums, numsSize, returnSize);
    printf("%d ",ret[0]);
    printf("%d ",ret[1]);
 }
// int main()
// {
//     printf("Hello!\n");
//     TwoDArray(2,3);

//     return 0;