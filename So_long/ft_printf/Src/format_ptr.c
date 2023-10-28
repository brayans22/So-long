/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:26:43 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/09/26 18:32:01 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_putnbr_base_uintptr(unsigned long nb, unsigned long base_number, \
		char *base_content, int *count_read)
{
	if (nb >= base_number)
	{
		ft_putnbr_base_uintptr(nb / base_number, base_number, \
				base_content, count_read);
		ft_putnbr_base_uintptr(nb % base_number, base_number, \
				base_content, count_read);
	}
	else
		ft_putchar(base_content[nb], count_read);
}

void	print_pointer(unsigned long ptr, int *count_read)
{
	if (ptr == 0)
	{
		ft_putstr(NULL_ADDRESS, count_read);
		return ;
	}
	ft_putstr(ZERO_ADDRESS, count_read);
	if ((*count_read) != ERROR)
		ft_putnbr_base_uintptr(ptr, HEX_NB, LOWER_HEX_BASE, count_read);
}
