class A {
public:
    void say1() {
        cout << "im not virtual working like A" << endl;
    }
    virtual void say2() {
        cout << "im virtual working like A" << endl;
    }
};

class B : public A {
public:
    void say1() {
        cout << "im not virtual working like B" << endl;
    }
    virtual void say2() {
        cout << "im virtual working like B" << endl;
    }
};

int main()
{
    A* a;
    B b;
    a = &b;

    a->say1(); // im not virtual working like A
    a->say2(); // im virtual working like B

    return 0;
}