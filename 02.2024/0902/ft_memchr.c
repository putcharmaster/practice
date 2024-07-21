#include <stdlib.h>

/*
Using `(unsigned char *)` is not strictly necessary, but it is often done to ensure well-defined behavior when working with raw memory or when you need to perform operations that are independent of the signedness of `char`. Here's why:

- **Byte Operations**: When you're dealing with raw memory, you typically want to work with bytes rather than characters. An `unsigned char` is guaranteed to be exactly  1 byte, while a `char` can be either signed or unsigned and may be more than  1 byte depending on the platform [0][1].

- **Extended ASCII**: On some platforms, `char` is signed, and using it directly can lead to unexpected behavior when working with extended ASCII characters (values above  127). Casting to `unsigned char` ensures that you're working with the full range of  0 to  255 [0][1].

- **Bitwise Operations**: If you're performing bitwise operations, such as masking or shifting, you might want to use `unsigned char` to avoid issues with sign extension [0].

- **Portability**: Ensuring that you're using `unsigned char` when working with byte-level operations helps make your code more portable across different platforms and compilers, as the behavior of `char` can vary [0].

However, if you're working with text and you know that your data will only contain printable ASCII characters, then using `(char *)` might be fine and could potentially make the code clearer to readers who are accustomed to thinking of characters as `char` types. But if you're doing anything that involves binary data, bitwise operations, or you're not sure about the signedness of `char` on your platform, then using `(unsigned char *)` is a safer choice.
*/

// anything memory => use unsigned char instead of char.

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s + 1) == (unsigned char)c)
			return ((void*)(s + 1));
		i++;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)s == (unsigned char)s)
			return ((void*)s);
		s++;
		i++;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
}
