/* { dg-do compile } */
/* { dg-options "-mavx512bw -mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vpmovzxbw\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%zmm\[0-9\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovzxbw\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovzxbw\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovzxbw\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vpmovzxbw\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vpmovzxbw\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vpmovzxbw\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */

#include <immintrin.h>

volatile __m512i res1;
volatile __m256i s1, res2;
volatile __m128i s2, res3;
volatile __mmask32 m32;
volatile __mmask16 m16;
volatile __mmask8 m8;

void extern
avx512bw_test (void)
{
  res1 = _mm512_cvtepu8_epi16 (s1);

  res1 = _mm512_mask_cvtepu8_epi16 (res1, m32, s1);
  res2 = _mm256_mask_cvtepu8_epi16 (res2, m16, s2);
  res3 = _mm_mask_cvtepu8_epi16 (res3, m8, s2);

  res1 = _mm512_maskz_cvtepu8_epi16 (m32, s1);
  res2 = _mm256_maskz_cvtepu8_epi16 (m16, s2);
  res3 = _mm_maskz_cvtepu8_epi16 (m8, s2);
}
