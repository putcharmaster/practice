no idea

int	max(int *tab, unsigned int len)
{
	if (len == 0)
		return (0);

	unsigned int	r;
	unsigned int	i;

	i = 0;
	r = tab[i];
	while (i < len)
	{
		if (r < tab[i])
			r = tab[i];
		i++;
	}
	return (r);
}
