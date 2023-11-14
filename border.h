#pragma once
#include "gameObject.h"

class Border : public gameObject
{
public:
    int life;
    int x;
    int y;

    Border();

    void initBorder(int x, int y);

    void OnCollisionEnter(gameObject* object) override;
    void OnCollisionStay() override;
    void OnCollisionExit() override;
};