
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

/* TYPE LINES */
# define TYPE_LINE_EOF 'F'
# define TYPE_LINE_FIRST 'Z'
# define TYPE_LINE_MIDDLE 'M'

/* STATUS GAME */
# define PLAYING 'R'
# define ENDGAME 'K'
# define START 'T'

/* ERROR VALUES */
# define ERROR -1

/* ERROR MESSAGES */
# define ERROR_OPEN_FILE "Error\n file cannot open correctly\n"
# define ERROR_CLOSE_FILE "Error\n file cannot be close correctly\n"
# define ERROR_ENTRANCE "Error\n more than one entrace\n"
# define ERROR_EXIT "Error\n more than one exit\n"
# define ERROR_INVALID_PATH "Error\n There is no valid path on the map\n"
# define ERROR_INVALID_BORDER "Error\n Map border is invalid\n"
# define ERROR_INVALID_MOVEMENT "Error\n Invalid Movement Key"
# define ERROR_INVALID_MAP "Error\n It is not a rectangular map\n"
# define ERROR_FEW_ARGUMENTS "Error\n Too few arguments\n"
# define ERROR_MANY_ARGUMENTS "Error\n Too many arguments\n"
# define ERROR_MEMORY "Error\n there is not enough memory\n"

# define SUCCESSFUL 3

#endif //CONSTANTS_H
