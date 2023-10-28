/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:29:36 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/09/26 16:29:20 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_putnbr_base_unsigned(unsigned int nb, unsigned int base_number, \
		char *base_content, int *count_read)
{
	if ((*count_read) == ERROR)
		return ;
	else if (nb >= base_number && (*count_read) != ERROR)
		ft_putnbr_base_unsigned(nb / base_number, base_number, \
		base_content, count_read);
	if ((*count_read) != ERROR)
		ft_putchar(base_content[nb % base_number], count_read);
}

void	print_unsigned_int(unsigned int number, int *count_read,
		unsigned int base_number, char *content_base)
{
	ft_putnbr_base_unsigned(number, base_number, content_base, count_read);
}
