#pragma once

namespace View
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define VI_MOUSE_BUTTON_0      ::View::Mouse::Button0
#define VI_MOUSE_BUTTON_1      ::View::Mouse::Button1
#define VI_MOUSE_BUTTON_2      ::View::Mouse::Button2
#define VI_MOUSE_BUTTON_3      ::View::Mouse::Button3
#define VI_MOUSE_BUTTON_4      ::View::Mouse::Button4
#define VI_MOUSE_BUTTON_5      ::View::Mouse::Button5
#define VI_MOUSE_BUTTON_6      ::View::Mouse::Button6
#define VI_MOUSE_BUTTON_7      ::View::Mouse::Button7
#define VI_MOUSE_BUTTON_LAST   ::View::Mouse::ButtonLast
#define VI_MOUSE_BUTTON_LEFT   ::View::Mouse::ButtonLeft
#define VI_MOUSE_BUTTON_RIGHT  ::View::Mouse::ButtonRight
#define VI_MOUSE_BUTTON_MIDDLE ::View::Mouse::ButtonMiddle