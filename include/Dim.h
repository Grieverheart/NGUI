#ifndef __NGUI_DIM_H
#define __NGUI_DIM_H

namespace NGUI{

	struct Dim{
		Dim(int pixels, float factor = 0.0f):
			pct(factor), px(pixels)
		{
			if(pct > 1.0f) pct = 1.0f;
			else if(pct < 0.0f) pct = 0.0f;
		}
		
		float pct;
		int   px;
	};

}
#endif