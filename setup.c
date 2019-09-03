#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(void)
{
	char word[2048], c;
	int cursor_position;
	FILE *file, *file_;
	file = fopen("text quest","rb");
	file_ = fopen("setup","w");
	while((c = fgetc(file)) != EOF)
	{
		if(c == '<')
		{
			fscanf(file, "%s", word);
			word[strlen(word) - 1] = 0;
			cursor_position = ftell(file);
			fprintf(file_, "%s %d\n", word, cursor_position);
		}
	}
	fclose(file);
	fclose(file_);
	return 0;
}
