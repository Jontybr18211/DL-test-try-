#include <stdio.h>

int step_function(double x) {
      return (x >= 0) ? 1 : 0;
}

int perceptron(int x1, int x2, double w1, double w2, double b) {
      return step_function(w1*x1 + w2*x2 + b);
}

int OR(int x1, int x2) {
      return perceptron(x1, x2, 1, 1, -0.5);
}

int NAND(int x1, int x2) {
      return perceptron(x1, x2, -1, -1, 1.5);
}

int AND(int x1, int x2) {
      return perceptron(x1, x2, 1, 1, -1.5);
}

int XOR(int x1, int x2) {
      int h1 = OR(x1, x2);
      int h2 = NAND(x1, x2);
      return AND(h1, h2);
}

int main() {
      int i, j;
      for (i = 0; i <= 1; i++) {
            for (j = 0; j <= 1; j++) {
                  printf("%d %d -> %d\n", i, j, XOR(i, j));
            }
      }
      return 0;
}
