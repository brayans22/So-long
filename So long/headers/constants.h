
#ifndef CONSTANTS_H
# define CONSTANTS_H

/* FILES CONSTANTS */
# define LINE_BREAK      '\n'
# define NULL_CHARACTER  '\0'

/* MOVEMENTS */
# define UP 'W'
# define LEFT 'A'
# define RIGHT 'D'
# define DOWN 'S'

/* FREE CASES */
# define FREE_LINE              -20
# define FREE_LINE_AND_NEXT     -21
# define FREE_MATRIX_AND_LINE   -22
# define FREE_LINES_MATRIX      -23
# define FREE_ALL               -24

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
# define PLAYING 'R'
# define ENDGAME 'K'
# define START 'T'
# define FIRST_LINE      -4
# define MIDDLE_LINE     -5
# define LAST_LINE       -6

/* ERROR VALUES && SUCCES STATUS*/
# define ERROR -1
# define SUCCESSFUL 1

/* ERROR MESSAGES */
# define ERROR_OPEN_FILE        "Error\nfile cannot open correctly\n"
# define ERROR_CLOSE_FILE       "Error\nfile cannot be close correctly\n"
# define ERROR_MORE_ELEM        "Error\nmore than one position (P) or more than one exit (E)\n"
# define ERROR_FEW_ELEM         "Error\nMissing position (P) or exit (E)\n"
# define ERROR_INVALID_SYMBOL   "Error\nthere is an invalid symbol on the map\n"
# define ERROR_INVALID_FORMAT   "Error\nthe file format is not correct\n"
# define ERROR_INVALID_BORDER   "Error\nMap border is invalid\n"
# define ERROR_INVALID_MOVEMENT "Error\nInvalid Movement Key\n"
# define ERROR_INVALID_MAP      "Error\nIt is not a rectangular map\n"
# define ERROR_FEW_ARGUMENTS    "Error\nToo few arguments\n"
# define ERROR_MANY_ARGUMENTS   "Error\nToo many arguments\n"
# define ERROR_MEMORY           "Error\nMalloc fails\n"
# define ERROR_WRITE            "Error\nWrite fails\n"

#endif //CONSTANTS_H
