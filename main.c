/* ******************************************************************************* */
/*                                                                                 */
/*                                                             :::      ::::::::   */
/*   main.c                                                  :+:      :+:    :+:   */
/*                                                         +:+ +:+         +:+     */
/*   By: mpal <mpal@student.42prague.com>                +#+  +:+       +#+        */
/*                                                     +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:17:04 by mpal                   #+#    #+#             */
/*   Updated: 2024/11/02 18:35:40 by mpal                  ###   ########.fr       */
/*                                                                                 */
/* ******************************************************************************* */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int     fd = open("big_line_no_nl", O_RDONLY);
    char    *line;

    if (fd < 0)
    {
        printf("ERROR");
        return (1);
    }
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf ("%s", line);
        free (line);
        line = get_next_line(fd);
    }
    close(fd);
    return(0);
/*    int     fd;
    char    *next_line;
    int     count;

    count = 0;
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }
    while (1)
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            break;
    count++;
    printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
    free(next_line);
    next_line = NULL;
    }
    close(fd);
    return(0);
*/
}
