#pragma once

#include "GameObject.h"
#include <vector>
#include <iostream>

class IObserver;
using std::vector;

class Subject : public GameObject
{
public:
	void registerObserver(IObserver* observer);
	void notifyObservers();
private:
	vector<IObserver*> observers;
};