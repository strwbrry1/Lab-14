
#include "Windows.h"

void Image0(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4]{
        {cx, cy + 20},
        {cx + 20, cy - 20},
        {cx - 20, cy - 20},
        {cx, cy + 20}
    };

    Polyline(hdc, p, 4);
    DeleteObject(hPen);
}

void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        {cx, cy - 20},
        {cx + 20, cy + 20},
        {cx - 20, cy + 20},
        {cx, cy - 20}
    };
    Polyline(hdc, p, 4);

    DeleteObject(hPen);
}

void Image2(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[5] = {
        {cx, cy - 20},
        {cx + 20, cy},
        {cx, cy + 20},
        {cx - 20, cy},
        {cx, cy - 20}
    };
    Polyline(hdc, p, 5);

    DeleteObject(hPen);
}

void Image3(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[5] = {
        {cx, cy},
        {cx + 20, cy - 20},
        {cx, cy + 40},
        {cx - 20, cy - 20},
        {cx, cy}
    };
    Polyline(hdc, p, 5);

    DeleteObject(hPen);
}

void Image4(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(150, 255, 0));
    SelectObject(hdc, hPen);

    POINT p[6] = {
        {cx - 20, cy},
        {cx + 20, cy},
        {cx, cy - 10},
        {cx + 20, cy - 20},
        {cx - 20, cy - 20},
        {cx - 20, cy + 20}
    };
    Polyline(hdc, p, 6);

    DeleteObject(hPen);
}

void Image5(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 100, 100));
    SelectObject(hdc, hPen);

    POINT p[6] = {
        {cx, cy},
        {cx + 20, cy - 20},
        {cx + 20, cy + 20},
        {cx - 20, cy + 20},
        {cx - 20, cy - 20},
        {cx, cy}
    };
    Polyline(hdc, p, 6);

    DeleteObject(hPen);
}

void Image6(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(70, 70, 170));
    SelectObject(hdc, hPen);

    POINT p[13] = {
        {cx, cy},
        {cx + 10, cy - 10},
        {cx + 10, cy},
        {cx, cy + 10},
        {cx - 10, cy + 10},
        {cx - 10, cy},
        {cx + 10, cy - 20},
        {cx + 20, cy - 20},
        {cx + 20, cy},
        {cx, cy + 20},
        {cx - 20, cy + 20},
        {cx - 20, cy},
        {cx, cy - 20}
    };
    Polyline(hdc, p, 13);

    DeleteObject(hPen);
}
