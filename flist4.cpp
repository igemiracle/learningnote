#include<io.h>
#include<stdio.h>
#include<direct.h>
#include<iostream>
#include<string>
using namespace std;

//查找所有文件，获取文件属性。隐藏文件，只读文件…… 
//控制台输入flist 路径 即可
 
void allDir(const char *path){
	struct _finddata_t data;
	char file[100];
	strcpy(file,path);
	_chdir(path);
	strcat(file,"\\*.*");
	
	long hnd = _findfirst(file, &data);
	if(hnd < 0)
	{
		perror(file);
	}

		printf("文件列表：\n");
	while(_findnext(hnd, &data) == 0)
	{
	
		string tempName = data.name;
		if(tempName[0] == '.')
			continue;
		if(data.attrib & _A_NORMAL)
		{
			printf("	普通文件	");
		}	
		else if(data.attrib & _A_RDONLY)
		{
			printf("	只读文件	");
		}
		else if(data.attrib & _A_HIDDEN)
		{
			printf("	隐藏文件	");
		}
		else if(data.attrib &_A_SYSTEM == _A_SYSTEM)
		{
			printf("	系统文件	");
		}
		else if(data.attrib & _A_SUBDIR)
		{
			printf("	子目录  	");
		}
		else{
			printf("	存档文件	");
		}
			
		if(data.attrib & _A_SUBDIR)
		{
			if((strcmp(data.name,".") != 0)&&(strcmp(data.name,"..")!=0))
			{
			printf("	[%s]*\n",data.name);
			}
		}else
			printf("	%s\n",data.name);
			
	}
	
	_findclose(hnd);
	
}


int main(int argc,char *argv[]) 
{	 
	allDir(argv[1]);
	return 0;
}
