/* Test generation of dlmzb for strlen on 440.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-skip-if "" { powerpc*-*-aix* } { "*" } { "" } } */
/* { dg-require-effective-target ilp32 } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=440" } } */
/* { dg-options "-O2 -mcpu=440" } */

/* { dg-final { scan-assembler "dlmzb\\. " } } */

typedef __SIZE_TYPE__ size_t;

size_t strlen(const char *);

size_t
strlen8(const long long *s)
{
  return strlen((const char *)s);
}
