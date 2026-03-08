#include <stdio.h>

int n, m;
int graph[1001][1001];

// 1. 연결된 구멍들을 다 '1'로 메꿔버리는 함수 (DFS)
void dfs(int x, int y) {
    // 지도를 벗어나면 중단
    if (x < 0 || x >= n || y < 0 || y >= m) return;

    // 현재 칸이 구멍(0)이라면
    if (graph[x][y] == 0) {
        graph[x][y] = 1; //  (다시 안 오게 1로 변경)

        // 상, 하, 좌, 우 연결된 모든 칸을 확인하러 이동
        dfs(x - 1, y); // 위
        dfs(x + 1, y); // 아래
        dfs(x, y - 1); // 왼쪽
        dfs(x, y + 1); // 오른쪽
    }
}

int main() {
    scanf("%d %d", &n, &m); // 지도 크기 입력

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]); // 한 자리씩 입력받기
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 2. 구멍(0)을 새로 발견할 때마다 아이스크림 1개 추가!
            if (graph[i][j] == 0) {
                dfs(i, j); // 연결된 모든 0을 1로 지우기
                count++;   // 덩어리 개수 증가
            }
        }
    }
    printf("%d\n", count); // 최종 개수 출력
    return 0;
}
