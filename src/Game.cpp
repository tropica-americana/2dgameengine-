#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
Game::Game(){
    isrunning = true ;
    std::cout<<"constructor being called " <<std::endl;
} ;
Game::~Game(){

    std::cout<<"game destructor being called  " <<std::endl;
};

void Game::initialize(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ){
        std::cout << "problem initializing everything"<<std::endl ;

        isrunning = false ;
            return ;
    }
    // SDL_DisplayMode displaymode ;
    //  SDL_GetCurrentDisplayMode ( 0 // this is the display index
                           //    , &displaymode ) ;
    int displayheight ; // generating local variables of height
    int displaywidth ;  // generating local variables of width
    displayheight =   600 ;  //displaymode.h ; // get the current height of the mac screen
    displaywidth =    860 ;  //displaymode.w ; // get the current width of the mac screen
    
    window = SDL_CreateWindow(
        NULL ,
        SDL_WINDOWPOS_CENTERED , // horizontal distance of window from the center
        SDL_WINDOWPOS_CENTERED , //horizontal  distance of the window from the center
        displaywidth, // HORIZTONTAL WIDTH AS PARAMETER
        displayheight , // VERTICAL LENGTH AS PARAMETER
        SDL_WINDOW_BORDERLESS
    );
    if(!window ) {
        std::cout<<"problem creating SDL window " <<std::endl ;
        isrunning = false ;   // if there was problem in running the window then please dont go in the while loop
        return ;
    }
     renderer = SDL_CreateRenderer(window
    , -1 // this is the window number which you wanna draw graohics into
    , 0 );
    if (!renderer ) {
        isrunning = false ;
        std::cout << " problem rendering the graphics on to the window " <<std::endl ;
        return ;
    }
    SDL_SetWindowFullscreen ( window , SDL_WINDOW_FULLSCREEN ) ;
    
    
    //--------------------------------------initialize tank image ---------------------------------------//
    SDL_Surface * surface = IMG_Load ("./assets/images/tank-tiger-right.png");
    tank_image_texture   = SDL_CreateTextureFromSurface (renderer , surface);
    SDL_FreeSurface(surface) ;
    
    
};


void Game::destroy() {
    SDL_DestroyWindow (window ) ;
    SDL_DestroyRenderer (renderer) ;
    SDL_Quit () ;
} ;

void Game::processInput () {
    SDL_Event sdlEvent ;

    while (SDL_PollEvent(&sdlEvent)){

        switch (sdlEvent.type) {

            case SDL_QUIT:

                isrunning = false ;
                break ;
            case SDL_KEYDOWN :
                if (sdlEvent.key.keysym.sym == SDLK_ESCAPE ){
                    isrunning = false ;
                }
                break;
        }
    }
    
    return ;
} ;
void Game::render () {
    
    SDL_SetRenderDrawColor( renderer , 21 , 21 , 21 , 255 ) ; // make background color as grey
    SDL_RenderClear (renderer ) ; // clear all the rectangle from our renderer
    SDL_Rect dstRect {10 ,10 ,32 ,32 }; // create a rectangle where we wanna render our texture
    SDL_RenderCopy(renderer , tank_image_texture , NULL , &dstRect) ; 
  //  SDL_DestroyTexture(texture) ;    // we dont wanna delete the tank texture
    SDL_RenderPresent(renderer) ; // swap the displyed renderer with the current renderer
};

void Game::update () {
    return ;
} ;
void Game::run () {
    while (isrunning ) {
        processInput() ;
        update () ;
        render () ;
    }
    destroy() ;
    return  ;
};



