#pragma once
#include <Windows.h>

namespace wear {
	struct coord { int x, y;  coord(int x, int y) { this->x = x; this->y = y; } };
	struct rgbS { BYTE r, g, b; rgbS(BYTE _r, BYTE _g, BYTE _b) { r = _r; g = _g;  b = _b; } };
	HBRUSH color(rgbS test) { return CreateSolidBrush(RGB(test.r, test.g, test.b)); }
	COLORREF colorR(rgbS test) { return RGB(test.r, test.g, test.b); }

		class FORM {
		public:

			void broadcastProc(
				HINSTANCE& hInstance,
				HINSTANCE& hPrevInstance,
				PWSTR& szCmdLine,
				int& nCmdShow)
			{
				this->hInstance = hInstance;
				this->hPrevInstance = hPrevInstance;
				this->szCmdLine = szCmdLine;
				this->nCmdShow = nCmdShow;
			}

			void initialization(
				int cbClsExtra = 0,
				int cbWndExtra = 0,
				HBRUSH background = WHITE_BRUSH,
				PWSTR cursor = (PWSTR)IDC_ARROW,
				PWSTR icon = (PWSTR)IDI_APPLICATION,
				PWSTR iconSm = (PWSTR)IDI_APPLICATION,
				UINT style = CS_VREDRAW | CS_HREDRAW,
				LPCWSTR className = L"FirstClass",
				WNDPROC funcR = nullptr)
			{
				wc.cbClsExtra = cbClsExtra;
				wc.cbWndExtra = cbWndExtra;
				wc.hbrBackground = background;
				wc.hCursor = LoadCursor(nullptr, (LPCSTR)cursor);
				wc.hIcon = LoadIcon(nullptr, (LPCSTR)icon);
				wc.hIconSm = LoadIcon(nullptr, (LPCSTR)iconSm);
				wc.hInstance = hInstance;
				wc.lpfnWndProc = funcR;
				wc.lpszClassName = (LPCSTR)className;
				wc.lpszMenuName = nullptr;
				wc.style = style;
			}



			HWND __stdcall create(
				LPCSTR title,
				DWORD style,
				coord position,
				coord size,
				HMENU menu,
				HWND parent = nullptr,
				LPVOID lParam = NULL)
			{
				return hwnd = CreateWindow(wc.lpszClassName, title, style, position.x, position.y, size.x, size.y, parent, menu, wc.hInstance, lParam);
			}

		public:
			HWND hwnd{};
			MSG message{};
			WNDCLASSEX wc{ sizeof(WNDCLASSEX) };

			HINSTANCE hInstance{}, hPrevInstance{};
			PWSTR szCmdLine{};
			int nCmdShow{};
		};

		class BUTTON {
		public:
			HWND create(LPCSTR content, coord pos, coord size, DWORD style, BYTE ID, FORM& parentWindow) {
				Form = parentWindow;
				return hButton = CreateWindow(
					LPCSTR("Button"), content,
					style | WS_VISIBLE | WS_CHILD,
					pos.x, pos.y, size.x, size.y,
					Form.hwnd, (HMENU)ID,
					NULL, NULL
				);
			}
			BOOL click(BYTE ID) { return LOWORD(wParams) == ID; }
		public:
			HWND	hButton{};
			FORM	Form{};
			WPARAM  wParams{};
		};


		class CHECKBOX {
		public:
			HWND create(LPCSTR content, coord pos, coord size, DWORD style, BYTE ID, FORM& parentWindow) {
				Form = parentWindow;
				return checkBox = CreateWindow(
					LPCSTR("button"), content,
					style | WS_CHILD | BS_AUTOCHECKBOX | WS_VISIBLE,
					pos.x, pos.y, size.x, size.y,
					Form.hwnd, (HMENU)ID,
					NULL, NULL
				);
			}
			BOOL click(BYTE ID) {
				return (HIWORD(wParams) == ID) == TRUE;
			}
		public:
			HWND	checkBox{};
			FORM	Form{};
			WPARAM  wParams{};
		};

		class LABEL {
		public:
			HWND create(LPCSTR content, DWORD style, coord pos, coord size, BYTE ID, FORM& parentWindow) {
				Form = parentWindow;
				return label = CreateWindow(
					LPCSTR("Static"), content,
					style | WS_CHILD | WS_VISIBLE,
					pos.x, pos.y, size.x, size.y,
					Form.hwnd, (HMENU)ID,
					NULL, NULL
				);
			}

			__inline
				void setTextColor(rgbS test) { SetTextColor((HDC)label, colorR(test)); }

			__inline
				void setBackgroundColor(rgbS test) { SetBkColor((HDC)label, colorR(test)); }
		public:
			HWND	label;
			FORM    Form;
		};
}