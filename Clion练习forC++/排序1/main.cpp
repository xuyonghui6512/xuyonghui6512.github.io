#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int a[] = {10, 6, 9, 5, 2, 8, 4, 7, 1, 3,12,14,11,13};
    int i, tmp;
    int len = sizeof(a) / sizeof(a[0]);
    for(i = 0; i < len;) {
        tmp = a[a[i] - 1];
        a[a[i] - 1] = a[i];
        a[i] = tmp;
        if(a[i] == i + 1) i++;
    }
    for(i = 0; i < len; ++i)
        printf("%d ", a[i]);
    printf("\n");
    int d=0;
    std::cout<<sizeof d<<std::endl;
    std::cout<<sizeof (int) <<"  "<<sizeof(char)<<"  "<<sizeof(double)<<std::endl;
    double o=40.755;
    int t=1;
    std::cout<<int(o/t)<<"   "<<o-int(o/t)<<std::endl; //将double分解成整数和小数

    char str1[] = "abc";
    char str2[] = "abc";
    const char str3[] = "abc";
    const char str4[] = "abc";
    const char *str5 = "abc";
    const char *str6 = "abc";
    char *str7 = "abc";
    char *str8 = "abc";
    cout << (str1 == str2) << endl;
    cout << (str3 == str4) << endl;
    cout << (str5 == str6) << endl;
    cout << (str7 == str8) << endl;
    return 0;
}