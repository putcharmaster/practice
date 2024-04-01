void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	int	i;

	i = 0;
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	while (temp && i < count * size)
	{
		(char*)temp[i] = 0;
		i++;
	}
	return (temp);	
}

/*
//wrong version.  no unsigned char.   void return  so return the void.
//no while loop necessary
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*caloc;
	size_t		end_size;

	end_size = count * size;
	caloc = (unsigned char *)malloc * end_size + 1;
	if (!caloc)
		return (NULL);
	while (caloc)
	{
		caloc++ = 0;
		//ft_bzero(caloc, end_size);
	}
}
*/
