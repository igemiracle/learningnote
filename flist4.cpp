#include<io.h>
#include<stdio.h>
#include<direct.h>
#include<iostream>
#include<string>
using namespace std;

//���������ļ�����ȡ�ļ����ԡ������ļ���ֻ���ļ����� 
//����̨����flist ·�� ����
 
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

		printf("�ļ��б�\n");
	while(_findnext(hnd, &data) == 0)
	{
	
		string tempName = data.name;
		if(tempName[0] == '.')
			continue;
		if(data.attrib & _A_NORMAL)
		{
			printf("	��ͨ�ļ�	");
		}	
		else if(data.attrib & _A_RDONLY)
		{
			printf("	ֻ���ļ�	");
		}
		else if(data.attrib & _A_HIDDEN)
		{
			printf("	�����ļ�	");
		}
		else if(data.attrib &_A_SYSTEM == _A_SYSTEM)
		{
			printf("	ϵͳ�ļ�	");
		}
		else if(data.attrib & _A_SUBDIR)
		{
			printf("	��Ŀ¼  	");
		}
		else{
			printf("	�浵�ļ�	");
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
