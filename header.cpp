#include <iostream>
#include <cmath>
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

void Cardioid::set(long double value){
	if (!cin || value<0)
        	throw exception();
	a=value;
}

long double Cardioid::get(){
	return a;
}

long double Cardioid::distance(long double f){
	return 2*a*(1-cos(f));
}

long double Cardioid::square(){
	return 6*a*a*M_PI;
}

long double Cardioid::length(long double f){
	return 8*a*(1-cos(f/2));
}

long double Cardioid::curvature(long double f){
	return 8.0/3.0*a*sin(f/2);
}

long double *Cardioid::extreme(){
	long double *array=new long double[4];
	array[0]=2*a*(1-cos(2*M_PI/3))*cos(2*M_PI/3);
	array[1]=2*a*(1-cos(2*M_PI/3))*sin(2*M_PI/3);
	array[2]=2*a*(1-cos(2*M_PI/3))*cos(2*M_PI/3);
	array[3]=2*a*(cos(2*M_PI/3)-1)*sin(2*M_PI/3);
	return array;
}

void dialogue(){
	Cardioid card;
	string commands[]={"0: Quit", "1: Setting radius", "2: Getting radius", "3: Getting distance", "4: Getting square", "5: Getting length", "6: Getting radius of curvature", "7: Getting maximum and minimum\n"};
	cout<<endl;
	long long res=sizeof(commands)/sizeof(commands[0]);
	while (res){
		cout<<"MENU:"<<endl;
        	for (long long i=0; i<sizeof(commands)/sizeof(commands[0]); i++){
        		cout<<commands[i]<<endl;
		}
        	cout<<"Enter number of a command:"<<endl;
		res=1;
        	try{
			cin>>res;
			if (!cin || res>=sizeof(commands)/sizeof(commands[0]) || res<0)
                		throw exception();
        	}catch (exception &ex){
			res=1;
			scanf("%*c");
			cin.clear();
			cout<<"Invalid command!"<<endl<<endl;
			continue;
		}
        	cout<<endl;
		long double f;
		long double a;
		long double *array;
		switch (res){
			case 0:
				break;
			case 1:
				try{
					cout<<"Enter a radius:"<<endl;
					cin>>a;
					card.set(a);
        			}catch (exception &ex){
					res=1;
					scanf("%*c");
					cin.clear();
					cout<<"Invalid radius!"<<endl<<endl;
					continue;
				}
				cout<<endl;
				break;
			case 2:
				cout<<"Radius: "<<card.get()<<endl<<endl;
				break;
			case 3:
				cout<<"Enter an angle:"<<endl;
				cin>>f;
				cout<<endl;
				cout<<"Distance: "<<card.distance(f)<<endl<<endl;
				break;
			case 4:
				cout<<"Square: "<<card.square()<<endl<<endl;
				break;
			case 5:
				cout<<"Enter an angle:"<<endl;
				cin>>f;
				cout<<endl;
				cout<<"Square: "<<card.length(f)<<endl<<endl;
				break;
			case 6:
				cout<<"Enter an angle:"<<endl;
				cin>>f;
				cout<<endl;
				cout<<"Radius of curvature: "<<card.curvature(f)<<endl<<endl;
				break;
			case 7:
				array=card.extreme();
				cout<<"Maximum:     x="<<array[0]<<"     y="<<array[1]<<endl;
				cout<<"Minimum:     x="<<array[2]<<"     y="<<array[3]<<endl<<endl;
				delete[] array;
				break;
		}
	}
}
