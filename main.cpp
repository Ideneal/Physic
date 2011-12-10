#include <SDL/SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "image.h"
#include "view.h"
#include "control.h"
#include "vettore.h"
#include "ball.h"

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_DEPTH 32

int main(){
	srand(time(NULL));
	View * screen = new View(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH);
	Control * ctrl = new Control(0,-1);
	
	Ball * a = new Ball(500,50,-5,0,"blue_ball.bmp"); 
	Ball * b = new Ball(450,50,-2,0,"blue_ball.bmp");
	Ball * c = new Ball(150,150,5,5,"blue_ball.bmp");
	Ball * d = new Ball(400,350,-6,1,"blue_ball.bmp");
	Ball * e = new Ball(600,50,1,2,"blue_ball.bmp");
	
	vector<Ball *> balls;
	
	balls.push_back(a);
	balls.push_back(b);
	balls.push_back(c);
	balls.push_back(d);
	balls.push_back(e);
	
	//imposta trasparenza al bianco
	for(int i=0; i<balls.size(); i++)
		balls[i]->getImg()->setTransparent(255, 255, 255);
	
	bool running = true;
	
	Image * background = new Image("black_background.bmp");
	
	SDL_Event * event = new SDL_Event();
     	while(running){
     		while(SDL_PollEvent(event)){
     			if(event->type == SDL_QUIT)
     				running = false;
     			if(event->type == SDL_KEYDOWN){
     				if(event->key.keysym.sym == SDLK_SPACE){
     					Ball * nw = new Ball(0,0,5,0,"blue_ball.bmp");
     					nw->getImg()->setTransparent(255, 255, 255);
     					balls.push_back(nw);
     					
     				}
     			}
     		}
     		screen->drawImage(background);
     		

     		
     		
     		for(int i=0; i<balls.size(); i++){
     			ctrl->move(balls[i]);
     			ctrl->controlEdges(balls[i], SCREEN_WIDTH, SCREEN_HEIGHT);
     			ctrl->applyGravity(balls[i]);
     			screen->drawImage(balls[i]->getImg(), balls[i]->getPosX(), balls[i]->getPosY());
     		}
     		
     		for(int i=0; i<balls.size(); i++){
     			for(int j=0; j<balls.size(); j++){
     				if(i != j && !balls[i]->getCollide()){
     					if( ctrl->getDistanza(balls[i], balls[j]) < balls[i]->getDiameter() ){
     						ctrl->collide(balls[i], balls[j]);
     						balls[j]->setCollide(true);
     					}
     				}
     			}
     			balls[i]->setCollide(true);
     		}
     		
     		for(int i=0; i<balls.size() ; i++)
     			balls[i]->setCollide(false);
     		
     			
     		
     		
     			
     		screen->refresh();
     		SDL_Delay(10);
    	}
    	
    	while(balls.size() != 0){
    		delete balls[balls.size()-1];
    		balls.pop_back();
    	}
	
	delete background;
	delete event;
	delete ctrl;
	delete screen;
	
	return 0;
}
