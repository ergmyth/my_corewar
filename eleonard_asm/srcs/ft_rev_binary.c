void	ft_rev_binary(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
		i++;
	}
}
