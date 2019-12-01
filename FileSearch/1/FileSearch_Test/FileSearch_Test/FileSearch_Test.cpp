// FileSearch_Test.cpp : �������̨Ӧ�ó������ڵ㡣
//
//#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "FileSearch.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
#if 1
	 char rootPath[10] = {0}, driveType[21] = {0};  
     UINT nType;  
 
     for(char a = 'A'; a <= 'Z'; a++)  
     {  
         sprintf_s(rootPath, "%c:\\", a);  
         nType = GetDriveType(rootPath);  
         if(nType != DRIVE_NO_ROOT_DIR)                  // DRIVE_NO_ROOT_DIR: ·����Ч  
         {  
             switch(nType)  
             {  
             case DRIVE_FIXED:  
                 strcpy_s(driveType, "Ӳ��");  
                 break;  
             case DRIVE_REMOVABLE:  
				 strcpy_s(driveType, "�ƶ�Ӳ��");
                 break;  
             case DRIVE_CDROM:  
				 strcpy_s(driveType, "����");
                 break;  
             case DRIVE_RAMDISK:  
				 strcpy_s(driveType, "RAM��");
                 break;  
             case DRIVE_REMOTE:  
				 strcpy_s(driveType, "Remote(Network) drive �������");
                 break;  
             case DRIVE_UNKNOWN:  
             default:  
				 strcpy_s(driveType, "δ֪��");
                 break;  
             }  
             cout<<rootPath<<"\t"<<driveType<<endl;  
			 SearchFile(rootPath);
         }  
     } 
#endif
	// SearchFile("D:\\");

	system("pause");
	return 0;
}

