/**************************************************************************************************
*                                                                                                 *
* This file is part of HPMPC.                                                                     *
*                                                                                                 *
* HPMPC -- Library for High-Performance implementation of solvers for MPC.                        *
* Copyright (C) 2014 by Technical Univeristy of Denmark. All rights reserved.                     *
*                                                                                                 *
* HPMPC is free software; you can redistribute it and/or                                          *
* modify it under the terms of the GNU Lesser General Public                                      *
* License as published by the Free Software Foundation; either                                    *
* version 2.1 of the License, or (at your option) any later version.                              *
*                                                                                                 *
* HPMPC is distributed in the hope that it will be useful,                                        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                                            *
* See the GNU Lesser General Public License for more details.                                     *
*                                                                                                 *
* You should have received a copy of the GNU Lesser General Public                                *
* License along with HPMPC; if not, write to the Free Software                                    *
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA                  *
*                                                                                                 *
* Author: Gianluca Frison, giaf (at) dtu.dk                                                       *
*                                                                                                 *
**************************************************************************************************/

#include <stdio.h>

#include "../problem_size.h"
#include "blas_s_codegen.h"
#include "../include/block_size.h"

#define NZ NX+NU+1
#define PNZ S_MR*((NZ+S_MR-NU%S_MR+S_MR-1)/S_MR);



void main()
	{
	
	const int bs = S_MR;
	
	int jj;
	
	int nx = NX;
	int nu = NU;
	int N = NN;
	
	int nz  = nx+nu+1;
	int sda = PNZ;
	
	FILE *f;
    f = fopen("sricposv_codegen.c", "w"); // a

	fprintf(f, "/**************************************************************************************************\n");
	fprintf(f, "*                                                                                                 *\n");
	fprintf(f, "* This file is part of HPMPC.                                                                     *\n");
	fprintf(f, "*                                                                                                 *\n");
	fprintf(f, "* HPMPC -- Library for High-Performance implementation of solvers for MPC.                        *\n");
	fprintf(f, "* Copyright (C) 2014 by Technical Univeristy of Denmark. All rights reserved.                     *\n");
	fprintf(f, "*                                                                                                 *\n");
	fprintf(f, "* HPMPC is free software; you can redistribute it and/or                                          *\n");
	fprintf(f, "* modify it under the terms of the GNU Lesser General Public                                      *\n");
	fprintf(f, "* License as published by the Free Software Foundation; either                                    *\n");
	fprintf(f, "* version 2.1 of the License, or (at your option) any later version.                              *\n");
	fprintf(f, "*                                                                                                 *\n");
	fprintf(f, "* HPMPC is distributed in the hope that it will be useful,                                        *\n");
	fprintf(f, "* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *\n");
	fprintf(f, "* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                                            *\n");
	fprintf(f, "* See the GNU Lesser General Public License for more details.                                     *\n");
	fprintf(f, "*                                                                                                 *\n");
	fprintf(f, "* You should have received a copy of the GNU Lesser General Public                                *\n");
	fprintf(f, "* License along with HPMPC; if not, write to the Free Software                                    *\n");
	fprintf(f, "* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA                  *\n");
	fprintf(f, "*                                                                                                 *\n");
	fprintf(f, "* Author: Gianluca Frison, giaf (at) dtu.dk                                                       *\n");
	fprintf(f, "*                                                                                                 *\n");
	fprintf(f, "**************************************************************************************************/\n");
	fprintf(f, "\n");
	fprintf(f, "#include <stdlib.h>\n");
	fprintf(f, "#include <stdio.h>\n");
	fprintf(f, "\n");
/*	fprintf(f, "#include \"../include/blas_d.h\"\n");*/
	fprintf(f, "#include \"../include/kernel_s_lib2.h\"\n");
	fprintf(f, "#include \"../include/kernel_s_lib4.h\"\n");
	fprintf(f, "\n");
/*	fprintf(f, "void dgemm_%dx%dx%d(float *A, int lda, float *B, int ldb, float *C, int ldc)\n", m, n, k);*/
	fprintf(f, "void sricposv_mpc(int nx, int nu, int N, int sda, float **hpBAbt, float **hpQ, float **hux, float *pL, float *pBAbtL, int *info)\n");
	fprintf(f, "	{\n");
	fprintf(f, "	if(!(nx==%d && nu==%d && N==%d))\n", nx, nu, N);
	fprintf(f, "		{\n");
	fprintf(f, "		printf(\"\\nError: solver not generated for that problem size\\n\\n\");\n");
	fprintf(f, "		exit(1);\n");
	fprintf(f, "		}\n");
	fprintf(f, "	\n");
	fprintf(f, "	float *pA, *pB, *pC, *x, *y, *ptrA, *ptrx;\n");
	fprintf(f, "	\n");
	fprintf(f, "	int i, j, k, ii, jj, kk;\n");
	fprintf(f, "	\n");
/*	fprintf(f, "	const int bs = D_MR;\n");*/
/*	fprintf(f, "	\n");*/
	fprintf(f, "	/* factorization and backward substitution */\n");
	fprintf(f, "	\n");
	fprintf(f, "	/* final stage */\n");
	fprintf(f, "	\n");
	fprintf(f, "	/*spotrf */\n");
/*	spotrf_p_scopy_p_t_lib(nz, nu, hpQ[N], sda, pL, sda);*/
	fprintf(f, "	pC = hpQ[%d];\n", N);
	spotrf_p_scopy_p_t_code_generator(f, nz, nu);
	fprintf(f, "	\n");
	fprintf(f, "	/* middle stages */\n");
	fprintf(f, "	for(ii=0; ii<N-1; ii++)\n");
	fprintf(f, "		{\n");
	fprintf(f, "		\n");
	fprintf(f, "		/* strmm */\n");
/*		strmm_ppp_lib(nz, nx, nu, hpBAbt[N-ii-1], sda, pL, sda, pBAbtL, sda);*/
	fprintf(f, "		pA = hpBAbt[%d-ii];\n", N-1);
	fprintf(f, "		pB = pL;\n");
	fprintf(f, "		pC = pBAbtL;\n");
	strmm_ppp_code_generator(f, nz, nx, nu);
	fprintf(f, "		\n");
	fprintf(f, "		/* ssyrk */\n");
/*		ssyrk_ppp_lib(nz, nx, pBAbtL, sda, hpQ[N-ii-1], sda);*/
	fprintf(f, "		pA = pBAbtL;\n");
	fprintf(f, "		pC = hpQ[%d-ii];\n", N-1);
	ssyrk_ppp_code_generator(f, nz, nz, nx);
	fprintf(f, "		\n");
	fprintf(f, "		/* spotrf */\n");
/*		dpotrf_p_dcopy_p_t_lib(nz, nu, hpQ[N-ii-1], sda, pL, sda);*/
	fprintf(f, "		pC = hpQ[%d-ii];\n", N-1);
	spotrf_p_scopy_p_t_code_generator(f, nz, nu);
	fprintf(f, "		\n");
	fprintf(f, "		}\n");
	fprintf(f, "	\n");
	fprintf(f, "	/* initial stage */\n");
	fprintf(f, "	\n");
	fprintf(f, "		/* strmm */\n");
/*		strmm_ppp_lib(nz, nx, nu, hpBAbt[N-ii-1], sda, pL, sda, pBAbtL, sda);*/
	fprintf(f, "		pA = hpBAbt[%d-ii];\n", N-1);
	fprintf(f, "		pB = pL;\n");
	fprintf(f, "		pC = pBAbtL;\n");
	strmm_ppp_code_generator(f, nz, nx, nu);
	fprintf(f, "		\n");
	fprintf(f, "		/* ssyrk */\n");
/*		ssyrk_ppp_lib(nz, nx, pBAbtL, sda, hpQ[N-ii-1], sda);*/
	fprintf(f, "		pA = pBAbtL;\n");
	fprintf(f, "		pC = hpQ[%d-ii];\n", N-1);
	ssyrk_ppp_code_generator(f, nz, nu, nx);
	fprintf(f, "		\n");
	fprintf(f, "		/* dpotrf */\n");
/*		spotrf_p_scopy_p_t_lib(nz, nu, hpQ[N-ii-1], sda, pL, sda);*/
	fprintf(f, "		pC = hpQ[%d-ii];\n", N-1);
	spotrf_p_code_generator(f, nz, nu);
	fprintf(f, "	\n");
	fprintf(f, "	\n");
	fprintf(f, "	\n");
/*	fprintf(f, "	d_print_pmat(%d, %d, %d, hpQ[0], %d);\n", nz, nz, bs, sda);*/
/*	fprintf(f, "	d_print_pmat(%d, %d, %d, hpQ[1], %d);\n", nz, nz, bs, sda);*/
/*	fprintf(f, "	d_print_pmat(%d, %d, %d, hpQ[%d], %d);\n", nz, nz, bs, N-1, sda);*/
/*	fprintf(f, "	d_print_pmat(%d, %d, %d, hpQ[%d], %d);\n", nz, nz, bs, N, sda);*/
/*	fprintf(f, "	\n");*/
	fprintf(f, "	/* forward substitution */\n");
	fprintf(f, "	for(ii=0; ii<N; ii++)\n");
	fprintf(f, "		{\n");
	fprintf(f, "		\n");
	fprintf(f, "		/* */\n");
	fprintf(f, "		for(jj=0; jj<%d; jj+=4)\n", nu-3);
	fprintf(f, "			{\n");
	fprintf(f, "			hux[ii][jj+0] = hpQ[ii][%d+%d*(jj+0)];\n", ((nu+nx)/bs)*bs*sda+(nu+nx)%bs, bs);
	fprintf(f, "			hux[ii][jj+1] = hpQ[ii][%d+%d*(jj+1)];\n", ((nu+nx)/bs)*bs*sda+(nu+nx)%bs, bs);
	fprintf(f, "			hux[ii][jj+2] = hpQ[ii][%d+%d*(jj+2)];\n", ((nu+nx)/bs)*bs*sda+(nu+nx)%bs, bs);
	fprintf(f, "			hux[ii][jj+3] = hpQ[ii][%d+%d*(jj+3)];\n", ((nu+nx)/bs)*bs*sda+(nu+nx)%bs, bs);
	fprintf(f, "			}\n");
	for(jj=0; jj<nu%4; jj++)
		{
	fprintf(f, "		hux[ii][%d] = hpQ[ii][%d];\n", (nu/4)*4+jj, ((nu+nx)/bs)*bs*sda+(nu+nx)%bs+bs*((nu/4)*4+jj));
		}
/*	fprintf(f, "		d_print_mat(%d, 1, hux[ii], %d);\n", nx+nu, nx+nu);*/
	fprintf(f, "		\n");
	fprintf(f, "		/* sgemv */\n");
/*		sgemv_p_t_lib(nx, nu, nu, &hpQ[ii][(nu/bs)*bs*sda+nu%bs], sda, &hux[ii][nu], &hux[ii][0], 1);*/
	fprintf(f, "		pA = &hpQ[ii][%d];\n", (nu/bs)*bs*sda+nu%bs);
	fprintf(f, "		x = &hux[ii][%d];\n", nu);
	fprintf(f, "		y = &hux[ii][0];\n");
	sgemv_p_t_code_generator(f, nx, nu, nu, 1);
/*	fprintf(f, "		d_print_mat(%d, 1, hux[ii], %d);\n", nx+nu, nx+nu);*/
	fprintf(f, "		\n");
	fprintf(f, "		/* strsv */\n");
/*		strsv_p_t_lib(nu, hpQ[ii], sda, &hux[ii][0]);*/
	fprintf(f, "		pA = hpQ[ii];\n");
	fprintf(f, "		x = &hux[ii][0];\n");
	strsv_p_t_code_generator(f, nu);
/*	fprintf(f, "		d_print_mat(%d, 1, hux[ii], %d);\n", nx+nu, nx+nu);*/
	fprintf(f, "		\n");
	fprintf(f, "		/* */\n");
	fprintf(f, "		for(jj=0; jj<%d; jj+=4)\n", nu-3);
	fprintf(f, "			{\n");
	fprintf(f, "			hux[ii][jj+0] = - hux[ii][jj+0];\n");
	fprintf(f, "			hux[ii][jj+1] = - hux[ii][jj+1];\n");
	fprintf(f, "			hux[ii][jj+2] = - hux[ii][jj+2];\n");
	fprintf(f, "			hux[ii][jj+3] = - hux[ii][jj+3];\n");
	fprintf(f, "			}\n");
	for(jj=0; jj<nu%4; jj++)
		{
	fprintf(f, "		hux[ii][%d] = - hux[ii][%d];\n", (nu/4)*4+jj, (nu/4)*4+jj);
		}
	fprintf(f, "		\n");
/*	fprintf(f, "		d_print_mat(%d, 1, hux[ii], %d);\n", nx+nu, nx+nu);*/
	fprintf(f, "		/* */\n");
	fprintf(f, "		for(jj=0; jj<%d; jj+=4)\n", nx-3);
	fprintf(f, "			{\n");
	fprintf(f, "			hux[ii+1][jj+%d] = hpBAbt[ii][%d+%d*(jj+0)];\n", nu+0, ((nu+nx)/bs)*bs*sda+(nu+nx)%bs, bs);
	fprintf(f, "			hux[ii+1][jj+%d] = hpBAbt[ii][%d+%d*(jj+1)];\n", nu+1, ((nu+nx)/bs)*bs*sda+(nu+nx)%bs, bs);
	fprintf(f, "			hux[ii+1][jj+%d] = hpBAbt[ii][%d+%d*(jj+2)];\n", nu+2, ((nu+nx)/bs)*bs*sda+(nu+nx)%bs, bs);
	fprintf(f, "			hux[ii+1][jj+%d] = hpBAbt[ii][%d+%d*(jj+3)];\n", nu+3, ((nu+nx)/bs)*bs*sda+(nu+nx)%bs, bs);
	fprintf(f, "			}\n");
	for(jj=0; jj<nx%4; jj++)
		{
	fprintf(f, "		hux[ii+1][%d] = hpBAbt[ii][%d];\n", nu+(nx/4)*4+jj, ((nu+nx)/bs)*bs*sda+(nu+nx)%bs+bs*((nx/4)*4+jj) );
		}
	fprintf(f, "		\n");
/*	fprintf(f, "		d_print_mat(%d, 1, hux[ii+1], %d);\n", nx+nu, nx+nu);*/
	fprintf(f, "		/* sgemv */\n");
/*		sgemv_p_t_lib(nx+nu, nx, 0, hpBAbt[ii], sda, &hux[ii][0], &hux[ii+1][nu], 1);*/
	fprintf(f, "		pA = hpBAbt[ii];\n");
	fprintf(f, "		x = &hux[ii][0];\n");
	fprintf(f, "		y = &hux[ii+1][%d];\n", nu);
	sgemv_p_t_code_generator(f, nx+nu, nx, 0, 1);
/*	fprintf(f, "		d_print_mat(%d, 1, hux[ii+1], %d);\n", nx+nu, nx+nu);*/
	fprintf(f, "		\n");
/*	fprintf(f, "		exit(2);\n");*/
	fprintf(f, "		\n");
	fprintf(f, "		}\n");
	fprintf(f, "	\n");
	fprintf(f, "	}\n");
	fprintf(f, "	\n");

    fclose(f);
	
	return;

	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*void dricposv(int nx, int nu, int N, int sda, float **hpBAbt, float **hpQ, float **hux, float *pL, float *pBAbtL)*/
/*	{*/
/*	*/
/*	const int bs = D_MR; //d_get_mr();*/

/*	int ii, jj;*/
/*	*/
/*	int nz = nx+nu+1;*/

	/* initial Cholesky factorization */
/*	dpotrf_p_dcopy_p_t_lib(nz, nu, hpQ[N], sda, pL, sda);*/

	/* factorization and backward substitution */
/*	for(ii=0; ii<N; ii++)*/
/*		{	*/
/*		dtrmm_ppp_lib(nz, nx, nu, hpBAbt[N-ii-1], sda, pL, sda, pBAbtL, sda);*/
/*		dsyrk_ppp_lib(nz, nx, pBAbtL, sda, hpQ[N-ii-1], sda);*/
/*		dpotrf_p_dcopy_p_t_lib(nz, nu, hpQ[N-ii-1], sda, pL, sda);*/
/*		}*/


	/* forward substitution */
/*	for(ii=0; ii<N; ii++)*/
/*		{*/
/*		for(jj=0; jj<nu; jj++) hux[ii][jj] = hpQ[ii][((nu+nx)/bs)*bs*sda+(nu+nx)%bs+bs*jj];*/
/*		dgemv_p_t_lib(nx, nu, nu, &hpQ[ii][(nu/bs)*bs*sda+nu%bs], sda, &hux[ii][nu], &hux[ii][0], 1);*/
/*		dtrsv_p_t_lib(nu, hpQ[ii], sda, &hux[ii][0]);*/
/*		for(jj=0; jj<nu; jj++) hux[ii][jj] = - hux[ii][jj];*/
/*		for(jj=0; jj<nx; jj++) hux[ii+1][nu+jj] = hpBAbt[ii][((nu+nx)/bs)*bs*sda+(nu+nx)%bs+bs*jj];*/
/*		dgemv_p_t_lib(nx+nu, nx, 0, hpBAbt[ii], sda, &hux[ii][0], &hux[ii+1][nu], 1);*/
/*		}*/
/*	*/
/*	}*/



