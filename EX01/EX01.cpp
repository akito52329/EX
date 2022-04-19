#include<iostream>
using namespace std;

int main() {
    int crane = 0;	//鶴
    int turtle = 0;	//亀
    int heads = 0;	//頭
    int legs = 0;	//脚
    cout << "頭の数は：";
    cin >> heads;
    cout << "脚の数は：";
    cin >> legs;

    turtle = legs / 2 - heads;//亀の計算
    crane = heads - turtle;//鶴の計算

    //ここで鶴と亀の数をcraneとturtleに代入
    cout << "鶴は" << crane << "亀は" << turtle << endl;
    return 0;
}