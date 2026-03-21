#include <stdio.h>
#include <assert.h>
#include <math.h>

enum ShapeType { CIRCLE, RECTANGLE, TRIANGLE };

typedef struct Shape{
    enum ShapeType type;
    union {
        struct {
            float radius;
        } circle;

        struct {
            float width;
            float height;
        } rectangle;

        struct {
            float base;
            float height;
        } triangle;
    } data;
}Shape;

float area(struct Shape* ptr) {
    // TO IMPLEMENT
    switch(ptr -> type){
        //指向对应存在的case
        case CIRCLE:
            return 3.14159f * ptr->data.circle.radius * ptr->data.circle.radius;
            //3.14159f*data.circle.radius*data.circle.radius(必须使用shape去访问所包含的成员，ptr指向shape)

        case RECTANGLE:
            return ptr->data.rectangle.width * ptr->data.rectangle.height;

        case TRIANGLE:
            return 0.5f * ptr->data.triangle.base * ptr->data.triangle.height;

        default:
            return 0.0f;
    }


    /*
    相当于：
        float area(Shape s) {
            switch (s.type) {
                case CIRCLE:
                    return 3.14159f * s.data.circle.radius * s.data.circle.radius;
                // ...
            }
        }
        调用时也改成 area(circle) 而不是 area(&circle)。
        不过实际开发中一般还是用指针，因为值传递会把整个 struct 拷贝一份到函数里，浪费内存和时间。指针只传一个地址（8字节），效率高很多。这也是你看 C 代码里到处都是指针传参的原因
    */

}

int main() {

    const float alpha = 0.0001;

    // Test circle
    struct Shape circle;
    circle.type = CIRCLE;
    circle.data.circle.radius = 2.0;

    float circle_area = area(&circle);
    assert(fabs(circle_area - (3.14159f * 2.0f * 2.0f)) < alpha);

    // WRITE MORE TESTS
    printf("All tests passed!\n");
    return 0;

}