/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:22:32 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/15 17:12:28 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 1;
	while (i < n && *s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
