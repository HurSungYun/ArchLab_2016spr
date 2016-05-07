/* 
 * Architecture Lab: Part A 
 * 
 * High level specs for the functions that the students will rewrite
 * in Y86 assembly language
 */

/* $begin examples */
/* linked list element */
typedef struct ELE {
	int val;
	struct ELE *next;
} *list_ptr;

/* sum_list - Sum the elements of a linked list */
int sum_list(list_ptr ls)
{
	int val = 0;
	while (ls) {
		if (!ls->val)
			val += 1;
		else
			val += ls->val;
		ls = ls->next;
	}
	return val;
}

/* rsum_list - Recursive sum the elements of a linked list, sum 1 for 0 value */
int rsum_list(list_ptr ls)
{
	if (!ls)
		return 0;
	else {
		int val = ls->val;
		if (!val)
			val = 1;
		int rest = rsum_list(ls->next);
		return val + rest;
	}
}

/* copy_block - Copy src to dest and return xor checksum of src */
int copy_block(int *src, int *dest, int len)
{
	int result = 0;
	while (len > 0) {
		int val = *src++;
		*dest++ = val;
		result ^= val;
		len--;
	}
	return result;
}
/* $end examples */
