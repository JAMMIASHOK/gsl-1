/* sort/gsl_sort_vector_long.h
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Thomas Walter, Brian Gough
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __GSL_SORT_VECTOR_LONG_H__
#define __GSL_SORT_VECTOR_LONG_H__

#include <stdlib.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_vector_long.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

void gsl_sort_vector_long (gsl_vector_long * v);
int gsl_sort_vector_long_index (gsl_permutation * p, const gsl_vector_long * v);

int gsl_sort_vector_long_smallest (long * dest, size_t k, const gsl_vector_long * v);
int gsl_sort_vector_long_largest (long * dest, size_t k, const gsl_vector_long * v);

int gsl_sort_vector_long_smallest_index (size_t * p, size_t k, const gsl_vector_long * v);
int gsl_sort_vector_long_largest_index (size_t * p, size_t k, const gsl_vector_long * v);

__END_DECLS

#endif /* __GSL_SORT_VECTOR_LONG_H__ */
