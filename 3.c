#include <stdio.h>

int n, m;
int graph[201][201]; // 미로 지도

// (큐에 넣을 데이터)
typedef struct {
    int x, y;
} Node;

Node queue[40001]; // 큐: 대기열 줄 세우기
int head = 0, tail = 0;

// 방향 설정: 상(-1,0), 하(1,0), 좌(0,-1), 우(0,1)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void push(int x, int y) {
    queue[tail].x = x;
    queue[tail].y = y;
    tail++;
}

Node pop() {
    return queue[head++];
}

int bfs(int startX, int startY) {
    push(startX, startY); // 1. 시작점(0,0)을 줄 세우기

    while (head < tail) { // 2. 줄 서 있는 사람이 없을 때까지 반복
        Node curr = pop(); // 줄 맨 앞 사람 나오기
        int x = curr.x;
        int y = curr.y;

        // 3. 현재 위치에서 상하좌우 4방향 확인
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 미로 밖이거나 괴물(0)이 있으면 패스
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (graph[nx][ny] == 0) continue;

            // 4. 처음 가보는 길(1)인 경우에만 거리 기록
            if (graph[nx][ny] == 1) {
                // 이전 칸의 숫자 + 1 을 해서 거리를 누적! (핵심)
                graph[nx][ny] = graph[x][y] + 1;
                push(nx, ny); // 다음 탐색을 위해 줄 세우기
            }
        }
    }
    // 5. 가장 오른쪽 아래(도착점)에 적힌 숫자가 최단 거리
    return graph[n - 1][m - 1];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]); // 한 자리씩 입력받기
        }
    }

    printf("%d\n", bfs(0, 0)); // (1,1) 위치인 (0,0)에서 시작
    return 0;
}
