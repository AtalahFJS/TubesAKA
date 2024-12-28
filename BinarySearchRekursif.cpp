#include <iostream>
#include <vector>
#include <chrono> // Untuk pengukuran waktu
#include <fstream>

using namespace std;

// Fungsi Binary Search Rekursif
int binarySearchRecursive(const vector<string>& dataset, int left, int right, const string& target) {
    if (left > right)
        return -1; // Kata tidak ditemukan

    int mid = left + (right - left) / 2; // Hindari overflow
    if (dataset[mid] == target)
        return mid; // Kata ditemukan
    else if (dataset[mid] < target)
        return binarySearchRecursive(dataset, mid + 1, right, target); // Cari di bagian kanan
    else
        return binarySearchRecursive(dataset, left, mid - 1, target); // Cari di bagian kiri
}

int main() {
    // Dataset kamus (contoh sederhana)
    vector<string> dataset = {"apple", "banana", "cherry", "date", "grape", "lemon", "orange", "pear"};
    string target = "cherry";

    // Pengukuran waktu
    auto start = chrono::high_resolution_clock::now();
    int result = binarySearchRecursive(dataset, 0, dataset.size() - 1, target);
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
