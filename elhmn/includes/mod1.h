/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:35:16 by bmbarga           #+#    #+#             */
/*   Updated: 2015/07/03 13:19:16 by bmbarga          ###   ########.fr       */
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
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <time.h>

# define TRUE			1
# define FALSE			0
# define ABS(x) (x < 0) ? -x : x

/*
** # define FT
*/


# define HOME

/*
** Window define
*/

# define WIN_TITLE		"MOD_ONE@zboub42.ass"

/*
** d_end
*/

/*
** key define
*/

# ifdef FT

#  define S_WIDTH		768
#  define S_HEIGH		600

#  define K_ESCAPE		53
#  define K_TAB			48
#  define K_UP			126
#  define K_DOWN		125
#  define K_RIGHT		124
#  define K_LEFT		123

#  define K_ENTER		36
#  define K_BP			51
#  define K_PLUS		69
#  define K_MOINS		78

#  define K_1			83
#  define K_2			84
#  define K_4			86
#  define K_5			87
#  define K_7			89
#  define K_8			91

#  define K_U1			18
#  define K_U2			19
#  define K_U3			20
#  define K_U4			21

#  define K_W			13
#  define K_S			1

# endif

# ifdef HOME

#  define S_WIDTH		768
#  define S_HEIGH		600

#  define K_ESCAPE		65307
#  define K_TAB			65289
#  define K_UP			65362
#  define K_DOWN		65364
#  define K_RIGHT		65363
#  define K_LEFT		65361

#  define K_ENTER		65293
#  define K_BP			65288
#  define K_PLUS		65451
#  define K_MOINS		65453

#  define K_1			65436
#  define K_2			65433
#  define K_4			65430
#  define K_5			65437
#  define K_7			65429
#  define K_8			65431

#  define K_U1			49
#  define K_U2			50
#  define K_U3			51
#  define K_U4			52
#  define K_W			119
#  define K_S			115

# endif

/*
** d_end
*/

/*
** base define
*/

# define DIST			3250.
# define FIELD			M_PI / 4.
# define RAY			10.
# define MAX_DIV		300.
# define SPEED			(SCALE / K_SCALE)
# define UPPER_DIV		1870.
# define ST				3
# define MAX_V			10000.
# define TRANS_NBR		7.

# define H_PER			2.

/*
** d_end
*/

/*
** color define
*/

# define WHITE			0x00FFFFFF

# define MASK_A			0xFF000000
# define MASK_R			0x00FF0000
# define MASK_G			0x0000FF00
# define MASK_B			0x000000FF
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define BLACK			0x00000000
# define BLUE			0x000000FF
# define COL			0x99AAAAFF
# define COLI			0x00440033
# define COLF			0x00FF6666
# define COL_BORD		0x993333AA

/*
** d_end
*/

/*
** scale define
*/

# define SCALE			400
# define K_SCALE		4000

# define Z_MAX			20000
# define X_MAX			20000
# define Y_MAX			20000

# define VEL_X			30.
# define VEL_Y			30.
# define VEL_Z			30.
# define VEL_WZ			1.
# define ZOOM_IN		50.
# define ZOOM_OUT		50.
# define ROT			M_PI / 10.
# define RC				1.

/*
** d_end
*/

typedef struct s_mod	t_mod;
typedef unsigned int	t_uint;
typedef struct s_env	t_env;
typedef struct s_color	t_color;
typedef struct s_lay	t_lay;
typedef struct s_vertx	t_vertx;
typedef struct s_base	t_base;
typedef struct s_obj	t_obj;
typedef struct s_glob	t_glob;
typedef struct s_top	t_top;
typedef struct s_ring	t_ring;
typedef struct s_cam	t_cam;
typedef struct s_lstpl	t_lstpl;

typedef void			(*t_initlm)(t_mod*, t_obj*);
typedef void			(*t_gbase)(t_mod*, t_obj*);

enum					e_ecoul
{
	VOID,
	WAVE,
	UP,
	RAIN
};

struct					s_lay
{
	void		*img;
	int			bpp;
	int			line;
	int			endian;
	int			depht;
};

/*
** list plane
*/

struct					s_lstpl
{
	t_obj		*plan;
	int			i;
	t_lstpl		*next;
};

struct					s_env
{
	void		*mlx;
	void		*win;
};

/*
** API 3D structures
*/

struct					s_vertx
{
	float		x;
	float		y;
	float		z;
	t_color		*col;
	int			act;
	int			vel;
	float		dirz;
	int			dirxy;
	int			col_s;
	int			end;
};

struct					s_base
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

struct					s_obj
{
	t_base		l_base;
	t_vertx		*l_mesh;
	t_base		g_base;
	t_vertx		*g_mesh;
	t_vertx		*s_mesh;
	int			size;
};

struct					s_cam
{
	t_base		l_base;
	t_vertx		*l_mesh;
	t_base		g_base;
	t_vertx		*g_mesh;
	t_vertx		*s_mesh;
};

struct					s_glob
{
	t_base		l_base;
	t_base		g_base;
};

struct					s_color
{
	t_uint		alpha;
	t_uint		color;
	t_uint		r;
	t_uint		g;
	t_uint		b;
};

struct					s_ring
{
	t_obj		*obj;
	int			st;
	int			r_vel;
};

struct					s_top
{
	t_ring		*ring;
	t_vertx		vertx;
	int			div;
};

struct					s_mod
{
	t_env		e;
	int			vel_p;
	int			slowMo;
	t_list		*tops;
	t_top		*z_tops;
	int			refresh;
	float		**map;
	t_base		b;
	void		*buf1;
	void		*buf2;
	void		*buf3;
	void		*buf4;
	char		*img1;
	char		*img2;
	char		*img3;
	char		*img4;
	t_lay		*lay;
	t_glob		glob;
	t_obj		*obj;
	t_obj		*water;
	t_obj		*rain;
	t_obj		*wave;
	t_lstpl		*plane;
	int			tran_sz;
	int			dist;
	int			pos;
	int			scale;
	int			k_scale;
	float		z_top;
	float		z_gtop;
	float		z_bot;
	int			ecoul;
	int			ring_nbr;
	t_color		*tmp;
	t_base		base_tmp;
	float		**img_tab;
	int			ind_e;
	int			ind_r;
	time_t		stime;
	time_t		etime;
	t_color		*col;
	t_color		*col_bord;
	t_color		*col_lim;
	int			upd_sm;
	int			bol;
	t_obj		**trans;
	int			act;
	int			h;
	int			ind_h;
	float		*lvl;
	int			ind_lvl;
	int			pt_surf;
	t_uint		st_lm;
	int			check;
};

/*
** get_data.c
*/

void					get_data(t_mod *mod, char *file);

/*
** get_all.c
*/

int						get_all(int fd, char **a);

/*
** data_error.c
*/

void					data_error(t_mod *mod);

/*
** init_mod.c
*/

void					init_env(t_mod *mod);
void					init_image(t_mod *mod);
void					init_hook(t_mod *mod);
void					init_mod(t_mod *mod, char *file);

/*
** init_mod_02.c
*/

void					init_map(float **map, t_mod *mod);
float					**init_imgtab(void);
int						tops_len(t_mod *mod);
t_top					*tops(t_mod *mod);
void					set_map(t_mod *mod);

/*
** init_scene.c
*/

void					init_scene(t_mod *mod);
void					init_l_base(t_base *l_base);
void					init_g_base(t_base *g_base);
void					init_centers(t_base *l_base, t_base *g_base);

/*
** init_cam.c
*/

void					init_cam(t_mod *mod);

/*
** map_builder.c
*/

void					map_builder(t_mod *mod);
void					get_lvl(t_mod *mod);
float					fun_surface(int i, int j, t_mod *mod);

/*
** set_obj.c
*/

void					init_obj(t_mod *m, t_obj **o, t_initlm i, t_gbase s);
void					get_sm(t_mod *mod, t_obj *obj);
void					get_persp(t_mod *mod, t_obj *obj);
void					loc_to_glob(t_mod *mod, t_obj *obj);

/*
** real_time.c fonction callback de mlx_loop_hook
*/

/*
** 0- Fonction loop:
** 1- affichage de la map a l'ecran.
** 2- gere les evenements.
** 3- gere l'ecoulement de l'eau
*/

int						real_time(t_mod *mod);
void					on_window(t_mod *mod, int b1, int b2, int b3);
void					update_sm(t_mod *mod, t_obj *obj);

/*
** real_wave.c
*/

void					real_wave(t_mod *mod);

/*
** real_rain.c
*/

void					real_rain(t_mod *mod);

/*
** real_up.c
*/

void					real_up(t_mod *mod);
void					put_trans(t_mod *mod);

/*
** real_up_tools.c
*/

void					init_trans(t_mod *mod, t_initlm initlm);

/*
** real_void.c
*/

void					real_void(t_mod *mod);
void					tab_zero(float **tab);

/*
** destroy_mod.c
*/

void					del_tab(float **tab);
void					del_map(float **map);
void					del_trans(t_obj ***trans);
void					del_rain(t_mod *mod);
void					del_plane(t_mod *mod);
void					del_tops(void *elem, size_t size);
void					destroy_mod(t_mod *mod);

/*
** event_handle_01.c
*/

int						mouse_hook(int button, int x, int y, t_mod *mod);
int						motion_notify(int x, int y, t_mod *mod);
int						key_press(int key, t_mod *mod);
int						key_release(int key, t_mod *mod);
int						expose_hook(t_mod *mod);

/*
** draw.c
*/

void					pixel_put_img(t_mod *mod, int x, int y, t_color *col, char *img);

/*
** color.c
*/

t_color					*degrad_col(t_color *Ci, t_color *Cf, float Zi, float Zf, float Zn);
void					low_light(t_color *color, t_uint inc, int sign);
t_color					*init_color(t_color *color, t_uint col);
void					set_color(t_color *col, t_uint r, t_uint g , t_uint b);
t_uint					rgb_to_color(t_uint r, t_uint g, t_uint b);
void					print_color(t_color *color);

/*
** print_map.c
*/

void					put_map(t_mod *mod, char *img);
void					print_surface(t_mod *mod, char *img);
void					clear_img(t_mod *mod, char *img);
void					print_map(float **map);

/*
** print_scene.c
*/

void					print_base(t_base *base);
void					print_mesh(t_vertx *mesh);
void					print_mesh_line(t_vertx *mesh);
void					print_vertx(t_vertx vertx);

/*
** base_oper_01.c
*/

void					move_base_down(t_base *base);
void					move_base_up(t_base *base);
void					move_base_left(t_base *base);
void					move_base_right(t_base *base);
void					move_base_in(t_base *base);
void					move_base_out(t_base *base);

/*
** base_oper_02.c
*/

void					rot_base_z(t_base *base, float rot);
void					rot_base_y(t_base *base, float rot);
void					rot_base_x(t_base *base, float rot);

/*
** dynamic_up.c
*/

void					water_init(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim);
void					dynamic_up(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim);
void					move_water_up(t_base *base);
void					init_water_bases(t_mod *mod);
void					init_water_meshes(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim);

/*
** dynamic_rain.c
*/

void					dynamic_rain(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim, int i);
void					init_water_meshes_rain(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim);
void					water_init_rain(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim);

/*
** init_rain_tools.c
*/

void					init_rain_meshes(t_mod *mod, t_color *col, int i);
void					set_rain_meshes(t_mod *mod, t_color *col, int i);
void					init_rain_bases(t_mod *mod, int i);

/*
** dynamic_wave.c
*/

void					dynamic_wave(t_mod *mod);

/*
** init_wave_tools.c
*/

void					init_wave_bases(t_mod *mod);
void					init_wave_meshes(t_mod *mod);
void					set_wave_meshes(t_mod *mod);

/*
** init_lm.c
*/

void					init_lm_surf(t_mod *mod, t_obj *obj);
void					init_lm_trans_up(t_mod *mod, t_obj *obj);
void					init_lm_trans(t_mod *mod, t_obj *obj);
void					init_lm_rain(t_mod *mod, t_obj *rain);
void					init_lm_trans_wave(t_mod *mod, t_obj *obj);

/*
** set_lm.c
*/

void					set_lm_up(t_mod *mod, t_vertx *lm);
void					set_lm_rain(t_mod *mod, t_vertx *lm);
void					gen_part(t_mod *mod, t_vertx *lm);

/*
** set_gbase.c
*/

void					set_gbase_surf(t_mod *mod, t_obj *obj);
void					set_gbase_trans(t_mod *mod, t_obj *obj);

/*
** draw_obj.c
*/

void					draw_obj(t_mod *mod, t_obj *obj, char *img);

#endif
