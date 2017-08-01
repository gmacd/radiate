#include "timer.hpp"


using namespace std;

namespace gmlib {

	Timer::Timer():
		_startTime(chrono::high_resolution_clock::now()),
		_lastTime(_startTime)
    {
	}

	void Timer::update()
	{
		auto now = chrono::high_resolution_clock::now();

		std::chrono::duration<float> lastElapsed = now - _lastTime;
		_lastElapsed = lastElapsed.count();

		std::chrono::duration<float> totalElapsed = now - _startTime;
		_totalElapsed = totalElapsed.count();

		_lastTime = now;
	}
}
