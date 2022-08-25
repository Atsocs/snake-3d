//
// Created by atsocs on 27/04/2020.
//

#include "ColorsCharlesCorrea.h"
#include <array>
#include <iostream>
#include <cassert>

Color GetCharlesColor(ColorCharlesCorrea pallete, int index)
{
	using pallete_type = std::array<std::array<int, 3>, 5>;

	static const pallete_type AppleGreen =
			{{
					 {149, 178, 50},
					 {116, 143, 21},
					 {84, 108, 0},
					 {56, 72, 0},
					 {29, 38, 0},
			 }};

	static const pallete_type RedScarletBasicDefault
			= {{
					   {196, 71, 52},
					   {160, 41, 22},
					   {126, 17, 0},
					   {88, 12, 0},
					   {49, 7, 0},
			   }};

	static const pallete_type NavyDarkDefault
			= {{
					   {50, 100, 164},
					   {0, 62, 142},
					   {0, 49, 113},
					   {0, 37, 84},
					   {0, 21, 48},
			   }};

	static const pallete_type PinkDarkDefault
			= {{
					   {189, 66, 174},
					   {177, 31, 159},
					   {160, 0, 140},
					   {128, 0, 113},
					   {100, 0, 87},
			   }};

	static const pallete_type TurquoiseBasicDefault
			= {{
					   {129, 198, 184},
					   {10, 157, 128},
					   {0, 126, 101},
					   {0, 103, 83},
					   {0, 76, 61},
			   }};

	static const pallete_type BrownBasicDefault
			= {{
					   {111, 71, 58},
					   {89, 47, 32},
					   {63, 27, 15},
					   {38, 12, 4},
					   {17, 4, 0},
			   }};

	static const pallete_type YellowBasicDefault
			= {{
					   {255, 208, 92},
					   {247, 189, 47},
					   {219, 158, 7},
					   {177, 126, 0},
					   {136, 97, 0},
			   }};

	static const pallete_type OrangeBasicDefault
			= {{
					   {255, 176, 96},
					   {255, 155, 53},
					   {245, 124, 0},
					   {193, 97, 0},
					   {151, 76, 0},
			   }};

	static const pallete_type RebeccaPurple
			= {{
					   {160, 121, 200},
					   {124, 78, 171},
					   {101, 51, 153},
					   {80, 27, 133},
					   {59, 13, 106},
			   }};

	static const pallete_type MidnightBasicDefault
			= {{
					   {97, 116, 135},
					   {66, 88, 110},
					   {44, 62, 80},
					   {27, 49, 71},
					   {12, 32, 50},
			   }};

	std::array<std::array<int, 3>, 5> usingPallete{};
	switch (pallete)
	{

		case ColorCharlesCorrea::APPLE_GREEN:
			usingPallete = AppleGreen;
			break;
		case ColorCharlesCorrea::RED_SCARLET_BASIC_DEFAULT:
			usingPallete = RedScarletBasicDefault;
			break;
		case ColorCharlesCorrea::NAVY_DARK_DEFAULT:
			usingPallete = NavyDarkDefault;
			break;
		case ColorCharlesCorrea::PINK_DARK_DEFAULT:
			usingPallete = PinkDarkDefault;
			break;
		case ColorCharlesCorrea::TURQUOISE_BASIC_DEFAULT:
			usingPallete = TurquoiseBasicDefault;
			break;
		case ColorCharlesCorrea::BROWN_BASIC_DEFAULT:
			usingPallete = BrownBasicDefault;
			break;
		case ColorCharlesCorrea::YELLOW_BASIC_DEFAULT:
			usingPallete = YellowBasicDefault;
			break;
		case ColorCharlesCorrea::REBECCA_PURPLE:
			usingPallete = RebeccaPurple;
			break;
		case ColorCharlesCorrea::MIDNIGHT_BASIC_DEFAULT:
			usingPallete = MidnightBasicDefault;
			break;
		default:
			std::cout << "not handled pallete" << std::endl;
			assert(false);
	}

	return Color{static_cast<unsigned char>(usingPallete[index][0]),
	             static_cast<unsigned char>(usingPallete[index][1]),
	             static_cast<unsigned char>(usingPallete[index][2]),
	             255};
}


Color GetCharlesColor(int index)
{
	static constexpr int colorsPerPallete = 5;
	static constexpr int mod = colorsPerPallete * static_cast<int>(ColorCharlesCorrea::MAX_COLOR_CHARLES_CORREA);
	int color = ((index % mod) + mod) % mod;
	auto pallete = static_cast<ColorCharlesCorrea>(color / 5);
	index = color % colorsPerPallete;
	return GetCharlesColor(pallete, index);
}