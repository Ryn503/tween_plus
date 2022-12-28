#include "Easing.hpp"
#include <cmath>

#define PI 3.141592741f

float Easing::easeLinear(float step)
{
    return step;
}

float Easing::easeInSine(float step)
{
    return 1.0f - cosf((step * PI) / 2.0f);
}

float Easing::easeOutSine(float step)
{
    return sinf((step * PI) / 2.0f);
}

float Easing::easeInOutSine(float step)
{
    return -(cosf(PI * step) - 1.0f) / 2.0f;
}

float Easing::easeOutInSine(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInSine(1.0f - 2.0f * step))
        : 0.5f * easeInSine(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeInCubic(float step)
{
    return step * step * step;
}

float Easing::easeOutCubic(float step)
{
    return 1.0f - powf(1.0f - step, 3.0f);
}

float Easing::easeInOutCubic(float step)
{
    return (step < 0.5) 
        ? 4.0f * step * step * step 
        : 1.0f - powf(-2.0f * step + 2.0f, 3.0f) / 2.0f;
}

float Easing::easeOutInCubic(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInCubic(1.0f - 2.0f * step))
        : 0.5f * easeInCubic(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeInQuint(float step)
{
    return step * step * step * step * step;
}

float Easing::easeOutQuint(float step)
{
    return 1.0f - powf(1.0 - step, 5.0);
}

float Easing::easeInOutQuint(float step)
{
    return (step < 0.5f) 
        ? 16.0f * step * step * step * step * step 
        : 1.0f - powf(-2.0f * step + 2.0f, 5.0f) / 2.0f;
}

float Easing::easeOutInQuint(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInQuint(1.0f - 2.0f * step))
        : 0.5f * easeInQuint(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeInCirc(float step)
{
    return 1.0f - sqrtf(1.0f - powf(step, 2.0f));
}

float Easing::easeOutCirc(float step)
{
    return sqrtf(1.0f - powf(step - 1.0f, 2.0f));
}

float Easing::easeInOutCirc(float step)
{
    return (step < 0.5f) 
        ? (1.0f - sqrtf(1.0f - powf(2.0f * step, 2.0f))) / 2.0f 
        : (sqrtf(1.0f - powf(-2.0f * step + 2.0f, 2.0f)) + 1.0f) / 2.0f;
}

float Easing::easeOutInCirc(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInCirc(1.0f - 2.0f * step))
        : 0.5f * easeInCirc(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeInElastic(float step)
{
    const float c4 = (2.0f * PI) / 3.0f;

    return (step == 0.0f) 
        ? 0.0f 
        : (step == 1.0f) 
        ? 1.0f 
        : -powf(2.0f, 10.0f * step - 10.0f) * sin((step * 10.0f - 10.75f) * c4);
}

float Easing::easeOutElastic(float step)
{
    const float c4 = (2.0f * PI) / 3.0f;

    return (step == 0.0f) 
        ? 0.0f 
        : (step == 1.0f) 
        ? 1.0f 
        : powf(2.0f, -10.0f * step) * sinf((step * 10.0f - 0.75f) * c4) + 1.0f;
}

float Easing::easeInOutElastic(float step)
{
    const float c5 = (2.0f * PI) / 4.5f;

    return (step == 0.0f) 
        ? 0.0f 
        : (step == 1.0f) 
        ? 1.0f 
        : (step < 0.5f) 
        ? -(powf(2.0f, 20.0f * step - 10.0f) * sinf((20.0f * step - 11.125f) * c5)) / 2.0f 
        : (powf(2.0f, -20.0f * step + 10.0f) * sinf((20.0f * step - 11.125f) * c5)) / 2.0f + 1.0f;
}

float Easing::easeOutInElastic(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInElastic(1.0f - 2.0f * step))
        : 0.5f * easeInElastic(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeInQuad(float step)
{
    return step * step;
}

float Easing::easeOutQuad(float step)
{
    return 1.0f - (1.0f - step) * (1.0f - step);
}

float Easing::easeInOutQuad(float step)
{
    return (step < 0.5f) 
        ? 2.0f * step * step 
        : 1.0f - powf(-2.0f * step + 2.0f, 2.0f) / 2.0f;
}

float Easing::easeOutInQuad(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInQuad(1.0f - 2.0f * step))
        : 0.5f * easeInQuad(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeInQuart(float step)
{
    return step * step * step * step;
}

float Easing::easeOutQuart(float step)
{
    return 1.0f - powf(1.0f - step, 4.0f);
}

float Easing::easeInOutQuart(float step)
{
    return (step < 0.5f) 
        ? 8.0f * step * step * step * step 
        : 1.0f - powf(-2.0f * step + 2.0f, 4.0f) / 2.0f;
}

float Easing::easeOutInQuart(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInQuart(1.0f - 2.0f * step))
        : 0.5f * easeInQuart(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeInExpo(float step)
{
    return (step == 0.0f) 
        ? 0.0f 
        : powf(2.0f, 10.0f * step - 10.0f);
}

float Easing::easeOutExpo(float step)
{
    return 1.0f - powf(2.0f, -8.0f * step);
}

float Easing::easeInOutExpo(float step)
{
    return (step == 0.0f) 
        ? 0.0f 
        : (step == 1.0f) 
        ? 1.0f 
        : (step < 0.5f) 
        ? powf(2.0f, 20.0f * step - 10.0f) / 2.0f 
        : (2.0f - powf(2.0f, -20.0f * step + 10.0f)) / 2.0f;
}

float Easing::easeOutInExpo(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInExpo(1.0f - 2.0f * step))
        : 0.5f * easeInExpo(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeInBack(float step)
{
    const float c1 = 1.70158f;
    const float c3 = c1 + 1.0f;

    return c3 * step * step * step - c1 * step * step;
}

float Easing::easeOutBack(float step)
{
    return 1.0f + (--step) * step * (2.70158f * step + 1.70158f);
}

float Easing::easeInOutBack(float step)
{
    const float c1 = 1.70158f;
    const float c2 = c1 + 1.525f;

    return (step < 0.5f) 
        ? (powf(2.0f * step, 2.0f) * ((c2 + 1.0f) * 2.0f * step - c2)) / 2.0f
        : (powf(2.0f * step - 2.0f, 2.0f) * ((c2 + 1.0f) * (step * 2.0f - 2.0f) + c2) + 2.0f) / 2.0f;
}

float Easing::easeOutInBack(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInBack(1.0f - 2.0f * step))
        : 0.5f * easeInBack(step * 2.0f - 1.0f) + 0.5f;
}

float Easing::easeOutBounce(float step)
{
    const float n1 = 7.5625f;
    const float d1 = 2.75f;

    if (step < 1.0f / d1) return n1 * step * step;
    if (step < 2.0f / d1) return n1 * (step -= 1.5f / d1) * step + 0.75f;
    if (step < 2.5f / d1) return n1 * (step -= 2.25f / d1) * step + 0.9375f;

    return n1 * (step -= 2.625f / d1) * step + 0.984375f;
}

float Easing::easeInBounce(float step)
{
    return 1.0f - easeOutBounce(1.0f - step);
}

float Easing::easeInOutBounce(float step)
{
    return (step < 0.5f)
        ? (1.0f - easeOutBounce(1.0f - 2.0f * step)) / 2.0f
        : (1.0f + easeOutBounce(2.0f * step - 1.0f)) / 2.0f;
}

float Easing::easeOutInBounce(float step)
{
    return (step < 0.5f)
        ? 0.5f * (1.0f - easeInBounce(1.0f - 2.0f * step))
        : 0.5f * easeInBounce(step * 2.0f - 1.0f) + 0.5f;
}