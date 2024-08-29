//sum of polynomial use cofficient and power

#include <iostream>

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

void sort(polynomialarray p[], int n){
    int i, j;
    polynomialarray temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if(p[j].expo < p[j+1].expo){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int sum(polynomialarray p1[], polynomialarray p2[], polynomialarray p3[], int n, int m){
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n && j < m)
        {
            if (p1[i].expo > p2[j].expo)
            {
                p3[k].coeff = p1[i].coeff;
                p3[k].expo = p1[i].expo;
                i++;
                k++;
            }
            else if (p1[i].expo < p2[j].expo)
            {
                p3[k].coeff = p2[j].coeff;
                p3[k].expo = p2[j].expo;
                j++;
                k++;
            }
            else
            {
                p3[k].coeff = p1[i].coeff + p2[j].coeff;
                p3[k].expo = p1[i].expo;
                i++;
                j++;
                k++;
            }
        }
        while (i < n)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        }
        while (j < m)
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }

        return k;
}



int main(int argc, char const *argv[])
{
    polynomialarray p1[10], p2[10], p3[10];
    int n, m, i, k;

    cout << "Enter the number of terms in first polynomial: ";
    cin >> n;

    for(i=0; i<n; i++){
        p1[i].add();
    }

    sort(p1, n);


    cout << "Enter the number of terms in second polynomial: ";
    cin >> m;

    for(i=0; i<m; i++){
        p2[i].add();
    }

    sort(p2, m);

    k = sum(p1, p2, p3, n, m);

    cout << "The sum of the two polynomials is: ";
    for (i = 0; i < k; i++)
    {
        p3[i].display();
    }
  
    return 0;

}
