// char* c 
char* c = 8;

// int m[10]
int mi[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// int (&m)[10]
int m1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int (&m)[10] = m1;

// std::string* m[]
std::string m2[] = { "1123", "2234", "3345" };
std::string* m3[] = &m2;

// char** c
char** c1 = 4;

// const int i
const int i1 = 3214789;

// int* const i
int* const i2 = 5;