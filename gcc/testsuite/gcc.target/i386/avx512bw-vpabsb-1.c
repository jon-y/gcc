/* { dg-do compile } */
/* { dg-options "-mavx512bw -mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%zmm\[0-9\]" 3 } } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%ymm\[0-9\]" 2 } } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%xmm\[0-9\]" 2 } } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpabsb\[ \\t\]+\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */

#include <immintrin.h>

volatile __m512i z;
volatile __m256i y;
volatile __m128i x;
volatile __mmask64 m1;
volatile __mmask32 m2;
volatile __mmask16 m3;

void extern
avx512bw_test (void)
{
  z = _mm512_abs_epi8 (z);
  z = _mm512_mask_abs_epi8 (z, m1, z);
  z = _mm512_maskz_abs_epi8 (m1, z);
  y = _mm256_mask_abs_epi8 (y, m2, y);
  y = _mm256_maskz_abs_epi8 (m2, y);
  x = _mm_mask_abs_epi8 (x, m3, x);
  x = _mm_maskz_abs_epi8 (m3, x);
}
