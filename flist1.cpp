#include<io.h>
#include<stdio.h>
#include<direct.h>
#include<iostream>

//需要命令行输入路径如C : \WINDOWS 即可列举出文件夹下所有文件 
void printDir(const char *path){
	struct _finddata_t data;
	char file[100];
	strcpy(file,path);
	_chdir(path);
	strcat(file,"\\*.*");
	
	long hnd = _findfirst(file, &data);//查找文件名与正则表达式chRE的匹配第一个文件
	if(hnd < 0)
	{
		perror(file);
	}
	int nRet = (hnd < 0) ? -1 : 1;	//hnd：handle 句柄 
	while(nRet >= 0)
	{
		if(data.attrib & _A_SUBDIR) //如果是目录
		{
			printf("	[%s]*\n",data.name);
		} 
		else
			printf("	[%s]\n",data.name);
		nRet = _findnext(hnd,&data);  
	}
	_findclose(hnd);//关闭当前句柄 
}


int main(int argc,char *argv[]) 
{	 
	printDir(argv[1]);
	return 0;
}
