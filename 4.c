#include <stdio.h>
#include <stdlib.h> // qsort 함수를 쓰기 위해 필요합니다.

// 오름차순 정렬 기준 (작은 순서대로)
int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 내림차순 정렬 기준 (큰 순서대로)
int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[100000], b[100000];

    // 배열 A 입력
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    // 배열 B 입력
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    // 1. A는 작은 순서대로 정렬 (오름차순)
    qsort(a, n, sizeof(int), compare_asc);
    // 2. B는 큰 순서대로 정렬 (내림차순)
    qsort(b, n, sizeof(int), compare_desc);

    // 3. 최대 K번 교체 수행
    for (int i = 0; i < k; i++) {
        // A의 작은 원소가 B의 큰 원소보다 작을 때만 교체
        if (a[i] < b[i]) {
            int temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        } else {
            // A의 원소가 더 크거나 같으면 더 이상 교체할 필요가 없음
            break;
        }
    }

    // 4. 배열 A의 모든 원소 합 계산
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    printf("%lld\n", sum);

    return 0;
}
