/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:16:38 by lmunoz-q          #+#    #+#             */
/*   Updated: 2019/08/11 20:16:39 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "world.h"
# include "camera.h"
# include "graphics.h"
# include "inventory_manager.h"

# define DEFAULT_MAX_WALK_SPEED	0.15
# define DEFAULT_MAX_RUN_SPEED	0.4
# define DEFAULT_MAX_LIFE		100

# define DEFAULT_FRICTION		0.90

# define DEFAULT_JUMP_FORCE		0.45

# define ACC_GRAVITY			0
# define ACC_PLAYER_WALK		0.05
# define ACC_PLAYER_JUMP		2
# define ACC_MODIFIER			3
# define ACCELERATIONS			4

# define CAMERA_HEIGHT		4

typedef struct		s_player_stats
{
	int				life;
	int				max_life;
	int				armor;
	int				stamina;
	int				max_stamina;
	int				kill_count;
	int				score;
	char			script_data[64];
}					t_player_stats;

typedef struct		s_player
{
	t_player_entity	entity;
	t_vec3d			acceleration[ACCELERATIONS];
	double			max_speed;
	t_bool			is_running;
	t_player_stats	stats;
	t_item			*main_hand;
}					t_player;

void				init_player(t_player *p, t_world *world);
void				update_entity_sector(t_eidos_frame *p, t_world *world);
void				render_player(t_player	*p, SDL_Surface *s, t_world *world,
					t_camera *cam);

#endif
