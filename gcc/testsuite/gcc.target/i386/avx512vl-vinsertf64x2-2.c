/* { dg-do run } */
/* { dg-options "-O2 -mavx512dq -mavx512vl -DAVX512VL" } */
/* { dg-require-effective-target avx512vl } */
/* { dg-require-effective-target avx512dq } */

#define AVX512F_LEN 256
#define AVX512F_LEN_HALF 128
#include "avx512dq-vinsertf64x2-2.c"

void
test_128 () {}
