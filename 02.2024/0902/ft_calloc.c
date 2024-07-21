#include <stdlib.h>

/*

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	void	*dst;

	s = count * size;
	dst = (void*)malloc(s);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, s);
	return (dst);
}

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for  5 integers using malloc
    int *allocated_with_malloc = malloc(5 * sizeof(int));

    // Allocate memory for  5 integers using calloc
    int *allocated_with_calloc = calloc(5, sizeof(int));

	printf("Values of allocated_with_malloc: ");
    for (size_t i =  0; i <  5; ++i) {
        printf("%d ", allocated_with_malloc[i]);
    	printf("%p", &allocated_with_malloc[i]);
    }
    putchar('\n'); 

    // Print the values allocated with calloc (all zeros)
    printf("Values of allocated_with_calloc: ");
    for (size_t i =  0; i <  5; ++i) {
        printf("%d ", allocated_with_calloc[i]);
	 printf("%p", &allocated_with_calloc[i]);

    }
    putchar('\n');

    // Free the allocated memory
    free(allocated_with_malloc);
    free(allocated_with_calloc);

    return  0;
}

