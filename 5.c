#include <stdio.h>

int main() {
    int n;          // 떡의 개수
    long long m;    // 필요한 떡의 총 길이
    // 1. 입력 받기 (사용자가 주는 값에 따라 유연하게 작동)
    if (scanf("%d %lld", &n, &m) != 2) return 0;

    long long arr[1000001];
    long long start = 0;
    long long end = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        // 입력받은 떡 중 가장 긴 떡을 찾아 end로 설정 (탐색의 최대 범위)
        if (arr[i] > end) end = arr[i];
    }

    long long result = 0;
    // 2. 이진 탐색 (본격적인 업다운 게임 시작)
    while (start <= end) {
        long long mid = (start + end) / 2; // 절단기 높이(H)를 중간값으로 설정
        long long total = 0;

        // 현재 높이(mid)로 잘랐을 때 나오는 떡의 양 계산
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) total += (arr[i] - mid);
        }

        // 3. 핵심 아이디어: 결과에 따라 범위를 절반씩 날리기
        if (total < m) {
            // 떡이 모자라면? 절단기를 낮춰서 더 많이 잘라야 해
            end = mid - 1; 
        } else {
            // 떡이 충분하면?  지금 높이 저장 더 높게도 되나 볼까?
            result = mid; 
            start = mid + 1;
        }
    }

    // 4. 최적의 절단기 높이 출력
    printf("%lld\n", result);
    return 0;
}
