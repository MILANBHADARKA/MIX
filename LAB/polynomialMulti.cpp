#include<bits/stdc++.h>
using namespace std;

class polynomialarray
{

public:
    int coeff;
    int expo;

    void add(){
        cout << "coefficients : ";
        cin >> coeff;
        cout << "exponent : ";
        cin >> expo;
    }

    void display(){
        cout << coeff << "x^" << expo << " ";
    }

};

void sort(polynomialarray arr[], int n){

    polynomialarray temp;

    for(int i=0;i<n;i++){
        for(int j = 0; j < n-i-1;j++){
            if(arr[j].expo < arr[j+1].expo){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int multiplication(polynomialarray p1[], polynomialarray p2[],polynomialarray p3[], int m, int n){
    int k =0;
    for(int i = 0;i<m; i++){
        for(int j = 0; j<n;j++){
            p3[k].expo = p1[i].expo + p2[j].expo;
            p3[k].coeff = p1[i].coeff * p2[j].coeff;
            k++;
        }
    }

    return k;
}

int main(int argc, char const *argv[])
{
    polynomialarray p1[10];
    polynomialarray p2[10];
    polynomialarray p3[100];

    int m,n;
    cout << "Enter size of poly 1: ";
    cin >> m;

    cout << "Enter the size of poly2 : ";
    cin >> n;

    for(int i=0;i<m;i++){
        p1[i].add();
    }
    for(int i=0;i<n;i++){
        p2[i].add();
    }

    int k = multiplication(p1,p2,p3,m,n);

    for(int i=0;i<k;i++){
        p3[i].display();
    }

    return 0;
}
