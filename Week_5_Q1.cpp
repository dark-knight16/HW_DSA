#include <iostream>
using namespace std;

//* Hàm hoán đổi giá trị của 2 biến có kiểu dữ liệu bất kì
template <class T>
void hoan_doi(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

int main() {
    int n;
    //? Nhập số lượng các đối tượng
    cout << "Enter n: ";
    cin >> n;

    //? Cấp phát mảng p chứa n đối tượng 
    string* p;
    p = new string [n];

    //? Nhập n đối tượng "đỏ", "trắng", "xanh" từ bàn phím
    for (int i = 0; i < n; i++) cin >> p[i];

    //? Cấp phát mảng a để mã hóa n đối tượng mảng p
    //? thỏa mãn "đỏ" = 0, "trắng" = 1, "xanh" = 2
    int* a;
    a = new int [n];
    for (int i = 0; i < n; i++) {
        if (p[i] == "do") a[i] = 0;
        else if (p[i] == "trang") a[i] = 1;
        else a[i] = 2;
    }

    //? Sắp xếp lại cả 2 mảng p và a 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                hoan_doi(p[i], p[j]);
                hoan_doi(a[i], a[j]);
            }
        }
    }

    //? In ra mảng đã sắp xếp 
    for (int i = 0; i < n; i++) cout << p[i] << ' ';

    //? Giải phóng bộ nhớ
    delete [] a;
    delete [] p;
}