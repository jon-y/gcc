/* { dg-do compile } */
/* { dg-options "-mavx512dq -O2" } */
/* { dg-final { scan-assembler-times "vrangesd\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\{\]" 2 } } */
/* { dg-final { scan-assembler-times "vrangesd\[ \\t\]+\[^\n\]*\{sae\}\[^\n\]*%xmm\[0-9\]\[^\{\]" 1 } } */

#include <immintrin.h>

volatile __m128d x1, x2;
volatile __mmask8 m;

void extern
avx512dq_test (void)
{
  x1 = _mm_range_sd (x1, x2, 3);
  x1 = _mm_range_round_sd (x1, x2, 3, _MM_FROUND_NO_EXC);
}
