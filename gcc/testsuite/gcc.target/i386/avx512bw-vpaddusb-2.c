/* { dg-do run } */
/* { dg-options "-O2 -mavx512bw -DAVX512BW" } */
/* { dg-require-effective-target avx512bw } */

#include "avx512f-helper.h"

#define SIZE (AVX512F_LEN / 8)
#include "avx512f-mask-type.h"

void
CALC (unsigned char *r, unsigned char *s1, unsigned char *s2)
{
  int i;
  for (i = 0; i < SIZE; i++)
    {
      int tmp = (int)s1[i] + (int)s2[i];
      if (tmp > 0xFF) tmp = 0xFF;
      if (tmp < 0) tmp = 0;
      r[i] = (unsigned char)tmp;
    }
}

void
TEST (void)
{
  int i;
  UNION_TYPE (AVX512F_LEN, i_b) res1, res2, res3, src1, src2;
  MASK_TYPE mask = MASK_VALUE;
  unsigned char res_ref[SIZE];

  for (i = 0; i < SIZE; i++)
    {
      src1.a[i] = 2 + 7 * i % 291;
      src2.a[i] = 3 + 11 * (i % 377) * i;
    }
  for (i = 0; i < SIZE; i++)
    res2.a[i] = DEFAULT_VALUE;

  res1.x = INTRINSIC (_adds_epu8) (src1.x, src2.x);
  res2.x = INTRINSIC (_mask_adds_epu8) (res2.x, mask, src1.x, src2.x);
  res3.x = INTRINSIC (_maskz_adds_epu8) (mask, src1.x, src2.x);

  CALC (res_ref, src1.a, src2.a);

  if (UNION_CHECK (AVX512F_LEN, i_b) (res1, res_ref))
    abort ();

  MASK_MERGE (i_b) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_b) (res2, res_ref))
    abort ();

  MASK_ZERO (i_b) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_b) (res3, res_ref))
    abort ();
}
