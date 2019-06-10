# include "doom-nukem.h"

/*
** TEMPORARY TESTS DO NOT TOUCH OR MAREK WILL SPANK YOU!
*/
void	init_test_world(t_e *e)
{
	t_obj *tmp;

	e->world.sectornum = 1;
	e->world.sectors = (t_sector *)malloc(sizeof(t_sector));
	e->world.sectors->id = 0;
	e->world.sectors->objectnum = 0;
	e->world.sectors->meshnum = 0;
	tmp = load_obj("assets/house.obj");
	if (tmp)
		e->world.sectors->objects = obj_to_object(tmp, "assets/house_tex.bmp");
	else
		puts("object not loaded");
	if (e->world.sectors->objects)
		e->world.sectors->objectnum++;
	else
		puts("object not transfered");
}

int main()
{
	t_e		env;

	libui_init();
	if (!(env_init(&env)))
		return (-1);
	init_test_world(&env);
	launch_main_menu(&env);
	//load threads
	//run func (state manager or whatever the fuck you want to call it!
	//unload funcs
	//destroy funcs
	env_destroy(&env);
	libui_close();
	return (0);
}
