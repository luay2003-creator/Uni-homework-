#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct {
    char arr[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == BUFFER_SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void enqueue(CircularBuffer *cb, char value) {
    if (isFull(cb)) {
        printf("[Overflow] Cannot insert '%c'\n", value);
        return;
    }
    cb->arr[cb->tail] = value;
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count++;
}

char dequeue(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("[Underflow] Buffer is empty\n");
        return '\0';
    }
    char value = cb->arr[cb->head];
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count--;
    return value;
}

int main() {
    CircularBuffer cb;
    initBuffer(&cb);

    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY");

    printf("\n--- Normal Case ---\n");
    printf("Input string: %s\n", name);

    // إدخال البيانات
    for (int i = 0; i < strlen(name); i++) {
        enqueue(&cb, name[i]);
    }

    // إخراج البيانات
    printf("Output: ");
    while (!isEmpty(&cb)) {
        printf("%c", dequeue(&cb));
    }

    printf("\n");

    // 🔥 اختبار Underflow
    printf("\n--- Underflow Test ---\n");
    dequeue(&cb); // المفروض يعطي خطأ

    // 🔥 اختبار Overflow
    printf("\n--- Overflow Test ---\n");
    for (int i = 0; i < BUFFER_SIZE + 3; i++) {
        enqueue(&cb, 'A' + i); // رح يتجاوز الحجم
    }

    printf("\nDone.\n");

    return 0;
}
