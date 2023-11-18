/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:53:45 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 18:00:56 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

/* Includes */
# include "constants.h"
# include "get_next_line.h"
# include "util.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/* Structs */
typedef struct s_validator
{
	int	total_exits;
	int	total_positions;
	int	case_free;
}t_validator;	

/* Protypes */
char	**process_file(char *path_file, char **lines, size_t *total_lines);
char	**free_case(char **lines, char *line, char *next_line \
		, int case_free);
int		is_valid_line(char *line, int type, t_validator *v \
		, size_t len_first_line);
#endif //FILE_H
