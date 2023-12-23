#include <stdio.h>

// 온도에 따라 의상을 추천하는 함수
void recommendOutfit(int temperature, int thickness, char *type)
{
    // 온도 범위에 따른 의상 추천
    if (temperature < 0)
    {
        printf("오늘은 날이 매우 추우니 ");
        // 추천 두께 설정
        thickness = 1;
    }
    else if (temperature < 10)
    {
        printf("오늘은 날이 조금 춥습니다. ");
        thickness = 2;
    }
    else if (temperature < 20)
    {
        printf("오늘은 날이 꽤 쌀쌀할 것 같아요. ");
        thickness = 3;
    }
    else
    {
        printf("오늘은 따뜻한 날이 예상됩니다. ");
        thickness = 4;
    }

    // 두께에 따라 옷을 추천
    if (thickness == 1)
    {
        printf("두꺼운 %s를 추천합니다.\n", type);
    }
    else if (thickness == 2)
    {
        printf("따뜻한 %s를 추천합니다.\n", type);
    }
    else if (thickness == 3)
    {
        printf("가볍게 %s를 추천합니다.\n", type);
    }
    else if (thickness == 4)
    {
        printf("시원한 %s를 추천합니다.\n", type);
    }
    else
    {
        printf("잘못된 두께 입력값입니다.\n");
    }
}
