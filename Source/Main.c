#include "stdio.h"

#include "Utils/Vector.h"
#include "Math/Vec2.h"

typedef struct _testSt{
    int testNum;
} testSt;

int main()
{

    Vec2i first = {4, 534};

    Vec2i second = {5, 755};

    Vec2i res = Add_Vec2i(first, second);

    printf("%d\n", res.x);
    printf("%d\n", res.y);

    return 0;
}
