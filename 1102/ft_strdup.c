#include <stdlib.h>


char    *ft_strdup(char *str)
{
        int     i;
        char    *dup;

        i = 0;
        while (str[i])
                i++;
        dup = (char *)malloc(i + 1);
        if (!dup)
                return NULL;
        while (i--)
                dup[i] = str[i];
        return (dup);
}


char	*ft_strdup(char *s)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	str = (char*)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (len >= 0)
	{
		str[len] = s[len];
		len--;
	}
	return (str);
}


/*  WRONG VERSION:  FIND OUT WHY IT'S WRONG
char	*ft_strdup(char *str)
{
	char	*dup;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
		i++;
	dup = (char*)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (j < i)
	{
		dup[j] = str[j];
		j++;
	}
	dup[j] = 0;
	return (dup);
}
*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (src == 0)
		return (NULL);
	while (*src)
	{
		dest[i] = src[i];
		i++;
	}
	dest = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;

	dup = (char*)malloc(i + 1);
	if (dup == 0)
		return (NULL);
	dup = ft_strcpy(dup, str);
	return (dup);
}
