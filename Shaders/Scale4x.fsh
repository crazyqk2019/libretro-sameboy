STATIC vec4 scale2x(sampler2D image, vec2 position, vec2 input_resolution, vec2 output_resolution)
{
    // o = offset, the width of a pixel
    vec2 o = 1.0 / input_resolution;
    // texel arrangement
    // A B C
    // D E F
    // G H I
    // vec4 A = texture(image, position + vec2( -o.x,  o.y));
    vec4 B = texture(image, position + vec2(    0,  o.y));
    // vec4 C = texture(image, position + vec2(  o.x,  o.y));
    vec4 D = texture(image, position + vec2( -o.x,    0));
    vec4 E = texture(image, position + vec2(    0,    0));
    vec4 F = texture(image, position + vec2(  o.x,    0));
    // vec4 G = texture(image, position + vec2( -o.x, -o.y));
    vec4 H = texture(image, position + vec2(    0, -o.y));
    // vec4 I = texture(image, position + vec2(  o.x, -o.y));
    vec2 p = position * input_resolution;
    // p = the position within a pixel [0...1]
    vec4 R;
    p = fract(p);
    if (p.x > .5) {
        if (p.y > .5) {
            // Top Right
            return equal(B, F) && inequal(B, D) && inequal(F, H) ? F : E;
        } else {
            // Bottom Right
            return equal(H, F) && inequal(D, H) && inequal(B, F) ? F : E;
        }
    } else {
        if (p.y > .5) {
            // Top Left
            return equal(D, B) && inequal(B, F) && inequal(D, H) ? D : E;
        } else {
            // Bottom Left
            return equal(D, H) && inequal(D, B) && inequal(H, F) ? D : E;
        }
    }
}

STATIC vec4 scale(sampler2D image, vec2 position, vec2 input_resolution, vec2 output_resolution)
{
    // o = offset, the width of a pixel
    vec2 o = 1.0 / (input_resolution * 2.);
    
    // texel arrangement
    // A B C
    // D E F
    // G H I
    // vec4 A = scale2x(image, position + vec2( -o.x,  o.y), input_resolution, output_resolution);
    vec4 B = scale2x(image, position + vec2(    0,  o.y), input_resolution, output_resolution);
    // vec4 C = scale2x(image, position + vec2(  o.x,  o.y), input_resolution, output_resolution);
    vec4 D = scale2x(image, position + vec2( -o.x,    0), input_resolution, output_resolution);
    vec4 E = scale2x(image, position + vec2(    0,    0), input_resolution, output_resolution);
    vec4 F = scale2x(image, position + vec2(  o.x,    0), input_resolution, output_resolution);
    // vec4 G = scale2x(image, position + vec2( -o.x, -o.y), input_resolution, output_resolution);
    vec4 H = scale2x(image, position + vec2(    0, -o.y), input_resolution, output_resolution);
    // vec4 I = scale2x(image, position + vec2(  o.x, -o.y), input_resolution, output_resolution);
    vec2 p = position * input_resolution * 2.;
    // p = the position within a pixel [0...1]
    p = fract(p);
    if (p.x > .5) {
        if (p.y > .5) {
            // Top Right
            return equal(B, F) && inequal(B, D) && inequal(F, H) ? F : E;
        } else {
            // Bottom Right
            return equal(H, F) && inequal(D, H) && inequal(B, F) ? F : E;
        }
    } else {
        if (p.y > .5) {
            // Top Left
            return equal(D, B) && inequal(B, F) && inequal(D, H) ? D : E;
        } else {
            // Bottom Left
            return equal(D, H) && inequal(D, B) && inequal(H, F) ? D : E;
        }
    }
}
