#include "tween.hpp"
#include <thread>
#include <algorithm>

const char* TweenAlreadyStarted::what()
{
    return "The tweening process already started.";
}

const char* NoTweeners::what()
{
    return "You can't tween without tweeners.";
}

Tween::Tween() = default;

void Tween::start(bool _parallel)
{
    if (running) throw TweenAlreadyStarted();
    if (tweeners.size() == 0) throw NoTweeners();
    
    parallel = _parallel;
    std::thread thread(&Tween::update, this);
    thread.detach();
    running = true;
}

void Tween::destroy()
{
    if (tweeners.size() == 0) throw NoTweeners();
    kill_all = true;
}

void Tween::set_loops(int _loops)
{
    loops = _loops;
}

bool Tween::is_running() const
{
    return running;
}

void Tween::tween(float* from, float to, float duration, TransitionType transition, EaseType ease)
{
    if (running) throw TweenAlreadyStarted();
    auto* tweener = new Tweener;

    tweener->target = from;
    tweener->start = *from;
    tweener->end = to;
    tweener->duration = duration;

    if (transition == TransitionType::Linear)
    {
        tweener->ease = Easing::easeLinear;
    }
    else switch (ease)
    {
        case EaseType::In:
            switch (transition)
            {
                case TransitionType::Sine:
                    tweener->ease = Easing::easeInSine;
                    break;

                case TransitionType::Cubic:
                    tweener->ease = Easing::easeInCubic;
                    break;

                case TransitionType::Quint:
                    tweener->ease = Easing::easeInQuint;
                    break;

                case TransitionType::Circ:
                    tweener->ease = Easing::easeInQuint;
                    break;

                case TransitionType::Elastic:
                    tweener->ease = Easing::easeInElastic;
                    break;

                case TransitionType::Quad:
                    tweener->ease = Easing::easeInQuad;
                    break;

                case TransitionType::Quart:
                    tweener->ease = Easing::easeInQuart;
                    break;

                case TransitionType::Expo:
                    tweener->ease = Easing::easeInExpo;
                    break;

                case TransitionType::Back:
                    tweener->ease = Easing::easeInBack;
                    break;

                case TransitionType::Bounce:
                    tweener->ease = Easing::easeInBounce;
                    break;
            }

            break;

        case EaseType::Out:
            switch (transition)
            {
                case TransitionType::Sine:
                    tweener->ease = Easing::easeOutSine;
                    break;

                case TransitionType::Cubic:
                    tweener->ease = Easing::easeOutCubic;
                    break;

                case TransitionType::Quint:
                    tweener->ease = Easing::easeOutQuint;
                    break;

                case TransitionType::Circ:
                    tweener->ease = Easing::easeOutQuint;
                    break;

                case TransitionType::Elastic:
                    tweener->ease = Easing::easeOutElastic;
                    break;

                case TransitionType::Quad:
                    tweener->ease = Easing::easeOutQuad;
                    break;

                case TransitionType::Quart:
                    tweener->ease = Easing::easeOutQuart;
                    break;

                case TransitionType::Expo:
                    tweener->ease = Easing::easeOutExpo;
                    break;

                case TransitionType::Back:
                    tweener->ease = Easing::easeOutBack;
                    break;

                case TransitionType::Bounce:
                    tweener->ease = Easing::easeOutBounce;
                    break;
            }
            
            break;

        case EaseType::InOut:
            switch (transition)
            {
                case TransitionType::Sine:
                    tweener->ease = Easing::easeInOutSine;
                    break;

                case TransitionType::Cubic:
                    tweener->ease = Easing::easeInOutCubic;
                    break;

                case TransitionType::Quint:
                    tweener->ease = Easing::easeInOutQuint;
                    break;

                case TransitionType::Circ:
                    tweener->ease = Easing::easeInOutQuint;
                    break;

                case TransitionType::Elastic:
                    tweener->ease = Easing::easeInOutElastic;
                    break;

                case TransitionType::Quad:
                    tweener->ease = Easing::easeInOutQuad;
                    break;

                case TransitionType::Quart:
                    tweener->ease = Easing::easeInOutQuart;
                    break;

                case TransitionType::Expo:
                    tweener->ease = Easing::easeInOutExpo;
                    break;

                case TransitionType::Back:
                    tweener->ease = Easing::easeInOutBack;
                    break;

                case TransitionType::Bounce:
                    tweener->ease = Easing::easeInOutBounce;
                    break;
            }
            
            break;

        case EaseType::OutIn:
            switch (transition)
            {
                case TransitionType::Sine:
                    tweener->ease = Easing::easeOutInSine;
                    break;

                case TransitionType::Cubic:
                    tweener->ease = Easing::easeOutInCubic;
                    break;

                case TransitionType::Quint:
                    tweener->ease = Easing::easeOutInQuint;
                    break;

                case TransitionType::Circ:
                    tweener->ease = Easing::easeOutInQuint;
                    break;

                case TransitionType::Elastic:
                    tweener->ease = Easing::easeOutInElastic;
                    break;

                case TransitionType::Quad:
                    tweener->ease = Easing::easeOutInQuad;
                    break;

                case TransitionType::Quart:
                    tweener->ease = Easing::easeOutInQuart;
                    break;

                case TransitionType::Expo:
                    tweener->ease = Easing::easeOutInExpo;
                    break;

                case TransitionType::Back:
                    tweener->ease = Easing::easeOutInBack;
                    break;

                case TransitionType::Bounce:
                    tweener->ease = Easing::easeOutInBounce;
                    break;
            }
            
            break;
    }

    tweeners.push_back(tweener);
}

void Tween::interval(float duration)
{
    if (running) throw TweenAlreadyStarted();
    auto* tweener = new Tweener;

    tweener->target = nullptr;
    tweener->duration = duration;

    tweeners.push_back(tweener);
}

void Tween::callback(std::function<void(void)> callable)
{
    if (running) throw TweenAlreadyStarted();
    this->callable = callable;
}

void Tween::update()
{
    loop:;

    while (!(std::all_of(tweeners.begin(), tweeners.end(), [](Tweener* tweener) -> bool
        {
            return tweener->finished;
        })))
    {
        if (kill_all) break;

        for (auto* tweener : tweeners)
        {
            if (tweener->finished) continue;
            if (!tweener->started)
            {
                tweener->time_start = Time::now();
                tweener->started = true;
            }

            auto time_now = Time::now();
            Seconds elapsed = time_now - tweener->time_start;
            tweener->step = std::min(elapsed.count() / tweener->duration, 1.0f);
            float delta = tweener->end - tweener->start;

            if (tweener->target != nullptr)
                *tweener->target = tweener->ease(tweener->step) * delta + tweener->start;

            if (tweener->step == 1.0) tweener->finished = true;
            else if (!parallel) break;
        }
    }

    if (loops != 0)
    {
        for (auto* tweener : tweeners)
        {
            tweener->started = false;
            tweener->finished = false;
            *tweener->target = tweener->start;
        }

        if (loops > 0) loops--;
        goto loop;
    }

    if (callable)
    {
        std::thread thread(callable);
        thread.detach();
    }

    for (auto* tweener : tweeners)
    {
        delete tweener;
    }

    tweeners.clear(); 
    running = false;
    delete this;
}