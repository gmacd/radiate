#pragma once

#include <chrono>


namespace gmlib {
	
	using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;

	class Timer
	{
	public:
		Timer();

		void update();

		float lastElapsed() const { return _lastElapsed; }
		float totalElapsed() const { return _totalElapsed; }

	private:
		time_point _startTime;
		time_point _lastTime;

		float _lastElapsed;
		float _totalElapsed;
	};
}
