#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 20

typedef struct {
    char arr[BUFFER_SIZE];
    int head;   // موقع القراءة
    int tail;   // موقع الكتابة
    int count;  // عدد العناصر الحالية
} CircularBuffer;

// تهيئة المخزن
void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// التحقق إذا ممتلئ
int isFull(CircularBuffer *cb) {
    return cb->count == BUFFER_SIZE;
}

// التحقق إذا فارغ
int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// إضافة عنصر
void enqueue(CircularBuffer *cb, char value) {
    if (isFull(cb)) {
        printf("\n[Error] Buffer Overflow while inserting '%c'\n", value);
        return;
    }

    cb->arr[cb->tail] = value;
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count++;
}

// حذف عنصر
char dequeue(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\n[Error] Buffer Underflow\n");
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

    // إضافة اللاحقة المطلوبة (بدون شرطة)
    strcat(name, "CE-ESY");

    printf("\nFinal string: %s\n", name);

    // إدخال الأحرف إلى المخزن
    for (int i = 0; i < strlen(name); i++) {
        enqueue(&cb, name[i]);
    }

    // إخراج الأحرف من المخزن
    printf("\nOutput: ");
    while (!isEmpty(&cb)) {
        char ch = dequeue(&cb);
        printf("%c", ch);
    }

    printf("\n");

    return 0;
}
