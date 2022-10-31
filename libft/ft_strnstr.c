/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:02:03 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/01 02:47:07 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			len_little;
	unsigned int	i;

	i = 0;
	len_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while ((i < len) && *big)
	{
		if ((ft_strncmp(big, little, len_little) == 0)
			&& (len_little + i <= len))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
