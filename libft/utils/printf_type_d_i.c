/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_d_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:07:43 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/02 01:03:49 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	type_d_i(int number)
{
	char	*tmp;
	int		i;

	tmp = ft_itoa(number);
	i = write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (i);
}
