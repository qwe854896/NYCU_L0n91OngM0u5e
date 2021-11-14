#include<random>
#include<ctime>
void test() {
  mt19937 gen(time(NULL));
  uniform_int_distribution<int> dist(0,100);
  cout << dist(gen) << endl;
}