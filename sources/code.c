#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 옷 스타일과 두께를 저장할 변수 선언
char **clothStyle;
char **clothThickness;

// 옷을 스타일과 두께에 따라 분류하는 함수
void classifyClothing(char **styles, char **thickness, int inputClothes);

// 온도에 따라 적절한 의상을 추천하는 함수
void recommendOutfit(int temperature);

int main()
{
    int temperature; // 온도를 저장할 변수

    // 온도 정보를 입력 받는 부분 (실제로는 API를 통해 받아오겠지만, 여기서는 직접 입력 받음)
    printf("오늘의 온도는 몇 도인가요? ");
    scanf("%d", &temperature);

    int inputClothes;
    printf("가지고 있는 옷들의 수를 입력하세요: ");
    scanf("%d", &inputClothes);
    // 온도에 따라 의상을 추천하는 함수 호출
    recommendOutfit(temperature);

        // 포인터 배열을 사용하여 동적으로 메모리 할당
    clothStyle = (char **)malloc(inputClothes * sizeof(char *));
    clothThickness = (char **)malloc(inputClothes * sizeof(char *));

    // 각각의 옷 정보를 입력 받음
    for (int i = 0; i < inputClothes; ++i)
    {
        clothStyle[i] = (char *)malloc(50 * sizeof(char));
        clothThickness[i] = (char *)malloc(50 * sizeof(char));

        printf("옷 %d 정보 입력\n", i + 1);
        printf("종류: ");
        scanf("%s", clothStyle[i]);
        printf("두께: ");
        scanf("%s", clothThickness[i]);
    }

    // 옷을 분류하는 함수 호출
    classifyClothing(clothStyle, clothThickness, inputClothes);

    free(clothStyle); // 메모리 해제
    free(clothThickness);

    return 0;
}

// 온도에 따라 의상을 추천하는 함수
void recommendOutfit(int temperature)
{
    // 온도 범위에 따른 의상 추천
    if (temperature < 0)
    {
        printf("~가 좋겠네요\n");
    }
    else if (temperature < 10)
    {
        printf("\n");
    }
    else if (temperature < 20)
    {
        printf("\n");
    }
    else
    {
        printf("\n");
    }
}

// 옷을 분류하는 함수
void classifyClothing(char **styles, char **thickness, int inputClothes)
{
}
