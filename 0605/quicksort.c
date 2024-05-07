#include <stdio.h>

void	swap(int arr[], int index_one, int index_two)
{
	int	tmp = arr[index_one];
	arr[index_one] = arr[index_two];
	arr[index_two] = tmp;
}

int	partition(int arr[], int low, int high)
{
	int	i;
	int	pivot = high;
	int	div_pos = low;

	i = low;
	while (i < high)
	{
		if (arr[i] < arr[pivot])
			swap(arr, div_pos++, i);
		i++;
	}
	swap(arr, pivot, div_pos);
	return (div_pos);
}

void	quicksort(int arr[], int low, int high)
{
	if (high > low)
	{
		int partition_index = partition(arr, low, high);
		quicksort(arr, low, partition_index-1);
		quicksort(arr, partition_index+1, high);
	}
}

void	print_array(int arr[], int len)
{
	int	i = 0;
	while (i < len)
		printf("%d\n", arr[i++]);
	printf("\n");
}

int	main()
{
	int	arr[] = {3, 44, 12, 298, 33, 5, 13, 8, 35};
	int	len = sizeof(arr)/sizeof(int);
	print_array(arr, len);
	quicksort(arr, 0, len-1);
	print_array(arr, len);
}
