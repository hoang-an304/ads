// implement clock data structure:
// structure to store hours(with minute and second)
// initialize clock variable with values: hour, minute and second
// increase clock variable by 1s
// calculate difference of 2 clocks
// main function to test all above
#include <stdio.h>

typedef struct {
    int hour;
    int minute;
    int second;
} Clock;

void initialize_clock(Clock *c, int h, int m, int s) {
    c->hour = h;
    c->minute = m;
    c->second = s;
}

void increment_clock(Clock *c) {
    c->second++;
    if (c->second == 60) {
        c->second = 0;
        c->minute++;
        if (c->minute == 60) {
            c->minute = 0;
            c->hour = (c->hour + 1) % 24;
        }
    }
}

int clock_difference(Clock c1, Clock c2) {
    int t1 = c1.hour * 3600 + c1.minute * 60 + c1.second;
    int t2 = c2.hour * 3600 + c2.minute * 60 + c2.second;
    return t1 > t2 ? t1 - t2 : t2 - t1;
}

int main() {
    Clock c1, c2;
    initialize_clock(&c1, 12, 30, 45);
    initialize_clock(&c2, 14, 15, 30);
    
    printf("Clock 1: %02d:%02d:%02d\n", c1.hour, c1.minute, c1.second);
    printf("Clock 2: %02d:%02d:%02d\n", c2.hour, c2.minute, c2.second);
    
    increment_clock(&c1);
    printf("Clock 1 after increment: %02d:%02d:%02d\n", c1.hour, c1.minute, c1.second);
    
    int diff = clock_difference(c1, c2);
    printf("Difference in seconds: %d\n", diff);
    
    return 0;
}
