#include "control.h"

Control::Control(){
	this->gravity = new Vettore();
}

Control::Control(Vettore * v){
	this->gravity = v;
}

Control::Control(int x, int y){
	this->gravity = new Vettore(x,y);
}

Control::~Control(){
	delete this->gravity;
}

Vettore * Control::getGravity() const{
	return this->gravity;
}

void Control::setGravity(Vettore * g){
	this->gravity = g;
}

void Control::move(Ball * b){
	int dx = b->getVett()->getX();
	int dy = - b->getVett()->getY();
	b->setPosX(b->getPosX() + dx);
	b->setPosY(b->getPosY() + dy);
}

void Control::collide(Ball * b1, Ball * b2){
	
	
	int x1, y1, x2, y2;
	x1 = b1->getPosX();
	y1 = b1->getPosY();
	x2 = b2->getPosX();
	y2 = b2->getPosY();
	float angle;
	float a,b,c;
	
	a = abs(y1 - y2);
	b = abs(x1 - x2);
	c = sqrt(pow(a,2) + pow(b,2));
	
	
	//calcolo dell'angolo
	if(c != 0)
		angle = this->toGrad(acos(b/c));
	else
		angle = 0;
	
	if(x1 < x2){
		if(y1 < y2){
			angle = 180 - angle;
		}else{
			angle += 180;
		}
	}else{
		if(y1 < y2){
			angle = angle;
		}else{
			angle = 360 - angle;
		}
	}
	
	while(angle < 0) angle += 360;
	while(angle >= 360) angle -= 360;
	
	
	//scambio dei vettori
	Vettore * n = b1->getVett();
	b1->setVett( b2->getVett() );
	b2->setVett( n );
	
	//variazione dell'angolazione
	b1->getVett()->setAngle(angle);
	b2->getVett()->setAngle(angle + 180);
	
	
	//imposta un attrito durante l'urto
	float x = this->percentuale( b1->getVett()->getX(), 10);
	float y = this->percentuale( b1->getVett()->getY(), 10);
	Vettore * attrito = new Vettore( -x,-y );
	this->applyVector(b1, attrito);
	x = this->percentuale( b2->getVett()->getX(), 10);
	y = this->percentuale( b2->getVett()->getY(), 10);
	attrito->setX(-x);
	attrito->setY(-y);
	this->applyVector(b2, attrito);
	
	delete attrito;
	
	
	
	//muovi b1 e b2 finche non smettono di collidere
	while(this->getDistanza(b1,b2) < b1->getDiameter()){
		this->move(b1);
		this->move(b2);
	}
	
}

void Control::applyGravity(Ball * b){
	this->applyVector(b, this->gravity);
}

void Control::controlEdges(Ball * b, int x, int y){
	Vettore * reverse = b->getVett();
	Vettore * attrito = new Vettore(1,0);
	
	if(b->getPosX() < 0){
		reverse->reverseX();
		while(b->getPosX() < 0)
			this->move(b);
	}
	
	if( ( b->getPosX() + b->getDiameter() ) > x){
		reverse->reverseX();
		while( ( b->getPosX() + b->getDiameter() ) > x)
			this->move(b);
	}
	
	if(b->getPosY() < 0){
		reverse->reverseY();
		while(b->getPosY() < 0)
			this->move(b);
	}
	
	if( ( b->getPosY() + b->getDiameter() ) > y){
		reverse->reverseY();
		
		while( ( b->getPosY() + b->getDiameter() ) > y)
			b->setPosY( b->getPosY() - 1 );
		
		
		
		if(this->gravity->getModule() != 0){
			if(reverse->getModule() > 2){
				attrito->setX( abs(percentuale(reverse->getX(), 10)) );
				if(reverse->getX() > 0)
					attrito->setX( -attrito->getX() );
				this->applyVector(b , attrito);
				this->applyVector(b , this->gravity);
				
			}else{
				reverse->setY(0);
				reverse->setX(0);
			}
		}
		
	}
	
	delete attrito;
}

void Control::applyVector(Ball * x, Vettore * v){
	Vettore * result = new Vettore();
	*result = (*(x->getVett())) + (*v);
	x->setVett( result );
}

float Control::percentuale(float mod, float percent){
	return (mod * percent)/100;
}

float Control::toGrad(float rad){
	return (360 * rad / (2 * M_PI));
}

float Control::middleAngle(float a, float b){
	float middle;
	bool traslatoa = false , traslatob = false;
	if(abs(a-b)>180){
		if(a < b){
			a += 360;
			traslatoa = true;
		}else{
			b += 360;
			traslatob = true;
		}
	}
	
	middle = abs(a-b) / 2;
	
	if(abs(a-b) == 180){
		middle = b+180;
		if(middle>=360) middle -=360;
	}
	
	if(traslatoa) a -= 360;
	if(traslatob) b -= 360;
	
	if(abs(a-b) > 180){
		if(a < b)
			middle = a-middle;
		else
			middle = b-middle;
	}else{
		if(a<b)
			middle = a + middle;
		else
			middle = b + middle;
	}
		
	return middle;
}

float Control::getDistanza(Ball * x, Ball * y) const {
	float a = x->getPosX() - y->getPosX();
	float b = x->getPosY() - y->getPosY();
	return sqrt(pow(a, 2) + pow(b, 2));
	//teorema di pitagora xD
}
