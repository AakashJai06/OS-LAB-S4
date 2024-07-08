#include <stdio.h>

int main() {
    int n, rf[20], f, flag[20] = {0},m[20], freq[20] = {0}, time[20] = {0};
    int i, j, pf = 0, next = 0, minFreq, minTime, minIndex;

    printf("Enter the length of the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rf[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        m[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int found = 0;

        for (j = 0; j < f; j++) {
            if (m[j] == rf[i]) {
                flag[i] = 1;
                freq[j]++;
                time[j] = next++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (i < f) {
                m[i] = rf[i];
                freq[i] = 1;
                time[i] = next++;
            } else {
                minIndex = 0;
                minFreq = freq[0];
                minTime = time[0];
                for (j = 1; j < f; j++) {
                    if (freq[j] < minFreq || (freq[j] == minFreq && time[j] < minTime)) {
                        minIndex = j;
                        minFreq = freq[j];
                        minTime = time[j];
                    }
                }
                m[minIndex] = rf[i];
                freq[minIndex] = 1;
                time[minIndex] = next++;
            }
            pf++;
        }

        for (j = 0; j < f; j++) {
            printf("%d ", m[j]);
        }
        printf("\n");
    }

    printf("Number of page faults is %d\n", pf);

    return 0;
}
