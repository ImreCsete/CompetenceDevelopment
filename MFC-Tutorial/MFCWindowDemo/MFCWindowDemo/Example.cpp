#include <afxwin.h>

/* 1. To show content of application, derive frame/window for CFrameWnd
*  2. Add style to window, remove minimize, maximize, close options
*  3. Specify location and size of window
*  4. Specify that window has no parent with NULL value as last argument
*/

class CMyFrame : public CFrameWnd {
public:
	CMyFrame() {
		Create(NULL, _T("MFC Application Tutorial"), WS_VISIBLE | WS_OVERLAPPED, CRect(90, 120, 550, 480), NULL);
	}
};

/* 1. Create application, derive from CWinApp
*  2. Let application use the window by using pointer to frame
*/

class CExample : public CWinApp {
	BOOL InitInstance() {
		CMyFrame* Frame = new CMyFrame(); m_pMainWnd = Frame;

		Frame->ShowWindow(SW_NORMAL);
		Frame->UpdateWindow();

		return TRUE;
	}
};

CExample theApp;