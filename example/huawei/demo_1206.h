#pragma once
#include <memory>
class tensor {
private:
    int n;
    int c;
    int h;
    int w;
    int* ptr;
public:
    tensor() {};
    int* init(int n, int c, int h, int w) {
        int size = n * c * h * w;
        ptr = (int *)malloc(size * sizeof(int));
    }

    void ChannelResize(int in, int ic, int ih, int iw, int groups) {
        if (in > n || ic > c || ih > h || iw > w) {
            // todo log print
            return;
        }

        int newsize = in * ic * ih *iw;
        int *new_ptr = (int *)malloc(newsize * sizeof(int));

        // ic = c / 4
        // todo groups not proper, process remaining
        for (int i = 0; i < ic / groups; i++) {
            for (int j = 0; j < ih; j++) {
                for (int k = 0; k < iw; k++) {
                    new_ptr[iw * ih * i + j * iw + k] =
                        (ptr[iw * ih * (4 * i + 0) + j * iw + k] +
                        ptr[iw * ih * (4 * i + 1) + j * iw + k] +
                        ptr[iw * ih * (4 * i + 2) + j * iw + k] +
                        ptr[iw * ih * (4 * i + 3) + j * iw + k]) / 4;
                }
            }
        }
        free(new_ptr);
    }
};


void test_1206() {
    printf("hello world 2023/12/06");
    // N C H W

}