#include<io.h>
#include<stdio.h>
#include<direct.h>
#include<iostream>

//��Ҫ����������·����C : \WINDOWS �����оٳ��ļ����������ļ� 
void printDir(const char *path){
	struct _finddata_t data;
	char file[100];
	strcpy(file,path);
	_chdir(path);
	strcat(file,"\\*.*");
	
	long hnd = _findfirst(file, &data);//�����ļ�����������ʽchRE��ƥ���һ���ļ�
	if(hnd < 0)
	{
		perror(file);
	}
	int nRet = (hnd < 0) ? -1 : 1;	//hnd��handle ��� 
	while(nRet >= 0)
	{
		if(data.attrib & _A_SUBDIR) //�����Ŀ¼
		{
			printf("	[%s]*\n",data.name);
		} 
		else
			printf("	[%s]\n",data.name);
		nRet = _findnext(hnd,&data);  
	}
	_findclose(hnd);//�رյ�ǰ��� 
}


int main(int argc,char *argv[]) 
{	 
	printDir(argv[1]);
	return 0;
}
