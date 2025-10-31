#include <stdio.h>

int main() {
    int pages[50], frames[10], n, f, i, j, k, pageFaults = 0, next = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag = 1; // page hit
                break;
            }
        }

        if (flag == 0) {
            frames[next] = pages[i];
            next = (next + 1) % f;
            pageFaults++;
        }

        printf("%d\t", pages[i]);
        for (k = 0; k < f; k++) {
            if (frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", n - pageFaults);

    return 0;
}
