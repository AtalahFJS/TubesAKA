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
            return mid; // Judul ditemukan
        else if (dataset[mid] < target)
            left = mid + 1; // Cari di bagian kanan
        else
            right = mid - 1; // Cari di bagian kiri
    }
    return -1; // Judul tidak ditemukan
}

int main() {
    // Membaca dataset dari file
    ifstream file("dataJudulBuku.txt"); // Ganti dengan nama file Anda
    if (!file) {
        cerr << "Error: Tidak dapat membuka file." << endl;
        return 1;
    }

    vector<string> dataset;
    string line;
    while (getline(file, line)) { // Membaca setiap baris dari file
        dataset.push_back(line);
    }
    file.close();

    // Pastikan dataset terurut
    sort(dataset.begin(), dataset.end());

    // Input judul yang ingin dicari
    cout << "Masukkan judul yang ingin dicari: ";
    string target;
    getline(cin, target);

    // Pengukuran waktu
    auto start = chrono::high_resolution_clock::now();
    int result = binarySearchIterative(dataset, target);
    auto end = chrono::high_resolution_clock::now();

    // Hasil pencarian
    if (result != -1)
        cout << "Judul ditemukan di indeks " << result << endl;
    else
        cout << "Judul tidak ditemukan" << endl;

    // Waktu eksekusi dalam mikrodetik
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Waktu eksekusi: " << duration.count() << " mikrodetik" << endl;
    cout << "Total judul: " << dataset.size() << endl;

    return 0;
}
