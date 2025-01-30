#include "pch.h"
#include "Youtube_Task1Dlg.h"

BEGIN_MESSAGE_MAP(CYoutubeTask1Dlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_BN_CLICKED(IDC_RESET_BUTTON, &CYoutubeTask1Dlg::OnReset)
    ON_BN_CLICKED(IDC_RANDOM_BUTTON, &CYoutubeTask1Dlg::OnRandomMove)
END_MESSAGE_MAP()

CYoutubeTask1Dlg::CYoutubeTask1Dlg(CWnd* pParent)
    : CDialogEx(IDD_YOUTUBETASK1_DIALOG, pParent), dragging(false), selectedPoint(-1), userRadius(50), borderThickness(2) {
}

BOOL CYoutubeTask1Dlg::OnInitDialog() {
    CDialogEx::OnInitDialog();
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
    return TRUE;
}

void CYoutubeTask1Dlg::DrawShapes(Graphics& g) {
    if (points.size() < 3) return;

    Pen pen(Color(255, 0, 0), 5);
    for (const auto& p : points) {
        g.FillEllipse(&pen, static_cast<Gdiplus::REAL>(p.x - 5),
            static_cast<Gdiplus::REAL>(p.y - 5),
            static_cast<Gdiplus::REAL>(10),
            static_cast<Gdiplus::REAL>(10));
    }

    int x1 = points[0].x, y1 = points[0].y;
    int x2 = points[1].x, y2 = points[1].y;
    int x3 = points[2].x, y3 = points[2].y;

    int d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (d == 0) return;

    int ux = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / d;
    int uy = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / d;

    Pen circlePen(Color(0, 0, 255), borderThickness);
    g.DrawEllipse(&circlePen, static_cast<Gdiplus::REAL>(ux - userRadius),
        static_cast<Gdiplus::REAL>(uy - userRadius),
        static_cast<Gdiplus::REAL>(userRadius * 2),
        static_cast<Gdiplus::REAL>(userRadius * 2));
}

void CYoutubeTask1Dlg::OnPaint() {
    CPaintDC dc(this);
    Graphics g(dc);
    DrawShapes(g);
}

void CYoutubeTask1Dlg::OnReset() {
    points.clear();
    Invalidate();
}

void CYoutubeTask1Dlg::OnRandomMove() {
    std::thread([this]() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distX(50, 400);
        std::uniform_int_distribution<int> distY(50, 300);

        for (int i = 0; i < 10; i++) {
            for (auto& p : points) {
                p.x = distX(gen);
                p.y = distY(gen);
            }
            Invalidate();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        }).detach();
}
