#include "pch.h"
#include "framework.h"
#include "Youtube_Task1.h"
#include "Youtube_Task1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CYoutubeTask1App, CWinApp)
END_MESSAGE_MAP()

CYoutubeTask1App::CYoutubeTask1App() {}

CYoutubeTask1App theApp;

BOOL CYoutubeTask1App::InitInstance() {
    CWinApp::InitInstance();
    CYoutubeTask1Dlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    return FALSE;
}
