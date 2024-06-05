int     out_of_int(long n)
{
    return (n < -2147483648 || n > 2147483647);
}

long    ft_atol(char *str)
{
    int i;
    int m;
    int r;

    i = 0;
    m = 1;
    r = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            m = -m;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + str[i++] - '0';
    }
    return (r * m);
}