char	ft_toupper(char c)
{
	if ('a' <= c && c <= 'z')
		c = c - 'a' + 'A';
	return (c);
}
