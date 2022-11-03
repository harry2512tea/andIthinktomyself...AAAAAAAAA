#include <SDL2/SDL.h>
#include <list>
#include <memory>

#define Shared std::shared_ptr
#define Weak std::weak_ptr




namespace ThomasTheTank
{
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
	};

	struct Input
	{
		bool getKeyDown(SDL_Keycode code);
		bool getKeyUp(SDL_Keycode code);
		bool getKey(SDL_Keycode code);
		//bool getMouseButtonDown();

	private:
		friend class Core;
		static std::list<SDL_Keycode> keys;
		static std::list<SDL_Keycode> keyDown;
		static std::list<SDL_Keycode> keyUp;
	};
}