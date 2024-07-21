#include <stdio.h>
#include <stddef.h>

void	ft_bzero1(void *s, size_t n)
{
	unsigned char	*str;
	size_t		i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	ft_bzero2(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
		*temp++ = 0;
}

/*  wrong ver.  1st try not the worst but malloc was unnessesary
void	ft_bzero(void *s, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(char *)s * n;
	if (!temp)
		return (NULL);
	while (temp && i < n)
	{
		temp[i] = 0;
		i++;	
	}
}
*/
