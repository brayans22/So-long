/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:25:13 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/09/26 16:27:54 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static void	ft_putnbr_decimal_base_int(int nb, int *count_read)
{
	if ((*count_read) == ERROR)
		return ;
	else if (nb <= MIN_RANGE_INT_IN_INT_FORMAT)
	{
		ft_putstr(MIN_RANGE_INT_IN_STR_FORMAT, count_read);
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-', count_read);
		ft_putnbr_decimal_base_int(-nb, count_read);
	}
	else if (nb > 9)
	{
		ft_putnbr_decimal_base_int(nb / 10, count_read);
		ft_putnbr_decimal_base_int(nb % 10, count_read);
	}
	else
		ft_putchar(nb + '0', count_read);
}

void	print_int(int number, int *count_read)
{
	ft_putnbr_decimal_base_int(number, count_read);
}
