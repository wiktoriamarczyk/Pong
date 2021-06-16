#include "Common.h"
#include "GameState.h"
#include "Engine.h"


int main()
{

    Engine MyEngine;
    if (MyEngine.Initialize() == false)
    {
        return 1;
    }
    MyEngine.Loop();

    // posprzatanie zasobow

    return 0;
}
