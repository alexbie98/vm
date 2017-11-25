#ifndef OBSERVER_H
#define OBSERVER_H

namespace vm {

template <typename T, typename EType>
class Observer {
	private:
	public:
		virtual ~Observer() {}
		virtual void beNotified(EType event, T& subject) = 0;
};

}
#endif
