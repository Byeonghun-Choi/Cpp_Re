#include<stdio.h>

/* 
2차원 배열의 출력 예시
int main(void) 
{
    int arr[3][3] = { 0 };
    int i, j;

    //3x3 
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            if (i == j) {
                arr[i][j] = 1;
            }
            else 
                arr[i][j] = 0;

        }
    }

    //구성된 행렬의 출력 
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/



int SeatAssign(int v, int h);
int seats[5][5];

int main(void) 
{
    int vLine = 0;  // 세로라인
    int hLine = 0;  // 가로라인

    while(1)
    {
        printf("할당할 좌석의 세로, 가로 위치 입력 : ");
        scanf("%d %d", &vLine, &hLine);

        if (hLine <= 0 || vLine <= 0)
            break;

        if (SeatAssign(vLine, hLine) == -1)
            printf("이미 할당된 자리입니다.\n\n");
        else 
            printf("할당이 완료되었습니다.\n\n");
    }
    printf("사용해주셔서 감사합니다. \n\n");
    return 0;
}

int SeatAssign(int v, int h)
{
    if(seats[v-1][h-1])
        return -1;

    seats[v-1][h-1] = 1;
    return 1;
}


