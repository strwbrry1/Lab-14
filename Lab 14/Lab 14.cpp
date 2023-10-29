// Lab 14.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab 14.h"

#include "images.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int img_x = 100;
int img_y = 100;

int imgN = 1;
int imgM = 1;

int type = 0;
int wheelDelta = 0;

int r = 0;
int g = 0;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB14, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB14));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB14));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB14);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT: // стрелка ВЛЕВО
            img_x -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT: // стрелка ВПРАВО
            img_x += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP: // стрелка Вverx
            img_y -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN: // стрелка Вniz
            img_y += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_SPACE:
            type++;
            if (type > 6) type = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x49: //I
            if (imgN > 0) {
                imgN -= 1;
            }
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4f: //O
            imgN += 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x55: //U
            if (imgM > 0) {
                imgM -= 1;
            }
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4e: //N
            imgM += 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case MOUSE_WHEELED:
            wheelDelta = GET_WHEEL_DELTA_WPARAM(wParam);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;
    case WM_LBUTTONDOWN:
        WORD xPos, yPos;

        // Сохраняем координаты курсора мыши
        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);

        img_x = xPos;
        img_y = yPos;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_MOUSEWHEEL: // КРУТИТЬ КОЛЁСИКО ВПЕРЕД/НАЗАД ЧТОБЫ ИЗМЕНИТЬ ЦВЕТ
        if (wheelDelta > WHEEL_DELTA) {
            r += 25;
            g += 25;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else  if (wheelDelta < WHEEL_DELTA ) {
            r -= 25;
            g -= 25;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        /*for (; wheelDelta > WHEEL_DELTA; wheelDelta -= WHEEL_DELTA) {
            r += 25;
            g += 25;
        }  
        for (; wheelDelta < 0; wheelDelta += WHEEL_DELTA) {
            r -= 25;
            g -= 25;
        }*/     
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            
            if (type == 0) {
                for (int i = 0; i <= imgN * 50; i += 50) {
                    for (int j = 0; j <= imgM * 50; j += 50) {
                        Image0(hdc, img_x + i, img_y + j, RGB(r, g, 0));
                    }
                }   
            }
            if (type == 1) {
                for (int i = 0; i <= imgN * 50; i += 50) {
                    for (int j = 0; j <= imgM * 50; j += 50) {
                        Image1(hdc, img_x + i, img_y + j, RGB(r, g, 0));
                    }
                }
            }
            if (type == 2) {
                for (int i = 0; i <= imgN * 50; i += 50) {
                    for (int j = 0; j <= imgM * 50; j += 50) {
                        Image2(hdc, img_x + i, img_y + j, RGB(r, g, 0));
                    }
                }
            }
            if (type == 3) {
                for (int i = 0; i <= imgN * 50; i += 50) {
                    for (int j = 0; j <= imgM * 50; j += 50) {
                        Image3(hdc, img_x + i, img_y + j, RGB(r, g, 0));
                    }
                }
            }
            if (type == 4) {
                for (int i = 0; i <= imgN * 50; i += 50) {
                    for (int j = 0; j <= imgM * 50; j += 50) {
                        Image4(hdc, img_x + i, img_y + j);
                    }
                }
            }
            if (type == 5) {
                for (int i = 0; i <= imgN * 50; i += 50) {
                    for (int j = 0; j <= imgM * 50; j += 50) {
                        Image5(hdc, img_x + i, img_y + j);
                    }
                }
            }
            if (type == 6) {
                for (int i = 0; i <= imgN * 50; i += 50) {
                    for (int j = 0; j <= imgM * 50; j += 50) {
                        Image6(hdc, img_x + i, img_y + j);
                    }
                }
            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
