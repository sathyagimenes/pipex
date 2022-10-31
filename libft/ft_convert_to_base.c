/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:17:55 by sde-cama          #+#    #+#             */
/*   Updated: 2022/07/08 17:49:40 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_number(unsigned long n, int base);
static char	converter(unsigned long number);

char	*ft_convert_to_base(unsigned long n, int base)
{
	char	*num;
	size_t	size_of_n;

	size_of_n = (size_number(n, base) + 1);
	num = (char *)malloc(size_of_n * sizeof(char));
	if (!num)
		return (NULL);
	num[--size_of_n] = '\0';
	while (size_of_n > 0)
	{
		num[--size_of_n] = converter(n % base);
		n /= base;
	}
	return (num);
}

static int	size_number(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

static char	converter(unsigned long number)
{
	char	c;

	c = (char)number + '0';
	if (c > '9')
		c += 39;
	return (c);
}
