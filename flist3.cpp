#include<io.h>
#include<stdio.h>
#include<direct.h>
#include<iostream>
#include<fstream>
using namespace std;

//需要控制台输入路径如C : \WINDOWS 即可列举出文件夹下所有文件 
//判断子目录，遍历子文件
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
	int nRet = (hnd < 0) ? -1 : 1;	//hnd：handle 句柄 
	while(nRet >= 0)
	{
		if(data.attrib & _A_SUBDIR) //如果是目录
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
			
		nRet = _findnext(hnd,&data);  
	}
	_findclose(hnd);//关闭当前句柄 
	fout.close();
}


int main(int argc,char *argv[]) 
{	 
	
	ofstream o_fstream;
	
	dfsFolder(argv[1],o_fstream);
	
	return 0;
}
