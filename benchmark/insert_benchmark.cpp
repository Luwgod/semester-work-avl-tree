#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include "algorithm"

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main(int argc, char **argv) {


  // работа с набором данных
  const auto path = string(kDatasetPath);
  const auto proj_path = string(kProjectPath);

  string data_file_sizes[10] = {"100", "500", "1000", "5000",
      "10000", "50000", "100000", "500000",
      "1000000", "5000000"};

//  ofstream bench_file(proj_path + "/benchmark/insert_bench.csv", std::ofstream::app);
//  ofstream bench_file(proj_path + "/benchmark/delete_bench.csv", std::ofstream::app);
  ofstream bench_file(proj_path + "/benchmark/search_bench.csv", std::ofstream::app);


  for(int i=0; i<10; i++) {

    for (string file_size : data_file_sizes) {

      auto input_file = ifstream(path + "/04/" + file_size + ".csv");

      //  auto input_file = ifstream(path + "/03/5000000.csv");

      vector<int> keys, shuffled_keys;
      string line;

      if (input_file) {
        while (getline(input_file, line)) {
          if (line != "") {
            keys.push_back(atoi(line.c_str()));
            shuffled_keys.push_back(atoi(line.c_str()));
          }
        }
      }
      random_shuffle(shuffled_keys.begin(), shuffled_keys.end());

      input_file.close();

      Node* root = NULL;
//      root = insert_benchmark_func(root, keys);

      const auto time_point_before = chrono::steady_clock::now();

//            root = insert_benchmark_func(root, keys);
//            root = delete_benchmark_func(root, shuffled_keys);
            search_benchmark_func(root, shuffled_keys);

      const auto time_point_after = chrono::steady_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      bench_file << time_elapsed_ns << ";";

      //    cout << abs(time_elapsed_ns) << "\n";
    }
    bench_file << "\n";
  }

  bench_file.close();

  return 0;
}
