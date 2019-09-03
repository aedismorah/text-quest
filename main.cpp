#include <map>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <algorithm>

void check_rare_case(std::string str)
{
	if(str == "watch gachi")
			system("start https://www.youtube.com/watch?v=okURsgV_AjQ");
	if(str == "play warthunder")
		system("start https://warthunder.ru/ru/");
	if(str == "watch anime")
		while(1)
		{
			MessageBox(0,"Your gay now", "Anime fan detected", MB_OK); 
		}
}

class Dialog
{
public:
	Dialog()
	{
		char identifier[128];
		int index;
		FILE* file;
		file = fopen("setup", "r");
		while(!feof(file))
		{
			fscanf(file, "%s%d", identifier, &index);
			module[std::string(identifier)] = index;
		}
		fclose(file);
	}
	
	void show(std::string str)
	{
		check_rare_case(str);
		std::replace(str.begin(), str.end(), ' ', '_');
		if (module.find(str) == module.end() ) 
			printf("you have made a spelling mistake, desu~");
		else 
		{
			char c;
			FILE *file;
			file = fopen("text quest", "rb");
			fseek(file, module[str], SEEK_SET);
			printf("------------------------------------------------------------------------------------\n");
			while((c = fgetc(file)) != '}')
				if(c != '{'){printf("%c", c);}
		}
	}
	
private:
	std::map<std::string, int> module;
};

int main(void)
{
	Dialog dialog;
	dialog.show("begin");
	std::string reply;
	while(1)
	{
		std::getline(std::cin, reply);
		dialog.show(reply);
	}
}
