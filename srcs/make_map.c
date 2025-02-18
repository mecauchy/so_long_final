/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:43:59 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 12:51:54 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	assign_map(t_list *lst)
{
	lst->img_wall = mlx_xpm_file_to_image(lst->mlx, "textures/wall.xpm",
			&lst->img_longueur, &lst->img_largeur);
	lst->img_coin = mlx_xpm_file_to_image(lst->mlx, "textures/collectible.xpm",
			&lst->img_longueur, &lst->img_largeur);
	lst->img_exit = mlx_xpm_file_to_image(lst->mlx, "textures/exit.xpm",
			&lst->img_longueur, &lst->img_largeur);
	lst->img_floor = mlx_xpm_file_to_image(lst->mlx, "textures/floor.xpm",
			&lst->img_longueur, &lst->img_largeur);
	lst->img_perso = mlx_xpm_file_to_image(lst->mlx, "textures/player.xpm",
			&lst->img_longueur, &lst->img_largeur);
	lst->img_default = mlx_xpm_file_to_image(lst->mlx, "textures/default.xpm",
			&lst->img_longueur, &lst->img_largeur);
	if (!lst->img_wall || !lst->img_coin || !lst->img_exit || !lst->img_floor
		|| !lst->img_perso || !lst->img_default)
	{
		free_all_game(lst);
		exit(EXIT_FAILURE);
	}
	lst->player.player_up = mlx_xpm_file_to_image(lst->mlx,
			"textures/player_up.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->player.player_down = mlx_xpm_file_to_image(lst->mlx,
			"textures/player_down.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->player.player_left = mlx_xpm_file_to_image(lst->mlx,
			"textures/player_left.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->player.player_right = mlx_xpm_file_to_image(lst->mlx,
			"textures/player_right.xpm", &lst->img_longueur, &lst->img_largeur);
	if (!lst->player.player_up || !lst->player.player_down
		|| !lst->player.player_left || !lst->player.player_right)
	{
		free_all_game(lst);
		exit(EXIT_FAILURE);
	}
}

int	create_map(t_list *lst)
{
	char	*step;
	char	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!lst->map)
		exit(1);
	while (y < lst->largeur_map)
	{
		x = 0;
		while (x < lst->longueur_map)
		{
			if (lst->map[y][x] == '1')
			{
				if (lst->img_wall == NULL)
					free_all_game(lst);
				mlx_put_image_to_window(lst->mlx, lst->window,
					lst->img_wall, x * 32, y * 32);
			}
			if (lst->map[y][x] == '0')
				mlx_put_image_to_window(lst->mlx, lst->window,
					lst->img_floor, x * 32, y * 32);
			if (lst->map[y][x] == 'C')
				mlx_put_image_to_window(lst->mlx, lst->window,
					lst->img_coin, x * 32, y * 32);
			if (lst->map[y][x] == 'E')
				mlx_put_image_to_window(lst->mlx, lst->window,
					lst->img_exit, x * 32, y * 32);
			if (y == lst->y && x == lst->x)
				mlx_put_image_to_window(lst->mlx, lst->window,
					lst->img_perso, x * 32, y * 32);
			x++;
		}
		y++;
	}
	tmp = ft_itoa(lst->move);
	step = ft_strjoin("steps : ", tmp);
	free(tmp);
	mlx_string_put(lst->mlx, lst->window, 10, 10, 0xFFFFFF, "ESC to quit");
	mlx_string_put(lst->mlx, lst->window, 10, 30, 0xFF0099, step);
	free(step);
	return (1);
}

void	init_lst(t_list *lst)
{
	lst->img_longueur = 32;
	lst->img_largeur = 32;
	lst->longueur_map = 0;
	lst->largeur_map = 0;
	lst->keycode = 0;
	lst->move = 0;
	lst->x = 0;
	lst->y = 0;
	lst->map_info.nb_coin = 0;
	lst->map_info.nb_exit = 0;
	lst->map_info.nb_player = 0;
	lst->map_info.nb_collectible = 0;
	lst->map_info.nb_collectible_found = 0;
	lst->map_info.nb_exit_found = 0;
}

void	init_game(t_list *lst)
{
	ft_bzero(lst, sizeof(lst));
	lst->window = NULL;
	lst->map = NULL;
	lst->img_wall = NULL;
	lst->img_exit = NULL;
	lst->img_coin = NULL;
	lst->img_perso = NULL;
	lst->img_default = NULL;
	lst->img_floor = NULL;
	lst->player.player_up = NULL;
	lst->player.player_down = NULL;
	lst->player.player_left = NULL;
	lst->player.player_right = NULL;
}
