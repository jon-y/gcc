/* { dg-do compile } */
/* { dg-options "-mavx512dq -mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%xmm\[0-9\]\[^\n\]*%xmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%ymm\[0-9\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%ymm\[0-9\]\[^\n\]*%ymm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\n\]*%zmm\[0-9\]\[^\{\]" 2 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 2 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\{z\}" 2 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*\{rn-sae\}\[^\n\]*%zmm\[0-9\]\[^\n\]*%zmm\[0-9\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*\{ru-sae\}\[^\n\]*%zmm\[0-9\]\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vcvtuqq2pd\[ \\t\]+\[^\n\]*\{rz-sae\}\[^\n\]*%zmm\[0-9\]\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */

#include <immintrin.h>

volatile __m512i s1;
volatile __m256i s2;
volatile __m128i s3;
volatile __m512d res1;
volatile __m256d res2;
volatile __m128d res3;
volatile __mmask8 m;

void extern
avx512dq_test (void)
{
  res1 = _mm512_cvtepu64_pd (s1);
  res1 = _mm512_mask_cvtepu64_pd (res1, m, s1);
  res1 = _mm512_maskz_cvtepu64_pd (m, s1);
  res2 = _mm256_cvtepu64_pd (s2);
  res2 = _mm256_mask_cvtepu64_pd (res2, m, s2);
  res2 = _mm256_maskz_cvtepu64_pd (m, s2);
  res3 = _mm_cvtepu64_pd (s3);
  res3 = _mm_mask_cvtepu64_pd (res3, m, s3);
  res3 = _mm_maskz_cvtepu64_pd (m, s3);
  res1 = _mm512_cvt_roundepu64_pd (s1, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  res1 = _mm512_mask_cvt_roundepu64_pd (res1, m, s1, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
  res1 = _mm512_maskz_cvt_roundepu64_pd (m, s1, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
