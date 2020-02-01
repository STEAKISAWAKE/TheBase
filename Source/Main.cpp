#include "stdio.h"

#include "Utils/Vector.h"
#include "Math/Vec2.h"
#include "Math/Mat4.h"

typedef struct _testSt{
    int testNum;
} testSt;

int main()
{

    iVector2 first = {4, 534};

    iVector2 second = {5, 755};

    iVector2 res = iVec2::Add(first, second);

    fVector2 tes = iVec2::toFVec2(res);

    printf("Converted: %.6f\n", tes.x);

    printf("%d\n", res.x);
    printf("%d\n", res.y);

    return 0;
}
