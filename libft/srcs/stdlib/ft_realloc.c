/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:28:11 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/28 16:10:21 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdlib.h>
** SYNOPSIS: memory reallocation
**
** DESCRIPTION:
**      This is the implementation of the ft_realloc() 
**  function, which is used to reallocate memory for 
**  a previously allocated block of memory.
**
**      The function takes two arguments: a pointer to the 
**  previously allocated block of memory, and the new size 
**  of the block of memory. If the pointer is NULL, the 
**  function behaves like malloc() and allocates a new block 
**  of memory of the specified size. If the size is 0, the 
**  function behaves like free() and frees the previously 
**  allocated block of memory.
**
**  If the pointer is not NULL and the size is greater than 0, 
**  the function allocates a new block of memory of the specified 
**  size, copies the contents of the old block of memory to the 
**  new block of memory using ft_memcpy(), and frees the old 
**  block of memory. The function then returns a pointer to 
**  the new block of memory.
*/

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	ft_memmove(new_ptr, ptr, size);
	return (new_ptr);
}
