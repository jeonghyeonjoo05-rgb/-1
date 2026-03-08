#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 무한대를 의미하는 값 (적당히 큰 값으로 설정)
const int INF = 1e9; 

int main() {
    int n, m;
    cin >> n >> m;

    // 1. 최단 거리 테이블을 무한대로 초기화
    int graph[101][101];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) graph[i][j] = 0; // 자기 자신으로 가는 비용은 0
            else graph[i][j] = INF;
        }
    }

    // 2. 도로 정보 입력받기 (양방향, 비용은 1)
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    // 최종 목적지 X와 거쳐갈 지점 K 입력받기
    int x, k;
    cin >> x >> k;

    // 3. 플로이드-워셜 알고리즘 수행 (3중 for문)
    // 거쳐가는 노드(k), 출발 노드(a), 도착 노드(b) 순서
    for (int k_node = 1; k_node <= n; k_node++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k_node] + graph[k_node][b]);
            }
        }
    }

    // 4. 결과 출력: 1번 -> K번 비용 + K번 -> X번 비용
    int distance = graph[1][k] + graph[k][x];

    if (distance >= INF) {
        cout << -1 << endl;
    } else {
        cout << distance << endl;
    }

    return 0;
}
