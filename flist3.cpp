#include<io.h>
#include<stdio.h>
#include<direct.h>
#include<iostream>
#include<fstream>
using namespace std;

//��Ҫ����̨����·����C : \WINDOWS �����оٳ��ļ����������ļ� 
//�ж���Ŀ¼���������ļ�
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
	int nRet = (hnd < 0) ? -1 : 1;	//hnd��handle ��� 
	while(nRet >= 0)
	{
		if(data.attrib & _A_SUBDIR) //�����Ŀ¼
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
	_findclose(hnd);//�رյ�ǰ��� 
	fout.close();
}


int main(int argc,char *argv[]) 
{	 
	
	ofstream o_fstream;
	
	dfsFolder(argv[1],o_fstream);
	
	return 0;
}
