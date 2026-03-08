#include <stdio.h>

int main() {
    int n;
    // 1. 지도 크기 입력 (예: 5)
    scanf("%d", &n);

    int x = 1, y = 1; // 시작 위치 (1, 1)
    char plan;

    
    while (scanf(" %c", &plan) != 0) {
        int nx = x, ny = y; // 일단 머릿속으로만 가보기 (임시 좌표)

        // 3. 방향에 따른 이동 계산
        if (plan == 'L') ny--;      // 왼쪽
        else if (plan == 'R') ny++; // 오른쪽
        else if (plan == 'U') nx--; // 위
        else if (plan == 'D') nx++; // 아래
        else break; // 더 이상 방향 문자가 없으면 종료

        // 4. 지도 밖인지 체크 (1보다 작거나 n보다 큰지)
        if (nx < 1 || ny < 1 || nx > n || ny > n) {
            continue; // 낭떠러지면 무시하고 다음 명령
        }

        // 5. 안전하다면 실제 내 위치 업데이트
        x = nx;
        y = ny;
    }

    // 6. 최종 도착 지점 출력 (x y 형식)
    printf("%d %d\n", x, y);

    return 0;
}
