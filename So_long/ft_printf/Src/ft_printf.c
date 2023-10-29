/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:17:47 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/09/27 16:20:07 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static void	print_format(char format, int *count_read, va_list p_arguments)
{
	if (format == STRING_FORMAT)
		print_string(va_arg(p_arguments, char *), count_read);
	else if (format == CHARACTER_FORMAT)
		print_char((char)va_arg(p_arguments, int), count_read);
	else if (format == INTEGER_FORMAT || format == DECIMAL_FORMAT)
		print_int(va_arg(p_arguments, int), count_read);
	else if (format == UNSIGNED_DECIMAL_FORMAT)
		print_unsigned_int(va_arg(p_arguments, unsigned int), count_read, \
				DECIMAL_NB, DEC_BASE);
	else if (format == HEX_UPPER_FORMAT)
		print_unsigned_int(va_arg(p_arguments, unsigned int), count_read, \
				HEX_NB, UPPER_HEX_BASE);
	else if (format == HEX_LOWER_FORMAT)
		print_unsigned_int(va_arg(p_arguments, unsigned int), count_read, \
				HEX_NB, LOWER_HEX_BASE);
	else if (format == POINTER_FORMAT)
		print_pointer(va_arg(p_arguments, unsigned long), count_read);
	else if (format == PERCENTAGE_FORMAT)
		print_char(PERCENTAGE_FORMAT, count_read);
	else
		(*count_read) = ERROR;
}

int	ft_printf(char const *format, ...)
{
	va_list			p_args;
	int				count_read;

	va_start(p_args, format);
	count_read = 0;
	while ((*format) && count_read != ERROR)
	{
		if ((*format) == PERCENTAGE_FORMAT)
		{
			format++;
			print_format(*format, &count_read, p_args);
		}
		else
			print_char(*format, &count_read);
		format++;
	}
	va_end(p_args);
	return (count_read);
}
/*
#include <stdio.h>
int main()
{
	int j = printf("%u, %i, %d\n", -10, 037, 037);
	int w = ft_printf("%u, %i, %d\n", -10, 037, 037);
	printf("original: %i, copia: %i",j,w);	
    return 0;
}
*/
