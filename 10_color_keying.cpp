/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
//#undef main

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int GRID_SIZE = 20;
const int INITIAL_SNAKE_SIZE = 4;
const int SNAKE_SPEED = 200;  // Delay between snake movements in milliseconds

// Direction enum
enum class Direction { UP, DOWN, LEFT, RIGHT };

// Snake segment struct
struct SnakeSegment {
    int x, y;
};

//int main(int argc, char* argv[]) {
//    // Initialize SDL
//    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
//        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    // Create the game window
//    SDL_Window* window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
//    if (!window) {
//        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
//        SDL_Quit();
//        return 1;
//    }
//
//    // Create the game renderer
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (!renderer) {
//        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        return 1;
//    }
//
//    // Initialize the game variables
//    std::vector<SnakeSegment> snake;
//    Direction snakeDirection = Direction::RIGHT;
//    int foodX = 0, foodY = 0;
//    int score = 0;
//    bool quit = false;
//
//    // Set initial snake position
//    for (int i = 0; i < INITIAL_SNAKE_SIZE; ++i) {
//        snake.push_back({ WINDOW_WIDTH / 2 - i * GRID_SIZE, WINDOW_HEIGHT / 2 });
//    }
//
//    // Game loop
//    while (!quit) {
//        SDL_Event event;
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_QUIT) {
//                quit = true;
//            }
//            else if (event.type == SDL_KEYDOWN) {
//                switch (event.key.keysym.sym) {
//                case SDLK_UP:
//                    snakeDirection = Direction::UP;
//                    break;
//                case SDLK_DOWN:
//                    snakeDirection = Direction::DOWN;
//                    break;
//                case SDLK_LEFT:
//                    snakeDirection = Direction::LEFT;
//                    break;
//                case SDLK_RIGHT:
//                    snakeDirection = Direction::RIGHT;
//                    break;
//                }
//            }
//        }
//
//        // Move the snake
//        int headX = snake.front().x;
//        int headY = snake.front().y;
//        switch (snakeDirection) {
//        case Direction::UP:
//            headY -= GRID_SIZE;
//            break;
//        case Direction::DOWN:
//            headY += GRID_SIZE;
//            break;
//        case Direction::LEFT:
//            headX -= GRID_SIZE;
//            break;
//        case Direction::RIGHT:
//            headX += GRID_SIZE;
//            break;
//        }
//
//        // Check for collision with food
//        if (headX == foodX && headY == foodY) {
//            // Increase score
//            score++;
//
//            // Generate new food position
//            foodX = (rand() % (WINDOW_WIDTH / GRID_SIZE)) * GRID_SIZE;
//            foodY = (rand() % (WINDOW_HEIGHT / GRID_SIZE)) * GRID_SIZE;
//
//            // Increase snake size
//            snake.push_back({});
//        }
//        else {
//            // Remove tail segment
//            snake.pop_back();
//        }
//
//        // Check for self-collision
//        for (const auto& segment : snake) {
//            if (segment.x == headX && segment.y == headY) {
//                quit = true;
//                break;
//            }
//        }
//
//        // Add new head segment
//        snake.insert(snake.begin(), { headX, headY });
//
//        // Clear the screen
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        SDL_RenderClear(renderer);
//
//        // Draw snake
//        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//        for (const auto& segment : snake) {
//            SDL_Rect rect{ segment.x, segment.y, GRID_SIZE, GRID_SIZE };
//            SDL_RenderFillRect(renderer, &rect);
//        }
//
//        // Draw food
//        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//        SDL_Rect foodRect{ foodX, foodY, GRID_SIZE, GRID_SIZE };
//        SDL_RenderFillRect(renderer, &foodRect);
//
//        // Update the screen
//        SDL_RenderPresent(renderer);
//
//        // Delay for snake movement
//        SDL_Delay(SNAKE_SPEED);
//    }
//
//    // Clean up and quit
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}

//Texture wrapper class
//class LTexture
//{
//	public:
//		//Initializes variables
//		LTexture();
//
//		//Deallocates memory
//		~LTexture();
//
//		//Loads image at specified path
//		bool loadFromFile( std::string path );
//
//		//Deallocates texture
//		void free();
//
//		//Renders texture at given point
//		void render( int x, int y );
//
//		//Gets image dimensions
//		int getWidth();
//		int getHeight();
//
//	private:
//		//The actual hardware texture
//		SDL_Texture* mTexture;
//
//		//Image dimensions
//		int mWidth;
//		int mHeight;
//};
//
////Starts up SDL and creates window
//bool init();
//
////Loads media
//bool loadMedia();
//
////Frees media and shuts down SDL
//void close();
//
////The window we'll be rendering to
//SDL_Window* gWindow = NULL;
//
////The window renderer
//SDL_Renderer* gRenderer = NULL;
//
////Scene textures
//LTexture gFooTexture;
//LTexture gBackgroundTexture;
//
//
//LTexture::LTexture()
//{
//	//Initialize
//	mTexture = NULL;
//	mWidth = 0;
//	mHeight = 0;
//}
//
//LTexture::~LTexture()
//{
//	//Deallocate
//	free();
//}
//
//bool LTexture::loadFromFile( std::string path )
//{
//	//Get rid of preexisting texture
//	free();
//
//	//The final texture
//	SDL_Texture* newTexture = NULL;
//
//	//Load image at specified path
//	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
//	if( loadedSurface == NULL )
//	{
//		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
//	}
//	else
//	{
//		//Color key image
//		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
//
//		//Create texture from surface pixels
//        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
//		if( newTexture == NULL )
//		{
//			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
//		}
//		else
//		{
//			//Get image dimensions
//			mWidth = loadedSurface->w;
//			mHeight = loadedSurface->h;
//		}
//
//		//Get rid of old loaded surface
//		SDL_FreeSurface( loadedSurface );
//	}
//
//	//Return success
//	mTexture = newTexture;
//	return mTexture != NULL;
//}
//
//void LTexture::free()
//{
//	//Free texture if it exists
//	if( mTexture != NULL )
//	{
//		SDL_DestroyTexture( mTexture );
//		mTexture = NULL;
//		mWidth = 0;
//		mHeight = 0;
//	}
//}
//
//void LTexture::render( int x, int y )
//{
//	//Set rendering space and render to screen
//	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
//	SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
//}
//
//int LTexture::getWidth()
//{
//	return mWidth;
//}
//
//int LTexture::getHeight()
//{
//	return mHeight;
//}
//
//bool init()
//{
//	//Initialization flag
//	bool success = true;
//
//	//Initialize SDL
//	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
//	{
//		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
//		success = false;
//	}
//	else
//	{
//		//Set texture filtering to linear
//		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
//		{
//			printf( "Warning: Linear texture filtering not enabled!" );
//		}
//
//		//Create window
//		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//		if( gWindow == NULL )
//		{
//			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
//			success = false;
//		}
//		else
//		{
//			//Create renderer for window
//			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
//			if( gRenderer == NULL )
//			{
//				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
//				success = false;
//			}
//			else
//			{
//				//Initialize renderer color
//				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
//
//				//Initialize PNG loading
//				int imgFlags = IMG_INIT_PNG;
//				if( !( IMG_Init( imgFlags ) & imgFlags ) )
//				{
//					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
//					success = false;
//				}
//			}
//		}
//	}
//
//	return success;
//}
//
//bool loadMedia()
//{
//	//Loading success flag
//	bool success = true;
//
//	//Load Foo' texture
//	if( !gFooTexture.loadFromFile( "foo.png" ) )
//	{
//		printf( "Failed to load Foo' texture image!\n" );
//		success = false;
//	}
//	
//	//Load background texture
//	if( !gBackgroundTexture.loadFromFile( "background.png" ) )
//	{
//		printf( "Failed to load background texture image!\n" );
//		success = false;
//	}
//
//	return success;
//}
//
//void close()
//{
//	//Free loaded images
//	gFooTexture.free();
//	gBackgroundTexture.free();
//
//	//Destroy window	
//	SDL_DestroyRenderer( gRenderer );
//	SDL_DestroyWindow( gWindow );
//	gWindow = NULL;
//	gRenderer = NULL;
//
//	//Quit SDL subsystems
//	IMG_Quit();
//	SDL_Quit();
//}
//
//int main( int argc, char* args[] )
//{
//	//Start up SDL and create window
//	if( !init() )
//	{
//		printf( "Failed to initialize!\n" );
//	}
//	else
//	{
//		//Load media
//		if( !loadMedia() )
//		{
//			printf( "Failed to load media!\n" );
//		}
//		else
//		{	
//			//Main loop flag
//			bool quit = false;
//
//			//Event handler
//			SDL_Event e;
//
//			//While application is running
//			while( !quit )
//			{
//				//Handle events on queue
//				while( SDL_PollEvent( &e ) != 0 )
//				{
//					//User requests quit
//					if( e.type == SDL_QUIT )
//					{
//						quit = true;
//					}
//				}
//
//				//Clear screen
//				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
//				SDL_RenderClear( gRenderer );
//
//				//Render background texture to screen
//				gBackgroundTexture.render( 0, 0 );
//
//				//Render Foo' to the screen
//				gFooTexture.render( 240, 190 );
//
//				//Update screen
//				SDL_RenderPresent( gRenderer );
//			}
//		}
//	}
//
//	//Free resources and close SDL
//	close();
//
//	return 0;
//}