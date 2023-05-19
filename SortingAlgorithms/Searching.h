#pragma once

struct indexedArray
{
private:
    int len;
   
    int i, j, indSize;
    int* kindex; // массив ключей индексной 				  //таблицы
    int* pindex; // массив индексов индексной 			  //таблицы

public:

    int* k; // массив ключей
    int* r; // массив элементов

    indexedArray(int len, int* array);


    int search(int key);
   
};

int search(int* array, int len, int elem);

int indexedSearch(indexedArray array, int len, int key);

int binSearch(int* array, int left, int right, int elem);