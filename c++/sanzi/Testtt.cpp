#include <iostream.h> 
class A 
{ 
public:
 virtual void print(void) 
 { 
    cout<<"A::print()"<<endl; 
 } 
};
class B:public A 
{ 
public:
 virtual void print(void) 
 { 
   cout<<"B::print()"<<endl;
 }; 
}; 
class C:public B
{
public:
 virtual void print(void)
 {
  cout<<"C::print()"<<endl;
 }
};
void print(A a) 
{ 
   a.print(); 
} 
void main(void) 
{ 
   A a, *pa,*pb,*pc; 
   B b; 
   C c; 
   
   pa=&a; 
   pb=&b; 
   pc=&c; 
   
   a.print(); ////  A::print()
   b.print(); //  B::print()
   c.print();  // C::print()
   
   pa->print(); //A::print()
   pb->print(); //B::print()
   pc->print(); //C::print()
   
   print(a); //
   print(b); //
   print(c); //
} 
