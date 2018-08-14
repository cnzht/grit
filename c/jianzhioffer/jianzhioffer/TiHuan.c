#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/*char * strreplace(char const * const original,char const * const pattern, char const * const replacement)
{
size_t const replen = strlen(replacement);
size_t const patlen = strlen(pattern);
size_t const orilen = strlen(original);

size_t patcnt = 0;
const char * oriptr;
const char * patloc;

// find how many times the pattern occurs in the original string
for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen)
{
patcnt++;
}

{
// allocate memory for the new string
size_t const retlen = orilen + patcnt * (replen - patlen);
char * const returned = (char *)malloc(sizeof(char)* (retlen + 1));

if (returned != NULL)
{
// copy the original string,
// replacing all the instances of the pattern
char * retptr = returned;
for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen)
{
size_t const skplen = patloc - oriptr;
// copy the section until the occurence of the pattern
strncpy(retptr, oriptr, skplen);
retptr += skplen;
// copy the replacement
strncpy(retptr, replacement, replen);
retptr += replen;
}
// copy the rest of the string.
strcpy(retptr, oriptr);
}
return returned;
}
}*/
/*void StrReplaceB(char* strSrc, char* strFind, char* strReplace)
{
	while (*strSrc != '\0')
	{
		if (*strSrc == *strFind)
		{
			if (strncmp(strSrc, strFind, strlen(strFind)) == 0)
			{
				int i = strlen(strFind);
				int j = strlen(strReplace);
				char* q = strSrc + i;
				char* p = q;//p、q均指向剩余字符串的首地址
				char* repl = strReplace;
				int lastLen = 0;
				while (*q++ != '\0')
					lastLen++;
				char* temp;
				temp = (char*)malloc(sizeof(char));
				//= new char[lastLen + 1];//临时开辟一段内存保存剩下的字符串,防止内存覆盖
				for (int k = 0; k < lastLen; k++)
				{
					*(temp + k) = *(p + k);
				}
				*(temp + lastLen) = '\0';
				while (*repl != '\0')
				{
					*strSrc++ = *repl++;
				}
				p = strSrc;
				char* pTemp = temp;//回收动态开辟内存
				while (*pTemp != '\0')
				{
					*p++ = *pTemp++;
				}
				free(temp);
				*p = '\0';
			}
			else
				strSrc++;
		}
		else
			strSrc++;
	}
}*/
void replaceSpace(char *str, int length) {
	int count = 0;
	for (int j = 0; j < length; j++)
	{
		if (str[j] == ' ')
		{
			count++;
		}
	}
	for (int i = length-1; i >=0; i--)
	{
		if (str[i]==' ')
		{
			str[i + 2*count] = str[i];
		}
		else
		{
			count--;
			str[i + 2*count] = '%';
			str[i + 2*count+1] = '2';
			str[i + 2*count+2] = '0';
		}
	}
}
int main()
{
	char  *str1 = "we in sohu !";
	char  *str2 = "%20";
	char  *str3 = " ";
	int m = strlen(str1);
	replaceSpace(str1, m);
	//StrReplaceB(&str1, &str3, &str2);
	printf("%s", str1);
	//puts(strreplace(&str1, str3, str2));
	getchar();
	return 0;
}
/*
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * strreplace(char const * const original,char const * const pattern, char const * const replacement)
{
	size_t const replen = strlen(replacement);
	size_t const patlen = strlen(pattern);
	size_t const orilen = strlen(original);

	size_t patcnt = 0;
	const char * oriptr;
	const char * patloc;

	// find how many times the pattern occurs in the original string
	for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen)
	{
		patcnt++;
	}

	{
		// allocate memory for the new string
		size_t const retlen = orilen + patcnt * (replen - patlen);
		char * const returned = (char *)malloc(sizeof(char)* (retlen + 1));

		if (returned != NULL)
		{
			// copy the original string, 
			// replacing all the instances of the pattern
			char * retptr = returned;
			for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen)
			{
				size_t const skplen = patloc - oriptr;
				// copy the section until the occurence of the pattern
				strncpy(retptr, oriptr, skplen);
				retptr += skplen;
				// copy the replacement 
				strncpy(retptr, replacement, replen);
				retptr += replen;
			}
			// copy the rest of the string.
			strcpy(retptr, oriptr);
		}
		return returned;
	}
}


char *strreplace2(const char *src, const char *from, const char *to)
{
	size_t size = strlen(src) + 1;
	size_t fromlen = strlen(from);
	size_t tolen = strlen(to);
	char *value = malloc(size);
	char *dst = value;
	if (value != NULL)
	{
		for (;;)
		{
			const char *match = strstr(src, from);
			if (match != NULL)
			{
				size_t count = match - src;
				char *temp;
				size += tolen - fromlen;
				temp = realloc(value, size);
				if (temp == NULL)
				{
					free(value);
					return NULL;
				}
				dst = temp + (dst - value);
				value = temp;
				memmove(dst, src, count);
				src += count;
				dst += count;
				memmove(dst, to, tolen);
				src += fromlen;
				dst += tolen;
			}
			
			{
				strcpy(dst, src);
				break;
			}
		}
	}
	return value;
}

//cl strreplace.c
//gcc strreplace.c
int main(int argc, char const *argv[])
{

	char* data = strreplace("java1024android1024cpp1024 from china ", "1024", "\u6765\u81ea\u4e2d\u56fd");
	printf("%s\n", data);
	data = strreplace("java中文android中文cpp中文 from china ", "中文", "test");
	printf("%s\n", data);

	char* data2 = strreplace2("java1024android1024cpp1024 from china ", "1024", "\u6765\u81ea\u4e2d\u56fd");
	printf("%s\n", data2);
	data2 = strreplace2("java中文android中文cpp中文 from china ", "中文", "test");
	printf("%s\n", data2);
	getchar();
	return 0;
}
*/
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0)
		{
			return 0;
		}
		else if (number==1)
		{
			return 1;
		}
		else if (number==2)
		{
			return 2;
		}
		else
		{
			return jumpFloor(number - 2) + jumpFloor(number - 1)
		}
	}
};