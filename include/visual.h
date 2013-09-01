#ifndef __NGUI_VISUAL_H
#define __NGUI_VISUAL_H

#include <string>

namespace NGUI{
	struct Rect{
		Rect(int sx, int sy, int x, int y):
			w_(sx), h_(sy), x_(x), y_(y)
		{}
		int w_, h_;
		int x_, y_;
	};

	struct Texture{
		Texture(unsigned int index):
			index_(index)
		{}
		unsigned int index_;
	};
	
	struct Text{
		Text(const std::string& text, const std::string& font, int width, int x, int y):
			text_(text),
			font_(font),
			width_(width),
			x_(x), y_(y)
		{}
		std::string text_;
		std::string font_;
		int width_;
		int x_, y_;
	};

	struct VisualPacket{
		VisualPacket(const Rect& rect, const Texture& tex, const Text& text):
			rect_(rect), tex_(tex), text_(text)
		{}
		Rect    rect_;
		Texture tex_;
		Text    text_;
	};
}

#endif