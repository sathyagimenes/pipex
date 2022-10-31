/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:10:36 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/15 18:25:32 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;

	size *= nmemb;
	if (size > 2147483647 || nmemb > 2147483647)
		return (NULL);
	memory = malloc(size);
	if (!memory)
		return (NULL);
	while (size--)
	{
		memory[size] = 0;
	}
	return (memory);
}
