#pragma once
#include <afxwin.h>
#include <gdiplus.h>
#include <vector>
#include <thread>
#include <random>

using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")

class CYoutubeTask1Dlg : public CDialogEx {
public:
    CYoutubeTask1Dlg(CWnd* pParent = nullptr);
    enum { IDD = IDD_YOUTUBETASK1_DIALOG };

protected:
    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange* pDX);
    DECLARE_MESSAGE_MAP()

private:
    std::vector<CPoint> points;
    int userRadius;
    int borderThickness;
    bool dragging;
    int selectedPoint;

    void DrawShapes(Graphics& g);
    void Reset();
    void StartRandomMovement();

    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnReset();
    afx_msg void OnRandomMove();
};
