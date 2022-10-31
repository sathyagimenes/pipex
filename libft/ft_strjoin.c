/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:51:07 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/12 20:37:35 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*full_str;
	size_t	size_s1;
	size_t	size_s2;
	int		i;

	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	full_str = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (full_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		full_str[i] = s1[i];
		i++;
	}
	while (s2[i - size_s1] != '\0')
	{
		full_str[i] = s2[i - size_s1];
		i++;
	}
	full_str[i] = '\0';
	return (full_str);
}
