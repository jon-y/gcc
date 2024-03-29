/* { dg-do compile } */
/* { dg-options "-mavx512dq -mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vinsertf64x2\[^\n\]*ymm" 3 } } */
/* { dg-final { scan-assembler-times "vinsertf64x2\[^\n\]*\{z\}" 2 } } */
/* { dg-final { scan-assembler-times "vinsertf64x2\[^\n\]*\{%k\[1-7\]\}\[^\{\]" 2 } } */
/* { dg-final { scan-assembler-times "vinsertf64x2\[^\n\]*zmm" 3 } } */

#include <immintrin.h>

volatile __m256d x;
volatile __m128d y;
volatile __m512d z;

void extern
avx512dq_test (void)
{
  x = _mm256_insertf64x2 (x, y, 1);
  x = _mm256_mask_insertf64x2 (x, 2, x, y, 1);
  x = _mm256_maskz_insertf64x2 (2, x, y, 1);
  z = _mm512_insertf64x2 (z, y, 1);
  z = _mm512_mask_insertf64x2 (z, 2, z, y, 1);
  z = _mm512_maskz_insertf64x2 (2, z, y, 1);
}
