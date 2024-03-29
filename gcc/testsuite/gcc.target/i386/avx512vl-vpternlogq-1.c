/* { dg-do compile } */
/* { dg-options "-mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vpternlogq\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\{\]" 3 } } */
/* { dg-final { scan-assembler-times "vpternlogq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\{\]" 3 } } */
/* { dg-final { scan-assembler-times "vpternlogq\[ \\t\]+\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpternlogq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpternlogq\[ \\t\]+\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vpternlogq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */

#include <immintrin.h>

volatile __m256i y, y2, y3;
volatile __m128i x, x2, x3;
volatile __mmask8 m;

void extern
avx512vl_test (void)
{
  y = _mm256_ternarylogic_epi64 (y, y2, y3, 0xF0);
  y = _mm256_mask_ternarylogic_epi64 (y, m, y2, y3, 0xF0);
  y = _mm256_maskz_ternarylogic_epi64 (m, y, y2, y3, 0xF0);

  x = _mm_ternarylogic_epi64 (x, x2, x3, 0xF0);
  x = _mm_mask_ternarylogic_epi64 (x, m, x2, x3, 0xF0);
  x = _mm_maskz_ternarylogic_epi64 (m, x, x2, x3, 0xF0);
}
