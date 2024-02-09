#include <stddef.h>
// for "size_t"

// easiest would be using memset
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '0', n);
}



void	ft_bzero(void *s, size_t n)
{
	size_z	i;
	char	*str;

	str = s;
	i = 0;
	while(i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	while(n--)
		*ptr++ = 0;
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char*)(s + i) = 0;
/*"Take the memory location s, treat it as a sequence of bytes, go to the i-th byte in that sequence, and set its value to zero.*/
		i++;
	}
}

/*
The expression *((char*)s + i) = 0; in the context of the ft_bzero function is setting the value at a specific location in memory to zero. Let's break down each part of this expression:

(char*)s: This is a cast operation that takes the void pointer s and treats it as a pointer to a char. A char is typically 1 byte in size, so this allows us to work with the individual bytes of whatever data structure s might be pointing to.
(char*)s + i: This performs pointer arithmetic. It takes the original pointer s and adds i to it. Since we're working with a char pointer, adding i to it advances the pointer by i bytes. This effectively moves the pointer to the i-th byte in the sequence that s points to.
*((char*)s + i): The asterisk (*) is a dereference operator. When applied to a pointer, it gives you the value stored at the memory location that the pointer is pointing to. So *((char*)s + i) gives you the value of the byte at the i-th position in the sequence pointed to by s.
*((char*)s + i) = 0;: Finally, this assigns the value 0 to the byte at the i-th position. This is done in a loop to clear n bytes starting from the memory location s. 

In simpler terms, this expression is saying: "Take the memory location s, treat it as a sequence of bytes, go to the i-th byte in that sequence, and set its value to zero.
*/
