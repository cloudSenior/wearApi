#include <iostream>
#include <type_traits>

namespace wear {
#ifdef _DEBUG_WARNING
	template < class T > void warrning (T out_content)
	{
		static_assert (std::is_same< T, char >() || std::is_same< T, wchar_t >(),
					   "[Error] type this not char/wchar");
		std::clog << T << std::endl;
	}
#endif
#ifdef _DEBUG_ERROR
	template < class T > void error (T out_content)
	{
		static_assert (std::is_same< T, char >() || std::is_same< T,  wchar_t >(),
					   "[Error] type this not char/wchar");
		std::cerr << T << std::endl;
	}
#endif
} // namespace wear
