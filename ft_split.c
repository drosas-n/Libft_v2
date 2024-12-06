#include "libft.h"

static int	ft_free_all(char **matrix)
{
    int	i;

    i = 0;
    while (matrix[i])
        i++;
    while(--i >= 0)
        free(matrix[i]);
    free(matrix);
    return (0);
}

static char	**ft_splitting_words(char const *s, char c, int i, int j)
{
	int	counter;
	int	k;

	while (s[++i])
	{
		counter = 0;
		while (s[i + counter] != c)
		{
			if (s[i + counter] != c && (s[i + counter + 1] == c || s[i + counter + 1] == '\0'))
			{
				matrix[j] = (char *)malloc(sizeof(char) * (counter + 2));
				if (!matrix[j])
					return (ft_free_all(matrix));
				k = 0;
				while (--counter > -2)
					matrix[j][k++] = s[i++];
				i--;
				matrix[j++][k] = '\0';
				break ;
			}
			counter++;
		}
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		j;
	int		counter;

	i = -1;
	counter = 0;
	while (s[++1])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
	}
	matrix = (char **)malloc(sizeof(char *) * (counter + 1))
	if (!matrix)
		return (0);
	matrix[counter] = NULL;
	i = -1;
	j = 0;
	matrix = ft_splitting_words(s, c, i, j);
	if (matrix == 0)
		return (0);
	return (matrix);
}
