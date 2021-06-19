# wearApi
```cpp
@param: HINSTANCE hInstance
@param: HINSTANCE hPrevInstance
@param: LPWSTR lpCmdLine
@param: int nCmdShow

wear::FORM().broadcastProc(); <- Transmitting program input parameters
```
----------------------------------------------------------------------
```cpp
@param int cbClsExtra 
@param int cbWndExtra
@param HRBRUSH backgroundColor
@param PWSTR cursor 
@param PWSTR icon
@param PWSTR iconSmall
@param DWORD style 
@param LPCWSTR classname
@param WNDCPROC callback ( [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT { 
    ... 
} )

wear::FORM().initialization(); <- Initializing the main method
```
-------------------------------------------------------------------------------------------------
```cpp
Get variable

wear::FORM().messege  <-  returns MSG
wear::FORM().hwnd     <-  returns hwnd
wear::FORM().wc       <-  returns ClasseEx

```
---------------------------------------------------------------------------------------------------
struct's && function
```cpp                                              
  struct coord -> constructor -> wear::coord(X = 10, Y = 10)            <- return value's x and y
  struct rgbS  -> constructor  -> wear::rgbS(R = 255, G = 255, B = 255) <- return value (r, g, b)
  
  wear::color(rgbS(NULL, NULL, NULL))  <- return HBRUSH 
  wear::colorR(rgbS(NULL, NULL, NULL)) <- return COLORREF
```
---------------------------------------------------------------------------------------------------
Create main form
```cpp
@param LPCSTR title
@param DWORD style
@param coord position
@param coord size
@param HMENU menu
@param HWND parent 
@param LPVOID lParam 

wear::FORM().create() <- create form

```
---------------------------------------------------------------------------------------------------
Elements WinApi

```cpp
wear::BUTTON().create(			
LPCSTR        content,
wear::coord   pos,
wear::coord   size,
DWORD         styles,
BYTE          ID,
wear::FORM    parent)

wear::CHECKBOX().create(			
LPCSTR          content,
wear::coord     pos,
wear::coord     size,
DWORD           styles,
BYTE            ID,
wear::FORM      parent)

wear::LABEL().create(
LPCSTR          content,
wear::coord     pos,
wear::coord     size,
DWORD           styles,
BYTE            ID,
wear::FORM      parent
)

```
--------------------------------------------------------------------------------------------------
