void fill_new_str(char *new_str, char *str)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while(str[i])
	{
		if (k == 0 && str[i] != ' ' && str[i] != '\t')
			k = 1;
		if (k == 1 && str[i] == ' ')
			new_str[j++] = '1';
		if (str[i] == '\t')
		{
			add_spcs(new_str, j);
			j += 3;
		}
		else
			new_str[j] = str[i];
		i++;
		j++;
	}
}
