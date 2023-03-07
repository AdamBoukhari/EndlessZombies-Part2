#include "Subject.h"
#include "IObserver.h"

void Subject::registerObserver(IObserver* observateur)
{
	//On ajoute seulement si l'observateur n'est pas déjà dans la liste, sinon on lève une exception.
	if (std::find(observers.begin(), observers.end(), observateur) != observers.end()) throw std::runtime_error("Subject::registerObserver()");
	observers.push_back(observateur);
}
//Appelez cette méthode lorsque vous voulez que les observers réagissent.
void Subject::notifyObservers()
{
	for (int i = 0; i < (int)observers.size(); i++)
	{
		observers[i]->notify(this);
	}
}