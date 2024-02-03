#include "BaseObject.h"
#include <Novice.h>

void BaseObject::Update()
{

}

void BaseObject::Draw()
{
	Novice::ScreenPrintf(15, 15, "Have you forgotten to implement of Object?");
}
