#include<afxwin.h>

class myframe :public CFrameWnd
{
public:
	myframe()
	{
		Create(0, "title");
	}
};

class myapp :public CWinApp
{
public:
	BOOL InitInstance()
	{
		myframe* pframe = new myframe;
		m_pMainWnd = pframe;
		pframe->ShowWindow(1);

		return TRUE;
	}
};

myapp obj;

