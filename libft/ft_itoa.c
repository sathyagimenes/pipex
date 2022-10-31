/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:29:21 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/14 21:51:45 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_number(int n);
static char	*converter(int n, char *s, size_t size_n);

char	*ft_itoa(int n)
{
	char	*num;
	size_t	size_of_n;

	size_of_n = size_number(n);
	num = malloc((size_of_n + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	converter(n, num, size_of_n);
	return (num);
}

static int	size_number(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*converter(int n, char *s, size_t size_n)
{
	unsigned int	number;

	number = n;
	if (n < 0)
		number *= -1;
	s[size_n] = '\0';
	while (size_n--)
	{
		s[size_n] = number % 10 + 48;
		number /= 10;
	}
	if (n < 0)
		*s = '-';
	return (s);
}
