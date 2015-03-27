#version 330

in vec2 UV;

uniform sampler2D tex;

uniform vec4 tint;

void main() {
    gl_FragColor = texture(tex, UV) * tint;
}
