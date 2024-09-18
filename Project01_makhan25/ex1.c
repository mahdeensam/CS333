/**
 * Mahdeen Ahmed Khan Sameer
 * 02/22/24
 * EX1
 */

int main() {
    char *p = (char *)0x1; // A typically misaligned address for types larger than char
    *p = 1; // Potential bus error due to misaligned access
    int *q = (int *)0xFFFFFFFF; // A typically invalid memory address
    *q = 2; // Potential segmentation fault due to illegal access
    return 0;
}
