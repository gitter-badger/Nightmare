#ifndef OBSERVER_H
#define OBSERVER_H

namespace NAV
{
	class ObservableObject;

	class Observer
	{
	public:
		virtual ~Observer() = 0;

		virtual void attach(ObservableObject obj) = 0;
		virtual void update() = 0;
	};
}

#endif