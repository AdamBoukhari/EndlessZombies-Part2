#pragma once

#include "Subject.h"
#include "GameMovingObject.h"

class IObserver : public GameMovingObject
{
public:
	virtual void notify(Subject* subject) = 0;
};