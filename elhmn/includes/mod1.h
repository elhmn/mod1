/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:35:16 by bmbarga           #+#    #+#             */
/*   Updated: 2015/05/05 06:24:05 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1- Rediger les prototypes, fonctions principales du programmes.
** 2- Determiner les structures de donnees.
** 3- Attribution des taches.
*/

/*
** Structure globale du main du mod1 (main.c) ::
*/

/*
** 1- get_data											(bmbarga)
** 2- check data error									(bmbarga)
** 3- init t_mod mod									(bmbarga) (mcanal)
** 4- build map											(bmbarga)
** 5- simulation hydrodynamique (temps reel)			(mcanal)
** 		-- Affichage de l'aquarium (ou just map).		(mcanal) / (bmbarga
**  - Destroy t_mod datas								(mcanal) (bmbarga)
*/

#ifndef MOD1_H
# define MOD1_H

# include "elhmn.h"
# include "X.h"
# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define TRUE	1
# define FALSE	0

//# define FT
# define HOME

/*
** Window define
*/

# define S_WIDTH	768
# define S_HEIGH	480
# define WIN_TITLE	"MOD_ONE@zboub42.ass"

/*
** d_end
*/

/*
** key define
*/

# define MOUSE_MOTION_UP	4
# define MOUSE_MOTION_DOWN	5
# define MOUSE_MOTION_RIGHT	7
# define MOUSE_MOTION_LEFT	6

# ifdef FT

#  define K_ESCAPE			53
#  define K_UP 				126		
#  define K_DOWN 			125	
#  define K_RIGHT 			124
#  define K_LEFT 			123

#  define K_ENTER			65293
#  define K_PLUS			69
#  define K_MOINS			78

#  define K_1 				83
#  define K_2 				84
#  define K_4 				86
#  define K_5 				87	
#  define K_7 				89	
#  define K_8 				91

# endif

# ifdef HOME

#  define K_ESCAPE			65307
#  define K_UP 				65362
#  define K_DOWN 			65364
#  define K_RIGHT 			65363
#  define K_LEFT 			65361

#  define K_ENTER 65293
#  define K_PLUS 65451
#  define K_MOINS 65453

#  define K_1 65436
#  define K_2 65433
#  define K_4 65430
#  define K_5 65437
#  define K_7 65429
#  define K_8 65431

#  define K_W 119
#  define K_S 115

# endif

/*
** d_end
*/

/*
** base define
*/

/* DIST est provisoire */
//# define DIST	2500.
# define DIST	2000.
# define FIELD	M_PI / 4.

/*
** d_end
*/

/*
** color define
*/

# define WHITE		0xFFFFFF

# define MASK_R		0xFF0000
# define MASK_G		0x00FF00
# define MASK_B		0x0000FF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLACK		0x000000
# define BLUE		0x0000FF

/*
** d_end
*/

/*
** scale define
*/

//# define SCALE		1500
//# define K_SCALE		15000
//
# define SCALE			2000
# define K_SCALE		10000

# define Z_MAX			20000 //hauteur z max set in file
# define X_MAX			20000 //hauteur z max set in file
# define Y_MAX			20000 //hauteur z max set in file


# define VEL_X			10.
# define VEL_Y			10.
# define VEL_Z			10.
# define ZOOM_IN		20.
# define ZOOM_OUT		20.
# define ROT			M_PI / 100.
# define RC				1.

/*
** d_end
*/

typedef struct	s_mod	t_mod;
typedef unsigned int	t_uint;
typedef struct	s_env	t_env;
typedef struct s_color	t_color;
typedef struct s_lay	t_lay;
typedef struct s_vertx	t_vertx;
typedef struct s_base	t_base;
typedef struct s_obj	t_obj;
typedef struct s_cam	t_cam;
typedef	struct s_glob	t_glob;

struct					s_lay
{
	void		*img;
	int			bpp;
	int			line;
	int			endian;
	int			depht;
};

struct	s_env
{
	void	*mlx;
	void	*win;
};

/*
** API 3D structures
*/

struct		s_vertx
{
	float		x;
	float		y;
	float		z;
	t_color		*col;
	int			end;
};

struct		s_base
{
	t_vertx		o;
	t_vertx		i;
	t_vertx		j;
	t_vertx		k;
};

/*
** attributes strating with "g_" are obj global att;
** attributes strating with "l_" are obj local att;
** attributes strating with "s_" are obj screen att;
*/

struct		s_obj
{
	t_base		l_base;
	t_vertx		*l_mesh;
	t_base		g_base;
	t_vertx		*g_mesh;
	t_vertx		*s_mesh; //can be usefull but i still dont know how and why
};

struct		s_cam
{
	t_base		l_base;
	t_vertx		*l_mesh;
	t_base		g_base;
	t_vertx		*g_mesh;
	t_vertx		*s_mesh; //can be usefull but i still dont know how and why
};

struct		s_glob
{
	t_base	l_base; //init to {0, 0, 0}
	t_base	g_base; //init to {0, 0, 0}
};


struct		s_mod
{
	t_env	e;
	t_list	*tops; //tops les sommets de la map
	int		refresh;
	float	**map; // map de l'espace 3D
	float	**s_map; // coordonnee a l'ecran
	t_base	b; // base
	void	*bg;
	char	*img;
	t_lay	*lay;
	t_glob	glob; //globale basis position
	t_obj	*obj; //tabs with polygonal objects
	t_cam	*cam; //tabs with cameras objects
	int		dist;
	int		scale;
	int		k_scale;
	float	z_top;
	float	z_bot;
};

struct			s_color
{
	unsigned int	alpha;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
};

/*
** get_data.c
*/

void	get_data(t_mod *mod, char *file);

/*
** get_all.c
*/

int		get_all(int fd, char **a);

/*
** data_error.c
*/

void	data_error(t_mod *mod);

/*
** init_mod.c
*/

void	set_map(t_mod *mod);
void	init_env(t_mod *mod);
void	init_image(t_mod *mod);
void	init_hook(t_mod *mod);
void	init_mod(t_mod *mod, char *file);
void	init_map(float **map, t_mod *mod);

/*
** init_scene.c
*/

void 	init_scene(t_mod *mod);
void	init_l_base(t_base *l_base);
void	init_g_base(t_base *g_base);
void	init_centers(t_base *l_base, t_base *g_base);

/*
** init_cam.c
*/

void	init_cam(t_mod *mod);

/*
** init_obj.c
*/

void	init_obj(t_mod *mod);



/*
** map_builder.c
*/

void	map_builder(t_mod *mod);
float	fun_surface(int i, int j, t_mod *mod);

/*
** set_obj.c
*/

void	get_s_map(t_vertx *sm, t_mod *mod);
void	set_obj(t_mod *mod);
void	get_persp(t_vertx **sm, t_vertx *gm, t_mod *mod);
void	obj_set_g_base(t_base *base, t_mod *mod);
void	loc_to_glob(t_obj *obj, t_mod *mod);
void	try_ltog(t_obj *obj);
void	map_to_mesh(float **map, t_obj *obj, t_mod *mod);

/*
** real_time.c fonction callback de mlx_loop_hook
*/

/*
** 0- Fonction loop:
** 1- affichage de la map a l'ecran.
** 2- gere les evenements.
** 3- gere l'ecoulement de l'eau
*/

int		real_time(t_mod *mod);

/*
** destroy_mod.c
*/

void	destroy_mod(t_mod *mod);

/*
** event_handle_01.c
*/

int		mouse_hook(int button, int x, int y, t_mod *mod);
int		motion_notify(int x, int y, t_mod *mod);
int		key_press(int key, t_mod *mod);
int		key_release(int key, t_mod *mod);
int		expose_hook(t_mod *mod);

/*
** draw.c
*/

void		pixel_put_img(t_mod *mod, int x, int y, t_color *col);

/*
** color.c
*/

t_color			*degrad_col(t_color *Ci, t_color *Cf, float Zi, float Zf, float Zn);
void			low_light(t_color *color, unsigned int inc, int sign);
t_color			*init_color(t_color *color, t_uint col);
void			set_color(t_color *col, t_uint r, t_uint g , t_uint b);
t_uint			rgb_to_color(t_uint r, t_uint g, t_uint b);
void			print_color(t_color *color);

/*
** print_map.c
*/

void			put_map(t_mod *mod);
void			print_surface(t_mod *mod);
void			clear_img(t_mod *mod);
void			print_map(float **map);

/*
** print_scene.c
*/

void			print_base(t_base *base);
void			print_mesh(t_vertx *mesh);
void			print_mesh_line(t_vertx *mesh);
void			print_vertx(t_vertx vertx);

/*
** base_oper_01.c
*/

void	move_base_down(t_base *base);
void	move_base_up(t_base *base);
void	move_base_left(t_base *base);
void	move_base_right(t_base *base);
void	move_base_in(t_base *base);
void	move_base_out(t_base *base);

/*
** base_oper_02.c
*/

void	rot_base_z(t_base *base, float rot);
void	rot_base_y(t_base *base, float rot);
void	rot_base_x(t_base *base, float rot);

#endif
