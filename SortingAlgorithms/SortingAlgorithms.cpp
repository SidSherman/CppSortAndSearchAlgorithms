// SortingAlgorithms.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Sorting.h"
#include "Searching.h"
#include <ctime>

int* genArray(int& len);

int main()
{

    int len = 0;
    
    srand(time(NULL));
    int* array = nullptr;
    array = genArray(len);

    indexedArray iArray = indexedArray(len, array);

    int inputCommand = -1;

    while (inputCommand != 0)
    {
        inputCommand = -1;
        std::cout << "Выберите действие\n1 - сортировка массива\n2 - Генерация нового массива\n3 - Поиск элемента в массиве\n0 - выход\n";
        std::cin >> inputCommand;

        switch (inputCommand)
        {
            case 1:
            {
                inputCommand = -1;
                while (inputCommand == -1)
                {
                    std::cout << "Выберите метод сортировки:\n";
                    std::cout << "1 Сортировка пузырьком\n";
                    std::cout << "2 Шейкер\n";
                    std::cout << "3 Гномья сортировка\n";
                    std::cout << "4 Сортировка вставкой\n";
                    std::cout << "5 Сортировка слиянием\n";
                    std::cout << "6 Быстрая сортировка\n";
                    std::cout << "7 Сортировка Шелла\n";
                    std::cout << "8 Сортировка методом кучи (пирамиды)\n";
                    std::cin >> inputCommand;
                }  
                switch (inputCommand)
                {
                case 1:
                    array = BubbleSort(array, len);
                    break;
                case 2:
                    array = ShakerSort(array, len);
                    break;
                case 3:
                    array = GnomeSort(array, len);
                    break;
                case 4:
                    array = InsertSort(array, len);
                    break;
                case 5:
                    array = MergeSort(array, 0, len - 1);
                    break;
                case 6:
                    array = QuickSort(array, 0, len - 1);
                    break;
                case 7:
                    array = ShellSort(array, len);
                    break;
                case 8:
                    array = HeapSort(array, len);
                    break;
                default:
                    break;
                }

                std::cout << "Отсортированный массив:\n";
                for (int i = 0; i < len; i++)
                {
                    std::cout << array[i] << " ";
                }
                std::cout << "\n";
            }
            case 2:
                array = genArray(len);
                iArray = indexedArray(len, array);
                break;
            case 3:
                inputCommand = -1;
                while (inputCommand == -1)
                {
                    std::cout << "Выберите метод поиска:\n";
                    std::cout << "1 Последовательный\n";
                    std::cout << "2 Индексно-последовательный\n";
                    std::cout << "3 Бинарный\n";
                    std::cin >> inputCommand;
                    }

                int elem;
                int index;
                
                

                switch (inputCommand)
                {
                case 1:
                    std::cout << "Введите элемент, индекс которого нужно найти:\n";
                    std::cin >> elem;
                    index = search(array, len, elem);
                    break;
                case 2:

                    
                    std::cout << "Введите ключ элемента, индекс которого нужно найти\n";
                    for (int i = 0; i < len; i++)
                    {
                        std::cout << "value: " << iArray.r[i] << " key: " << iArray.k[i] << "\n";
                    }

                    std::cin >> elem;
                    index = indexedSearch(iArray, len, elem);
                    break;
                
                case 3:
                    std::cout << "Введите элемент, индекс которого нужно найти:\n";
                    std::cin >> elem;
                    index = binSearch(array, 0, len-1, elem);
                    break;
                default:
                    index = -1;
                    break;
                }

                std::cout << "Индекс элемента: " << index;
                break;

        }
    }
    
    
    getchar();

}


int* genArray(int& len)
{
    std::cout << "Введите длину массива:\n";
    std::cin >> len;
    int* array = new int[len];
   
    for (int i = 0; i < len; i++)
    {
        array[i] = std::rand() % 100;
        std::cout << array[i] << " ";

    }
    return array;
    std::cout << "\n";
}


