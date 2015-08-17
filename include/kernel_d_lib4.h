/**************************************************************************************************
*                                                                                                 *
* This file is part of HPMPC.                                                                     *
*                                                                                                 *
* HPMPC -- Library for High-Performance implementation of solvers for MPC.                        *
* Copyright (C) 2014-2015 by Technical University of Denmark. All rights reserved.                *
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

//#if defined(TARGET_X64_AVX2) || defined(TARGET_X64_AVX)
//#include <mmintrin.h>
//#include <xmmintrin.h>  // SSE
//#include <emmintrin.h>  // SSE2
//#include <pmmintrin.h>  // SSE3
//#include <smmintrin.h>  // SSE4
//#include <immintrin.h>  // AVX
//#endif

// kernel
void kernel_dgemm_nt_12x4_vs_lib4(int km, int kn, int kmax, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg, int tc, int td);
void kernel_dgemm_nt_10x4_vs_lib4(int km, int kn, int kmax, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg, int tc, int td);
void kernel_dgemm_nt_8x4_vs_lib4(int km, int kn, int kmax, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg, int tc, int td);
void kernel_dgemm_nt_8x2_vs_lib4(int km, int kn, int kmax, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg, int tc, int td);
void kernel_dgemm_nt_6x4_vs_lib4(int km, int kn, int kmax, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg, int tc, int td);
void kernel_dgemm_nt_4x4_vs_lib4(int km, int kn, int kmax, double *A, double *B, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nt_4x2_vs_lib4(int km, int kn, int kmax, double *A, double *B, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nt_2x2_vs_lib4(int km, int kn, int kmax, double *A, double *B, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nt_12x4_lib4(int kmax, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg, int tc, int td);
void kernel_dgemm_nt_8x4_lib4(int kmax, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg, int tc, int td);
void kernel_dgemm_nt_4x4_lib4(int kmax, double *A, double *B, double *C, double *D, int alg, int tc, int td);
#if defined(CORTEX_A15) || defined(CORTEX_A9) || defined(CORTEX_A7)
void kernel_dgemm_nt_4x4_nn_lib4(int kmax, double *A, double *B, double *C, double *D, int alg, int tc, int td);
#endif
void kernel_dgemm_nn_8x4_lib4(int kmax, double *A, int sda, double *B, int sdb, double *C, int sdc, double *D, int sdd, int alg, int tc, int td);
void kernel_dgemm_nn_8x4_vs_lib4(int km, int kn, int kmax, double *A, int sda, double *B, int sdb, double *C, int sdc, double *D, int sdd, int alg, int tc, int td);
void kernel_dgemm_nn_8x2_vs_lib4(int km, int kn, int kmax, double *A, int sda, double *B, int sdb, double *C, int sdc, double *D, int sdd, int alg, int tc, int td);
void kernel_dgemm_nn_4x4_vs_lib4(int km, int kn, int kmax, double *A, double *B, int sdb, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nn_4x2_vs_lib4(int km, int kn, int kmax, double *A, double *B, int sdb, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nn_2x4_vs_lib4(int km, int kn, int kmax, double *A, double *B, int sdb, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nn_2x2_vs_lib4(int km, int kn, int kmax, double *A, double *B, int sdb, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nn_4x4_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nn_4x2_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nn_2x4_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, int alg, int tc, int td);
void kernel_dgemm_nn_2x2_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, int alg, int tc, int td);
void kernel_dtrmm_nt_u_12x4_lib4(int kadd, double *A0, int sda, double *B, double *D0, int sdd);
void kernel_dtrmm_nt_u_8x4_lib4(int kadd, double *A0, int sda, double *B, double *D0, int sdd);
void kernel_dtrmm_nt_u_4x4_lib4(int kadd, double *A, double *B, double *D);
void kernel_dtrmm_nt_u_10x4_vs_lib4(int km, int kadd, double *A0, int sda, double *B, double *D0, int sdd);
void kernel_dtrmm_nt_u_8x4_vs_lib4(int km, int kadd, double *A0, int sda, double *B, double *D0, int sdd);
void kernel_dtrmm_nt_u_6x4_vs_lib4(int km, int kadd, double *A0, int sda, double *B, double *D0, int sdd);
void kernel_dtrmm_nt_u_4x4_vs_lib4(int km, int kadd, double *A, double *B, double *D);
void kernel_dtrmm_nt_l_8x4_lib4(int kmax, double *A0, int sda, double *B, double *C0, int sdc);
void kernel_dtrmm_nt_l_8x2_lib4(int kmax, double *A0, int sda, double *B, double *C0, int sdc);
void kernel_dtrmm_nt_l_4x4_lib4(int kmax, double *A, double *B, double *C);
void kernel_dtrmm_nt_l_4x2_lib4(int kmax, double *A, double *B, double *C);
void kernel_dtrmm_nt_l_2x4_lib4(int kmax, double *A, double *B, double *C);
void kernel_dtrmm_nt_l_2x2_lib4(int kmax, double *A, double *B, double *C);
void kernel_dtrmm_l_u_nt_8x4_lib4(int kmax, double *A, int sda, double *B, double *C, int sdc, double *D, int sdd, int alg);
void kernel_dtrmm_l_u_nt_4x4_lib4(int kmax, double *A, double *B, double *C, double *D, int alg);
void kernel_dsyrk_nt_12x4_vs_lib4(int km, int kn, int kadd, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg);
void kernel_dsyrk_nt_8x8_vs_lib4(int km, int kn, int kadd, double *A0, int sda, double *B0, int sdb, double *C0, int sdc, double *D0, int sdd, int alg);
void kernel_dsyrk_nt_8x4_vs_lib4(int km, int kn, int kadd, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg);
void kernel_dsyrk_nt_8x2_vs_lib4(int km, int kn, int kadd, double *A0, int sda, double *B, double *C0, int sdc, double *D0, int sdd, int alg);
void kernel_dsyrk_nt_4x4_vs_lib4(int km, int kn, int kadd, double *A, double *B, double *C, double *D, int alg);
void kernel_dsyrk_nt_4x2_vs_lib4(int km, int kn, int kadd, double *A, double *B, double *C, double *D, int alg);
void kernel_dsyrk_nt_2x2_vs_lib4(int km, int kn, int kadd, double *A, double *B, double *C, double *D, int alg);
void kernel_dsyrk_nn_4x4_lib4(int kadd, double *A, double *B, int sdb, double *C, double *D, int alg);
void kernel_dsyrk_nn_4x2_lib4(int kadd, double *A, double *B, int sdb, double *C, double *D, int alg);
void kernel_dsyrk_nn_2x2_lib4(int kadd, double *A, double *B, int sdb, double *C, double *D, int alg);
void kernel_dsyrk_dpotrf_nt_8x4_lib4(int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C, int sdc, double *D, int sdd, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_4x4_lib4(int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_12x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C, int sdc, double *D, int sdd, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_10x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C, int sdc, double *D, int sdd, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_8x8_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, int sdbp, double *Am, int sdam, double *Bm, int sdbm, double *C, int sdc, double *D, int sdd, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_8x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C, int sdc, double *D, int sdd, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_6x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C, int sdc, double *D, int sdd, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_4x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_4x2_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg, int fast_rsqrt);
void kernel_dsyrk_dpotrf_nt_2x2_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg, int fast_rsqrt);
void kernel_dgemm_dtrsm_nt_12x4_lib4(int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C0, int sdc, double *D0, int sdd, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_8x4_lib4(int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C0, int sdc, double *D0, int sdd, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_4x4_lib4(int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_12x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C0, int sdc, double *D0, int sdd, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_10x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C0, int sdc, double *D0, int sdd, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_8x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C0, int sdc, double *D0, int sdd, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_8x2_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C0, int sdc, double *D0, int sdd, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_6x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, int sdap, double *Bp, double *Am, int sdam, double *Bm, double *C0, int sdc, double *D0, int sdd, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_4x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_4x2_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_2x4_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg);
void kernel_dgemm_dtrsm_nt_2x2_vs_lib4(int km, int kn, int tri, int kadd, int ksub, double *Ap, double *Bp, double *Am, double *Bm, double *C, double *D, double *fact, int alg);
void kernel_dgemv_t_12_lib4(int kmax, double *A, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_t_8_lib4(int kmax, double *A, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_t_4_lib4(int kmax, double *A, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_t_3_lib4(int kmax, double *A, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_t_2_lib4(int kmax, double *A, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_t_1_lib4(int kmax, double *A, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_n_12_vs_lib4(int km, int kmax, double *A0, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_n_8_vs_lib4(int km, int kmax, double *A0, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_n_4_vs_lib4(int km, int kmax, double *A, double *x, double *y, double *z, int alg);
void kernel_dgemv_n_12_lib4(int kmax, double *A0, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_n_8_lib4(int kmax, double *A0, int sda, double *x, double *y, double *z, int alg);
void kernel_dgemv_n_4_lib4(int kmax, double *A, double *x, double *y, double *z, int alg);
void kernel_dgemv_n_2_lib4(int kmax, double *A, double *x, double *y, double *z, int alg);
void kernel_dgemv_n_1_lib4(int kmax, double *A, double *x, double *y, double *z, int alg);
void kernel_dtrmv_u_t_12_lib4(int kmax, double *A, int sda, double *x, double *y, int alg);
void kernel_dtrmv_u_t_8_lib4(int kmax, double *A, int sda, double *x, double *y, int alg);
void kernel_dtrmv_u_t_4_lib4(int kmax, double *A, int sda, double *x, double *y, int alg);
void kernel_dtrmv_u_t_2_lib4(int kmax, double *A, int sda, double *x, double *y, int alg);
void kernel_dtrmv_u_t_1_lib4(int kmax, double *A, int sda, double *x, double *y, int alg);
void kernel_dtrmv_u_n_12_lib4(int kmax, double *A0, int sda, double *x, double *y, int alg);
void kernel_dtrmv_u_n_8_lib4(int kmax, double *A0, int sda, double *x, double *y, int alg);
void kernel_dtrmv_u_n_4_lib4(int kmax, double *A, double *x, double *y, int alg);
void kernel_dtrmv_u_n_2_lib4(int kmax, double *A, double *x, double *y, int alg);
//void kernel_dtrsv_n_12_lib4(int kmax, double *A0, int sda, double *x, double *y);
void kernel_dtrsv_n_8_lib4(int kmax, int inverted_diag, double *A0, int sda, double *x, double *y);
void kernel_dtrsv_n_4_lib4(int kmax, int inverted_diag, double *A, double *x, double *y);
void kernel_dtrsv_n_4_vs_lib4(int km, int kn, int kmax, int inverted_diag, double *A, double *x, double *y);
void kernel_dtrsv_t_4_lib4(int kmax, int inverted_diag, double *A, int sda, double *x);
void kernel_dtrsv_t_3_lib4(int kmax, int inverted_diag, double *A, int sda, double *x);
void kernel_dtrsv_t_2_lib4(int kmax, int inverted_diag, double *A, int sda, double *x);
void kernel_dtrsv_t_1_lib4(int kmax, int inverted_diag, double *A, int sda, double *x);
void kernel_dsymv_4_lib4(int kmax, double *A, int sda, double *x_n, double *y_n, double *z_n, double *x_t, double *y_t, double *z_t, int tri, int alg);
void kernel_dsymv_3_lib4(int kmax, double *A, int sda, double *x_n, double *y_n, double *z_n, double *x_t, double *y_t, double *z_t, int tri, int alg);
void kernel_dsymv_2_lib4(int kmax, double *A, int sda, double *x_n, double *y_n, double *z_n, double *x_t, double *y_t, double *z_t, int tri, int alg);
void kernel_dsymv_1_lib4(int kmax, double *A, int sda, double *x_n, double *y_n, double *z_n, double *x_t, double *y_t, double *z_t, int tri, int alg);
void kernel_dgetr_4_lib4(int kmax, int kna, double *A, double *C, int sdc);
void kernel_dgetr_8_lib4(int kmax, int kna, double *A, int sda, double *C, int sdc);
void kernel_dgetr_3_lib4(int kmax, int kna, double *A, double *C, int sdc);
void kernel_dgetr_2_lib4(int kmax, int kna, double *A, double *C, int sdc);
void kernel_dgetr_1_lib4(int kmax, int kna, double *A, double *C, int sdc);
void kernel_dtrtr_l_8_lib4(int kmax, int kna, double *A, int sda, double *C, int sdc);
void kernel_dtrtr_l_4_lib4(int kmax, int kna, double *A, int sda, double *C);
void kernel_dsyttmm_lu_nt_4x4_lib4(int kmax, double *A, double *C);
void kernel_dsyttmm_lu_nt_2x2_lib4(int kmax, double *A, double *C);
void kernel_dsyttmm_ul_nt_8x4_lib4(int kmax, double *A, int sda, double *B, double *C, int sdc, double *D, int sdd, int alg);
void kernel_dsyttmm_ul_nt_4x4_lib4(int kmax, double *A, double *B, double *C, double *D, int alg);
void kernel_dttmm_ll_nt_4x4_lib4(int kmax, double *A, double *B, double *C);
void kernel_dttmm_uu_nt_4x4_lib4(int kmax, double *A, double *B, double *C);
void kernel_dttmm_uu_nt_4x2_lib4(int kmax, double *A, double *B, double *C);
void kernel_dgema_4_lib4(int kmax, int kna, double *A, int sda, double *C, int sdc);
void kernel_dgema_3_lib4(int kmax, int kna, double *A, int sda, double *C, int sdc);
void kernel_dgema_2_lib4(int kmax, int kna, double *A, int sda, double *C, int sdc);
void kernel_dgema_1_lib4(int kmax, int kna, double *A, int sda, double *C, int sdc);
void kernel_dtrma_4_lib4(int kmax, int kna, double *A, int sda, double *C, int sdc);
void kernel_dtrtr_u_4_lib4(int kmax, double *A, double *C, int sdc);
void kernel_dtrinv_8x4_lib4(int kmax, double *A, int sda, double *B, double *C, int sdc, double *fact);
void kernel_dtrinv_4x4_lib4(int kmax, double *A, double *B, double *C, double *fact);
void kernel_dtrinv_4x2_lib4(int kmax, double *A, double *B, double *C, double *fact);
void kernel_dtsyrk_dpotrf_nt_4x4_lib4(int kadd, int ksub, double *Ap, double *Am, double *C, double *D, double *fact, int alg);
//void kernel_dtsyrk_dpotrf_nt_4x2_lib4(int kadd, int ksub, double *Ap, double *Am, double *C, double *D, double *fact, int alg);
//void kernel_dtsyrk_dpotrf_nt_2x2_lib4(int kadd, int ksub, double *Ap, double *Am, double *C, double *D, double *fact, int alg);
void kernel_dtrmm_dtrsm_nt_4x4_lib4(int kadd, int ksub, double *A, double *B, double *C, double *D, double *fact, int alg);
//void kernel_dtrmm_dtrsm_nt_4x2_lib4(int kadd, int ksub, double *A, double *B, double *C, double *D, double *fact, int alg);
//void kernel_dtrmm_dtrsm_nt_2x4_lib4(int kadd, int ksub, double *A, double *B, double *C, double *D, double *fact, int alg);
//void kernel_dtrmm_dtrsm_nt_2x2_lib4(int kadd, int ksub, double *A, double *B, double *C, double *D, double *fact, int alg);
void kernel_dgemm_diag_right_4_lib4(int kmax, double *A, int sda, double *B, double *C, int sdc, double *D, int sdd, int alg);
void kernel_dgemm_diag_right_3_lib4(int kmax, double *A, int sda, double *B, double *C, int sdc, double *D, int sdd, int alg);
void kernel_dgemm_diag_right_2_lib4(int kmax, double *A, int sda, double *B, double *C, int sdc, double *D, int sdd, int alg);
void kernel_dgemm_diag_right_1_lib4(int kmax, double *A, int sda, double *B, double *C, int sdc, double *D, int sdd, int alg);
void kernel_dgemm_diag_left_4_lib4(int kmax, double *A, double *B, double *C, double *D, int alg);
void kernel_dgemm_diag_left_3_lib4(int kmax, double *A, double *B, double *C, double *D, int alg);
void kernel_dgemm_diag_left_2_lib4(int kmax, double *A, double *B, double *C, double *D, int alg);
void kernel_dgemm_diag_left_1_lib4(int kmax, double *A, double *B, double *C, double *D, int alg);
void kernel_dsyrk_diag_left_right_4_lib4(int kmax, double *Al, double *Ar, double *B, double *C, double *D, int alg);
void kernel_dsyrk_diag_left_right_3_lib4(int kmax, double *Al, double *Ar, double *B, double *C, double *D, int alg);
void kernel_dsyrk_diag_left_right_2_lib4(int kmax, double *Al, double *Ar, double *B, double *C, double *D, int alg);
void kernel_dsyrk_diag_left_right_1_lib4(int kmax, double *Al, double *Ar, double *B, double *C, double *D, int alg);
void kernel_dgemv_diag_lib4(int kmax, double *dA, double *x, double *y, double *z, int alg);

// corner
void corner_dtrmm_nt_u_12x3_lib4(double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_12x2_lib4(double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_12x1_lib4(double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_8x3_lib4(double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_8x2_lib4(double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_8x1_lib4(double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_4x3_lib4(double *A, double *B, double *C);
void corner_dtrmm_nt_u_4x2_lib4(double *A, double *B, double *C);
void corner_dtrmm_nt_u_4x1_lib4(double *A, double *B, double *C);
void corner_dtrmm_nt_u_8x3_vs_lib4(int km, double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_8x2_vs_lib4(int km, double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_8x1_vs_lib4(int km, double *A0, int sda, double *B, double *C0, int sdc);
void corner_dtrmm_nt_u_4x3_vs_lib4(int km, double *A, double *B, double *C);
void corner_dtrmm_nt_u_4x2_vs_lib4(int km, double *A, double *B, double *C);
void corner_dtrmm_nt_u_4x1_vs_lib4(int km, double *A, double *B, double *C);
void corner_dtrtr_l_3_lib4(int kna, double *A, int sda, double *C);
void corner_dtrtr_l_2_lib4(int kna, double *A, int sda, double *C);
void corner_dttmm_ll_nt_4x4_lib4(double *A, double *B, double *C);
void corner_dttmm_uu_nt_4x4_lib4(double *A, double *B, double *C);
void corner_dttmm_uu_nt_2x2_lib4(double *A, double *B, double *C);
void corner_dtrma_3_lib4(int kna, double *A, double *C, int sdc);
void corner_dtrma_2_lib4(int kna, double *A, double *C, int sdc);
void corner_dtrinv_4x4_lib4(double *fact, double *C);
void corner_dtrinv_2x2_lib4(double *fact, double *C);

// aux
void kernel_align_panel_8_0_lib4(int kmax, double *A, int sda, double *B, int sdb);
void kernel_align_panel_8_1_lib4(int kmax, double *A, int sda, double *B, int sdb);
void kernel_align_panel_8_2_lib4(int kmax, double *A, int sda, double *B, int sdb);
void kernel_align_panel_8_3_lib4(int kmax, double *A, int sda, double *B, int sdb);
void kernel_align_panel_4_0_lib4(int kmax, double *A, double *B);
void kernel_align_panel_4_1_lib4(int kmax, double *A0, int sda, double *B);
void kernel_align_panel_4_2_lib4(int kmax, double *A0, int sda, double *B);
void kernel_align_panel_4_3_lib4(int kmax, double *A0, int sda, double *B);
void kernel_align_panel_3_0_lib4(int kmax, double *A, double *B);
void kernel_align_panel_3_2_lib4(int kmax, double *A0, int sda, double *B);
void kernel_align_panel_3_3_lib4(int kmax, double *A0, int sda, double *B);
void kernel_align_panel_2_0_lib4(int kmax, double *A, double *B);
void kernel_align_panel_2_3_lib4(int kmax, double *A0, int sda, double *B);
void kernel_align_panel_1_0_lib4(int kmax, double *A, double *B);
void kernel_add_align_panel_8_0_lib4(int kmax, double alpha, double *A, int sda, double *B, int sdb);
void kernel_add_align_panel_8_1_lib4(int kmax, double alpha, double *A, int sda, double *B, int sdb);
void kernel_add_align_panel_8_2_lib4(int kmax, double alpha, double *A, int sda, double *B, int sdb);
void kernel_add_align_panel_8_3_lib4(int kmax, double alpha, double *A, int sda, double *B, int sdb);
void kernel_add_align_panel_4_0_lib4(int kmax, double alpha, double *A, double *B);
void kernel_add_align_panel_4_1_lib4(int kmax, double alpha, double *A0, int sda, double *B);
void kernel_add_align_panel_4_2_lib4(int kmax, double alpha, double *A0, int sda, double *B);
void kernel_add_align_panel_4_3_lib4(int kmax, double alpha, double *A0, int sda, double *B);
void kernel_add_align_panel_3_0_lib4(int kmax, double alpha, double *A, double *B);
void kernel_add_align_panel_3_2_lib4(int kmax, double alpha, double *A0, int sda, double *B);
void kernel_add_align_panel_3_3_lib4(int kmax, double alpha, double *A0, int sda, double *B);
void kernel_add_align_panel_2_0_lib4(int kmax, double alpha, double *A, double *B);
void kernel_add_align_panel_2_3_lib4(int kmax, double alpha, double *A0, int sda, double *B);
void kernel_add_align_panel_1_0_lib4(int kmax, double alpha, double *A, double *B);



// new kernels
void kernel_dsyrk_dpotrf_nt_8x4_vs_lib4_new(int km, int kn, int kadd, int tri_A, double *Ap0, int sdap, double *Bp, int ksub, double *Am0, int sdam, double *Bm, int alg, double *C0, int sdc, int use_diag_C, double *diag_C, double *D0, int sdd, double *inv_diag_D);
void kernel_dsyrk_dpotrf_nt_4x4_vs_lib4_new(int km, int kn, int kadd, int tri_A, double *Ap0, double *Bp, int ksub, double *Am0, double *Bm, int alg, double *C0, int use_diag_C, double *diag_C, double *D0, double *inv_diag_D);
void kernel_dsyrk_dpotrf_nt_4x2_vs_lib4_new(int km, int kn, int kadd, int tri_A, double *Ap, double *Bp, int ksub, double *Am, double *Bm, int alg, double *C, int use_diag_C, double *diag_C, double *D, double *inv_diag_D);
void kernel_dsyrk_dpotrf_nt_2x2_vs_lib4_new(int km, int kn, int kadd, int tri_A, double *Ap, double *Bp, int ksub, double *Am, double *Bm, int alg, double *C, int use_diag_C, double *diag_C, double *D, double *inv_diag_D);
void kernel_dgemm_dtrsm_nt_8x4_lib4_new(int kadd, int tri_A, double *Ap0, int sdap, double *Bp, int ksub, double *Am0, int sdam, double *Bm, int alg, double *C0, int sdc, double *D0, int sdd, double *E, int use_inv_diag_E, double *inv_diag_E);
void kernel_dgemm_dtrsm_nt_8x4_vs_lib4_new(int km, int kn, int kadd, int tri_A, double *Ap0, int sdap, double *Bp, int ksub, double *Am0, int sdam, double *Bm, int alg, double *C0, int sdc, double *D0, int sdd, double *E, int use_inv_diag_E, double *inv_diag_E);
void kernel_dgemm_dtrsm_nt_8x2_vs_lib4_new(int km, int kn, int kadd, int tri_A, double *Ap0, int sdap, double *Bp, int ksub, double *Am0, int sdam, double *Bm, int alg, double *C0, int sdc, double *D0, int sdd, double *E, int use_inv_diag_E, double *inv_diag_E);
void kernel_dgemm_dtrsm_nt_4x4_vs_lib4_new(int km, int kn, int kadd, int tri_A, double *Ap0, double *Bp, int ksub, double *Am0, double *Bm, int alg, double *C0, double *D0, double *E, int use_inv_diag_E, double *inv_diag_E);
void kernel_dgemm_dtrsm_nt_4x2_vs_lib4_new(int km, int kn, int kadd, int tri_A, double *Ap, double *Bp, int ksub, double *Am, double *Bm, int alg, double *C, double *D, double *E, int use_inv_diag_E, double *inv_diag_E);
