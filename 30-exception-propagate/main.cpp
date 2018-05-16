#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

//write your code here
class Calculator : public exception {
	private :
		struct ooops : std::exception {
			const char* what() const noexcept { return "n and p should be non-negative"; }
		};
	public :
		int power(int base, int exponent) {
			if(base < 0 || exponent < 0) {
				throw ooops(); 
			}
			return pow(base, exponent);
		}
};

int main() {
	Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }

	return 0;
}
