#include<windows.h>
#include<stdio.h>
#include<math.h>
#pragma comment(lib,"user32.lib") 
#pragma comment(lib,"gdi32.lib")
const double pi = 3.14159265;

void ClearWind1(HDC hdc, int SCREEN_WIDTH, int SCREEN_HEIGHT);
int main1(int argc, char *argv[])
{
	TCHAR title[256];//����̨�������
	GetConsoleTitle(title, 256);//��ȡ����̨����
	//��ͨ��FindWindow�������������ȡ���ھ��HWND��֮��������GetDC��������HWND��ȡHDC
	HWND hWnd = FindWindow(0, title);
	HDC hdc = GetDC(hWnd);//HDC���豸����������/��ȡ��Ļ��ʾDC��

	int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN); //��Ļ���   
	int SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN); //��Ļ�߶�  

	double rho, theta, x, y;//�������ֱ������
	HPEN hPen1, hPen2, hPen3;
	hPen1 = CreatePen(PS_SOLID, 0, RGB(255, 155, 0));//��ӻ�������
	hPen2 = CreatePen(PS_SOLID, 0, RGB(0, 255, 0));//��ӻ�������
	hPen3 = CreatePen(PS_SOLID, 0, RGB(0, 0, 255));//��ӻ�������

	for (int j = 0; j<1000; j++){
		ClearWind1(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);//����	
		for (int i = 0; i<20000; i++)
		{
			theta = -pi + pi / 10000.0*i;
			rho = 1 + cos(7 * (theta + j / 100.0)) + pow(1.5*(sin(3 * (theta + j / 100.0))), 2);
			x = 400 + 50 * rho*cos(theta);
			y = 300 - 50 * rho*sin(theta);

			//��֧��ͬɫ�ı�
			if (theta<(-pi / 3.0)){
				SelectObject(hdc, hPen1);//���ʰ󶨵����
			}
			if (theta>-pi / 3.0)
			{
				SelectObject(hdc, hPen2);//���ʰ󶨵����
			}
			if (theta>pi / 3.0)
			{
				SelectObject(hdc, hPen3);//���ʰ󶨵����
			}
			MoveToEx(hdc, 400, 300, NULL); //���Ƶ����
			LineTo(hdc, (int)x, (int)y); //������ͼ
		}
		Sleep(10);//��ʱ ms
	}
	return 0;
}

void ClearWind1(HDC hdc, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	HPEN hPen;
	HBRUSH hBrush;
	hBrush = CreateSolidBrush(RGB(0, 128, 128));
	hPen = CreatePen(PS_SOLID, 0, RGB(0, 128, 128));
	SelectObject(hdc, hBrush);
	SelectObject(hdc, hPen);
	Rectangle(hdc, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

