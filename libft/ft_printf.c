/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:19:46 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/02 00:39:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_types(va_list args, char type);

int	ft_printf(const char *parameter, ...)
{
	int		i;
	int		j;
	char	*types;
	va_list	args;

	i = 0;
	j = 0;
	types = ft_strdup("cdiuxXps%%");
	va_start(args, parameter);
	while (parameter[i] != '\0')
	{
		if (parameter[i] == '%' && ft_strchr(types, parameter[i + 1]))
		{
			i++;
			j += ft_print_types(args, parameter[i]);
		}
		else
			j += write(1, &parameter[i], sizeof(char));
		i++;
	}
	va_end(args);
	free(types);
	return (j);
}

static int	ft_print_types(va_list args, char type)
{
	int	j;

	j = 0;
	if (type == 'c')
		j += type_c(va_arg(args, int));
	else if (type == 'd' || type == 'i')
		j += type_d_i(va_arg(args, int));
	else if (type == 's')
		j += type_s(va_arg(args, char *));
	else if (type == 'u')
		j += type_u(va_arg(args, unsigned int));
	else if (type == 'x')
		j += type_x(va_arg(args, unsigned int));
	else if (type == 'X')
		j += type_upperx(va_arg(args, unsigned int));
	else if (type == 'p')
		j += type_p(va_arg(args, unsigned long));
	else if (type == '%')
		j += type_c(type);
	return (j);
}
