/* blas/source_gemv_r.h
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman
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

{
    size_t i, j;
    size_t ix, iy;
    size_t lenX, lenY;

    if (alpha == 0.0 && beta == 1.0)
	return;

    if (TransA == CblasNoTrans) {
	lenX = N;
	lenY = M;
    } else {
	lenX = M;
	lenY = N;
    }

    /* form  y := beta*y */
    if (beta == 0.0) {
	iy = OFFSET(lenY, incY);
	for (i = 0; i < lenY; i++) {
	    Y[iy] = 0.0;
	    iy += incY;
	}
    } else if (beta != 1.0) {
	iy = OFFSET(lenY, incY);
	for (i = 0; i < lenY; i++) {
	    Y[iy] *= beta;
	    iy += incY;
	}
    }

    if (alpha == 0.0)
	return;

    if ((order == CblasRowMajor && TransA == CblasNoTrans)
	|| (order == CblasColMajor && TransA == CblasTrans)) {
	/* form  y := alpha*A*x + y */
	iy = OFFSET(lenY, incY);
	for (i = 0; i < lenY; i++) {
	    BASE temp = 0.0;
	    ix = OFFSET(lenX, incX);
	    for (j = 0; j < lenX; j++) {
		temp += X[ix] * A[lda * i + j];
		ix += incX;
	    }
	    Y[iy] += alpha * temp;
	    iy += incY;
	}
    } else if ((order == CblasRowMajor && TransA == CblasTrans)
	       || (order == CblasColMajor && TransA == CblasNoTrans)) {
	/* form  y := alpha*A'*x + y */
	ix = OFFSET(lenX, incX);
	for (j = 0; j < lenX; j++) {
	    const BASE temp = alpha * X[ix];
	    if (temp != 0.0) {
		iy = OFFSET(lenY, incY);
		for (i = 0; i < lenY; i++) {
		    Y[iy] += temp * A[lda * j + i];
		    iy += incY;
		}
	    }
	    ix += incX;
	}
    } else {
	BLAS_ERROR("unrecognized operation");
    }
}
