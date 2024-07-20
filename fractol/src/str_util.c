#include "../inc/fractol.h"

int     ft_isdigit(char *str)
{
    while (str)
    {
        if ((*str >= '0' && *str <= '9')
            || *str == '-' || *str == '.')
            str++;
        else
            return (0); 
    }
    return (1);
}

static int    ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(const char *src)
{
    int     i;
    char    *dup;

    i = 0;
    dup = malloc(ft_strlen(src) + 1);
    if (dup == 0)
        return (NULL);
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = 0;
    return (dup);
}

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

int ft_strcmp(const char *s1, char *s2)
{
    int i;
    i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i])
        i++;
    return (s1[i]-s2[i]);
}