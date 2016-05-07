#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int src[8], dst[16];
int PseudoEnd = 419;
int FromHere  = 5;

/* $begin ncopy */
/*
 * @brief concatenates src and dst,  and stores the result in dst.
 * It does this by looking for a Pseudo-end of array, and from there on
 * copying src into dst. Also it returns the number of positive ints
 * contained in src array.
 *
 * @note: dst length is always ensure to be large enough to contain src
 *
 * @param src source array
 * @param dst destination array
 * @param len length of the source array
 *
 * @retval int number of positive values in source array
 */
int ncopy(int *src, int *dst, int len)
{
    int count = 0;
    int val;
    int i = 0;
    
    while(*dst != PseudoEnd){
      dst++;
    }

    dst++;
    
    while (len > 0) {
      val = *src++;
      *dst++ = val;
       
      if (val > 0)
        count++;
      len--;
    }
   
  return count;
}
/* $end ncopy */

int main()
{
    int i, count;

    dst[FromHere] = PseudoEnd;

    for (i=0; i<8; i++)
      src[i]= i+1;
    
    count = ncopy(src, dst, 8);
    printf ("count=%d\n", count);
    exit(0);
}


