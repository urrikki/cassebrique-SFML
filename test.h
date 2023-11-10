#pragma once
#include "gameObject.h"

class Test : public gameObject
{
public:

    Test();
    void initTest();

    void OnCollisionEnter(gameObject* object) override;
    void OnCollisionStay();
    void OnCollisionExit();
};
