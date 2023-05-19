#include <iostream>
#include "Searching.h"
#include "Sorting.h"


int search(int* array, int len, int elem)
{

    int index = -1;
    for (int i = 0; i < len; i++)
    {
        if (array[i] == elem)
        {
            index = i;
            break;
        }
    }
    return(index);
}


int indexedSearch(indexedArray array, int len, int key)
{
    int index = -1;
    index = array.search(key);
    return index;
}


int binSearch(int* array, int left, int right, int elem)
{
    
    int index = -1;
    int middle = (right+left) / 2;

    if (array[middle] == elem)
    {
        index = middle;
    }
    else
    {
        if (left == right)
            return index;
        index = binSearch(array, left, middle, elem);

        if (index != -1)
            return index;
        else
            index = binSearch(array, middle + 1, right, elem);
    }
    return index;
}

indexedArray::indexedArray(int len, int* array)
{
    this->len = len;
    k = new int[len];
    r = new int[len];
    kindex = new int[len / 8];
    pindex = new int[len / 8];

    for (int i = 0; i < len; i++)
    {
        r[i] = array[i];
        k[i] = i + 10;
    }
    k = QuickSort(k, 0,len);

    for (i = 0, j = 0; i < len; i = i + 8)
    {
        kindex[j] = k[i];
        pindex[j] = i;
        j++;
    }
    pindex[j] = len;
    indSize = j;
}

int indexedArray::search(int key)
{
    for (j = 0; j < len; j++)
    {
        if (key < kindex[j])
            break;
    }
    if (j == 0)
        i = 0;
    else
        i = pindex[j - 1];

    for (i; i < pindex[j]; i++)
    {
        if (k[i] == key)
            return i;
    }
    return -1;
}