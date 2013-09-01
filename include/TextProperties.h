#ifndef __NGUI_TEXT_PROPERTIES_H
#define __NGUI_TEXT_PROPERTIES_H

#include "Dim.h"
#include <string>

namespace NGUI{
	struct TextProperties{
		TextProperties(void):
			font_(""),
			width_(0),
			x_(0, 0.5f), y_(0, 0.5f)
		{}
		std::string font_;
		int         width_;
		NGUI::Dim   x_, y_;
	};
}

#endif