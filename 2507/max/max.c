int	max(int *tab, unsigned int len)
{
	int	max;
	unsigned int	i = 0;

	if (!tab)
		return (0);
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}
