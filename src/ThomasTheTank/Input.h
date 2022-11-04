#include <SDL2/SDL.h>
#include <list>
#include <memory>
#include "Wrapping/ThomasMath.h"

#define Shared std::shared_ptr
#define Weak std::weak_ptr

namespace ThomasTheTank
{
	/**
	* Input manager class
	*/
	struct Input
	{
		/**
		* Check if specified key was pressed between frames.
		* 
		* \param SDL_Keycode code Key identifier.
		* 
		* \return BOOL Whether key was pressed.
		*/
		bool getKeyDown(SDL_Keycode code);

		/**
		* Check if specified key was released between frames.
		*
		* \param SDL_Keycode code Key identifier.
		*
		* \return BOOL Whether key was pressed.
		*/
		bool getKeyUp(SDL_Keycode code);

		/**
		* Check if specified key is currently pressed.
		*
		* \param SDL_Keycode code Key identifier.
		*
		* \return BOOL Current key state.
		*/
		bool getKey(SDL_Keycode code);

		/**
		* Check if specified button is currently pressed.
		*
		* \param INT _button button identifier.
		*
		* \return BOOL Current button state.
		*/
		bool getButton(int _button);

		/**
		* Check if specified button was pressed between frames.
		*
		* \param INT _button button identifier.
		*
		* \return BOOL Whether button was pressed.
		*/
		bool getButtonDown(int _button);

		/**
		* Check if specified button was released between frames.
		*
		* \param INT _button button identifier.
		*
		* \return BOOL Whether button was released.
		*/
		bool getButtonUp(int _button);

		/**
		* Get the raw position of the mouse within the window in pixels.
		* returns VEC3 with z always being equal to 0.
		* 
		* \return VEC3 Mouse position in pixels.
		*/
		vec3 mousePosition() { return mousePos; };
		
		/**
		* Get the mouse input in pixels relative to the previous frame
		* 
		* \return VEC2 Mouse input in pixels.
		*/
		vec2 mouseInput() { return mouseInp; };

	private:
		friend class Core;
		static std::list<SDL_Keycode> keys; ///< List of all keys currently pressed.
		static std::list<SDL_Keycode> keyDown; ///< List of all keys pressed this frame.
		static std::list<SDL_Keycode> keyUp; ///< List of all keys released this frame.
		static std::list<int> buttons; ///< List of all buttons currently pressed.
		static std::list<int> buttonDown; ///< List of all buttons pressed this frame.
		static std::list<int> buttonUp; ///< List of all buttons released this frame.
		static vec3 mousePos; ///< The raw position of the mouse.
		static vec2 mouseInp; ///< The mouse input relative to the last frame.
	};

	/**
	* Key wrapping from SDL identifiers.
	*/
	struct Keys
	{
		static const int UP = SDLK_UP;
		static const int DOWN = SDLK_DOWN;
		static const int LEFT = SDLK_LEFT;
		static const int RIGHT = SDLK_RIGHT;
		static const int A = SDLK_a;
		static const int B = SDLK_b;
		static const int C = SDLK_c;
		static const int D = SDLK_d;
		static const int E = SDLK_e;
		static const int F = SDLK_f;
		static const int G = SDLK_g;
		static const int H = SDLK_h;
		static const int I = SDLK_i;
		static const int J = SDLK_j;
		static const int K = SDLK_k;
		static const int L = SDLK_l;
		static const int M = SDLK_m;
		static const int N = SDLK_n;
		static const int O = SDLK_o;
		static const int P = SDLK_p;
		static const int Q = SDLK_q;
		static const int R = SDLK_r;
		static const int S = SDLK_s;
		static const int T = SDLK_t;
		static const int U = SDLK_u;
		static const int V = SDLK_v;
		static const int W = SDLK_w;
		static const int X = SDLK_x;
		static const int Y = SDLK_y;
		static const int Z = SDLK_z;
		static const int key_0 = SDLK_0;
		static const int key_1 = SDLK_1;
		static const int key_2 = SDLK_2;
		static const int key_3 = SDLK_3;
		static const int key_4 = SDLK_4;
		static const int key_5 = SDLK_5;
		static const int key_6 = SDLK_6;
		static const int key_7 = SDLK_7;
		static const int key_8 = SDLK_8;
		static const int key_9 = SDLK_9;
		static const int FN_1 = SDLK_F1;
		static const int FN_2 = SDLK_F2;
		static const int FN_3 = SDLK_F3;
		static const int FN_4 = SDLK_F4;
		static const int FN_5 = SDLK_F5;
		static const int FN_6 = SDLK_F6;
		static const int FN_7 = SDLK_F7;
		static const int FN_8 = SDLK_F8;
		static const int FN_9 = SDLK_F9;
		static const int FN_10 = SDLK_F10;
		static const int FN_11 = SDLK_F11;
		static const int FN_12 = SDLK_F12;
		static const int SPACE = SDLK_SPACE;
		static const int BACKSPACE = SDLK_BACKSPACE;
		static const int RETURN = SDLK_RETURN;
		static const int ENTER = SDLK_KP_ENTER;
		static const int LSHIFT = SDLK_LSHIFT;
		static const int RSHIFT = SDLK_RSHIFT;
		static const int LCTRL = SDLK_LCTRL;
		static const int RCTRL = SDLK_RCTRL;
		static const int LALT = SDLK_LALT;
		static const int RALT = SDLK_RALT;
		static const int TAB = SDLK_TAB;
		static const int CAPSLOCK = SDLK_CAPSLOCK;
		static const int INSERT = SDLK_INSERT;
		static const int DELETE = SDLK_DELETE;
		static const int HOME = SDLK_HOME;
		static const int END = SDLK_END;
		static const int PGUP = SDLK_PAGEUP;
		static const int PGDN = SDLK_PAGEDOWN;
		static const int PRINTSCREEN = SDLK_PRINTSCREEN;
		static const int SCROLLLOCK = SDLK_SCROLLLOCK;
		static const int PAUSE = SDLK_PAUSE;
		static const int NUM_0 = SDLK_KP_0;
		static const int NUM_1 = SDLK_KP_1;
		static const int NUM_2 = SDLK_KP_2;
		static const int NUM_3 = SDLK_KP_3;
		static const int NUM_4 = SDLK_KP_4;
		static const int NUM_5 = SDLK_KP_5;
		static const int NUM_6 = SDLK_KP_6;
		static const int NUM_7 = SDLK_KP_7;
		static const int NUM_8 = SDLK_KP_8;
		static const int NUM_9 = SDLK_KP_9;
		static const int NUM_DOT = SDLK_KP_PERIOD;
		static const int NUM_ADD = SDLK_KP_PLUS;
		static const int NUM_MINUS = SDLK_KP_MINUS;
		static const int NUM_MULTIPLY = SDLK_KP_MULTIPLY;
		static const int NUM_DIVIDE = SDLK_KP_DIVIDE;
		static const int MINUS = SDLK_MINUS;
		static const int PLUS = SDLK_PLUS;
		static const int SEMICOLON = SDLK_SEMICOLON;
		static const int AT = SDLK_AT;
		static const int HASH = SDLK_HASH;
		static const int SLASH = SDLK_SLASH;
		static const int BACKSLASH = SDLK_BACKSLASH;
		static const int PERIOD = SDLK_PERIOD;
		static const int COMMA = SDLK_COMMA;
		static const int LSQUAREBRACKET = SDLK_LEFTBRACKET;
		static const int RSQUAREBRACKET = SDLK_RIGHTBRACKET;
	};
}