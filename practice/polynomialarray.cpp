#include<iostream>
using namespace std;

class polynomial{
    public:
    float coef;
    int expo;

    polynomial(){
        coef = 0;
        expo = 0;
    }

    void setvalue(float c,int e){
        coef = c;
        expo = e;
    }
};


void display(polynomial p[], int n){
    for(int i=0 ; i<n && p[i].expo!=0 ; i++){
        cout << p[i].coef << "X^" << p[i].expo;
        cout << " + ";
    }

    cout << endl;
}

void sort(polynomial p[], int n){
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-1-i;j++){
            if(p[j].expo > p[j+1].expo){
                polynomial temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

}

void addition(polynomial p1[], polynomial p2[], polynomial p3[],int n1,int n2){
    sort(p1,n1);
    sort(p2,n2);

    int i =0;
    int j=0;
    int k=0;

    while(i<n1 && j<n2){
        if(p1[i].expo == p2[j].expo){
            p3[k].expo = p1[i].expo;
            p3[k].coef = p1[i].coef + p2[j].coef;

            i++;
            j++;
            k++;
        }
        else if(p1[i].expo > p2[j].expo){
            p3[k] = p1[i];

            k++;
            i++;
        }
        else{
            p3[k] = p2[j];

            j++;
            k++;
        }
    }

    while(i<n1){
        p3[k] = p1[i];

        i++;
        k++;
    }

    while(j<n2){
        p3[k] = p2[j];

        j++;
        k++;
    }
}

int main(){
    int n1,n2;

    cout << "Enter size";

    cin >> n1 >> n2;

    polynomial p1[n1];
    polynomial p2[n2];

    cout << "Enter polynomial 1";

    for(int i =0;i<n1;i++){
        cout << "Expo: ";
        cin >> p1[i].expo;
        cout << "Coef: ";
        cin >> p1[i].coef;
    }
    cout << "Enter polynomial 2";

    for(int i =0;i<n2;i++){
        cout << "Expo: ";
        cin >> p2[i].expo;
        cout << "Coef: ";
        cin >> p2[i].coef;
    }

    int size = n1+n2;
    polynomial p3[size];

    addition(p1,p2,p3,n1,n2);

    display(p3,size);

}