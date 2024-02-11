char	*ft_strstr(char *src, char *to_find)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (to_find[0] == 0)
		return (str);
	while (src[i])
	{
		while (src[i + f] && src[i + f] == to_find[f])
		{
			if (!to_find[f + 1])
				return (&str[i]);
			f++;
		}
		i++;
	}
	return (0);
}


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}

// the best one
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (*str != c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return (str);
}

// also good one
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char*)s);
	return (NULL);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s && c != *s)
		s++;
	if (c == *s)
		return ((char*)s);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if (!(char)c)
		return ((char*)s);
	return (NULL);
}


