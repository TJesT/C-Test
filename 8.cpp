void* operator new    // выделение памяти под один объект
void* operator new[]  // выделение памяти под массив объектов

class Apple{};
Apple *a = new Apple; // выделение памяти под один объект
int *a = new int[10]; // выделение памяти под массив объектов

int N = 10;
int *i = (int*)malloc(sizeof(int) * N);
if (i == nullptr) {
    throw runtime_error("cant allocate that much");
}
memset(i, 0, N * sizeof(int));