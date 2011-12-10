#include "view.h"

View::View(){
	SDL_Init(SDL_INIT_EVERYTHING);
	this->screen = NULL;
	this->scr_widht = 0;
	this->scr_height = 0;
	this->scr_depht = 32;
}

View::View(int w, int h, int d){
	SDL_Init(SDL_INIT_EVERYTHING);
	this->scr_widht = w;
	this->scr_height = h;
	this->scr_depht = d;
	this->screen = SDL_SetVideoMode(w, h, d, SDL_SWSURFACE | SDL_DOUBLEBUF);
}

View::~View(){
	SDL_FreeSurface(this->screen);
	SDL_Quit();
}

SDL_Surface * View::getScreen() const{
	return this->screen;
}

int View::getWidht() const{
	return this->scr_widht;
}

int View::getHeight() const{
	return this->scr_height;
}

int View::getDepht() const{
	return this->scr_depht;
}

void View::setWidht(int w){
	this->scr_widht = w;
}

void View::setHeight(int h){
	this->scr_height = h;
}

void View::setDepht(int d){
	this->scr_depht = d;
}

void View::drawImage(Image * img){
	SDL_BlitSurface(img->getSurface(), NULL, this->screen, NULL);
}

void View::drawImage(Image * img, int x, int y){
	
	SDL_Rect * rettangolo = new SDL_Rect();
	//the rectangle has 4 parameters: x , y , w , h 
        rettangolo->x = x;
        rettangolo->y = y;
        
        SDL_BlitSurface(img->getSurface(), NULL, this->screen, rettangolo);
        delete rettangolo;
}

void View::refresh(){
	SDL_Flip(this->screen);
}
