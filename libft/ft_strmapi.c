/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:06:13 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/14 21:55:06 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size_s;
	size_t	i;
	char	*output;

	size_s = ft_strlen(s);
	output = malloc((size_s + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < size_s)
	{
		output[i] = f(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
