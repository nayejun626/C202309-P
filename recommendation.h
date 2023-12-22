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
