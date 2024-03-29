#pragma once

// internal
#include "common.hpp"
#include "salmon.hpp"
#include "turtle.hpp"
#include "fish.hpp"
#include "water.hpp"
#include "shark.hpp"
#include "puffer.hpp"
#include "whale.hpp"
#include "advturtle.hpp"


// stlib
#include <vector>
#include <random>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_mixer.h>

// Container for all our entities and game logic. Individual rendering / update is 
// deferred to the relative update() methods
class World
{
public:
	World();
	~World();

	// Creates a window, sets up events and begins the game
	bool init(vec2 screen);

	// Releases all associated resources
	void destroy();

	// Steps the game ahead by ms milliseconds
	bool update(float ms);

	// Renders our scene
	void draw();

	// Should the game be over ?
	bool is_over()const;


private:
	// Generates a new turtle
	bool spawn_turtle();

	// Generates a new fish
	bool spawn_fish();	

	// Generates a new shark
	bool spawn_shark();
	
	// Generates a new puffer
	bool spawn_puffer();

	// Generates a new puffer
	bool spawn_whale();
	
	// Generates a new puffer
	bool spawn_advturtle();


	// !!! INPUT CALLBACK FUNCTIONS
	void on_key(GLFWwindow*, int key, int, int action, int mod);
	void on_mouse_move(GLFWwindow* window, double xpos, double ypos);

private:
	// Window handle
	GLFWwindow* m_window;

	// Screen texture
	// The draw loop first renders to this texture, then it is used for the water shader
	GLuint m_frame_buffer;
	Texture m_screen_tex;

	// Water effect
	Water m_water;

	// Number of fish eaten by the salmon, displayed in the window title
	unsigned int m_points;

	// Game entities
	Salmon m_salmon;
	std::vector<Turtle> m_turtles;
	std::vector<Fish> m_fish;
	std::vector<Shark> m_sharks;
	std::vector<Puffer> m_puffer;
	std::vector<Whale> m_whales;
	std::vector<AdvTurtle> m_advturtles;

	float m_current_speed;
	float m_next_turtle_spawn;
	float m_next_fish_spawn;
	float m_next_shark_spawn;
	float m_next_puffer_spawn;
	float m_next_whale_spawn;
	float m_next_advturtle_spawn;
	
	Mix_Music* m_background_music;
	Mix_Chunk* m_salmon_dead_sound;
	Mix_Chunk* m_salmon_eat_sound;

	// C++ rng
	std::default_random_engine m_rng;
	std::uniform_real_distribution<float> m_dist; // default 0..1
};
