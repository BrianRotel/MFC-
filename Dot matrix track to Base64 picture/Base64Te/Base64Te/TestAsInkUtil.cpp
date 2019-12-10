// TestAsInkUtil.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <atlstr.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

typedef LPCWSTR(WINAPI *pAGSIGN2IMG)(LPCWSTR, long);


int _tmain(int argc, _TCHAR* argv[])
{

	wstring strdllPath = L"AsInkUtil.dll";

	HINSTANCE hDll = LoadLibrary(strdllPath.c_str());

	if (hDll)
	{
		pAGSIGN2IMG pFunc = (pAGSIGN2IMG)GetProcAddress(hDll, "AgSignDataToImageBase64");

		if (pFunc)
		{
			string strPath;
			int nMaxSize = 400;

			cout << "����ǩ�������ļ�����:" << endl;

			cin >> strPath;

			cout << "����ͼƬ��߳ߴ�(����):" << endl;

			cin >> nMaxSize;

			if (nMaxSize < 100)
				nMaxSize = 100;
			if (nMaxSize > 2000)
				nMaxSize = 2000;

			cout << endl;

			ifstream in(strPath);

			stringstream ss;

			ss << in.rdbuf();

			string strData = ss.str();
			size_t origsize = strData.length() + 1;
			const size_t newsize = 100;
			size_t convertedChars = 0;
			wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(strData.length() - 1));
			mbstowcs_s(&convertedChars, wcstring, origsize, strData.c_str(), _TRUNCATE);
			//wstring strRet = pFunc(AgAnsi2T(strData).c_str(), nMaxSize);
				wstring strRet = pFunc(wcstring, nMaxSize);
			wcout << strRet << endl;
		}
	}

	cout << endl;

	system("pause");

	return 0;
}

