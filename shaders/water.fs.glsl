#version 330
uniform sampler2D screen_texture;
uniform float time;
uniform float dead_timer;

in vec2 uv;

layout(location = 0) out vec4 color;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// HANDLE THE WATER WAVE DISTORTION HERE (you may want to try sin/cos)
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
vec2 distort(vec2 uv) {

// The most basic form of the sine wave function is: A*sin(wt + p)
	
	float PI = 3.14159265359;

	// Amplitude
	float A = 0.01f;
	
	// Angular frequency
	float w = 2.f * PI * 0.5f;
	w = 4.f* w;

	// Phase
	float p = 0.f;

	// Sine wave function
	float yx = A * sin(w  * uv.x + p);
	float yy = A * sin(w  * uv.y + p);

	//vec2 coord = uv.xy;

	
    return vec2(uv.x + yy, uv.y + yx);
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// HANDLE THE COLOR SHIFTING HERE (you may want to make the image slightly blue-ish)
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
vec4 color_shift(vec4 in_color) {
	vec4 color = in_color;
	return color;
}

vec4 fade_color(vec4 in_color) {
	vec4 color = in_color;
	if (dead_timer > 0)
		color -= 0.1 * dead_timer * vec4(0.1, 0.1, 0.1, 0);

	return color;
}

void main()
{
	vec2 coord = distort(uv);

    vec4 in_color = texture(screen_texture, coord);
    color = color_shift(in_color);
    color = fade_color(color);
}