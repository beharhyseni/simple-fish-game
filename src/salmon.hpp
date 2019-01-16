#pragma once

#include "common.hpp"

class Turtle;
class Fish;
class Shark;

class Salmon : public Renderable
{
public:
	// Creates all the associated render resources and default transform
	bool init();

	// Releases all associated resources
	void destroy();
	
	// Update salmon position based on direction
	// ms represents the number of milliseconds elapsed from the previous update() call
	void update(float ms);
	
	// Renders the salmon
	void draw(const mat3& projection)override;

	// Collision routines for turtles and fish
	bool collides_with(const Turtle& turtle);
	bool collides_with(const Fish& fish);
	bool collides_with(const Shark& shark);

	// Returns the current salmon position
	vec2 get_position()const;

	// Calculates the angle between salmon facing direction point and mouse direction
	float calc_angle(double p1, double p2, double xpos, double ypos);

	// Return the previous direction of the salmon (x coordinate)
	double get_prev_x();

	// Return the previous direction of the salmon (y coordinate)
	double get_prev_y();

	// Save the mouse position coordinates (will be used to save the coordinates from World Class to Salmon Class)
	void set_salmon_prev_facing_position(double x, double y);

	// Moves the salmon's position by the specified offset
	void move(vec2 off);

	// Set salmon rotation in radians
	void set_rotation(float radians);

	// True if the salmon is alive
	bool is_alive()const;

	// Kills the salmon, changing its alive state and triggering on death events
	void kill();

	// Called when the salmon collides with a fish, starts lighting up the salmon
	void light_up();

	// Set the Salmon light state (if just ate a fish: set 1; else 0)
	void set_light(int n);


	// Set salmon movement flag (used to keep track of the stte of the user keys)
	void Salmon::set_movement(const std::string& flag);

	// Get salmon movement flag (used to keep track of the stte of the user keys)
	bool Salmon::get_movement(const std::string& flag);

private:
	float m_light_up_countdown_ms; // Used to keep track for how long the salmon should be lit up
	bool m_is_alive; // True if the salmon is alive
	vec2 m_position; // Window coordinates
	vec2 m_scale; // 1.f in each dimension. 1.f is as big as the associated texture
	float m_rotation; // in radians
	size_t m_num_indices; // passed to glDrawElements
};
