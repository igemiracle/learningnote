#include<io.h>
#include<stdio.h>
#include<direct.h>
#include<iostream>
#include<fstream>
using namespace std;

//final版 全功能 
/*
  1、控制台输入flist C : \Windows 即可列举出文件夹下所有文件，遍历子目录文件，同时显示文件信息 
  2、flist C:\Windows print可以只打印文件名
  3、flist C:\Windows all 可以显示文件信息并打印文件名 
*/

void dfsFolder(const char *path,ofstream &fout)
{
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
				printf("\n	[%s]*\n",data.name);
				char newPath[100];
				strcpy(newPath,path);
				strcat(newPath,"\\");
				strcat(newPath,data.name);
				dfsFolder(newPath,fout);
			} 
		}	
		else
			
			printf("	%s\n",data.name);
			 
	}
	_findclose(hnd);
	fout.close();
}

void printDir(const char *path){
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
	int nRet = (hnd < 0) ? -1 : 1; 
	while(nRet >= 0)
	{
		if(data.attrib & _A_SUBDIR) 
		{
			printf("\n	[%s]*\n",data.name);
		} 
		else
			printf("	 %s\n",data.name);
		nRet = _findnext(hnd,&data);  
	}
	_findclose(hnd);
}

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
	ofstream o_fstream;
	
	if(strcmp(argv[2],"all") == 0)
	{
		allDir(argv[1]);
	}
	else if(strcmp(argv[2],"print") == 0)
	{
		printDir(argv[1]);
	}
	else
	dfsFolder(argv[1],o_fstream);
	
	return 0;
}
