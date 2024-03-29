/* { dg-do compile } */
/* { dg-options "-mavx512bw -mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\[\\n\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}{z}" 1 } } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%xmm\[0-9\]\[\\n\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}{z}" 1 } } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\n\]*%ymm\[0-9\]\[\\n\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovwb\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}{z}" 1 } } */

#include <immintrin.h>

volatile __m128i x, z;
volatile __m256i y;
volatile __m512i u;
volatile __mmask8 m1;
volatile __mmask16 m2;
volatile __mmask32 m3;

void extern
avx512bw_test (void)
{
  z = _mm_cvtepi16_epi8 (x);
  z = _mm_mask_cvtepi16_epi8 (z, m1, x);
  z = _mm_maskz_cvtepi16_epi8 (m1, x);
  z = _mm256_cvtepi16_epi8 (y);
  z = _mm256_mask_cvtepi16_epi8 (z, m2, y);
  z = _mm256_maskz_cvtepi16_epi8 (m2, y);
  y = _mm512_cvtepi16_epi8 (u);
  y = _mm512_mask_cvtepi16_epi8 (y, m3, u);
  y = _mm512_maskz_cvtepi16_epi8 (m3, u);
}
