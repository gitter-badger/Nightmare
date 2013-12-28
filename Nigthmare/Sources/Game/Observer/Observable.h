#ifndef OBSERVABLE_OBJECT_H
#define OBSERVALBE_OBJECT_H

#include <memory>

namespace NAV
{
	class Notifiable;

	class Obeservable
	{
	public:
		ObeservableObject(std::shared_ptr<Notifiable> objPtr);
		virtual ~ObeservableObject();

		virtual Notifiable notifiable() const = 0;
		virtual bool changeOcurs() = 0;

	protected:
		std::shared_ptr<Notifiable> notfierPtr;
	};
}

#endif
