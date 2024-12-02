#include <iostream>
using namespace std;

void processInput(int x){
    if (x > 5) {
        cout << "xは5より大きい" << endl;
    } else {
        cout << "xは5以下" << endl;
    }

    cout << "xの値は" << x << "です" << endl;
}

void logicalOperator(int x, int y) {
    if (x == 10 && y == 10) {
        cout << "xとyは10" << endl;
    }

    if (x == 10 || y == 10) {
        cout << "xかyは10" << endl;
    }

    if (!(x == y)) {
        cout << "x と y は等しくない" << endl;
    }

}

void elseif(int x ) {
      if (x < 10) {
    cout << "xは10より小さい" << endl;
  }
  else if (x > 20) {
    cout << "xは10より小さくなくて、20より大きい" << endl;
  }
  else if (x == 15) {
    cout << "xは10より小さくなくて、20より大きくなくて、15である" << endl;
  }
  else {
    cout << "xは10より小さくなくて、20より大きくもなくて、15でもない" << endl;
  };
}

int main() {
    int x;
    int y;
    cin >> x >> y;
    /*processInput(x);*/
    logicalOperator(x, y);
    return 0;
}
