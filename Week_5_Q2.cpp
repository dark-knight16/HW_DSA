#include <iostream>
using namespace std;

int prime[1000001];

//* Thuật toán sàng số nguyên tố Eratosthenes từ 0 đến 1000000
void sieve_Eratosthenes() {
    for (int i = 0; i < 1000000; i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= 1000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) prime[j] = 0;
        }
    }
}

//* Kiểm tra xem số m có tồn tại trong mảng array gồm n phần tử không 
bool check_number_in_arrayBlum(int* array, int n, int m) {
    for (int i = 0; i < n; i++) {
        if (array[i] == m) return 1;
    }
    return 0;
}

//* Sắp xếp tăng dần mảng array gồm n phần tử bằng thuật toán sắp xếp chèn 
void insertion_sort(int* array, int n) {
    for (int i = 1; i < n; i++) {
        int temp = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > temp) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
}

//* Tìm tất cả các cặp số có trong mảng array gồm n phần tử đã được sắp xếp tăng dần
//* sao cho tổng của chúng bằng giá trị target xác định 
void find_pair_Blum(int* array, int n, int target) {
    int left = 0;
    int right = n - 1;
    cout << target << endl;
    while (left < right) {
        if (array[left] + array[right] == target) {
            cout << "Pair found: " << "(" << array[left] << ", " << array[right] << ")" << endl;
            return;
        }
        array[left] + array[right] < target? left++ : right--;
    }
    cout << "Not found pair" << endl;
}

int main() {
    int n;
    //? Nhập số N
    cout << "Enter N: ";
    cin >> n;
    sieve_Eratosthenes();

    //? Cấp phát động mảng các số Blum 
    int* array_Blum;
    array_Blum = new int [n];

    //? Chỉ số bắt đầu của mảng các số Blum
    int index_prime = 0;

    //? Số lượng các phần tử trong mảng các số Blum
    int count_elements = 0;

    //? Điều kiện của phần tử thỏa mãn là một số Blum 
    for (int i = 2; i <= n/2; i++) {
        for (int j = i; j <= n/2; j++) {
            if (prime[i] && prime[j] && i*j < n) {
                array_Blum[index_prime] = i*j;
                index_prime++;
                count_elements++;
            }
        }
    }
    
    //? In ra mảng số nửa nguyên tố Blum nhỏ hơn N 
    cout << "Array Blum: ";
    for (int i = 0; i < count_elements; i++) cout << array_Blum[i] << ' ';
    cout << endl;

    //? Xắp sếp mảng các số Blum theo thứ tự tăng dần bằng thuật toán InsertionSort
    insertion_sort(array_Blum, count_elements);

    //? Tìm tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N  
    for (int i = 0; i < count_elements; i++) {
        find_pair_Blum(array_Blum, count_elements, array_Blum[i]);
    }

    //? Kiểm tra số Blum M có tồn tại trong dãy Blum được tạo ra hay không
    int m;
    cout << "Enter m: ";
    cin >> m;
    if (check_number_in_arrayBlum(array_Blum, count_elements, m)) {
        cout << m << " co ton tai trong day Blum duoc tao ra";
    }
    else cout << m << " khong ton tai trong day Blum duoc tao ra";

    //? Giải phóng bộ nhớ
    delete [] array_Blum;
}