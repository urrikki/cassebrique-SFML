#pragma once
#include "gameObject.h"

class Border : public gameObject
{
public:
    int life;

    Border();

    void OnCollisionEnter(gameObject* object) override;
    void OnCollisionStay() override;
    void OnCollisionExit() override;
};