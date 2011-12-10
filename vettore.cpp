#include "vettore.h"

float Vettore::toRad(float gradi) const{
	return (gradi * 2 * M_PI / 360);
}

float Vettore::toGrad(float rad) const{
	return (360 * rad / (2 * M_PI));
}

Vettore::Vettore(){
	this->x = 0;
	this->y = 0;
}

Vettore::Vettore(float cos, float sen){
	this->y = sen;
	this->x = cos;
}

Vettore::~Vettore(){
}

float Vettore::getX() const{
	return this->x;
}

float Vettore::getY() const{
	return this->y;
}

float Vettore::getAngle() const{
	float angle;
	float module = this->getModule();
	
	if(module == 0)
		return 0;
	else 
		angle = this->toGrad(acos(abs(this->x) / module));
	
	if(this->y > 0){
		if(x < 0)
			angle = 180 - angle;
	}else if(this->y < 0){
		if(x > 0)
			angle = 360 - angle;
		else
			angle += 180;
	}else{
		if(x<0)
			angle = 180;
		else 
			angle = 0;
	}
	
	return angle;
}

float Vettore::getModule() const{
	return sqrt(pow(this->x , 2) + pow(this->y , 2));
}

void Vettore::setX(float cos){
	this->x = cos;
}

void Vettore::setY(float sen){
	this->y = sen;
}

void Vettore::setAngle(float angle){
	float module = this->getModule();
	this->x = module * cos( this->toRad(angle) );
	this->y = module * sin( this->toRad(angle) );
}

void Vettore::setModule(float mod){
	// mod : oldmod = newx : oldx
	this->x = (mod * this->x) / this->getModule();
	
	// mod : oldmod = newy : oldy
	this->y = (mod * this->y) / this->getModule();
}

void Vettore::reverseX(){
	this->x = - this->x;
}

void Vettore::reverseY(){
	this->y = - this->y;
}

void Vettore::reverse(){
	this->reverseX();
	this->reverseY();
}

Vettore Vettore::operator+(const Vettore & v) const{
	Vettore * sum = new Vettore(v.getX() + this->getX(), v.getY() + this->getY());
	return *sum;
}

Vettore * Vettore::operator+(const Vettore * v) const{
	Vettore * sum = new Vettore(v->getX() + this->getX(), v->getY() + this->getY());
	return sum;
}
	
	
