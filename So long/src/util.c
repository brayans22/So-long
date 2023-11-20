/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:05:21 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 17:05:33 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/util.h"

static void	ft_putchar(char nb)
{
	write(1, &nb, 1);
}

static int	is_format_ber(char *format_path)
{
	char	*format_ber;

	format_ber = BER_FORMAT;
	while ((*format_path) == (*format_ber) && (*format_path) && (*format_ber))
	{
		format_path++;
		format_ber++;
	}
	return ((*format_ber) == NULL_CHARACTER
		&& (*format_path) == NULL_CHARACTER);
}

int	display_message(char *message, size_t len)
{
	write(1, message, len);
	return (ERROR);
}

int	is_valid_path(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	return (len > 4 && is_format_ber(path + len - 4));
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
