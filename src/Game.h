#ifndef GAME_H
#define GAME_H 
#include <SDL2/SDL.h>

class Game {
private:
	SDL_Window * window ; 
	SDL_Renderer * renderer ; 
public: 
    Game() ; 
    ~Game() ; 
    void initialize  (); 
	void processInput () ; 
	void update () ; 
	void render () ; 
	void run () ; 		 
    void destroy () ; 
    
} ;  
#endif
