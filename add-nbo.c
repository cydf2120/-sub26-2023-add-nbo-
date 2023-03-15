#include <stdio.h>
#include <stdint.h>

uint32_t	shift(uint32_t a) 
{
	uint32_t	a1;
	uint32_t	a2;
	uint32_t	a3;
	uint32_t	a4;
	uint32_t	result;

	a1 = (a & 0xff000000) >> 24;
	a2 = (a & 0x00ff0000) >> 8;
	a3 = (a & 0x0000ff00) << 8;
	a4 = (a & 0x000000ff) << 24;
	result = a1 | a2 | a3 | a4;
	return (result);
}

int main(int argc, char* argv[]) {
	uint32_t	a;
	uint32_t	b;
	uint32_t	result;
	
	if (argc != 3)
		return 0;	//파일이 2개가 안들어오면 프로그램 종료

	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "r");

	if (fp1 == NULL || fp2 == NULL) 
	{
		printf("파일 읽기 실패");
		return 0;
	}

	fread(&a, 4, 1, fp1);
	fread(&b, 4, 1, fp2);
	a = shift(a);
	b = shift(b);
	result = a + b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, result, result);

	fclose(fp1);
	fclose(fp2);
	return 0;
}
