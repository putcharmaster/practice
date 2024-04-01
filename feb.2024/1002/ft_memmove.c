#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t	i;

	if (dst == src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		cdst = (unsigned char*)dst;
		csrc = (unsigned char*)src;
		i = 0;
		while (len > 0)
		{
			len--;
			cdst[len] = csrc[len];
		}
	}
	return (dst);
}


/*
#include <stdlib.h>

char *ft_strnew(size_t size) {
    char *str;
    if (!(str = (char *)calloc(size +  1, sizeof(char))))
        return NULL;
    return str;
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp;

	temp = ft_strnew(n);
	if (temp)
	{
		temp = ft_memcpy(temp, src, n);
		dst = ft_memcpy(dst, temp, n);
	}
	free (temp);
	return (dst);
}
*/


void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i++;
		}
	}
	return (dst);
}

