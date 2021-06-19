#include <Windows.h>
#include "engine.hh"

#define TitleForm (LPCSTR)"Hello World"


LRESULT CALLBACK WNDPROCESSING(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

wear::FORM __main;

int WINAPI wWinMain(_In_	 HINSTANCE hInstance,
					_In_opt_ HINSTANCE hPrevInstance,
					_In_	 LPWSTR	   lpCmdLine,
					_In_	 int	   nCmdShow)
{	
	__main.broadcastProc(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	__main.initialization(0, 0, wear::color(wear::rgbS(30
		, 30, 30)), 
		(PWSTR)IDC_ARROW, 
		(PWSTR)IDI_APPLICATION, 
		(PWSTR)IDI_APPLICATION, 
		3U,
		L"form1",
		[](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT {
			return WNDPROCESSING(hWnd, uMsg, wParam, lParam);
		});

	// Инцилизация микро-ядра формы
	MSG message   = __main.message;
	HWND hwnd     = __main.hwnd;
	WNDCLASSEX wc = __main.wc;

	
	if (!RegisterClassEx(&wc)) return EXIT_FAILURE;
	if (hwnd = __main.create(TitleForm, WS_MINIMIZE, wear::coord(450, 450), wear::coord(650, 250), nullptr, NULL, nullptr),
		hwnd == INVALID_HANDLE_VALUE) return EXIT_FAILURE;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&message, nullptr, 0, 0))
		TranslateMessage(&message), DispatchMessageW(&message);

	return static_cast<int>(message.wParam);
}


// Обработка сообщений
LRESULT __stdcall WNDPROCESSING(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_PAINT: {
		wear::BUTTON Start, Exit;
		wear::CHECKBOX UpdateVersion;

		Start.create(
			(LPCSTR)"Test",
			wear::coord(0, 0),
			wear::coord(150, 50),
			NULL,
			0,
			__main
		);

		Exit.create(
			(LPCSTR)"Exit",
			wear::coord(0, 50),
			wear::coord(150, 50),
			NULL,
			1,
			__main
		);


		UpdateVersion.create(
			(LPCSTR)"Test",
			wear::coord(0,100),
			wear::coord(149, 40),
			NULL, 3, __main
		);

		break;
	}

	case WM_COMMAND: {
		wear::BUTTON   eventButtonProcessing;
		wear::CHECKBOX eventCheckBoxProcessing;
		eventButtonProcessing.wParams   = wParam;
		eventCheckBoxProcessing.wParams = wParam;

		static BOOL lastClicked = FALSE;	

		if (eventButtonProcessing.click(0)) {
			MessageBox(NULL, "Button work", NULL, NULL);
		}

		if (eventButtonProcessing.click(1)) {
			PostQuitMessage(EXIT_SUCCESS);
		}

		// Включение обновление версии
		if (eventCheckBoxProcessing.click(3)) {
			MessageBox(NULL, "checkbox work", NULL, NULL);
		}	

		break;
	}


	case WM_DESTROY: { PostQuitMessage(EXIT_SUCCESS); break; }
		return NULL;
	}


	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}