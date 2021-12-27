#pragma once

#define SLOW 0
#define POISON 1
#define DAMAGEINCREASE 2
enum EffectType
{
	slow,
	poisoning,
	damageIncrease
};

class Effect
{
private:
	EffectType type;
	int length;
public:
	inline int getLength() { return length; }
	inline void setLength(int len) { this->length = len; }
	inline EffectType getEffetType() { return type; }
	inline Effect(EffectType t, int len) : type(t), length(len) {}
	virtual inline ~Effect() {}
};

class SlowEffect : public Effect
{
private:
	float slowCoeff;
public:
	inline float getSlowCoeff() { return slowCoeff; }
	inline SlowEffect(int len, float slow) : Effect(EffectType::slow, len), slowCoeff(slow) {}
};

class PoisonEffect : public Effect
{
private:
	float damagePerSecond;
public:
	inline float getDPS() { return damagePerSecond; }
	inline PoisonEffect(int len, float dmg) : Effect(EffectType::poisoning, len), damagePerSecond(dmg) {}
};

class DamageIncreaseEffect : public  Effect
{
private:
	float damageCoeff;
public:
	inline float getDamageCoeff() { return damageCoeff; }
	inline DamageIncreaseEffect(int len, float dmgcoeff) : Effect(EffectType::damageIncrease, len), damageCoeff(dmgcoeff) {}
};

class Effects
{
private:
	Effect** effects;
public:
	inline Effect**& getEffects() { return effects; }
	Effects();
	~Effects();
};