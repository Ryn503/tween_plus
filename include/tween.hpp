#ifndef TWEEN_HPP
#define TWEEN_HPP

#include <vector>
#include <chrono>
#include <functional>
#include "easing.hpp"

class TweenAlreadyStarted : public std::exception
{
    public : const char* what();
};

class NoTweeners : public std::exception
{
    public : const char* what();
};

enum class TransitionType
{
    Linear,
    Sine,
    Cubic,
    Quint,
    Circ,
    Elastic,
    Quad,
    Quart,
    Expo,
    Back,
    Bounce
};

enum class EaseType
{
    In,     // Start slowly and speeds up towards the end.
    Out,    // Start quickly and slows down towards the end.
    InOut,  // Start and end slowly.
    OutIn   // Start and end quickly.
};

class Tween
{
    private:
        using Time = std::chrono::high_resolution_clock;
        using Seconds = std::chrono::duration<float>;

        struct Tweener
        {
            float (*ease)(float) {Easing::easeLinear};
            float* target;
            float start;
            float end;
            float duration;
            float step;
            bool started = false;
            bool finished = false;
            std::chrono::_V2::system_clock::time_point time_start;
        };

    private:
        std::vector<Tweener*> tweeners;
        std::function<void(void)> callable;
        bool running {false};
        bool kill_all {false};
        bool parallel {false};
        int loops {0};
        
        void update();

    public:
        /*
            \brief Create a new Tween.

            \warning You need to create this as a pointer.
        */
        Tween();

        /*
            \brief Start the tweening process.

            \param parallel All tweeners start at same time.
            \warning Interval tweeners will not work as intended if parallel is enabled.
        */
        void start(bool parallel = false);

        /*
            \brief Destroy all tweeners safely.

            \warning Calling this function all tweening value will stop in the currently tweening value.
        */
        void destroy();

        /*
            \brief Set the times to loop all tweeners.

            Setting the loop to 0 disable looping and setting to negative enable infinite looping.

            \param loops Set the numbers of times to loop.
            \warning Setting loop won't call the Callback multiple times, only when all repetitions end.
        */
        void set_loops(int loops);

        /*
            \brief Check if the tweening process started.
        */
        bool is_running() const;

        /*
            \brief Tween a float;

            \param from The variable to tween from.
            \param to The end value.
            \param duration The tweener duration in seconds.
            \param transition The easing transition type.
            \param ease The easing type.
        */
        void tween(float* from, float to, float duration, TransitionType transition = TransitionType::Linear, EaseType ease = EaseType::In);

        /*
            \brief Pause the tweening process for a time

            \param duration The tweener duration in seconds.
            \warning This will not work as intended if you start tweening as parallel.
        */
        void interval(float duration);

        /*
            \brief The function to call when all tweeners end.

            \param callable The callback function.
        */
        void callback(std::function<void(void)> callable);

};

#endif