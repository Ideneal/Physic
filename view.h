#ifndef VIEW_H
#define VIEW_H

#include <SDL/SDL.h>
#include "image.h"

class View{
	private:
		SDL_Surface * screen;
		int scr_widht;
		int scr_height;
		int scr_depht;
	public:
		View();
		View(int, int, int);
		~View();
		
		SDL_Surface * getScreen() const;
		int getWidht() const;
		int getHeight() const;
		int getDepht() const;
		
		void setWidht(int);
		void setHeight(int);
		void setDepht(int);
		
		void drawImage(Image *);
		void drawImage(Image *, int, int); //Image + pos
		void refresh();
};
#endif
