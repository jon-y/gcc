/* { dg-do run } */
/* { dg-options "-O2 -mavx512bw -DAVX512BW" } */
/* { dg-require-effective-target avx512bw } */

#include "avx512f-helper.h"

#define SIZE (AVX512F_LEN / 8)
#include "avx512f-mask-type.h"

void
CALC (char *r, char *s)
{
  int i;
  for (i = 0; i < SIZE; i++)
    {
      r[i] = s[0];
    }
}

void
TEST (void)
{
  int i, sign;
  UNION_TYPE (AVX512F_LEN, i_b) res1, res2, res3;
  UNION_TYPE (128, i_b) src;
  MASK_TYPE mask = SIZE | 123;
  char res_ref[SIZE];

  sign = -1;
  for (i = 0; i < 16; i++)
    {
      src.a[i] = 1 + 3 * i * sign;
      sign = sign * -1;
    }
  for (i = 0; i < SIZE; i++)
    res2.a[i] = DEFAULT_VALUE;

  CALC (res_ref, src.a);

  if (AVX512F_LEN == 512)
    {
      res1.x = INTRINSIC (_broadcastb_epi8) (src.x);
      if (UNION_CHECK (AVX512F_LEN, i_b) (res1, res_ref))
	abort ();
    }

  res2.x = INTRINSIC (_mask_broadcastb_epi8) (res2.x, mask, src.x);
  res3.x = INTRINSIC (_maskz_broadcastb_epi8) (mask, src.x);

  MASK_MERGE (i_b) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_b) (res2, res_ref))
    abort ();

  MASK_ZERO (i_b) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_b) (res3, res_ref))
    abort ();

  CALC (res_ref, src.a);

  if (AVX512F_LEN == 512)
    {
      res1.x = INTRINSIC (_set1_epi8) (src.a[0]);
      if (UNION_CHECK (AVX512F_LEN, i_b) (res1, res_ref))
	abort ();
    }

  res2.x = INTRINSIC (_mask_set1_epi8) (res2.x, mask, src.a[0]);
  res3.x = INTRINSIC (_maskz_set1_epi8) (mask, src.a[0]);

  MASK_MERGE (i_b) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_b) (res2, res_ref))
    abort ();

  MASK_ZERO (i_b) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_b) (res3, res_ref))
    abort ();
}
