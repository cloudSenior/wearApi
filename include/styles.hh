#pragma once
#include <map>
#include <Windows.h>

#include "math.hh"
#include "types.hh"



namespace wear {
	using namespace wear;

	const std::map< cstr, DWORD > styles = {{"Border", WS_BORDER},
											{"Caption", WS_CAPTION},
											{"child", WS_CHILD},
											{"childWindow", WS_CHILDWINDOW},
											{"clpchildren", WS_CLIPCHILDREN},
											{"disable", WS_DISABLED},
											{"scroll", WS_HSCROLL},
											{"icon", WS_ICONIC},
											{"maximize", WS_MAXIMIZE},
											{"maximizebox", WS_MAXIMIZEBOX},
											{"minimmize", WS_MINIMIZE},
											{"minimmizebox", WS_MINIMIZEBOX},
											// Window styles
											{"overlappedwindow", WS_OVERLAPPEDWINDOW},
											{"overlapped", WS_OVERLAPPED},
											{"systemenu", WS_SYSMENU},
											{"thickframe", WS_THICKFRAME},
											{"popup", WS_POPUP},
											{"popupwindow", WS_POPUPWINDOW},
											{"sizebox", WS_SIZEBOX},
											{"tabstop", WS_TABSTOP},
											// button styles
											{"checkbox", BS_AUTOCHECKBOX}};

	std::map< cstr, LPCSTR > classElement {{"button", LPCSTR ("button")}, {"label", LPCSTR ("static")}, };

} // namespace wear