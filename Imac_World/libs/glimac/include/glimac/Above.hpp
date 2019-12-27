#ifndef _ABOVE_HPP 
#define _ABOVE_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl.h>
#include <glimac/glm.hpp>
#include "glimac/ShapeGrid.hpp"

namespace glimac
{
	class Above
	{
		public:
			// Constructor
			Above(){};
			//Destructor
			~Above();
			void initImgui(SDL_Window* window,SDL_GLContext* glContext) const;
			void beginFrame(SDL_Window* window) const;
			void drawAbove(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, ShapeGrid &cubeSelect);
    		void endFrame(SDL_Window* window) const;
    		inline int getClickCreateCube(){return clickCreateCube;};
			inline int getClickDeleteCube(){return clickDeleteCube;};
			inline int getClickExtrudeCube(){return clickExtrudeCube;};
			inline int getClickDigCube(){return clickDigCube;};
			inline int getClickGenerateWorld(){return clickGenerateWorld;};
			inline int getClickSaveFile(){return clickSaveFile;};
			inline int getClickOpenFile(){return clickOpenFile;};
			inline int getClickDay(){return clickDay;};
			inline int getClickNight(){return clickNight;};

    	private:
    		int clickCreateCube;
			int clickDeleteCube;
			int clickExtrudeCube;
        	int clickDigCube;
        	int clickGenerateWorld;
        	int clickSaveFile;
        	int clickOpenFile;
        	int clickDay;
        	int clickNight;
	};
}

#endif 



