/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:18:18 by kamilprzyby       #+#    #+#             */
/*   Updated: 2022/02/21 18:12:27 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_press(int keycode)
{
	if (keycode == ESC)
		quit();
	else if (keycode == W)
		data()->key.w = 1;
	else if (keycode == S)
		data()->key.s = 1;
	else if (keycode == A)
		data()->key.a = 1;
	else if (keycode == D)
		data()->key.d = 1;
	else if (keycode == LEFT)
		data()->key.left = 1;
	else if (keycode == RIGHT)
		data()->key.right = 1;
	else if (keycode == P)
		data()->key.p = !data()->key.p;
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == W)
		data()->key.w = 0;
	else if (keycode == S)
		data()->key.s = 0;
	else if (keycode == A)
		data()->key.a = 0;
	else if (keycode == D)
		data()->key.d = 0;
	else if (keycode == LEFT)
		data()->key.left = 0;
	else if (keycode == RIGHT)
		data()->key.right = 0;
	return (0);
}

void	hooks(void)
{
	if (data()->key.w == 1)
		move_forward();
	if (data()->key.s == 1)
		move_backwards();
	if (data()->key.a == 1)
		move_left();
	if (data()->key.d == 1)
		move_right();
	if (data()->key.left == 1)
		rotate_left();
	if (data()->key.right == 1)
		rotate_right();
}
