#include "ball.h"

Ball::Ball(){
	this->collide = false;
	this->posx = 0;
	this->posy = 0;
	this->v = new Vettore();
	this->img = NULL;
}

Ball::Ball(string name){
	this->collide = false;
	this->posx = 0;
	this->posy = 0;
	this->v = new Vettore();
	this->img = new Image(name);
}

Ball::Ball(int xpos, int ypos, string name){
	this->collide = false;
	this->posx = xpos;
	this->posy = ypos;
	this->v = new Vettore();
	this->img = new Image(name);
}

Ball::Ball(int xpos, int ypos, int x, int y, string name){
	this->collide = false;
	this->posx = xpos;
	this->posy = ypos;
	this->v = new Vettore(x,y);
	this->img = new Image(name);
}

Ball::~Ball(){
	delete this->v;
	delete this->img;
}

int Ball::getPosX() const{
	return this->posx;
}

int Ball::getPosY() const{
	return this->posy;
}

Vettore * Ball::getVett() const{
	return this->v;
}

Image * Ball::getImg() const{
	return this->img;
}

float Ball::getRadius() const{
	return this->img->getWidth() / 2;
}

float Ball::getDiameter() const{
	return this->img->getWidth();
}

bool Ball::getCollide() const{
	return this->collide;
}

void Ball::setCollide(bool c){
	this->collide = c;
}

void Ball::setPosX(int x){
	this->posx = x;
}

void Ball::setPosY(int y){
	this->posy = y;
}

void Ball::setVett(Vettore * w){
	this->v = w;
}

void Ball::setImg(Image * i){
	this->img = i;
}
