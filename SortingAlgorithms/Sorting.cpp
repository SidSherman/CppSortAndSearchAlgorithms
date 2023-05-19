#include "Sorting.h"

int* BubbleSort(int* array, int len) {


	int temp;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (array[j-1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}

	return array;

}


int* ShakerSort(int* array, int len) {

	int temp;
	int left = 0;
	int right  = len - 1;
	int flag = 1; // наличие переменной

	while ( (left < right) && flag > 0)
	{
		flag = 0;

		for (int i = left; i < right; i++) //движемся направо
		{
			
			if (array[i] > array[i+1])
			{
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				flag = 1;
			}
		
		}
		right--;

		for (int i = right; i > left; i--) //движемся наплево
		{
			if (array[i-1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				flag = 1;
			}
			
		}
		left++;
	}

	return array;

}



int* GnomeSort(int* array, int len)
{
	int i, j;
	int min, temp;
	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}

	return array;
}

int* InsertSort(int* array, int len)
{

	int temp;
	int j;
	for (int i = 0; i < len ; i++)
	{
		temp = array[i];
		j = i;
		while ((j > 0) && (array[j - 1] > temp))
		{
			array[j] = array[j - 1];
			j = j - 1;
		}
		array[j] = temp;

	}
	return array;
}

int* MergeSort(int* array, int left, int right)
{
	if (left == right)
		return array;

	int middle = (left + right) /2; //находим середину

	MergeSort(array, left, middle);
	MergeSort(array, middle + 1, right);

	int* temp = new int [right]; // дополнительный массив

	int i = left;  // начало первого пути
	int j = middle +1; // начало второго пути

	for (int step = 0; step < right - left + 1; step++) // для всех элементов дополнительного массива
	{
			// записываем в формируемую последовательность меньший из элементов двух путей
			// или остаток первого пути если j > r
		if ((j > right) || ((i <= middle) && (array[i] < array[j]))) 
		{
			temp[step] = array[i];
			i++;
		}
		else 
		{
			temp[step] = array[j];
			j++;
		}
	}
	  // переписываем сформированную последовательность в исходный массив
	 for (int step = 0; step < right - left + 1; step++)
		array[left + step] = temp[step];

	 return temp;
}


int* QuickSort(int* array, int left, int right) {

	int pivot;
	int left_index = left;
	int right_index = right;
	pivot = array[left];

	while (left < right)
	{
		while ((array[right] >= pivot) && (left < right))
		{
			right--;
		}
			
		if (left != right)
		{
			array[left] = array[right];
			left++;
		}

		while ((array[left] <= pivot) && (left < right))
		{
			left++;
		}
			
		if (left != right)
		{
			array[right] = array[left];
			right--;
		}
	}

	array[left] = pivot;
	pivot = left;
	left = left_index;
	right = right_index;

	if (left < pivot)
		QuickSort(array, left, pivot - 1);

	if (right > pivot)
		QuickSort(array, pivot + 1, right);

	return array;
}

int* ShellSort(int* array, int len)
{
	int i, j, increment, temp;
	increment = 3;

	while (increment > 0)
	{
		for (i = 0; i < len; i++)
		{
			j = i;
			temp = array[i];
			while ((j >= increment ) && (array[j - increment] > temp))
			{
				array[j] = array[j - increment];
				j = j - increment;
			}
			array[j] = temp;
		}

		if (increment / 2 != 0)
			increment = increment / 2;
		else if (increment == 1)
			increment = 0;
		else
			increment = 1;
	}
	return array;
}


int* SelectionSort(int* array, int len)
{
	int left = 0, right = len-1;
	int index;
	int min;
	int temp;
	for (int i = left; i < right; i++) {
		min = array[i];
		index = i;
		for (int j = i + 1; j < right; j++) {
			if (array[j] < min)
			{
				min = array[j];
				index = j;
			}			
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	return array;
}



void siftDown(int* array, int root, int bottom)  // Функция "просеивания" через кучу - формирование кучи
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	while ((root * 2 <= bottom) && (!done)) // Пока не дошли до последнего ряда
	{
		if (root * 2 == bottom)    // если мы в последнем ряду, 
			maxChild = root * 2; // запоминаем левый потомок
		else
			if (array[root * 2] > array[root * 2 + 1]) // иначе запоминаем больший потомок 													// из двух		
				maxChild = root * 2;
			else
				maxChild = root * 2 + 1;
		if (array[root] < array[maxChild]) // если элемент вершины меньше максимального 										      //потомка
		{
			int temp = array[root]; // меняем их местами
			array[root] = array[maxChild];
			array[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1; // пирамида сформирована
	}
}


int* HeapSort(int* array, int len)
{
	// Формируем нижний ряд пирамиды	
	for (int i = (len / 2) - 1; i >= 0; i--)
		siftDown(array, i, len);	
	// Просеиваем через пирамиду остальные элементы
	for (int i = len - 1; i >= 1; i--)
	{
		int temp = array[0];
		array[0] = array[i];

		array[i] = temp;
		siftDown(array, 0, i - 1);
	}
	return array;
}
