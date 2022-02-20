/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprzybyl <kprzybyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:18:18 by kamilprzyby       #+#    #+#             */
/*   Updated: 2022/02/20 16:48:32 by kprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_press(int keycode)
{
	if (keycode == ESC)
		quit();
	else if (keycode == W)
		data()->move.w = 1;
	else if (keycode == S)
		data()->move.s = 1;
	else if (keycode == A)
		data()->move.a = 1;
	else if (keycode == D)
		data()->move.d = 1;
	else if (keycode == LEFT)
		data()->move.left = 1;
	else if (keycode == RIGHT)
		data()->move.right = 1;
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == W)
		data()->move.w = 0;
	else if (keycode == S)
		data()->move.s = 0;
	else if (keycode == A)
		data()->move.a = 0;
	else if (keycode == D)
		data()->move.d = 0;
	else if (keycode == LEFT)
		data()->move.left = 0;
	else if (keycode == RIGHT)
		data()->move.right = 0;
	return (0);
}

void	hooks(void)
{
	if (data()->move.w == 1)
		move_forward();
	if (data()->move.s == 1)
		move_backwards();
	if (data()->move.a == 1)
		move_left();
	if (data()->move.d == 1)
		move_right();
	if (data()->move.left == 1)
		rotate_left();
	if (data()->move.right == 1)
		rotate_right();
}
