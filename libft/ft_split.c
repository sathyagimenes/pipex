/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:49:32 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/15 18:37:21 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_substrings(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_copy_substr(char *substr, char const *s, int j, int substr_len)
{
	int	i;

	i = 0;
	while (substr_len > 0)
		substr[i++] = s[j - substr_len--];
	substr[i] = '\0';
	return (substr);
}

static char	**ft_separator(char **array, char const *s, char c, int substr_qty)
{
	int	i;
	int	j;
	int	substr_len;

	i = 0;
	j = 0;
	substr_len = 0;
	while (s[j] && i < substr_qty)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			substr_len++;
		}
		array[i] = malloc(sizeof(char) * (substr_len + 1));
		if (array[i] == NULL)
			return (NULL);
		ft_copy_substr(array[i], s, j, substr_len);
		substr_len = 0;
		i++;
	}
	array[i] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		substr_qty;
	char	**new_array;

	if (s == NULL)
		return (NULL);
	substr_qty = ft_count_substrings(s, c);
	new_array = malloc(sizeof(char *) * (substr_qty + 1));
	if (new_array == NULL)
		return (NULL);
	ft_separator(new_array, s, c, substr_qty);
	return (new_array);
}
