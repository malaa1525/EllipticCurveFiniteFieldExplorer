#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// returns n modulo p
int mod(int n, int p){
    int r=n%p;
    if (r<0) r+=p;
    return r;
}

//modular exponentiation: computes base^expnont mod p
int modPower(int base, int exponent, int p){
    int result=1;
    for (int i=1;i<=exponent; i++){
        result*=base;
    }
    result=mod(result,p);
    return result;
    
}


//Basic primality test
bool IsPrime(int p){
    if (p<2) return false;
    if (p==2) return true;
    if (p%2==0) return false;
    for(int i=3; i*i<=p;i++){
        if (p%i==0) return false;}
    return true;
}



int main() {
    int p,a,b;
    cout << "This is an elliptic curve over finite fields explorer.\nIt studies elliptic curves E: y^2=x^3+ax+b over finite fields F_p for a prime p not equal to 2 or 3.\nPlease input the prime p and the coefficients a and b\n\n";
    
    
    bool InvalidInput=true;
    do{
        cout << "p= ";
        cin >> p;
        if (p==2 || p==3) cout << "p can not be 2 or 3\n";
        else if (!IsPrime(p)) cout << "p is not a prime\n"; 
        else InvalidInput=!IsPrime(p); 
    }while(InvalidInput);
    cout << "\na= ";
    cin>> a;
    cout << "\nb= ";
    cin>> b;
    
    
    int disc=-16*(4*a*a*a +27*b*b);
    cout << "Discriminant E= "<< disc<<endl;
    int disc_p=mod(disc,p);
    if (disc_p ==0) cout << "The curve E is singular modulo p, so it is not an elliptic curve";
    else {
        cout << "Discriminant E mod p = "<< disc_p<<endl;
        //Euler's Criterion: given an integer n and a prime p coprime to n, n is a square mod p iff n^((p-1)/2) is congruent to 1 mod p, otherwise, n is not a square. 
        
        int a_p=mod(a,p);
        int b_p=mod(b,p);
        cout<<"working modulo p, we have a="<< a_p << ", b="<<b_p<< endl;
        
        int x; //x-coordinates
        int SquareCounter=0; // counts the x-coordinates where we have a non-zero value for y mod p. We get two points for such x.
        int ZeroCounter=0; // counts the x-coordinates where we have a zero value for y mod p. We get one point for such x.
        int exponent=(p-1)/2;
        int rhs, Y2;
        vector<int> points;
        for (x=0;x<p;x++)
        {
            rhs=mod(x*x*x+a_p*x+b_p,p);
            cout<< "x= "<< x<< ", rhs=x^3+ax+b mod p= "<< rhs<< endl;
            Y2=modPower(rhs,exponent,p);
            cout << "rhs^((p-1)/2) mod p= "<< Y2<< endl;
            if (Y2==1) {SquareCounter++;
                points.push_back(x);
            }
            else if (Y2==0) {ZeroCounter++;
                points.push_back(x);
            }
        }
        cout << "Then #E(F_p)= "<< 2*SquareCounter+ZeroCounter+1 << endl;
        cout<< "The x-coordinates are:{ ";
        for(int k : points){
        cout<< k << ",  ";
        }
        cout<<"the point at infinity [0:1:0]}";
    }
    return 0;
}
