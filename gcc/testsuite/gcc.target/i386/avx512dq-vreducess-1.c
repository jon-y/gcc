/* { dg-do compile } */
/* { dg-options "-mavx512dq -O2" } */
/* { dg-final { scan-assembler-times "vreducess\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\{\]" 1 } } */

#include <immintrin.h>

volatile __m128 x1, x2;
volatile __mmask8 m;

void extern
avx512dq_test (void)
{
  x1 = _mm_reduce_ss (x1, x2, 123);
}
