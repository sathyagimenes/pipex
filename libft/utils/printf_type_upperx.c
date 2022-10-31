/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_upperx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:24:53 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/02 01:04:01 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	type_upperx(unsigned long number)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_convert_to_base(number, 16);
	while (tmp[i] != '\0')
	{
		tmp[i] = ft_toupper(tmp[i]);
		i++;
	}
	i = write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (i);
}
