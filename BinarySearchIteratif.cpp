#include <iostream>
#include <vector>
#include <chrono> // Untuk pengukuran waktu

using namespace std;

// Fungsi Binary Search Iteratif
int binarySearchIterative(const vector<string>& dataset, const string& target) {
    int left = 0, right = dataset.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // Hindari overflow
        if (dataset[mid] == target)
            return mid; // Kata ditemukan
        else if (dataset[mid] < target)
            left = mid + 1; // Cari di bagian kanan
        else
            right = mid - 1; // Cari di bagian kiri
    }
    return -1; // Kata tidak ditemukan
}

int main() {
    // Dataset kamus (contoh sederhana)
    vector<string> dataset = {"apple", "banana", "cherry", "date", "grape", "lemon", "orange", "pear"};
    string target = "cherry";

    // Pengukuran waktu
    auto start = chrono::high_resolution_clock::now();
    int result = binarySearchIterative(dataset, target);
    auto end = chrono::high_resolution_clock::now();

    // Hasil pencarian
    if (result != -1)
        cout << "Kata ditemukan di indeks " << result << endl;
    else
        cout << "Kata tidak ditemukan" << endl;

    // Waktu eksekusi
    chrono::duration<double> duration = end - start;
    cout << "Waktu eksekusi: " << duration.count() << " detik" << endl;

    return 0;
}
