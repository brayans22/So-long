#include "../headers/graphic.h"

int ft_destroy(t_igraphic *igraphic)
{
    mlx_destroy_window(igraphic->mlx_ptr, igraphic->win_ptr);
    //mlx_destroy_display(igraphic->mlxptr);
    free(igraphic->mlx_ptr);
    exit(EXIT_SUCCESS);
    return (0);
}

int detect_key(int key_sysm, t_igraphic *igraphic)
{
    (void)igraphic;
    printf("Pressed key: %d\\n", key_sysm);
    return (0);
}