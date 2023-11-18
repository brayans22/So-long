/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:55:14 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 18:04:34 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

/* Includes */
# include "constants.h"
# include <unistd.h>
# include "get_next_line.h"

/* Protypes */
int	display_error_message(char *message, size_t len);
int	is_valid_path(char *path);

#endif //UTIL_H
