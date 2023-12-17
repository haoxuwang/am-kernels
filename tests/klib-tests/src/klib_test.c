
#include "../include/klib_test.h"

#define N 32
uint8_t data[N];

void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    data[i] = i + 1;
  }
}

// 检查[l,r)区间中的值是否依次为val, val + 1, val + 2...
void check_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(data[i] == val + i - l);
  }
}

// 检查[l,r)区间中的值是否均为val
void check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(data[i] == val);
  }
}

void test_memset() {
  int l, r;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      uint8_t val = (l + r) / 2;
      memset(data + l, val, r - l);
      check_seq(0, l, 1);
      check_eq(l, r, val);
      check_seq(r, N, r + 1);
    }
  }
}




void test_strlen() {
    for (size_t i = 1; i < 32; i++)
    {
      char test[i];
      for (size_t j = 0; j < i-1; j++)
      {
        test[j] = j;
      }
      test[i - 1] = '\0';
      assert(strlen(test)==i-1);
    }
    
}

int num_data[] = {0, INT_MAX / 17, INT_MAX, INT_MIN, INT_MIN + 1,
              UINT_MAX / 17, INT_MAX / 17, UINT_MAX};

void test_sprintf() {
  char buf[128];
  sprintf(buf, "%d + %d = %d\n", 1, 1, 2);
	assert(strcmp(buf, "1 + 1 = 2\n") == 0);
}

int main(){
    test_memset();
    test_strlen();
    test_sprintf();
}