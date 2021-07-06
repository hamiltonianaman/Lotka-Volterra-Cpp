#include<tuple>
#include<iomanip>
#include<fstream>
using namespace std;

#define fmt  setw(20) << setprecision(10) << scientific 
// fmt will be used in output formatting


double alpha, beta, delta, eta, h;

double dprey(double prey,double predator){
	return(prey*alpha - prey*predator*beta);
}

double dpredator(double prey,double predator){
	return(predator*delta*prey*beta  - eta*predator);
}


auto rk4(double prey,double predator){
	//K1
	double kx1 = h*dprey(prey,predator);
	double ky1 = h*dpredator(prey,predator);	
	//k2
	double kx2 = h*dprey(prey+.5*kx1,predator+.5*ky1);
	double ky2 = h*dpredator(prey+.5*kx1,predator+.5*ky1);
	//K3
	double kx3 = h*dprey(prey+.5*kx2,predator+.5*ky2);
	double ky3 = h*dpredator(prey+.5*kx2,predator+.5*ky2);
	//K4
	double kx4 = h*dprey(prey+kx3,predator+ky3);
	double ky4 = h*dpredator(prey+kx3,predator+ky3);
	
	return make_tuple(prey+(kx1+2*(kx2+kx3)+kx4)/6,predator+(ky1+2*(ky2+ky3)+ky4)/6);
}

int main(){
	//System parameters
	double prey=10,predator=5,time=0.0,endtime=15.0;		
	
	h     = 1e-4;	
	alpha = 1; 
	beta  =.1; 
	eta   =	1.5;
	delta =.75;
	
	/*
	alpha : Natural Birth rate of preys in absence of any predation
	Beta  : Death rate of preys due to predation
	eta   : Natural death rate of predator
	delta : Number of prey death required to make one predator 
	h	  : step-size    
	*/
	
	/*
	Differential equation used for numerical simulations.
	prey'	 	= alpha*prey - beta*prey*predator
	predator' 	= delta*prey*predator*beta - eta*predator
	*/
	
	
	ofstream output("output.dat");
	
	output <<"#"<< setw(19) <<"Time" << setw(20) <<"Prey" << setw(20) <<"Predator" <<endl;
	while(time<=endtime){		
		tie(prey,predator)=rk4(prey,predator);
		output << fmt << time << fmt << prey << fmt << predator << endl;
		time+=h;
	}
	output.close();
	
}
