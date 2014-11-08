/* { dg-do run } */
/* { dg-options "-O2 -mavx512vl -mavx512dq -DAVX512VL" } */
/* { dg-require-effective-target avx512vl } */
/* { dg-require-effective-target avx512dq } */

#define AVX512F_LEN 256
#define AVX512F_LEN_HALF 128
#include "avx512f-vbroadcasti32x4-2.c"

void
test_128 () {}
