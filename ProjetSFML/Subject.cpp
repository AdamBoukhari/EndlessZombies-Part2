#include "Subject.h"
#include "IObserver.h"

void Subject::registerObserver(IObserver* observateur)
{
	//On ajoute seulement si l'observateur n'est pas d�j� dans la liste, sinon on l�ve une exception.
	if (std::find(observers.begin(), observers.end(), observateur) != observers.end()) throw std::runtime_error("Subject::registerObserver()");
	observers.push_back(observateur);
}
//Appelez cette m�thode lorsque vous voulez que les observers r�agissent.
void Subject::notifyObservers()
{
	for (int i = 0; i < (int)observers.size(); i++)
	{
		observers[i]->notify(this);
	}
}