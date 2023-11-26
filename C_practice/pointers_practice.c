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
int main()
{
    printf("Hello!\n");
    TwoDArray(2,3);

    return 0;
}