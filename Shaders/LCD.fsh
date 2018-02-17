#define COLOR_LOW 0.8
#define COLOR_HIGH 1.0
#define SCANLINE_DEPTH 0.1

vec4 scale(sampler2D image)
{
    vec2 texCoord = vec2(gl_FragCoord.x, uResolution.y - gl_FragCoord.y) / uResolution;
    
    vec2 pos = fract(texCoord * textureDimensions);
    vec2 sub_pos = fract(texCoord * textureDimensions * 6);
    
    vec4 center = texture(image, texCoord);
    vec4 left = texture(image, texCoord - vec2(1.0 / textureDimensions.x, 0));
    vec4 right = texture(image, texCoord + vec2(1.0 / textureDimensions.x, 0));
    
    if (pos.y < 1.0 / 6.0) {
        center = mix(center, texture(image, texCoord + vec2(0, -1.0 / textureDimensions.y)), 0.5 - sub_pos.y / 2.0);
        left =   mix(left,   texture(image, texCoord + vec2(-1.0 / textureDimensions.x, -1.0 / textureDimensions.y)), 0.5 - sub_pos.y / 2.0);
        right =  mix(right,  texture(image, texCoord + vec2( 1.0 / textureDimensions.x, -1.0 / textureDimensions.y)), 0.5 - sub_pos.y / 2.0);
        center *= sub_pos.y * SCANLINE_DEPTH + (1 - SCANLINE_DEPTH);
        left *= sub_pos.y * SCANLINE_DEPTH + (1 - SCANLINE_DEPTH);
        right *= sub_pos.y * SCANLINE_DEPTH + (1 - SCANLINE_DEPTH);
    }
    else if (pos.y > 5.0 / 6.0) {
        center = mix(center, texture(image, texCoord + vec2(0, 1.0 / textureDimensions.y)), sub_pos.y / 2.0);
        left =   mix(left,   texture(image, texCoord + vec2(-1.0 / textureDimensions.x, 1.0 / textureDimensions.y)), sub_pos.y / 2.0);
        right =  mix(right,  texture(image, texCoord + vec2( 1.0 / textureDimensions.x, 1.0 / textureDimensions.y)), sub_pos.y / 2.0);
        center *= (1.0 - sub_pos.y) * SCANLINE_DEPTH + (1 - SCANLINE_DEPTH);
        left *= (1.0 - sub_pos.y) * SCANLINE_DEPTH + (1 - SCANLINE_DEPTH);
        right *= (1.0 - sub_pos.y) * SCANLINE_DEPTH + (1 - SCANLINE_DEPTH);
    }
    
    
    vec4 midleft = mix(left, center, 0.5);
    vec4 midright = mix(right, center, 0.5);
    
    vec4 ret;
    if (pos.x < 1.0 / 6.0) {
        ret = mix(vec4(COLOR_HIGH * center.r, COLOR_LOW * center.g, COLOR_HIGH * left.b, 1),
                  vec4(COLOR_HIGH * center.r, COLOR_LOW * center.g, COLOR_LOW  * left.b, 1),
                  sub_pos.x);
    }
    else if (pos.x < 2.0 / 6.0) {
        ret = mix(vec4(COLOR_HIGH * center.r, COLOR_LOW  * center.g, COLOR_LOW * left.b, 1),
                  vec4(COLOR_HIGH * center.r, COLOR_HIGH * center.g, COLOR_LOW * midleft.b, 1),
                  sub_pos.x);
    }
    else if (pos.x < 3.0 / 6.0) {
        ret = mix(vec4(COLOR_HIGH * center.r  , COLOR_HIGH * center.g, COLOR_LOW * midleft.b, 1),
                  vec4(COLOR_LOW  * midright.r, COLOR_HIGH * center.g, COLOR_LOW * center.b, 1),
                  sub_pos.x);
    }
    else if (pos.x < 4.0 / 6.0) {
        ret = mix(vec4(COLOR_LOW * midright.r, COLOR_HIGH * center.g , COLOR_LOW  * center.b, 1),
                  vec4(COLOR_LOW * right.r   , COLOR_HIGH  * center.g, COLOR_HIGH * center.b, 1),
                  sub_pos.x);
    }
    else if (pos.x < 5.0 / 6.0) {
        ret = mix(vec4(COLOR_LOW * right.r, COLOR_HIGH * center.g  , COLOR_HIGH * center.b, 1),
                  vec4(COLOR_LOW * right.r, COLOR_LOW  * midright.g, COLOR_HIGH * center.b, 1),
                  sub_pos.x);
    }
    else {
        ret = mix(vec4(COLOR_LOW  * right.r, COLOR_LOW * midright.g, COLOR_HIGH * center.b, 1),
                  vec4(COLOR_HIGH * right.r, COLOR_LOW * right.g  ,  COLOR_HIGH * center.b, 1),
                  sub_pos.x);
    }
    
    return ret;
}
