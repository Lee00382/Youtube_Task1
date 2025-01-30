#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"

class CYoutubeTask1App : public CWinApp {
public:
    CYoutubeTask1App();
    virtual BOOL InitInstance();
    DECLARE_MESSAGE_MAP()
};

extern CYoutubeTask1App theApp;
