#ifndef VETTORE_H
#define VETTORE_H

#include <cmath>

using namespace std;

class Vettore{
	private:
		float x;
		float y;
		
		float toGrad(float) const;
		float toRad(float) const;
	public:
		Vettore();
		Vettore(float , float);
		~Vettore();
		
		float getX() const;
		float getY() const;
		float getAngle() const;
		float getModule() const;
		
		void setX(float);
		void setY(float);
		void setAngle(float);
		void setModule(float);
		
		void reverseX();
		void reverseY();
		void reverse();
		
		Vettore operator+(const Vettore &) const;
		Vettore * operator+(const Vettore *) const;
};
#endif		
