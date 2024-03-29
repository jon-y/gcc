/* { dg-do compile } */
/* { dg-options "-mavx512dq -mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%ymm\[0-9\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%zmm\[0-9\]\[^\{\]" 2 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 2 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\{z\}" 2 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*\{sae\}\[^\n\]*%zmm\[0-9\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*\{sae\}\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvttps2qq\[ \\t\]+\[^\n\]*\{sae\}\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */

#include <immintrin.h>

volatile __m512i x1;
volatile __m256i x2;
volatile __m128i x3;
volatile __m256 z1;
volatile __m128 z2;
volatile __mmask8 m;

void extern
avx512dq_test (void)
{
  x1 = _mm512_cvttps_epi64 (z1);
  x1 = _mm512_mask_cvttps_epi64 (x1, m, z1);
  x1 = _mm512_maskz_cvttps_epi64 (m, z1);
  x2 = _mm256_cvttps_epi64 (z2);
  x2 = _mm256_mask_cvttps_epi64 (x2, m, z2);
  x2 = _mm256_maskz_cvttps_epi64 (m, z2);
  x3 = _mm_cvttps_epi64 (z2);
  x3 = _mm_mask_cvttps_epi64 (x3, m, z2);
  x3 = _mm_maskz_cvttps_epi64 (m, z2);
  x1 = _mm512_cvtt_roundps_epi64 (z1, _MM_FROUND_NO_EXC);
  x1 = _mm512_mask_cvtt_roundps_epi64 (x1, m, z1, _MM_FROUND_NO_EXC);
  x1 = _mm512_maskz_cvtt_roundps_epi64 (m, z1, _MM_FROUND_NO_EXC);
}
