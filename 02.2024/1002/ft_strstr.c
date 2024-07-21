
char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}


char    *ft_strstr(char *src, char *to_find)
{
        int     i;
        int     f;

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



