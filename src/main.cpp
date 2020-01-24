#include <iostream>
#include "SDL2/SDL.h"

using namespace std;

const int WIDTH = 800, HEIGHT = 600; 


int main(int argc, char* argv[]) {

  if( SDL_Init( SDL_INIT_EVERYTHING) < 0){
      cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
      return EXIT_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow("Asteroid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

  if( window == NULL){
    cout << "Could not create window: " << SDL_GetError() << endl;
    return EXIT_FAILURE;
  }


  SDL_Renderer* renderer = NULL;
  renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

  // Set render color to red ( background will be rendered in this color )
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

  // Clear winow
  SDL_RenderClear( renderer );

  // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
  SDL_Rect r;
  r.x = 50;
  r.y = 50;
  r.w = 50;
  r.h = 50;


  // Set render color to blue ( rect will be rendered in this color )
  SDL_SetRenderDrawColor( renderer, 255, 0, 255, 255 );

  // Render rect
  SDL_RenderFillRect( renderer, &r );
  SDL_RenderDrawLine( renderer , 20, 20, 400, 400 );

  // Render the rect to the screen
  SDL_RenderPresent(renderer);

  SDL_Event windowEvent;
  while(true){
    if(SDL_PollEvent( &windowEvent)){
      if(SDL_QUIT == windowEvent.type){
        break;
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
