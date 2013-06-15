#ifndef __CMOUSE_H
#define __CMOUSE_H
#include "../include/manager.h"

class CMouse{
public:
	CMouse(void);
	~CMouse(void);
	
	void init(NGUI::Manager* gui_manager);
	void onMouse(int button, int state, int x, int y);
	void onMotion(int x, int y);
	void onPassiveMotion(int x, int y);
private:
	NGUI::Manager* gui_manager_;
	int windowWidth;
	int windowHeight;
};
#endif