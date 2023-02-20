#ifndef __header__
#define __header__

class Cardioid{
	private:
		long double a;
	public:
		Cardioid(long double a=0){set(a);}
		~Cardioid(){}
		long double get();
		long double square();
		long double distance(long double);
		long double length(long double);
		long double curvature(long double);
		long double *extreme();
		void set(long double);
};

void dialogue();

#endif
