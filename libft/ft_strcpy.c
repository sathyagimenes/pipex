/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:01:59 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/30 01:37:33 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!src || len == 0)
		return ;
	while (src[i] && i < (len - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}
