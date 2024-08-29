#include<bits/stdc++.h>
using namespace std;

class Circularqueue{
    public:

    int arr[5];
    int start=-1;
    int rear=-1;

    void Emplace(int x){
        if(start == -1){
            arr[++start] = x;
            ++rear;
        }
        else if(start == (rear+1)%5 ){
            start++;
            rear = (rear+1)%5;
            arr[rear] = x;
        }
        else{
            rear = (rear + 1)%5;
            arr[rear] = x;
        }
    }

    void Display(){
        int y = start;

        if(start == -1){
            cout << "Empty";
            return;
        }

        while(y !=rear){
            cout << arr[y] << endl;
            y=(y+1)%5;
        }
        cout << arr[y];
    }

};

int main(int argc, char const *argv[])
{

    Circularqueue* C1 = new Circularqueue();

    C1->Emplace(1);
    C1->Emplace(2);
    C1->Emplace(3);
    C1->Emplace(4);
    C1->Emplace(5);
    C1->Emplace(6);
    C1->Emplace(7);

    C1->Display();
    
    return 0;
}
