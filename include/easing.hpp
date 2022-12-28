#ifndef EASING_HPP
#define EASING_HPP

struct Easing
{
    static float easeLinear(float step);
    static float easeInSine(float step);
    static float easeOutSine(float step);
    static float easeInOutSine(float step);
    static float easeOutInSine(float step);
    static float easeInCubic(float step);
    static float easeOutCubic(float step);
    static float easeInOutCubic(float step);
    static float easeOutInCubic(float step);
    static float easeInQuint(float step);
    static float easeOutQuint(float step);
    static float easeInOutQuint(float step);
    static float easeOutInQuint(float step);
    static float easeInCirc(float step);
    static float easeOutCirc(float step);
    static float easeInOutCirc(float step);
    static float easeOutInCirc(float step);
    static float easeInElastic(float step);
    static float easeOutElastic(float step);
    static float easeInOutElastic(float step);
    static float easeOutInElastic(float step);
    static float easeInQuad(float step);
    static float easeOutQuad(float step);
    static float easeInOutQuad(float step);
    static float easeOutInQuad(float step);
    static float easeInQuart(float step);
    static float easeOutQuart(float step);
    static float easeInOutQuart(float step);
    static float easeOutInQuart(float step);
    static float easeInExpo(float step);
    static float easeOutExpo(float step);
    static float easeInOutExpo(float step);
    static float easeOutInExpo(float step);
    static float easeInBack(float step);
    static float easeOutBack(float step);
    static float easeInOutBack(float step);
    static float easeOutInBack(float step);
    static float easeOutBounce(float step);
    static float easeInBounce(float step);
    static float easeInOutBounce(float step);
    static float easeOutInBounce(float step);
};

#endif