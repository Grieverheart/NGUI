#ifndef __NGUI_VISUAL_H
#define __NGUI_VISUAL_H

namespace NGUI{
	struct Rect{
		Rect(float sx, float sy, float x, float y):
			w_(sx), h_(sy), x_(x), y_(y)
		{}
		float w_, h_;
		float x_, y_;
	};

	struct Texture{
		Texture(void* data):
			data_(data)
		{}
		void* data_;
	};

	struct VisualPacket{
		VisualPacket(const Rect& rect, const Texture& tex):
			rect_(rect), tex_(tex)
		{}
		Rect    rect_;
		Texture tex_;
	};		
}

#endif