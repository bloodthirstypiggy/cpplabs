#include "Effect.h"

Effects::~Effects()
{
	delete effects[0];
	delete effects[1];
	delete effects[2];
	delete effects;
}

Effects::Effects()
{
	effects = new Effect * [3];
	effects[0] = new SlowEffect(3, 2.0f);
	effects[1] = new PoisonEffect(3, 10);
	effects[2] = new DamageIncreaseEffect(3, 2.0f);
}
