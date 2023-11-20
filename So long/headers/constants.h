/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:54:18 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 19:26:48 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/* FILES CONSTANTS */
# define LINE_BREAK      '\n'
# define NULL_CHARACTER  '\0'

/* MOVEMENTS */
# define COMMAND_W 		119 	// MAC 13
# define COMMAND_S 		115 	// MAC 1
# define COMMAND_D 		100 	// MAC 0
# define COMMAND_A 		97 	// MAC 2
# define COMMAND_ESC 	65307

/* ELEMENTS */
# define EXIT 'E'
# define POSITION 'P'
# define COLLECTABLE 'C'
# define WALL '1'
# define EMPTY '0'

/* LIMITS */
# define MAX_EXITS 1
# define MAX_PLAYERS 1
# define MAX_POSITIONS 1
# define MAX_BORDER_SIDES 1

/* FILES */
# define LEN_BER_FORMAT 4
# define BER_FORMAT     ".ber"

/* BOOLEANS */
# define TRUE 1
# define FALSE 0

/* GAME */
# define FIRST_LINE      	-4
# define MIDDLE_LINE     	-5
# define LAST_LINE       	-6
# define UP_OR_DOWN 		-7
# define LEFT_OR_RIGHT 		-8

/* PATHS IMAGES */
# define PATH_IMG_COLLECTABLE 	"images/collectable.xpm"
# define PATH_IMG_EXIT 			"images/exit.xpm"
# define PATH_IMG_BACKGROUND 	"images/background.xpm"
# define PATH_IMG_WALL 			"images/wall.xpm"
# define PATH_IMG_PLAYER		"images/player.xpm"

/* ERROR VALUES && SUCCES STATUS*/
# define ERROR -1
# define SUCCESSFUL 1

/* MESSAGES */
# define WON_MESSAGE				"\n YOU WON!\n"
# define INVALID_KEY_MESSAGE 		"Error\nInvalid Key\n"
# define FAIL_EXIT_MESSAGE "Error\nYou can't exit, you need more collectibles\n"
# define TOTAL_MOVEMENTS_MESSAGE	"\n Total Movements: "
# define ERROR_OPEN_FILE        	"Error\nFile cannot open correctly\n"
# define ERROR_CLOSE_FILE       	"Error\nFile cannot be close correctly\n"
# define ERROR_MORE_ELEM  "Error\nMore than one Position (P) or Exit (E)\n"
# define ERROR_FEW_ELEM         	"Error\nMissing position (P) or exit (E)\n"
# define ERROR_INVALID_SYMBOL   "Error\nThere is an invalid symbol on the map\n"
# define ERROR_INVALID_FORMAT   	"Error\nThe file format is not correct\n"
# define ERROR_INVALID_BORDER   	"Error\nThe map is not surrounded\n"
# define ERROR_INVALID_MOVEMENT 	"Error\nInvalid Movement Key\n"
# define ERROR_INVALID_SIZE			"Error\nThe map is not square\n"
# define ERROR_INVALID_MAP      	"Error\nIt is not a rectangular map\n"
# define ERROR_FEW_ARGUMENTS    	"Error\nToo few arguments\n"
# define ERROR_MANY_ARGUMENTS   	"Error\nToo many arguments\n"
# define ERROR_MEMORY           	"Error\nMalloc fails\n"
# define ERROR_WRITE            	"Error\nWrite fails\n"

#endif //CONSTANTS_H
