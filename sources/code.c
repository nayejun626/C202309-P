#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **clothStyle;
char **clothThickness;

void classifyClothing(char **styles, char **thickness, int inputClothes);

void recommendOutfit(int temperature);

int main()
{
    int temperature; // 날씨 온도를 저장할 변수

    // 온도 정보를 받아오는 부분 (실제로는 API를 사용하지만 사용할 수준이 안돼서 직접 입력)
    printf("오늘의 온도는 몇 도인가요? ");
    scanf("%d", &temperature);

    // 코디를 추천하는 함수 호출
    recommendOutfit(temperature);

    int inputClothes;
    printf("가지고 있는 옷들을 입력하세요: ");
    scanf("%d", &inputClothes);

    // 포인터 배열을 사용하여 동적으로 메모리 할당
    clothStyle = (char **)malloc(inputClothes * sizeof(char *));
    clothThickness = (char **)malloc(inputClothes * sizeof(char *));

    // 가지고 있는 옷 정보 입력 받기
    for (int i = 0; i < inputClothes; ++i)
    {
        clothStyle[i] = (char *)malloc(50 * sizeof(char));
        clothThickness[i] = (char *)malloc(50 * sizeof(char));

        printf("옷 %d 정보 입력\n", i + 1);
        printf("종류: \n");
        scanf("%s", clothStyle[i]);
        printf("두께: \n");
        scanf("%s", clothThickness[i]);
    }

    // 옷 분류 함수 호출
    classifyClothing(clothStyle, clothThickness, inputClothes);

    // 메모리 해제
    for (int i = 0; i < inputClothes; ++i)
    {
        free(clothStyle[i]);
        free(clothThickness[i]);
    }
    free(clothStyle);
    free(clothThickness);

    return 0;
}

// 온도의 범위에 따라 아웃핏을 추천해주는 함수 정의
void recommendOutfit(int temperature)
{
    if (temperature < 0)
    {
        printf("\n");
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
