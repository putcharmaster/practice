#include <stdio.h>

void	swap(int *a, int *b)
{
	int	t = *a;
	*a = *b;
	*b = t;
}

int	partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int	i = low - 1;
	int	j = low;

	while (j <= high -1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		int	pi = partition(arr, low, high);
		quicksort(arr, low, pi -1);
		quicksort(arr, pi + 1, high);
	}
}

void	printarray(int arr[], int size)
{
	int	i;
	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
	printf("\n");
}

int	main()
{
	int arr[] = {0, -1, 5, 7, 355, 10};
	int	n = sizeof(arr) / sizeof(arr[0]);
	quicksort(arr, 0, n - 1);
	printarray(arr, n);
	return (0);
}
