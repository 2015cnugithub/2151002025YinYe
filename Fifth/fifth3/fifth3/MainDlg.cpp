// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "fifth3.h"
#include "MainDlg.h"
#include "afxdialogex.h"


// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CDialog)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_Sphere_STATIC, bitmappp);
	DDX_Control(pDX, IDC_Sphere_STATIC, bitmappp);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_EN_CHANGE(IDC_Radius, &CMainDlg::OnEnChangeRadius)
	ON_EN_CHANGE(IDC_Volume, &CMainDlg::OnEnChangeVolume)
END_MESSAGE_MAP()


// CMainDlg 消息处理程序


void CMainDlg::OnEnChangeRadius()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMainDlg::OnEnChangeVolume()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
BOOL CMainDlg::PreTranslateMessage(MSG* pMsg)
{
	float radius, volume, surface;
	CEdit *pBoxR, *pBoxV, *pBoxS;
	pBoxR = (CEdit*)GetDlgItem(IDC_Radius);
	pBoxV = (CEdit*)GetDlgItem(IDC_Volume);
	pBoxS = (CEdit*)GetDlgItem(IDC_Surface);
	CString str;

	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		if (GetFocus() == GetDlgItem(IDC_Radius))  //根据不同控件焦点判断是那个在执行  
		{
			UpdateData(true);

			pBoxR -> GetWindowText(str);
			radius = _wtof(str);
			volume = 4.0 / 3.0 * 3.14 * (radius*radius*radius);
			surface = 4 * 3.14 * radius*radius;
			str.Format(_T("%.3f"), volume);
			pBoxV -> SetWindowText(str);
			str.Format(_T("%.3f"), surface);
			pBoxS -> SetWindowText(str);

			CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Sphere_STATIC); // 得到 Picture Control 句柄
			pWnd->ModifyStyle(0, SS_BITMAP); // 修改它的属性为位图
			pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, _T("sssphere.bmp"),
				IMAGE_BITMAP,
				100 * radius,
				100 * radius,
				LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE)); 
		}

		if (GetFocus() == GetDlgItem(IDC_Volume))  //根据不同控件焦点判断是那个在执行  
		{
			UpdateData(true);
			pBoxV->GetWindowText(str);
			volume = _wtof(str);
			radius = pow(3.0 * volume / 4 / 3.14,1.0/3);
			surface = 4 * 3.14 * radius*radius;
			str.Format(_T("%.3f"), radius);
			pBoxR->SetWindowText(str);
			str.Format(_T("%.3f"), surface);
			pBoxS->SetWindowText(str);

			CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Sphere_STATIC); // 得到 Picture Control 句柄
			pWnd->ModifyStyle(0, SS_BITMAP); // 修改它的属性为位图
			pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, _T("sssphere.bmp"),
				IMAGE_BITMAP,
				100 * radius,
				100 * radius,
				LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE));
		}

		if (GetFocus() == GetDlgItem(IDC_Surface))  //根据不同控件焦点判断是那个在执行  
		{
			UpdateData(true);
			pBoxS->GetWindowText(str);
			surface = _wtof(str);
			radius = pow(surface / 4 / 3.14, 1.0/2);
			volume = 4.0 / 3.0 * 3.14 * (radius*radius*radius);
			str.Format(_T("%.3f"), volume);
			pBoxV->SetWindowText(str);
			str.Format(_T("%.3f"), radius);
			pBoxR->SetWindowText(str);

			CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Sphere_STATIC); // 得到 Picture Control 句柄
			pWnd->ModifyStyle(0, SS_BITMAP); // 修改它的属性为位图
			pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, _T("sssphere.bmp"),
				IMAGE_BITMAP,
				100 * radius,
				100 * radius,
				LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE));
		}
	}
	if (pMsg->message == WM_LBUTTONDOWN)//左键按下  
	{
		int dx, dy, dd;
		CRect rc;
		GetWindowRect(&rc);//GetParent()->top = 202 left = 368
		CPoint pt;
		GetCursorPos(&pt);//x709 y245
		if (pt.x - rc.left > 341 && pt.y - rc.top > 43)
		{
			dx = abs(pt.x - 709);
			dy = abs(pt.y - 245);
			dd = max(dx, dy);
			CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Sphere_STATIC); // 得到 Picture Control 句柄
			pWnd->ModifyStyle(0, SS_BITMAP); // 修改它的属性为位图
			pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, _T("sssphere.bmp"),
				IMAGE_BITMAP,
				dd,
				dd,
				LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE));
			radius = dd / 100.0;
			volume = 4.0 / 3.0 * 3.14 * (radius*radius*radius);
			surface = 4 * 3.14 * radius*radius;

			str.Format(_T("%.3f"), surface);
			pBoxS->SetWindowText(str);
			str.Format(_T("%.3f"), volume);
			pBoxV->SetWindowText(str);
			str.Format(_T("%.3f"), radius);
			pBoxR->SetWindowText(str);
		}
		
	}
	//if (pMsg->message == WM_LBUTTONUP)//左键抬起  
	//{
	//	CPoint pt;
	//	GetCursorPos(&pt);
	//	CString sttttt;
	//	sttttt.Format(_T("%d,%d"), pt.x, pt.y);
	//	AfxMessageBox(sttttt);
	//}
		return 0; //这里必须返回0 否则运行报错  
}