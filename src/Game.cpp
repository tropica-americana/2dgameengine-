#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
Game::Game(){	
    std::cout<<"constructor being called " <<std::endl; 
} ; 
Game::~Game(){
	std::cout<<"game destructor being called  " <<std::endl; 
}; 

void Game::initialize(){
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0 ){
            std::cout << "problem initializing everything"<<std::endl ; 
            return ; 
    }
    window = SDL_CreateWindow( 
        NULL ,
        SDL_WINDOWPOS_CENTERED , 
        SDL_WINDOWPOS_CENTERED , 
        800 , // HORIZTONTAL WIDTH AS PARAMETER 
        600 , // VERTICAL LENGTH AS PARAMETER 
        SDL_WINDOW_BORDERLESS  
    );
    if(!window ) {
        std::cout<<"problem creating SDL window " <<std::endl ; 
        return ; 
    }
     renderer = SDL_CreateRenderer(window 
    , -1 // this is the window number which you wanna draw graohics into 
    , 0 );
    if (!renderer ) {
        std::cout << " problem rendering the graphics on to the window " <<std::endl ; 
        return ; 
    }
};
void Game::destroy() {
    SDL_DestroyWindow (window ) ; 
    SDL_DestroyRenderer (renderer) ; 
    SDL_Quit () ;   
} ; 

void Game::processInput () {
    SDL_Event
    
} ; 
