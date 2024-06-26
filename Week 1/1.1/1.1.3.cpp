#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    //defining an array with names of the numers
    string nameForNum[9]={"one","two","three","four","five","six","seven","eight","nine"};
    
    //creating and printing output
    for(int i=a; i<=b;i++){
        if(1<=i and i<=9){
            cout<< nameForNum[i-1]<<endl;   
        }else{
            if(i%2==0){
                cout << "even" << endl;
            }else{
                cout << "odd" << endl;
            }
        }
    }
return 0;

}