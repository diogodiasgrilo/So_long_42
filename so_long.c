/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:26:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/13 12:47:04 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My Window");
    
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    
    mlx_loop(mlx_ptr);
    
    return 0;
}