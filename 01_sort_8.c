#include <stdio.h>
#include <stdlib.h>

// сортировка Шелла
void shellSort(int* arr, int size, FILE* fp)
{
    int temp, s, i, j, z;
    for (s = size / 2; s > 0; s /= 2)
    {
        for (i = 0; i < size; i++)
        {
            for (j = i + s; j < size; j += s)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    for (z = 0; z < size; z++)
                    {
                        if (z != 0)
                        {
                            fprintf(fp, " ");
                        }
                        fprintf(fp, "%d", arr[z]);
                    }
                    fprintf(fp, "\n");
                }
            }
        }
    }
}

// сортировка "расческой"
void combSort(int* arr, int size, FILE* fp)
{
    double factor = 1.2473309;
    int step = size - 1;
    int temp, i, j;
    while (step >= 1)
    {
        for (i = 0; i + step < size; i++)
        {
            if (arr[i] > arr[i + step])
            {
                temp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = temp;

                for (j = 0; j < size; j++)
                {
                    if (j != 0)
                    {
                        fprintf(fp, " ");
                    }
                    fprintf(fp, "%d", arr[j]);
                }
                fprintf(fp, "\n");
            }
        }
        step /= factor;
    }
}

int main()
{
    int size, i;
    scanf("%d", &size);
    int* arr1 = (int*)malloc(sizeof(int) * size);
    int* arr2 = (int*)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }
    char qf[] = "shellSort.log";
    FILE* fp = fopen(qf, "w+");
    for (i = 0; i < size; i++)
    {
        if (i != 0)
        {
            fprintf(fp, " ");
        }
        fprintf(fp, "%d", arr1[i]);
    }
    fprintf(fp, "\n");
    shellSort(arr1, size, fp);
    fclose(fp);
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr1[i]);
        if (i < size - 1)
        {
            printf(" ");
        }
    }
    char hf[] = "combSort.log";
    fp = fopen(hf, "w+");
    for (i = 0; i < size; i++)
    {
        if (i != 0)
        {
            fprintf(fp, " ");
        }
        fprintf(fp, "%d", arr2[i]);
    }
    fprintf(fp, "\n");
    combSort(arr2, size, fp);
    fclose(fp);
    free(arr1);
    free(arr2);
    printf("\n");
    return 0;
}