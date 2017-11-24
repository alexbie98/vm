#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "data/Observer.h"
namespace vm {

template <typename T, typename EType> 
class Subject {

	private:
		std::vector<Observer<T,EType>&> obsList;
	public:
		virtual ~Subject();

		void addObserver(Observer<T,EType>& obs){
			obsList.push_back(obs);
		}

		bool removeObserver(Observer<T, EType> obs){
			size_t origSize = obsList.size();
			obsList.erase(std::remove(obsList.begin(), obsList.end(), obs));
			return obsList.size() == origSize;
		}

		void notifyAll (EType event) {
			for (Observer<T, EType> obs : obsList){
				obs.beNotified(event, static_cast<T&>(this));
			}
		}

};

}

#endif
