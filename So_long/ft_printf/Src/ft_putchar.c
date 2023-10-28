/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:29:00 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/09/26 16:30:20 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_putchar(char c, int *count_read)
{
	int	status;

	status = write(1, &c, 1);
	if (status == ERROR)
		(*count_read) = ERROR;
	else
		(*count_read)++;
}
