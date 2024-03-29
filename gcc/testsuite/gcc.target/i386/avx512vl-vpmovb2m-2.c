/* { dg-do run } */
/* { dg-options "-O2 -mavx512bw -mavx512vl -DAVX512VL" } */
/* { dg-require-effective-target avx512vl } */
/* { dg-require-effective-target avx512bw } */

#define AVX512F_LEN 256
#define AVX512F_LEN_HALF 128
#include "avx512bw-vpmovb2m-2.c"

#undef AVX512F_LEN
#undef AVX512F_LEN_HALF

#define AVX512F_LEN 128
#define AVX512F_LEN_HALF 128
#include "avx512bw-vpmovb2m-2.c"
