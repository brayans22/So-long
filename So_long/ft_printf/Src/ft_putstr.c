/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:09:13 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/09/27 16:00:42 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_putstr(const char *str, int *count_read)
{
	if (!str)
		return ;
	while (*str && (*count_read) != ERROR)
	{
		ft_putchar(*str, count_read);
		str++;
	}
}
