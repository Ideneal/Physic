#ifndef CONTROLL_H
#define CONTROLL_H

#include "ball.h"
#include "vettore.h"
#include <cmath>

using namespace std;

class Control{
	private:
		Vettore * gravity;
		
		float percentuale(float, float);
		float toGrad(float);
		float middleAngle(float, float);
	public:
		Control();
		Control(Vettore *);
		Control(int, int);
		~Control();
		
		Vettore * getGravity() const;
		
		void setGravity(Vettore *);
		
		void move(Ball *);
		void collide(Ball *, Ball *);
		void applyGravity(Ball *);
		void controlEdges(Ball *, int, int); //Ball + bordo(x,y)
		void applyVector(Ball *, Vettore *);
		float getDistanza(Ball *, Ball *) const;
};
#endif
