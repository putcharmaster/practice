#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int	n = nbr;
	int	len = 0;
	char	*mlc;
	int	j = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	mlc = malloc(sizeof(char) * len + 1);
	if (!mlc)
		return (NULL);
	if (nbr < 0)
		mlc[len] = '\0';
	if (nbr == 0)
	{
		mlc[0] = '0';
		return (mlc);
	}
	if (nbr < 0)
	{
		mlc[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		mlc[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (mlc);
	

}
