#include <stdio.h>
#include <string.h>

#define MAX_CHARS_TO_TRANSLATE 100

char translate(char in)
{
	if (in == ' ')
		return ' ';
	if (in == 'a')
		return 'y';
	if (in == 'b')
		return 'h';
	if (in == 'c')
		return 'e';
	if (in == 'd')
		return 's';
	if (in == 'e')
		return 'o';
	if (in == 'f')
		return 'c';
	if (in == 'g')
		return 'v';
	if (in == 'h')
		return 'x';
	if (in == 'i')
		return 'd';
	if (in == 'j')
		return 'u';
	if (in == 'k')
		return 'i';
	if (in == 'l')
		return 'g';
	if (in == 'm')
		return 'l';
	if (in == 'n')
		return 'b';
	if (in == 'o')
		return 'k';
	if (in == 'p')
		return 'r';
	if (in == 'q')
		return 'z';
	if (in == 'r')
		return 't';
	if (in == 's')
		return 'n';
	if (in == 't')
		return 'w';
	if (in == 'u')
		return 'j';
	if (in == 'v')
		return 'p';
	if (in == 'w')
		return 'f';
	if (in == 'x')
		return 'm';
	if (in == 'y')
		return 'a';
	if (in == 'z')
		return 'q';
	if (in == '\0')
		return '\0';
	fprintf(stderr, "Unknown %c\n", in);
	return in;
}

char *translation(char *inGooglerese)
{
	static char buffer[MAX_CHARS_TO_TRANSLATE + 1] = "";
	//printf("%s", inGooglerese);
	for (int i = 0; i <= strlen(inGooglerese); ++i)
		buffer[i] = translate(inGooglerese[i]);

	return buffer;
}

int main()
{
	int lines = 0;
	char buffer[MAX_CHARS_TO_TRANSLATE + 1] = "";
	scanf("%d\n", &lines);
	//printf("Reading %d lines \n", lines);
	for (int i = 0; i < lines; ++i)
	{
		gets(buffer);
		printf("Case #%d: %s\n", i + 1, translation(buffer));
	}
	return 0;
}
