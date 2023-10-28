/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:14:56 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/09/27 16:20:46 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* INCLUDES */
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/* CONSTANTS */
# define DECIMAL_FORMAT              		'd'
# define CHARACTER_FORMAT            		'c'
# define INTEGER_FORMAT              		'i'
# define STRING_FORMAT               		's'
# define POINTER_FORMAT              		'p'
# define UNSIGNED_DECIMAL_FORMAT     		'u'
# define HEX_LOWER_FORMAT            		'x'
# define HEX_UPPER_FORMAT            		'X'
# define PERCENTAGE_FORMAT           		'%'
# define DECIMAL_NB                  		10
# define HEX_NB                      		16
# define UPPER_HEX_BASE              		"0123456789ABCDEF"
# define LOWER_HEX_BASE              		"0123456789abcdef"
# define DEC_BASE                    		"0123456789"
# define MIN_RANGE_INT_IN_STR_FORMAT     	"-2147483648"
# define MIN_RANGE_INT_IN_INT_FORMAT     	-2147483648
# define NULL_ADDRESS                    	"0x0"
# define STR_NULL                        	"(null)"
# define ZERO_ADDRESS                    	"0x"
# define ERROR                           	-1
# define LEN_ZERO_ADDRESS                	2
# define LEN_NULL_WORD                   	6
# define LEN_MIN_RANGE_INT               	11

/* PROTOTYPE FUNCTIONS */
int		ft_printf(char const *format, ...);
void	print_char(char c, int *count_read);
void	print_int(int number, int *count_read);
void	print_pointer(unsigned long ptr, int *count_read);
void	print_string(char *str, int *count_read);
void	print_unsigned_int(unsigned int number, int *count_read, \
		unsigned int base_number, char *content_base);
void	ft_putstr(const char *str, int *count_read);
void	ft_putchar(char c, int *count_read);

#endif
