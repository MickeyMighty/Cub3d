#include "../../includes/cub3d.h"


static void flood_fill(t_cub3d *cub, int pos_x, int pos_y, int target, int nb)
{
	if ((pos_y >= cub->map->size_y || pos_y < 0)
  || (pos_x >= cub->map->size_x[pos_y] || pos_x < 0))
    ft_error(cub, "Map is not close.\n");
	else if (cub->map->map[pos_y][pos_x] == 1
  || cub->map->map[pos_y][pos_x] == nb)
    return ;
  else
  {
    if (cub->map->map[pos_y][pos_x] != 2)
      cub->map->map[pos_y][pos_x] = nb;
    flood_fill(cub, pos_x + 1, pos_y, target, nb);
    flood_fill(cub, pos_x - 1, pos_y, target, nb);
    flood_fill(cub, pos_x, pos_y + 1, target, nb);
    flood_fill(cub, pos_x, pos_y - 1, target, nb);
  }
  return ;
}

int	check_map(t_cub3d *cub)
{
  int     pos_x;
  int     pos_y;
  int     check;

  check = 0;
  cub->map->ticket = 0;
  pos_x = (int)(cub->player->pos_x - 0.5);
  pos_y = (int)(cub->player->pos_y - 0.5);
  cub->map->check_pos_x = pos_x;
  cub->map->check_pos_y = pos_y;
	if (cub->map->size_y < 3 || cub->map->size_x_max < 3)
      return (0);
  while (check < cub->map->size_y)
  {
    if (cub->map->size_x[check] < 3)
      return (0);
    check++;
  }
	if (pos_y >= cub->map->size_y || pos_y < 0)
    return (0);
	if (pos_x >= cub->map->size_x[pos_y] || pos_x < 0)
    return (0);
  flood_fill(cub, pos_x, pos_y, 0, 9);
  flood_fill(cub, pos_x, pos_y, 9, 0);
  return (1);
}
