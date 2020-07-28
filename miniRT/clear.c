int		ft_close_program(t_scene *ascene)
{
	ft_terminator(ascene);
	ft_destroy_images(ascene);
	exit(0);
}

void	ft_terminator(t_scene *ascene)
{
	void	*current;
	void	*next;

	current = ascene->cam_list;
	while (current)
	{
		next = ((t_camera *)current)->next;
		free(current);
		current = next;
	}
	current = ascene->light_list;
	while (current)
	{
		next = ((t_light *)current)->next;
		free(current);
		current = next;
	}
	current = ascene->object_list;
	while (current)
	{
		next = ((t_obj_link *)current)->next;
		free(((t_obj_link *)current)->object);
		free((t_obj_link *)current);
		current = next;
	}
}

void	ft_destroy_images(t_scene *ascene)
{
	t_img_link	*il;
	t_img_link	*next;

	il = ascene->img_list;
	while (il->nbr < ascene->cam_nbr)
	{
		mlx_destroy_image(ascene->mlx, il->ip);
		next = il->next;
		free(il);
		il = next;
	}
}
