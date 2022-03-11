int	ft_isalpha(char c)
{
	if ('A' <= c && c <= 'z')
	{
		if (c <= 'Z' || 'a' <= c)
			return (1);
	}
	return (0);
}
