#ifndef EXCPETION_H_
#define EXCPETION_H_

#include <string>

namespace NAV
{
	class Exception
	{
	public:
		Exception(std::string cause);

#ifndef _MSC_VER
		virtual ~Exception() noexcept(true);
#endif

#ifdef _MSC_VER
		virtual ~Exception() throw();
#endif
		virtual std::string getCause() const;
		virtual void raise() const;

	protected:
		std::string cause;
	};

}
#endif
