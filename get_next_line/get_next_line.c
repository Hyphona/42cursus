/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/08 10:01:18 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    //static int  line;
    
    if (!fd || BUFFER_SIZE <= 0)
        return ((void *) 0);
    return ((void *) 0);
}

/*
#include <stdio.h>
int main(void)
{
    printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
}
*/