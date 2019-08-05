#include <string.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

unsigned char *base64_decode(unsigned char *input, long* size)
{
	int table[] =
	{
		0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,62,0,0,0,
		63,52,53,54,55,56,57,58,
		59,60,61,0,0,0,0,0,0,0,0,
		1,2,3,4,5,6,7,8,9,10,11,12,
		13,14,15,16,17,18,19,20,21,
		22,23,24,25,0,0,0,0,0,0,26,
		27,28,29,30,31,32,33,34,35,
		36,37,38,39,40,41,42,43,44,
		45,46,47,48,49,50,51
	};

	long len;
	long str_len;
	unsigned char *res;
	int i, j;

	len = strlen(input);

	if (strstr(input, "=="))
	{
		str_len = len / 4 * 3 - 2;
	}
	else if (strstr(input, "="))
	{
		str_len = len / 4 * 3 - 1;
	}
	else
	{
		str_len = len / 4 * 3;
	}

	res = malloc(sizeof(unsigned char)*str_len + 1);

	res[str_len] = '\0';

	for (i = 0, j = 0; i < len - 2; j += 3, i += 4)
	{
		res[j] = ((unsigned char)table[input[i]]) << 2 | (((unsigned char)table[input[i + 1]]) >> 4);
		res[j + 1] = (((unsigned char)table[input[i + 1]]) << 4) | (((unsigned char)table[input[i + 2]]) >> 2);
		res[j + 2] = (((unsigned char)table[input[i + 2]]) << 6) | ((unsigned char)table[input[i + 3]]);
	}

	*size = str_len;
	return res;
}