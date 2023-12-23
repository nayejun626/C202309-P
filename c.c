#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 옷의 종류와 두께를 멤버로 갖는 구조체 정의
typedef struct
{
    char type[50];
    int thickness;
} Clothing;

// 온도에 따라 적절한 의상을 추천하는 함수 선언하기
void recommendOutfit(int temperature, int thickness, char *type);

// 옷을 분류하고 랜덤으로 타입을 선택하여 추천하는 함수
void classifyAndRecommend(Clothing *clothes, int inputClothes, int temperature);

int main()
{
    int temperature;

    // 온도 정보를 입력 받는 부분 (실제로는 API를 통해 받아오겠지만, 여기에선 직접 입력 받음)
    printf("오늘의 온도는 몇 도인가요? ");
    scanf("%d", &temperature);
    // 의류 데이터베이스가 없어서 번거롭지만, 일일이 옷을 입력 받음
    int inputClothes;
    printf("가지고 있는 옷의 수를 입력하세요: ");
    scanf("%d", &inputClothes);

    // 구조체 포인터 배열 동적 할당
    Clothing **candidateClothes = (Clothing **)malloc(inputClothes * sizeof(Clothing *));

    // 각각의 옷 정보를 입력 받음.
    for (int i = 0; i < inputClothes; ++i)
    {
        printf("옷 %d 정보 입력\n", i + 1);
        printf("종류(패딩, 코트, 바람막이 등): ");
        scanf("%s", clothes[i].type);

        // 두께를 숫자로 입력받기
        printf("두께( 1(매우두꺼움), 2(두꺼움), 3(중간), 4(얇음) 1~4 중 입력): ");
        scanf("%d", &clothes[i].thickness);
    }

    // 옷을 분류하고 랜덤으로 타입을 선택하여 추천하는 함수 호출
    classifyAndRecommend(clothes, inputClothes, temperature);

    free(clothes); // 메모리 해제

    return 0;
}

// 옷을 분류하고 랜덤으로 타입을 선택하여 추천하기 위해 만든 함수
// 이 함수가 수행하는 것은 1.배열에서 랜덤하게 옷 하나를 선택하고 ,
// 2. 선택된 옷의 타입을 출력한 후 recommendOutfit 함수에 해당 정보(두께 및 타입)를 전달하는 것
void classifyAndRecommend(Clothing *clothes, int inputClothes, int temperature)
{
    srand(time(NULL)); // 난수생성을 매번 다르게 하게끔 초기화 시켜줌

    // "두께"에 맞는 후보 옷을 저장할 새로운 배열 생성하기
    Clothing **candidateClothes = (Clothing **)malloc(inputClothes * sizeof(Clothing *));
    int candidateCount = 0; // 후보 옷의 개수

    // 후보 옷을 찾아서 배열에 저장
    for (int i = 0; i < inputClothes; ++i)
    {
        // 현재 온도와 "두께"에 맞는 옷을 후보로 선택
        if ((temperature < 0 && clothes[i].thickness == 1) ||
            (temperature < 10 && clothes[i].thickness == 2) ||
            (temperature < 20 && clothes[i].thickness == 3) ||
            (temperature >= 20 && clothes[i].thickness == 4))
        {
            candidateClothes[candidateCount] = &clothes[i];
            candidateCount++;
        }
    }

    if (candidateCount == 0)
    {
        printf("해당 조건에 맞는 옷이 없습니다.\n");
        return;
    }

    int randomIndex = rand() % candidateCount;
    printf("추천된 옷: %s\n", candidateClothes[randomIndex]->type);
    recommendOutfit(temperature, candidateClothes[randomIndex]->thickness, candidateClothes[randomIndex]->type);
    free(candidateClothes); // 동적으로 할당한 메모리 해제
}

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
        printf("가벼운 %s를 추천합니다.\n", type);
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
