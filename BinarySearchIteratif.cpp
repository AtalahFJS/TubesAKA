#include <iostream>
#include <vector>
#include <chrono> // Untuk pengukuran waktu
#include <fstream>
#include <algorithm> // Untuk sort

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
    // Membaca dataset dari file
    ifstream file("dataJudulBuku.txt");
    if (!file) {
        cerr << "Error: Tidak dapat membuka file." << endl;
        return 1;
    }

    vector<string> dataset;
    string kata;
    while (file >> kata) { // Membaca setiap kata dari file
        dataset.push_back(kata);
    }
    file.close();

    // Pastikan dataset terurut
    sort(dataset.begin(), dataset.end());

    // Input kata yang ingin dicari
    cout << "Masukkan kata yang ingin dicari: ";
    string target;
    cin >> target;

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

