#ifndef BALL_H
#define BALL_H

#include "image.h"
#include "vettore.h"
#include <string>

using namespace std;

class Ball{
	private:
		bool collide;
		int posx;
		int posy;
		Vettore * v;
		Image * img;
	public:
		Ball();
		Ball(string); //file img
		Ball(int, int, string); //pos + file img
		Ball(int, int, int, int, string); //pos + vett + file img
		~Ball();
		
		int getPosX() const;
		int getPosY() const;
		Vettore * getVett() const;
		Image * getImg() const;
		float getRadius() const;
		float getDiameter() const;
		bool getCollide() const;
		
		void setCollide(bool);
		void setPosX(int);
		void setPosY(int);
		void setVett(Vettore *);
		void setImg(Image *);
};
#endif
