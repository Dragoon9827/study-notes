#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

unsigned char *base64_encode(unsigned char *str, long str_len)
{
	long len;
	unsigned char *res;
	int i, j;

	unsigned char *base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
	if (str_len % 3 == 0)
	{ 
		len = str_len / 3 * 4;
	}
	else
	{
		len = (str_len / 3 + 1) * 4;
	}

	res = malloc(sizeof(unsigned char)*len + 1);

	res[len] = '\0';
 
	for (i = 0, j = 0; i < len - 2; j += 3, i += 4)
	{
		res[i] = base64_table[str[j] >> 2]; 
		res[i + 1] = base64_table[(str[j] & 0x3) << 4 | (str[j + 1] >> 4)];
		res[i + 2] = base64_table[(str[j + 1] & 0xf) << 2 | (str[j + 2] >> 6)];
		res[i + 3] = base64_table[str[j + 2] & 0x3f];
	}

	switch (str_len % 3)
	{
	case 1:
		res[i - 2] = '=';
		res[i - 1] = '=';
		break;
	case 2:
		res[i - 1] = '=';
		break;
	}

	return res;
}
